#pragma once

namespace cpp
{

    class CPP IB : public IObject
    {
    public:
		IB();
        virtual int method(int arg) = 0;
        virtual ~IB() {};
    };

}
