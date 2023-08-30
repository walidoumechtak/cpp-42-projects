#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/* ========== Start canonical form ========== */
Character::Character() : name("Def_Character"), temp(NULL), cpt(0)
{
    for (int i = 0; i < 4; i++)
        this->arr[i] = NULL;
    std::cout << "[Character] Default Constructor caled" << std::endl;
}

Character::Character(std::string in_name) : name(in_name), temp(NULL), cpt(0)
{
    for (int i = 0; i < 4; i++)
        this->arr[i] = NULL;
    std::cout << "[Character] constructor called with name: " << name << std::endl;   
}

Character::Character(const Character& source)
{
    std::cout << "[Character] copy construcotr called" << std::endl;
    this->temp = NULL;
    for (int i = 0; i < 4; i++)
        this->arr[i] = NULL;
    *this = source;
}

Character &Character::operator= (const Character& source)
{
    std::cout << "[Character] copy assignement operator called" << std::endl;
    if (this != &source)
    {
        this->cpt = source.cpt;
        this->name = source.name;
        if (this->temp)
            delete this->temp;
        //***********************
        if (source.temp && source.temp->getType() == "ice")
            this->temp = new Ice();
        else if (source.temp && source.temp->getType() == "cure")
            this->temp = new Cure();
        else
            this->temp = NULL;
        for (int i = 0; i < 4; i++)
        {
            if (this->arr[i])
                delete this->arr[i];
            if (source.arr[i] && source.arr[i]->getType() == "ice")
                this->arr[i] = new Ice();
            else if (source.arr[i] && source.arr[i]->getType() == "cure")
                this->arr[i] = new Cure();
            else
                this->arr[i] = NULL;
        }
    }
    return (*this);
}

Character::~Character()
{
    std::cout << "[Character] Destructor called" << std::endl;
    if (this->temp != NULL)
    {
        delete this->temp;
        this->temp = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->arr[i] != NULL)
        {
            delete this->arr[i];
            this->arr[i] = NULL;
        }
    }
}
/* ========== End canonical form ========== */

std::string const & Character::getName() const
{
    return (this->name);
}

void    Character::equip(AMateria* m)
{
    if (cpt < 4)
    {
        this->arr[cpt] = m;
        cpt++;
    }
    else
    {
        if (this->temp == NULL)
            this->temp = m;
        else
        {
            delete this->temp;
            this->temp = m;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx > 3)
        return;
    if (this->temp != NULL)
        delete this->temp;
    this->temp = this->arr[idx];
    int i = idx;
    for (; i < 4; i++)
    {
        if (this->arr[i] != NULL && i + 1 < 4)
            this->arr[i] = this->arr[i + 1];
        else
            break;
    }
    if (i + 1 >= 4)
        this->arr[i] = NULL;
    else
        this->arr[i - 1] = NULL;
    cpt--;
}

void     Character::use(int idx, ICharacter& target)
{
    if (idx > 3)
        return;
    this->arr[idx]->use(target);
}