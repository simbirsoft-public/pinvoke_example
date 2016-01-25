#include "stdafx.h"
#include "UnmanagedC.h"

using namespace shim;

UnmanagedC::UnmanagedC() {}
UnmanagedC::~UnmanagedC() {}
void UnmanagedC::setMethodHandler(—_method_ptr ptr)
{
	m—_method_ptr = ptr;
}

int UnmanagedC::method(int arg)
{
	cpp::ModuleException *error = nullptr;
	int result = m—_method_ptr(arg, &error);
	if (error != nullptr)
		throw error;
	return result;
}
