#include "stdafx.h"
#include "ModuleException.h"

using namespace cpp;

ModuleException::ModuleException(int code)
{
	mCode = code;
}

int ModuleException::getCode()
{
	return mCode;
}

ModuleException::~ModuleException()
{
}
