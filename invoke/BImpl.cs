using System;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace invoke
{
    internal sealed class BImpl : AB
    {
        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int BImpl_method(IntPtr instance, int arg);

        private IntPtr mInstance;
        internal BImpl(IntPtr instance)
        {
            Debug.Assert(instance != IntPtr.Zero);
            mInstance = instance;
            Utils.addRef(mInstance);
        }

        ~BImpl()
        {
            Utils.release(mInstance);
        }

        public override int method(int arg)
        {
            return BImpl_method(mInstance, arg);
        }

        internal override IntPtr getUnmanaged()
        {
            Utils.addRef(mInstance);
            return mInstance;
        }

    }
}
