#ifndef TOPOSAM_HPP_INCLUDED
#define TOPOSAM_HPP_INCLUDED

#include "tabela.hpp"
#include "utakmica.hpp"
#define MAX 20

class TopOsam
{
private:
    Tabela tabelica;
    Utakmica tekme[MAX];
public:
    ///ovde ce bato da bude da uzima prvih osam
    ///spaja timove
    ///treba da racuna koliko ko ima pobeda
    ///pobede dobijamo iz onog brojaca, funkcije, koja ce biti u utakmica.hpp, oke ipak bez ovoga sto covek da se muci
    ///nakon toga 4 pobednika

    ///radi ako je verovati mom instinktu
    friend ostream& operator<<(ostream& izlaz, const TopOsam& to)
    {
///        ispisTabelaTopOsam(to.tabelica);
        for (int i=0; i<MAX; i++)
        {
            izlaz << to.tekme[i];
        }
        return izlaz;
    }
};


#endif // TOPOSAM_HPP_INCLUDED
