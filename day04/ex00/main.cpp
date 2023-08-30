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
    j->makeSound(); //will output the dog sound!
    meta->makeSound();// The animal sound.
    delete meta;
    delete j;
    delete i;
}

void    wrongTest()
{
    WrongAnimal *animal = new WrongAnimal();
    WrongAnimal *w_cat = new WrongCat();
    std::cout << "type " << w_cat->getType() << std::endl;
    animal->makeSound();
    std::cout << "|---------------------|" << std::endl;
    w_cat->makeSound(); // this should display the cat sound but not .......!
    delete animal;
    delete w_cat;
}

int main(void)
{
    subject_test();
    // wrongTest();
    return (0);
}