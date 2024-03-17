#include "Serializer.hpp"

Serializer::Serializer()
{
    return;
}

Serializer::Serializer(Serializer const &cpy)
{
    *this = cpy;
    return;
}

Serializer::~Serializer()
{
    return;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
    (void)rhs;
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    std::cout << "Serialized: " << raw << std::endl;
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data *>(raw);

    std::cout << "Deserialized: " << raw << std::endl;
    return ptr;
}