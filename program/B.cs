using System;
using invoke;

namespace program
{
    class B : AB
    {
        public override int method(int arg)
        {
            return arg * 10;
        }
    }
}
