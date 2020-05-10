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
#include <fstream>
#include <sstream>

///klasa koja objedinjuje igrace, trenera i daje ostale info o timu
///imamo metodu za ispis svega
///funkcija za ispis samo naziva tima
///funkcija za ispis koja se koristi u tabeli

class Tim: public TimUcinak
{
    ///ovde sam stavio public jer nemam blage kako da ispis utakmice pristupi ako je protected
public:
    string nazivtima;
    Datum osnovano;
    Arena ar;
    Trener tren;
    ///ovo ostaje ovakvo dok se ne odrade vektori
    ///Igrac igraci[BROJ_IGRACA];
    static int budzet;
public:
    Tim ():TimUcinak(0, 0, 0, 0, 0, 0, 0), nazivtima("mani mani"), osnovano (1, 1, 1), ar("as", "serbija", "ns", 13200), tren("nenad", "lukic", 1, 1, 1, "lele", "lala")
    {
        budzet+=1000;
    };

    friend ostream& operator<<(ostream& izlaz, const Tim& t)
    {
        izlaz<<"Tim: "<<t.nazivtima<<endl;
        cout << t.osnovano;
        cout << t.ar;
        cout << t.tren;

        ///ovako bih ja za igrace valjda tako ide
        /*for (int i=0; i<BROJ_IGRACA; i++)
        {
            cout << t[i].igraci;
        }*/
        return izlaz;
    }
    static int getStatickiBudzet()
    {
        return budzet;
    }
    static int setBudzet (int a)
    {
        budzet=a;
        return budzet;
    }

    ///metode za povecavanje i smanjivanje rade na neki nacin, ali zapravo ne rade
    ///s obzirom na to da on ne zna koja je vrednost u txt fajlu
    ///oke ipak rade

    static void povecajBudzet (int a, string budzetfajl)
    {
        budzet=dajbudzet(budzetfajl);
        budzet=budzet+a;

        ofstream fajl;
        fajl.open (budzetfajl);
        fajl << budzet << endl;
        fajl.close();
    }
    static void smanjiBudzet (int a, string budzetfajl)
    {
        budzet=dajbudzet(budzetfajl);
        budzet=budzet-a;

        ofstream fajl;
        fajl.open (budzetfajl);
        fajl << budzet << endl;
        fajl.close();
    }
    static int dajbudzet (string naziv)
    {
        int b;
        string linija;
        ifstream fajl (naziv);
        if (fajl.is_open())
        {
            getline (fajl,linija);

            stringstream ss;
            ss << linija;
            ss >> b;
            fajl.close();
            return b;
        }
        else
        {
            cout << "Neuspesno otvoren fajl";
            return 0;
        }
    }
    static void citajBudzetFajl (string nazivFajla)
    {
        string linija;
        ifstream fajl (nazivFajla);
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) )
            {
                cout << linija << '\n';
            }
            fajl.close();
        }
        else
        {
            cout << "Neuspesno otvoren fajl";
        }

    }
    ///ovo su te kao neke metode
    /*void najboljiigracutimu ()
    {
        int i;
        int najbolji;
        najbolji=igraci[0].indexkor;
        for (i=0; i<BROJ_IGRACA; i++)
        {
            if (najbolji<igraci[i].indexkor)
            {
                najbolji=igraci[i].indexkor;
            }
        }
        ///ispis te linije iz fajla
    }*/
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
    friend void ispisNazivaTima (const Tim &ti);
    friend void ispisTabelaTim (const Tim &tt);
};

int Tim::budzet=0;
void ispisNazivaTima (const Tim &ti)
{
    cout << ti.nazivtima;
}
void ispisTabelaTim (const Tim &tt)
{
    cout << tt.nazivtima << "\t" << tt.pobede << "\t" << tt.pobedeprod << "\t" << tt.poraziprod << "\t" <<  tt.porazi << "\t" << tt.poenidati << ":" << tt.poeniprimljeni << "\t" ;
}
void citajtimfajl(string tim)
{
    string linija;
    ifstream fajl (tim);
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
void citajtimoveucesnike(string timo)
{
    int i=1;
    string linija;
    ifstream fajl (timo);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << "Opcija " << i << ": ";
            cout << linija << '\n';
            i++;
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}

/*void ispisTima ()
{
    cout << "Naziv tima: " << nazivtima << endl;
    cout << "Datum osnivanja: ";
///        ispisDatuma (osnovano);
    cout << endl;
    cout << "Arena: ";
///        ispisArena(ar);
    cout << "Pobede: " << pobede << " / Pobede nakon produzetaka: " << pobedeprod <<" / Porazi: " << porazi << " / Porazi nakon produzetaka: " << poraziprod <<endl;
    cout << "Bodovi u trenutnoj sezoni: " << bodovi << endl;
    cout << "Ukupno datih poena: " << poenidati << " / Ukupno primljenih poena: " << poeniprimljeni << endl;
    cout << "Trener: ";
///        tren.ispisTrenera ();
for (int i=0; i<BROJ_IGRACA; i++)
    {
        cout << "Igrac: " << endl;
        igraci[i].ispisIgraca();
        cout << endl;
    }*/



///Tim (string nt, int d2, int m, int g, string na, string da, string naa, int bra, string a, string b,int a1, int b2, int c2, string d, string n): TimUcinak(0, 0, 0, 0,0, 0, 0), nazivtima(nt),osnovano(d2, m, g), ar(na, da, naa, bra),tren(a, b, a1, b2, c2, d, n) {};

#endif // TIM_HPP_INCLUDED
