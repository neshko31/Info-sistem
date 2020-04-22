#ifndef TABELA_HPP_INCLUDED
#define TABELA_HPP_INCLUDED
#define BROJ_TIMOVA 16

#include "tim.hpp"

///od ove klase pocinje zurka
///veoma haoticno
///mozda bude neki sort ne znam ko ima najvise koseva ili tako

class Tabela
{
private:
    int godinapocetka;
    int godinapocetkaplayoff;
    Tim timovi[BROJ_TIMOVA];
public:
    friend  void ispisTabela (const Tabela &tab);
};
void ispisTabela (const Tabela &tab)
{
    int i;
    cout << "Godina pocetka regularnog dela: " << tab.godinapocetka << endl;
    cout << "Godina zavrsetka regularnog dela: " << tab.godinapocetkaplayoff << endl;
    cout << "Tabela ovogodisnjeg takmicenja: " << endl;
    cout << "Naziv tima    Pobede    Pobede nakon prod.    Porazi    Porazi nakon prod.    Poeni dati:Poeni primljeni    Bodovi";
    for (i=1; i<=16; i++)
    {
        cout << i << ". ";
        ispisTabelaTim (tab.timovi[i]);
    }
}
#endif // TABELA_HPP_INCLUDED
