#pragma once

#ifdef WIN32
#define _STDCALL _stdcall
#else
#define _STDCALL
#endif

namespace cpp
{
	class ModuleException;
}

typedef int (_STDCALL *IB_method_ptr)(int arg);

typedef int (_STDCALL *Ñ_method_ptr)(int arg, cpp::ModuleException **error);

typedef long (_STDCALL *UnmanagedObjectManager_remove)(void* instance);
typedef void (_STDCALL *UnmanagedObjectManager_add)(void* instance);