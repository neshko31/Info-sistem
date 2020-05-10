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
    friend  void ispisTabela (const Tabela &tab);
    friend void ispisTabelaTopOsam (const Tabela &tabto);
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

void ispisTabelaTopOsam (const Tabela &tabto)
    {
        int i;
        cout << "Klubovi koji su prosli u narednu fazu" << endl;
        cout << "Naziv tima    Pobede    Pobede nakon prod.    Porazi nakon prod.    Porazi    Poeni dati:Poeni primljeni    Bodovi";
        for (i=1; i<=8; i++)
        {
            cout << i << ". ";
            ispisTabelaTim (tabto.timovi[i]);
        }
    }

void citajregdeotabela(string regdeo)
{
    string linija;
    ifstream fajl (regdeo);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            ///Ovo je kao neki nacin da ogranicimo dokle on treba da pise
            if (linija == "Kola")
            {
                break;
            }
            cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}
#endif // TABELA_HPP_INCLUDED
