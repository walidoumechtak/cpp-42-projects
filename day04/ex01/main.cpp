#include "Cat.hpp"
#include "Dog.hpp"


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

        std::cout << "ptr is : " << c1.getBrain() << std::endl;
        std::cout << "The addr is: " << c2.getBrain() << std::endl;
    }
    std::cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
    std::cout << " -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;

        Dog d1;
        Dog d2 = d1;

        std::cout << "ptr is : " << d1.getBrain() << std::endl;
        std::cout << "the addr is : " << d2.getBrain() << std::endl;
}

void    additional_tests()
{
    Cat *cat_ptr = new Cat();
    Brain *brain_ptr = cat_ptr->getBrain();
    brain_ptr->setIdeas("let me thinking for that !!", 98);
    //*******************************
    Cat copy_cat(*cat_ptr);
    Brain *copy_cat_brain = copy_cat.getBrain();
    std::string *my_ideas = copy_cat_brain->getIdeas();
    for (int i = 0; i < 100; i++)
    {
        std::cout << my_ideas[i] << std::endl;
    }
    delete cat_ptr;
}

int main(void)
{
    subTest();
    // Half_dog_Half_cat();
    // DeepCopy();
    // additional_tests();

    // system("leaks brain");
    return (0);
}