#ifndef IGRAC_HPP_INCLUDED
#define IGRAC_HPP_INCLUDED

using namespace std;

enum Positions {plejmejker, bek, krilo, krilni_centar, centar};
#include "mesto.hpp"
#include "datum.hpp"

class Igrac
{
private:
    string ime;
    string prezime;
    int dres;
    int visina;
    Positions pozicije;
    Datum dat;
    Mesto mestasc;
public:
    Igrac (string im="Nenad", string prez="Lukic", int dr2=31, int d2=1, int m2=1, int g2=1, string dr="da", string na="dada") : ime(im), prezime(prez), dres(dr2), dat (d2, m2, g2), mestasc(dr, na) {};
    friend void ispisIgraca (const Igrac &i);
};

void ispisIgraca (const Igrac &i)
{
    cout << "Ime: " << i.ime << endl << "Prezime: " << i.prezime << endl << "Broj na dresu: " << i.dres << endl;
    cout << "Visina: " << i.visina;
    cout << "Datum rodjenja: ";
    ispisDatuma(i.dat);
    cout << "Drzava i mesto rodjenja: ";
    ispisMesto(i.mestasc);
}

#endif // IGRAC_HPP_INCLUDED
