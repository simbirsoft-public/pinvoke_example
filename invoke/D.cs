using System;
using System.Runtime.InteropServices;

namespace invoke
{
    public sealed class D
    {
        private IntPtr mInstance;

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr D_createInstance(IntPtr b, IntPtr c);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int D_method(IntPtr instance, int arg, ref IntPtr error);

        public D(AB b, C c)
        {
            if (b == null || c == null)
                throw new NullReferenceException();
            IntPtr bUnmanaged = b.getUnmanaged();
            IntPtr cUnmanaged = c.getUnmanaged();

            mInstance = D_createInstance(bUnmanaged, cUnmanaged);

            Utils.release(bUnmanaged);
            Utils.release(cUnmanaged);
        }

        public int method(int arg)
        {
            IntPtr error = IntPtr.Zero;
            int result = D_method(mInstance, arg, ref error);
            if (error != IntPtr.Zero)
            {
                var ex = new ModuleException(error);
                Utils.release(error);
                throw ex;
            }
            return result;
        }

        ~D()
        {
            Utils.release(mInstance);
        }
    }
}
