using System;
using System.Runtime.InteropServices;

namespace invoke
{
    public abstract class AB
    {
        private IntPtr mInstance;

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr UnmanagedB_createInstance();

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr UnmanagedB_setMethodHandler(IntPtr instance,
        [MarshalAs(UnmanagedType.FunctionPtr)]MethodHandler ptr);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void UnmanagedB_resetManagedObject(IntPtr instance);

        [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
        private delegate int MethodHandler(int arg);

        private int impl_method(int arg)
        {
            return method(arg);
        }

        public abstract int method(int arg);

        public AB()
        {
            mInstance = UnmanagedB_createInstance();
            UnmanagedB_setMethodHandler(mInstance, impl_method);
        }

        ~AB()
        {
            UnmanagedB_resetManagedObject(mInstance);
            Utils.release(mInstance);
        }

        internal virtual IntPtr getUnmanaged()
        {
            ObjectManager.add(mInstance, this);
            return mInstance;
        }

    }
}
