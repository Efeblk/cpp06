#include "Serializer.hpp"
#include <iostream>

int main()
{
    std::cout << "sizeof(Data) = " << sizeof(Data) << std::endl;
    Data d;

    d.s1 = "Hello";
    d.n = 42;
    d.s2 = "World";

    uintptr_t raw = Serializer::serialize(&d);
    Data *ptr = Serializer::deserialize(raw);
    (void)ptr;
}