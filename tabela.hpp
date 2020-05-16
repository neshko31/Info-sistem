#ifndef TABELA_HPP_INCLUDED
#define TABELA_HPP_INCLUDED
#define BROJ_TIMOVA 16

#include "tim.hpp"

///od ove klase pocinje zurka
///veoma haoticno
///mozda bude neki sort ne znam ko ima najvise koseva ili tako
///ovde je potreban sort da bismo sortirali ko je prosao dalje u playoff

///isto kao i ova kola mogu samo da kazem da valja
class Tabela
{
private:
    int godinapocetka;
    int godinapocetkaplayoff;
    Tim timovi[BROJ_TIMOVA];
public:
    friend ostream& operator<<(ostream& izlaz, const Tabela& ta)
    {
        izlaz << "Pocetak ovog dela sezone/Kraj ovog dela sezone: " << ta.godinapocetka << "/" << ta.godinapocetkaplayoff << endl;
        ///ovaj deo samo postoji kao neka ideja
        /*for (int i=0; i<BROJ_TIMOVA; i++)
        {
        ispisTabelaTim(ta[i].timovi);
        }*/
        return izlaz;
    }
};

#endif // TABELA_HPP_INCLUDED
