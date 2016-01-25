#include "stdafx.h"
#include "shim_api.h"

using namespace cpp;

SHIM D* D_createInstance(IB *b, C *c)
{
    return new D(b, c);
}

SHIM int D_method(D *instance, int arg, ModuleException **error)
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