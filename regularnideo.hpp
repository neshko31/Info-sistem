#ifndef REGULARNIDEO_HPP_INCLUDED
#define REGULARNIDEO_HPP_INCLUDED
#define BROJ_KOLA 30

#include "tabela.hpp"
#include "kolo.hpp"

class RegularniDeo
{
private:
    ///int trajanje;
    int brojtimova;
   /// Tabela tabelarno;
    vector <Kolo*> kolaa;
public:
    ///korisnik dobija opciju ispisa samo kola ili kola+tabela
    ///ovde je ispis ovih svih kola kao i ispis same tabele

    ///ni ovo se ne moze testirati jeri nema konstruktora
    friend ostream& operator<<(ostream& izlaz, const RegularniDeo& rd)
    {
///        izlaz << "Trajanje u mesecima: "<< rd.trajanje << endl;
        izlaz << "Broj timova ucesnika: "<< rd.brojtimova << endl;
  ///      izlaz << rd.tabelarno;
        /*for (int i=0; i<BROJ_KOLA; i++)
        {
            izlaz << rd.kola[i];
        }*/
        return izlaz;
    }
    void dodajkolo(Kolo* kol)
    {
        kolaa.push_back(kol);
    }
};

#endif // REGULARNIDEO_HPP_INCLUDED
