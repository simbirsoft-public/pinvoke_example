#pragma once

#include "IObject.h"
#include "TObjectImpl.h"

namespace cpp
{
    class CPP A : TObjectImpl<IObject>
    {
        int mField;
    public:
        A(int someArgument);
        int someMethod(int someArgument);
    };

}
