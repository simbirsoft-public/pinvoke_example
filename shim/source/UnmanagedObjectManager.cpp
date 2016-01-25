#include "stdafx.h"
#include "UnmanagedObjectManager.h"

namespace shim
{

	UnmanagedObjectManager UnmanagedObjectManager::mInstance;

	UnmanagedObjectManager::UnmanagedObjectManager()
		: mAdd(nullptr)
		, mRemove(nullptr)
	{
	}

	void shim::UnmanagedObjectManager::add(void * instance)
	{
		if (mInstance.mAdd == nullptr)
			return;
		mInstance.mAdd(instance);
	}

	long UnmanagedObjectManager::remove(void * instance)
	{
		if (mInstance.mRemove == nullptr)
			return 0;
		return mInstance.mRemove(instance);
	}

	void UnmanagedObjectManager::setAdd(UnmanagedObjectManager_add ptr)
	{
		mInstance.mAdd = ptr;
	}

	void UnmanagedObjectManager::setRemove(UnmanagedObjectManager_remove ptr)
	{
		mInstance.mRemove = ptr;
	}

}