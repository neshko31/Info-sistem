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
};

#endif // REGULARNIDEO_HPP_INCLUDED
