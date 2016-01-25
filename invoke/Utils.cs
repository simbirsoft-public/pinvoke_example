using System;
using System.Runtime.InteropServices;
using System.Diagnostics;

namespace invoke
{
    internal static class Utils
    {
        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void IObject_addRef(IntPtr instance);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void IObject_release(IntPtr instance);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void IReset_resetManagedObject(IntPtr instance);

        internal static void addRef(IntPtr instance)
        {
            if (instance != IntPtr.Zero)
                IObject_addRef(instance);
        }

        internal static void release(IntPtr instance)
        {
            if (instance != IntPtr.Zero)
                IObject_release(instance);
        }

        internal static void resetManagedObject(IntPtr instance)
        {
            if (instance != IntPtr.Zero)
                IReset_resetManagedObject(instance);
        }
    }
}
