#include "stdafx.h"
#include "D.h"

namespace cpp
{

    D::D(IB *b, C *c) : mB(b), mC(c)
    {
        if (mB != nullptr)
            mB->addRef();
        if (mC != nullptr)
            mC->addRef();
    }

    D::~D()
    {
        if (mB != nullptr)
            mB->release();
        if (mC != nullptr)
            mC->release();
    }

    int D::method(int arg)
    {
        if (mB == nullptr || mC == nullptr)
            return -1;
        else
            return mB->method(mC->method(arg));
    }

}