#include "stdafx.h"
#include "shim_api.h"

using namespace cpp;

SHIM A* A_createInstance(int someArgument)
{
    return new A(someArgument);
}

SHIM int A_someMethod(A *instance, int someArgument)
{
    return instance->someMethod(someArgument);
}