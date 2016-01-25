#pragma once
#include "type_defenitions.h"


namespace cpp
{
    class A;
    class IB;
    class C;
	class ModuleException;
}

namespace shim
{
	class UnmanagedB;
	class UnmanagedC;
}

#ifdef __cplusplus
extern "C"
{
#endif

    //A
    SHIM cpp::A* A_createInstance(int someArgument);
    SHIM int A_someMethod(cpp::A *instance, int someArgument);

	//IB
	SHIM shim::UnmanagedB *UnmanagedB_createInstance();
	SHIM void UnmanagedB_setMethodHandler(shim::UnmanagedB *instance, IB_method_ptr ptr);

	SHIM int BImpl_method(cpp::IB *instance, int arg);

	//C
	SHIM shim::UnmanagedC *UnmanagedC_createInstance();
	SHIM void UnmanagedC_setMethodHandler(shim::UnmanagedC *instance, Ñ_method_ptr ptr);

	SHIM cpp::C *C_createInstance();
	SHIM int C_method(cpp::C *instance, int arg, cpp::ModuleException **error);

	//ModuleException
	SHIM cpp::ModuleException *ModuleException_createInstance(int code);
	SHIM int ModuleException_getCode(cpp::ModuleException *instance);

	//Utils
	SHIM void IObject_addRef(cpp::IObject *instance);
	SHIM void IObject_release(cpp::IObject *instance);
	SHIM void IReset_resetManagedObject(shim::IReset *instance);

#ifdef __cplusplus 
} // extern "C"
#endif