#ifndef TOPOSAM_HPP_INCLUDED
#define TOPOSAM_HPP_INCLUDED

#include "tabela.hpp"
#include "utakmica.hpp"

class TopOsam
{
private:
    Tabela tabelica;
    Utakmica tekme[20];
public:
    ///ovde ce bato da bude da uzima prvih osam
    ///spaja timove
    ///treba da racuna koliko ko ima pobeda
    ///pobede dobijamo iz onog brojaca, funkcije, koja ce biti u utakmica.hpp, oke ipak bez ovoga sto covek da se muci
    ///nakon toga 4 pobednika
    friend void ispisTopOsam (const TopOsam &topo);
};

void ispisTopOsam (const TopOsam &topo)
{
    int i;
    cout << "TOP OSAM" << endl;
    cout << endl;
    ispisTabelaTopOsam(topo.tabelica);
    for (i=0; i<20; i++)
    {
        ispisUtakmica(topo.tekme[i]);
    }

}
#endif // TOPOSAM_HPP_INCLUDED
