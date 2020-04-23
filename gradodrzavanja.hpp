#ifndef GRADODRZAVANJA_HPP_INCLUDED
#define GRADODRZAVANJA_HPP_INCLUDED

#include "mesto.hpp"
#include "arena.hpp"

class GradOdrzavanja
{
private:
    Mesto mestina;
    Arena are;
public:
    ///ovde fakticki nista specijalno
    ///samo da se spomene gde se ovo odrzava
    friend void ispisGradOdrzavanja (const GradOdrzavanja &gr);
};

void ispisGradOdrzavanja (const GradOdrzavanja &gr)
{
    cout << "Igraci koji igraju na ovozenoskom Final Four-u su smesteni u mestu: " ;
    ispisMesto(gr.mestina);
    cout << "Naziv arene gde se igraju utakmice: ";
    ispisArena(gr.are);
}
#endif // GRADODRZAVANJA_HPP_INCLUDED
