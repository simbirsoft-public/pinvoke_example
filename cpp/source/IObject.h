#pragma once

namespace cpp
{

	class CPP IObject
	{
	protected:
		IObject();
		virtual ~IObject();
	public:
		virtual void addRef() const = 0;
		virtual bool release() const = 0;
	};

}