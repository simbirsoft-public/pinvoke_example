#pragma once

#include "IObject.h"
#include "TObjectImpl.h"

namespace cpp
{

	class CPP C : TObjectImpl<IObject>
	{
	public:
		C();
		virtual int method(int arg);
		virtual ~C() {};
	};

}