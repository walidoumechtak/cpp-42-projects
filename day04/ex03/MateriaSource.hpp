#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *m_arr[4];
        AMateria *temp;
        int cpt;
    public:
        MateriaSource();
        MateriaSource(const MateriaSource& source);
        MateriaSource &operator= (const MateriaSource& source);
        ~MateriaSource();
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};


#endif