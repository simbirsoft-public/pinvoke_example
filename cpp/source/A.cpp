#include "stdafx.h"
#include "A.h"

using namespace cpp;

A::A(int someArgument)
    : mField(someArgument)
{
}

int A::someMethod(int someArgument)
{
    return mField * someArgument;
}
