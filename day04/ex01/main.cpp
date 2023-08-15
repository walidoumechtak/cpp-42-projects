#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


void    subTest()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;
}

void    Half_dog_Half_cat()
{
    int size = 10;
    Animal  *arr[size];

    for (int    i = 0; i < size; i ++)
    {
        if (i < size / 2)
            arr[i] = new Dog();
        else
            arr[i] = new Cat();
    }

    for (int    j = 0; j < size; j ++)
        delete arr[j];
}

void    DeepCopy()
{
    {
        Cat c1;
        Cat c2(c1);

        Brain *ptr_cat = c1.getBrain();
        std::cout << "ptr is : " << ptr_cat << std::endl;
        std::cout << "The addr is: " << c2.getBrain() << std::endl;
    }
    std::cout << " ===============================================" << std::endl;

        Dog d1;
        Dog d2(d1);

        Brain *ptr_dog = d1.getBrain();
        std::cout << "ptr is : " << ptr_dog << std::endl;
        std::cout << "the addr is : " << d2.getBrain() << std::endl;
}

int main(void)
{
    // subTest();
    // Half_dog_Half_cat();
    DeepCopy();



    system("leaks brain");
    return (0);
}