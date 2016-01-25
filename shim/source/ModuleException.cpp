#include "stdafx.h"
#include "shim_api.h"

using namespace cpp;

SHIM ModuleException *ModuleException_createInstance(int code)
{
	return new ModuleException(code);
}

SHIM int ModuleException_getCode(ModuleException *instance)
{
	return instance->getCode();
}
