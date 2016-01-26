#include "stdafx.h"
#include "shim_api.h"
#include "UnmanagedC.h"

using namespace shim;
using namespace cpp;

SHIM UnmanagedC *UnmanagedC_createInstance()
{
	return new UnmanagedC();
}

SHIM void UnmanagedC_setMethodHandler(UnmanagedC *instance, Ñ_method_ptr ptr)
{
	instance->setMethodHandler(ptr);
}

SHIM void UnmanagedC_resetManagedObject(UnmanagedC *instance)
{
    instance->resetManagedObject();
}

SHIM C *C_createInstance()
{
	return new C();
}

SHIM int C_method(C *instance, int arg, ModuleException **error)
{
    try
    {
        return instance->method(arg);
    }
    catch (ModuleException& ex)
    {
        *error = new ModuleException(ex.getCode());
        return 0;
    }
}
