#include "stdafx.h"
#include "shim_api.h"
#include "UnmanagedB.h"

namespace shim
{

	UnmanagedB::UnmanagedB() {}

	UnmanagedB::~UnmanagedB() {}

	void UnmanagedB::setMethodHandler(IB_method_ptr ptr)
	{
		mIB_method_ptr = ptr;
	}

	int UnmanagedB::method(int arg)
	{
		return mIB_method_ptr(arg);
	}

}