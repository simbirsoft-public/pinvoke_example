using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace invoke
{
    internal static class ObjectManager
    {
        [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
        private delegate void AddHandler(IntPtr instance);
        [UnmanagedFunctionPointerAttribute(CallingConvention.Cdecl)]
        private delegate long RemoveHandler(IntPtr instance);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void UnmanagedObjectManager_setAdd(
            [MarshalAs(UnmanagedType.FunctionPtr)] AddHandler ptr);

        [DllImport("shim.dll", CallingConvention = CallingConvention.Cdecl)]
        private static extern void UnmanagedObjectManager_setRemove(
            [MarshalAs(UnmanagedType.FunctionPtr)] RemoveHandler ptr);

        private static AddHandler mAddHandler;
        private static RemoveHandler mRemoveHandler;

        private class Holder
        {
            internal int count;
            internal Object ptr;
        }

        private static Dictionary<IntPtr, Holder> mObjectMap;

        private static long removeImpl(IntPtr instance)
        {
            return remove(instance);
        }

        private static void addImpl(IntPtr instance)
        {
            add(instance);
        }

        static ObjectManager()
        {
            mAddHandler = new AddHandler(addImpl);
            UnmanagedObjectManager_setAdd(mAddHandler);
            mRemoveHandler = new RemoveHandler(removeImpl);
            UnmanagedObjectManager_setRemove(mRemoveHandler);

            mObjectMap = new Dictionary<IntPtr, Holder>();
        }

        internal static void add(IntPtr instance, Object ptr = null)
        {
            Holder holder;
            if (!mObjectMap.TryGetValue(instance, out holder))
            {
                holder = new Holder();
                holder.count = 1;
                holder.ptr = ptr;
            }
            else
            {
                if (holder.ptr == null && ptr != null)
                    holder.ptr = ptr;
                holder.count++;
            }
        }

        internal static long remove(IntPtr instance)
        {
            long result = 0;
            Holder holder;
            if (mObjectMap.TryGetValue(instance, out holder))
            {
                holder.count--;
                if (holder.count == 0)
                    mObjectMap.Remove(instance);
                result = holder.count;
            }
            return result;
        }
    }
}
