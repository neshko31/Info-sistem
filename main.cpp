#include <iostream>
#include <fstream>

using namespace std;

#include "datum.hpp"
#include "mesto.hpp"
#include "arena.hpp"
#include "igrac.hpp"
#include "tim.hpp"
#include "trener.hpp"
#include "tabela.hpp"
#include "kolo.hpp"
#include "utakmica.hpp"
#include "gradodrzavanja.hpp"
#include "regularnideo.hpp"
#include "toposam.hpp"
#include "finalfour.hpp"
#include "sezona.hpp"

void pisiTxt(string nazivFajla, string tekst)
{
    /// fajl je sada objekat klase ofstream
    ofstream fajl;

    /// koristimo metodu open za otvaranja fajla
    /// kao parametar prosledjujemo naziv fajla i njegovu ekstenziju
    fajl.open (nazivFajla);

    /// pisanje vrsimo tako sto umesto cout pisemo naziv fajla
    /// koristimo operator <<
    fajl << tekst << endl;

    /// na kraju zatvaramo fajl
    fajl.close();
}

void citajTxt(string nazivFajla)
{
    string linija;
    ifstream fajl (nazivFajla);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            ///Ovo je kao neki nacin da ogranicimo dokle on treba da pise
            /*
           if (linija == "Arena")
           {
               break;
           }*/
           cout << linija << '\n';
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}
int main()
{
    ///string nasFajl = "real madrid 18.19.txt";

    ///system("dir");
   /* cout<<"Unesite tekst koji hocete da upisete u fajl:"<<endl;
    char ulaz[100];
    cin.getline(ulaz,sizeof(ulaz));

    pisiTxt(nasFajl, ulaz);

    cout<<"U fajlu pise: ";*/
///    citajTxt(nasFajl);

    return 0;
}
