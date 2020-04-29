#include <iostream>
#include <fstream>

///ideju za funkcionalnost cu da objasnim da li imam ovim high quality memom
///Well yes, but actually no.
///ideje koje imam za sad:
///plate igraca, prosecna starost, prosecna visina po timovima, sortovi po visini u timovima
///najbolji igrac u svakom timu i nakon toga najbolji igrac tog dela sezone, za regularni deo i final four
///tabela na svakih nekoliko kola, u ovom slucaju 5 kola
///tabela koja pokazuje kako se koji tim pokazao kao domacin, a kako kao gost
///valjda ce biti jos koja
///i evo jos jedna
///za info o igracu, ako korisnik unes ime i prezime igraca kao i tim da mu program nadje tog igraca i ispise ostale stvari o njemu

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


///ovako nesto se moze koristi za upis u odredjene fajlove, u ovom slucaju timske fajlove
/*Tim t1 ("a", 1, 1, 1, "a", "a", "aa", 1, "a", "a", 1, 1, 1, "a", "a");
t1.pisiTxt13("khimki 18.19.txt", "lalalala");*/
    return 0;
}
