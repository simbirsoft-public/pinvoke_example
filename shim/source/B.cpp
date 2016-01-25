#include "stdafx.h"
#include "shim_api.h"
#include "UnmanagedB.h"

using namespace shim;
using namespace cpp;

SHIM UnmanagedB *UnmanagedB_createInstance()
{
	return new UnmanagedB();
}

SHIM void UnmanagedB_setMethodHandler(UnmanagedB *instance, IB_method_ptr ptr)
{
	instance->setMethodHandler(ptr);
}

SHIM void UnmanagedB_resetManagedObject(UnmanagedB *instance)
{
    instance->resetManagedObject();
}

SHIM int BImpl_method(IB *instance, int arg)
{
	return instance->method(arg);
}
