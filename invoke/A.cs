using System;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace invoke
{
    public sealed class A
    {
        private IntPtr mInstance;

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr A_createInstance(int someArgument);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int A_someMethod(IntPtr instance, int someArgument);

        internal A(IntPtr instance)
        {
            Debug.Assert(instance != IntPtr.Zero);
            mInstance = instance;
            Utils.addRef(mInstance);
        }

        public A(int someArgument)
        {
            mInstance = A_createInstance(someArgument);
        }

        public int someMethod(int someArgument)
        {
            return A_someMethod(mInstance, someArgument);
        }

        internal IntPtr getUnmanaged()
        {
            Utils.addRef(mInstance);
            return mInstance;
        }

        ~A()
        {
            Utils.release(mInstance);
        }

    }
}
