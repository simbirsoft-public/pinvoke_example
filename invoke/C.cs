using System;
using System.Runtime.InteropServices;

namespace invoke
{
    public class C
    {
        private IntPtr mHandlerInstance;
        private IntPtr mInstance;

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr UnmanagedC_createInstance();

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr C_createInstance();

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr UnmanagedC_setMethodHandler(IntPtr instance,
        [MarshalAs(UnmanagedType.FunctionPtr)]MethodHandler ptr);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void UnmanagedC_resetManagedObject(IntPtr instance);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int C_method(IntPtr instance, int arg, ref IntPtr error);

        [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
        private delegate int MethodHandler(int arg, ref IntPtr error);

        private int impl_method(int arg, ref IntPtr error)
        {
            try
            {
                return method(arg);
            }
            catch (ModuleException ex)
            {
                error = ex.getUnmanaged();
                return 0;
            }
        }

        public virtual int method(int arg)
        {
            IntPtr error = IntPtr.Zero;
            int result = C_method(mInstance, arg, ref error);
            if (error != IntPtr.Zero)
            {
                var ex = new ModuleException(error);
                Utils.release(error);
                throw ex;
            }
            return result;
        }

        public C()
        {
            mHandlerInstance = UnmanagedC_createInstance();
            UnmanagedC_setMethodHandler(mHandlerInstance, impl_method);
            mInstance = C_createInstance();
        }

        ~C()
        {
            UnmanagedC_resetManagedObject(mHandlerInstance);
            Utils.release(mHandlerInstance);

            Utils.release(mInstance);
        }

        internal IntPtr getUnmanaged()
        {
            ObjectManager.add(mHandlerInstance, this);
            return mHandlerInstance;
        }

    }
}
