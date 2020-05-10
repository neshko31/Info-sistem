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
    ///korisnik dobija opciju ispisa samo kola ili kola+tabela
    ///ovde je ispis ovih svih kola kao i ispis same tabele

    ///ni ovo se ne moze testirati jeri nema konstruktora
    friend ostream& operator<<(ostream& izlaz, const RegularniDeo& rd)
    {
        izlaz << "Trajanje u mesecima: "<< rd.trajanje << endl;
        izlaz << "Broj timova ucesnika: "<< rd.brojtimova << endl;
        cout << rd.tabelarno;
        for (int i=0; i<BROJ_KOLA; i++)
        {
            cout << rd.kola[i];
        }
        return izlaz;
    }

    friend void ispisRegularniDeoKT (const RegularniDeo &reg);
    friend void ispisRegularniDeoK (const RegularniDeo &reg);
};

void ispisRegularniDeoKT (const RegularniDeo &reg)
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

void ispisRegularniDeoK (const RegularniDeo &reg)
{
    int i;
    cout << "REGULARNI DEO" << endl;
    cout << endl;
    cout << "Regularni deo traje " << reg.trajanje << endl;
    cout << "Broj timova koji su ucestvovali u toj sezoni iznosi " << reg.brojtimova << endl;
    for (i=0; i<BROJ_KOLA; i++)
    {
        ispisKola (reg.kola[i]);
    }
}

void citajregdeokola(string regdeo)
{
    string linija;
    ifstream fajl (regdeo);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            if (linija == "Kola")
            {
                break;
            }
        }
        cout << "Kola" << endl;
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}

void citajregdeokolatabela(string regdeo)
{
    string linija;
    ifstream fajl (regdeo);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}
#endif // REGULARNIDEO_HPP_INCLUDED
