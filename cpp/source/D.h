#pragma once

#include "IObject.h"
#include "TObjectImpl.h"

namespace cpp
{
    class IB;
    class C;

    class CPP D : public TObjectImpl<IObject>
    {
        IB *mB;
        C *mC;
    public:
        D(IB *b, C *c);
        ~D();

        int method(int arg);
    };

}
