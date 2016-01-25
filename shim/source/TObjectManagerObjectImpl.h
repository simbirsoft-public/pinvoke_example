#pragma once

#include "UnmanagedObjectManager.h"
#include "IReset.h"

namespace shim
{
	template <typename T>
	class TObjectManagerObjectImpl : public T, IReset
	{
		mutable bool mManagedObjectReleased;
	public:
		TObjectManagerObjectImpl()
			: mManagedObjectReleased(false)
		{
		}

		virtual ~TObjectManagerObjectImpl()
		{
			UnmanagedObjectManager::remove(getInstance());
		}

		void *getInstance() const
		{
			return (void *)this;
		}

		virtual void addRef() const
		{
			UnmanagedObjectManager::add(getInstance());
		}

		virtual bool release() const
		{
			long result = UnmanagedObjectManager::remove(getInstance());
			if (result == 0)
				if (mManagedObjectReleased)
					delete this;
			return result == 0;
		}

		virtual void resetManagedObject() const
		{
			mManagedObjectReleased = true;
		}
	};

}