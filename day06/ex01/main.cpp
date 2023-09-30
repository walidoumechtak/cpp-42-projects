#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
    Data *before_cast = new Data();
    uintptr_t   int_ptr;
    Data *after_cast;

    std::cout << "before cast: " << before_cast << std::endl;

    int_ptr = Serializer::serialize(before_cast);
    after_cast = Serializer::deserialize(int_ptr);

    std::cout << "after cast: " << after_cast << std::endl;

    delete before_cast;
    return (0);
}