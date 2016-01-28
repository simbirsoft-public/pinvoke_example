#pragma once

namespace cpp
{
	class ModuleException;
}

typedef int (*IB_method_ptr)(int arg);

typedef int (*Ñ_method_ptr)(int arg, cpp::ModuleException **error);

typedef long (*UnmanagedObjectManager_remove)(void* instance);
typedef void (*UnmanagedObjectManager_add)(void* instance);