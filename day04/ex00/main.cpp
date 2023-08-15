#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"


void    subject_test()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

}

void    wrongTest()
{
    WrongAnimal *animal = new WrongAnimal();
    WrongAnimal *w_cat = new WrongCat();
    std::cout << "type " << w_cat->getType() << std::endl;
    animal->makeSound();
    std::cout << "|---------------------|" << std::endl;
    w_cat->makeSound();
}

int main(void)
{
    // subject_test();
    wrongTest();
    return (0);
}