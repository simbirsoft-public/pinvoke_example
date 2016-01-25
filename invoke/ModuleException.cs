using System;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace invoke
{
    public sealed class ModuleException : Exception
    {
        IntPtr mInstance;

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern IntPtr ModuleException_createInstance(int code);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern int ModuleException_getCode(IntPtr instance);

        public int Code
        {
            get
            {
                return ModuleException_getCode(mInstance);
            }
        }

        public ModuleException(int code)
        {
            mInstance = ModuleException_createInstance(code);
        }

        internal ModuleException(IntPtr instance)
        {
            Debug.Assert(instance != IntPtr.Zero);
            mInstance = instance;
            Utils.addRef(mInstance);
        }

        ~ModuleException()
        {
            Utils.release(mInstance);
        }

        internal IntPtr getUnmanaged()
        {
            Utils.addRef(mInstance);
            return mInstance;
        }

    }
}
