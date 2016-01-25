#pragma once

#include "type_defenitions.h"

namespace shim
{
	class UnmanagedObjectManager
	{
		UnmanagedObjectManager();

		static UnmanagedObjectManager mInstance;
		UnmanagedObjectManager_remove mRemove;
		UnmanagedObjectManager_add mAdd;
	public:
		static void add(void *instance);
		static long remove(void *instance);

		static void setAdd(UnmanagedObjectManager_add ptr);
		static void setRemove(UnmanagedObjectManager_remove ptr);
	};

}