#pragma once

#include "IObject.h"
#include "TObjectImpl.h"

namespace cpp
{

	class CPP ModuleException : public TObjectImpl<IObject>
	{
		int mCode;
	public:
		ModuleException(int code);
		int getCode();
		~ModuleException();
	};

}