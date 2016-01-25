#include "stdafx.h"
#include "C.h"
#include "ModuleException.h"

using namespace cpp;

C::C() {}

int C::method(int arg)
{
    if (arg > 10)
        throw ModuleException(1);
    return 5 * arg;
}
