#pragma once

#include "type_defenitions.h"
#include "TObjectManagerObjectImpl.h"

namespace cpp
{
	class C;
}

namespace shim
{

	class UnmanagedC : public TObjectManagerObjectImpl<cpp::C>
	{
		—_method_ptr m—_method_ptr;
	public:
		UnmanagedC();
		void setMethodHandler(—_method_ptr ptr);
		virtual int method(int arg);
		virtual ~UnmanagedC();
	};

}
