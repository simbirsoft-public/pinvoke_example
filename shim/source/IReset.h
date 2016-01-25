#pragma once

namespace shim
{
	class IReset
	{
	public:
		virtual void resetManagedObject() const = 0;
		virtual ~IReset() {};
	};
}