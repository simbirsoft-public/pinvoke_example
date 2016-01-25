#include "stdafx.h"
#include "shim_api.h"

using namespace cpp;
using namespace shim;

SHIM void IObject_addRef(IObject *instance)
{
	instance->addRef();
}

SHIM void IObject_release(IObject *instance)
{
	instance->release();
}