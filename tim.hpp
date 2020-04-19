#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED

#define BROJ_IGRACA 30

#include "igrac.hpp"
#include "datum.hpp"
#include "mesto.hpp"
#include "arena.hpp"
#include "trener.hpp"

class Tim
{
private:
    string nazivtima;
    string sponzor;
    Datum osnovano;
    Mesto mestasce;
    string trofeji;
    Arena ar;
    int pobede;
    int pobedeprod;
    int porazi;
    int poraziprod;
    int bodovi;
    int poenidati;
    int poeniprimljeni;
    Trener tren;
    Igrac igraci[BROJ_IGRACA];
public:
    friend void ispisTima (const Tim &timm);
};

void ispisTima (const Tim &timm)
{
    cout << "Naziv tima: " << timm.nazivtima << endl;
    cout << "Sponzori tima: " << timm.sponzor << endl;
    cout << "Datum osnivanja: ";
    ispisDatuma (timm.osnovano);
    cout << "Trofeji: " << timm.trofeji << endl;
    cout << "Arena: ";
    ispisArena(timm.ar);
    cout << "Pobede: " << timm.pobede << " / Pobede nakon produzetaka: " << timm.pobedeprod <<" / Porazi: " << timm.porazi << " / Porazi nakon produzetaka: " << timm.poraziprod <<endl;
    cout << "Bodovi u trenutnoj sezoni: " << timm.bodovi << endl;
    cout << "Ukupno datih poena: " << timm.poenidati << " / Ukupno primljenih poena: " << timm.poeniprimljeni << endl;
    cout << "Trener: ";
    ispisTrenera(timm.tren);
    for (int i=0; i<BROJ_IGRACA; i++)
    {
        cout << "Igrac: " << endl;
        ispisIgraca(timm.igraci[i]);
        cout << endl;
    }
}

#endif // TIM_HPP_INCLUDED
