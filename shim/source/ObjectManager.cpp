#include "stdafx.h"
#include "shim_api.h"
#include "UnmanagedObjectManager.h"

using namespace shim;

SHIM void UnmanagedObjectManager_setAdd(UnmanagedObjectManager_add ptr)
{
    UnmanagedObjectManager::setAdd(ptr);
}

SHIM void UnmanagedObjectManager_setRemove(UnmanagedObjectManager_remove ptr)
{
    UnmanagedObjectManager::setRemove(ptr);
}