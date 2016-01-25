#pragma once

namespace cpp
{
	template<typename T>
	class TObjectImpl : public T
	{
		volatile mutable long mRefs;
	public:
		TObjectImpl()
		{
			mRefs = 1;
		}

		virtual ~TObjectImpl() {}

		virtual void addRef() const
		{
			++mRefs;
		}

		virtual bool release() const
		{
			long result = --mRefs;
			if (result == 0)
				delete this;
			return result == 0;
		}
	};
}