#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED

#define BROJ_IGRACA 30

///ovde jos jedan primerak, racunamo proseke nekih stvari
///ovi proseci ce biti kao komentar dokle god ne nadjem nacin da ubacim igrace u konstruktor

#include "igrac.hpp"
#include "datum.hpp"
#include "mesto.hpp"
#include "arena.hpp"
#include "trener.hpp"
#include "timucinak.hpp"

///klasa koja objedinjuje igrace, trenera i daje ostale info o timu
///imamo metodu za ispis svega
///funkcija za ispis samo naziva tima
///funkcija za ispis koja se koristi u tabeli

class Tim: public TimUcinak
{
private:
    string nazivtima;
    Datum osnovano;
    Arena ar;
    Trener tren;

    ///ovo ostaje ovakvo dok se ne odrade vektori
    ///Igrac igraci[BROJ_IGRACA];
public:
    Tim (string nt, int d2, int m, int g, string na, string da, string naa, int bra, string a, string b,int a1, int b2, int c2, string d, string n): TimUcinak(0, 0, 0, 0,0, 0, 0), nazivtima(nt),osnovano(d2, m, g), ar(na, da, naa, bra),tren(a, b, a1, b2, c2, d, n) {};
    void ispisTima ()
    {
        cout << "Naziv tima: " << nazivtima << endl;
        cout << "Datum osnivanja: ";
        ispisDatuma (osnovano);
        cout << endl;
        cout << "Arena: ";
        ispisArena(ar);
        cout << "Pobede: " << pobede << " / Pobede nakon produzetaka: " << pobedeprod <<" / Porazi: " << porazi << " / Porazi nakon produzetaka: " << poraziprod <<endl;
        cout << "Bodovi u trenutnoj sezoni: " << bodovi << endl;
        cout << "Ukupno datih poena: " << poenidati << " / Ukupno primljenih poena: " << poeniprimljeni << endl;
        cout << "Trener: ";
        tren.ispisTrenera ();



        /*for (int i=0; i<BROJ_IGRACA; i++)
        {
            cout << "Igrac: " << endl;
            igraci[i].ispisIgraca();
            cout << endl;
        }*/
    }

    ///ovo su te kao neke metode
    /*void prosekstarosti ()
    {
        int godine=0;
        int i;
        for (i=0; i<BROJ_IGRACA; i++)
        {
            godine=2020-igraci[i].dat.godina;
        }
        int prosek1;
        prosek1=prosek1/i;
        cout << prosek1;
    }

    void prosekvisina ()
    {
        int vis=0;
        int j=0;
        for (j=0; j<BROJ_IGRACA; j++)
        {
            vis=igraci[i].visina;
        }
        vis=vis/j;
    }*/
/*
    void pisiTxt13(string nazivFajla, string tekst)
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
}*/


    friend void ispisNazivaTima (const Tim &ti);
    friend void ispisTabelaTim (const Tim &tt);
};

void ispisNazivaTima (const Tim &ti)
{
    cout << ti.nazivtima;
}

void ispisTabelaTim (const Tim &tt)
{
    cout << tt.nazivtima << "\t" << tt.pobede << "\t" << tt.pobedeprod << "\t" << tt.porazi << "\t" << tt.poraziprod << "\t" << tt.poenidati << ":" << tt.poeniprimljeni << "\t" << tt.bodovi;
}

#endif // TIM_HPP_INCLUDED
