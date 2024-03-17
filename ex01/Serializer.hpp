#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

class Serializer
{
public:
    Serializer();
    Serializer(std::string const &value);
    Serializer(Serializer const &src);
    ~Serializer();

    Serializer &operator=(Serializer const &rhs);

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif