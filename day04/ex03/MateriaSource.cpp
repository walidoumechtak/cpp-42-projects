#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

/* ========== Start canonicl form ========== */
MateriaSource::MateriaSource() : temp(NULL), cpt(0)
{
    for (int i = 0; i < 4; i++)
    {
        this->m_arr[i] = NULL;
    }
    std::cout << "[MateriaSource] constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& source)
{
    std::cout << "[MateriaSource] copy constructor called" << std::endl;
    *this = source;
}

MateriaSource &MateriaSource::operator= (const MateriaSource& source)
{
    std::cout << "[MateriaSource] copy constructor called" << std::endl;
    if (this != &source)
    {
        this->cpt = source.cpt;
        if (this->temp != NULL)
        {
            if (source.temp->getType() == "ice")
                this->temp = new Ice();
            else
                this->temp = new Cure();
        }
        else
            this->temp = NULL;
        for (int i = 0; i < 4; i++)
        {
            if (this->m_arr[i] != NULL)
            {
                if (this->m_arr[i]->getType() == "ice")
                    this->m_arr[i] = new Ice();
                else
                    this->m_arr[i] = new Cure();
            }
            else
                this->m_arr[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    if (this->temp != NULL)
    {
        delete this->temp;
        this->temp = NULL;
    }
    for (int i = 0; i < 4; i++)
    {
        if (this->m_arr[i] != NULL)
        {
            delete this->m_arr[i];
            this->m_arr[i] = NULL;
        }
    }
    std::cout << "[MateriaSource] destructor called" << std::endl;
}
/* ========== End canonicl form ========== */

void    MateriaSource::learnMateria(AMateria *ptr)
{
    if (cpt < 4)
    {
        this->m_arr[cpt] = ptr;
        cpt++;
    }
    else
    {
        if (temp != NULL)
        {
            delete this->temp;
            this->temp = ptr;
        }
        else
            this->temp = ptr;
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    AMateria *new_mat;
    if (type == "ice")
    {
        new_mat = new Ice();
    }
    else if (type == "cure")
    {
        new_mat = new Cure();
    }
    else
        return (0);
    return (new_mat);
}
