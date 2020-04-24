#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED

#define BROJ_IGRACA 30

#include "igrac.hpp"
#include "datum.hpp"
#include "mesto.hpp"
#include "arena.hpp"
#include "trener.hpp"

///klasa koja objedinjuje igrace, trenera i daje ostale info o timu
///imamo metodu za ispis svega
///funkcija za ispis samo naziva tima
///funkcija za ispis koja se koristi u tabeli

class Tim
{
private:
    string nazivtima;
    Datum osnovano;
    Mesto mestasce;
    string trofeji;
    Arena ar;
    Trener tren;
    Igrac igraci[BROJ_IGRACA];
public:

    void ispisTima ()
    {
        cout << "Naziv tima: " << nazivtima << endl;
        cout << "Datum osnivanja: ";
        ispisDatuma (osnovano);
        cout << endl;
        cout << "Trofeji u ovom takmicenju: " << trofeji << endl;
        cout << "Arena: ";
        ispisArena(ar);
        cout << "Pobede: " << pobede << " / Pobede nakon produzetaka: " << pobedeprod <<" / Porazi: " << porazi << " / Porazi nakon produzetaka: " << poraziprod <<endl;
        cout << "Bodovi u trenutnoj sezoni: " << bodovi << endl;
        cout << "Ukupno datih poena: " << poenidati << " / Ukupno primljenih poena: " << poeniprimljeni << endl;
        cout << "Trener: ";
        tren.ispisTrenera ();
        for (int i=0; i<BROJ_IGRACA; i++)
        {
            cout << "Igrac: " << endl;
            ispisIgraca(igraci[i]);
            cout << endl;
        }
    }
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
