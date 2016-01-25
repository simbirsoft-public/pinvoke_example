#pragma once

#include "type_defenitions.h"
#include "TObjectManagerObjectImpl.h"

namespace cpp
{
	class IB;
}

namespace shim
{

	class UnmanagedB : public TObjectManagerObjectImpl<cpp::IB>
	{
		IB_method_ptr mIB_method_ptr;
	public:
		UnmanagedB();
		void setMethodHandler(IB_method_ptr ptr);
		virtual int method(int arg);
	protected:
		virtual ~UnmanagedB();
	};

}