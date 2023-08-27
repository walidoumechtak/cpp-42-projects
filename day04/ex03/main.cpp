#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void    basic_test()
{
    // ICharacter *t = new Character();
    Character *c = new Character("Charcter-walid");
    AMateria *m1 = new Ice();
    AMateria *m2 = new Cure();
    AMateria *m3 = new Ice();
    AMateria *m4 = new Cure();

    AMateria *m5 = new Cure();


    c->equip(m1);
    c->equip(m2);
    c->equip(m3);
    c->equip(m4);
    // the m5 materia will not quiped because the inventory if full
    c->equip(m5);

    c->use(0, *c);
    c->use(1, *c);
    c->use(2, *c);
    c->use(3, *c);
    c->use(4, *c);
    c->use(5, *c);

    delete c;
}

void    sub_test()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;
}

void test1()
{

    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter *ch1 = new Character("ch_1");

    /* ********************* */
    ch1->equip(new Ice());
    ch1->equip(new Cure());
    /* ********************* */

    AMateria * mat = new Ice();
    AMateria *cloned_mat = mat->clone();
    
    /* ********************* */
    ch1->equip(mat);
    ch1->equip(cloned_mat);
    /* ********************* */

    AMateria *ms = src->createMateria("cure");
    
    /* ********************* */
    ch1->unequip(0);
    ch1->equip(ms);
    /* ********************* */

    std::cout << "------------------------------------------" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        ch1->use(i, *ch1);
    }
    std::cout << "------------------------------------------" << std::endl;
    
    delete src;
    delete ch1;
}

int main()
{
    // basic_test();
    // sub_test();
    test1();
}