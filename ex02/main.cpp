#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    Base *base = new Base;
    Base *a = new A;
    Base *b = new B;
    Base *c = new C;

    
    base->identify(a);
    base->identify(b);
    base->identify(c);
    base->identify(*a);
    base->identify(*b);
    base->identify(*c);

    delete base;
    delete a;
    delete b;
    delete c;
    return 0;
}