#ifndef REGULARNIDEO_HPP_INCLUDED
#define REGULARNIDEO_HPP_INCLUDED
#define BROJ_KOLA 30

#include "tabela.hpp"
#include "kolo.hpp"

class RegularniDeo
{
private:
    int trajanje;
    int brojtimova;
    Tabela tabelarno;
    Kolo kola[BROJ_KOLA];
public:
    ///ovde je ispis ovih svih kola kao i ispis same tabele
    friend void ispisRegularniDeo (const RegularniDeo &reg);
};

void ispisRegularniDeo (const RegularniDeo &reg)
{
    int i;
    cout << "REGULARNI DEO" << endl;
    cout << endl;
    cout << "Regularni deo traje " << reg.trajanje << endl;
    cout << "Broj timova koji su ucestvovali u toj sezoni iznosi " << reg.brojtimova << endl;
    ispisTabela (reg.tabelarno);
    for (i=0; i<BROJ_KOLA; i++)
    {
        ispisKola (reg.kola[i]);
    }
}
#endif // REGULARNIDEO_HPP_INCLUDED
