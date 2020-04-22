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
    Datum datigr;
    Mesto mestoigr;
public:
    Igrac(string imq="Nenad", string prezq="Lukic", int d2=1, int m2=1, int g2=1, string dr="da", string naz="dada", int dre=31, int vis2=196, Positions poz=centar) : ime(imq), prezime(prezq), dres(dre), visina(vis2), pozicije(poz), datigr (d2, m2, g2), mestoigr(dr, naz) {};
    friend void ispisIgraca (const Igrac &i);
};

void ispisIgraca (const Igrac &i)
{
    cout << "Ime: " << i.ime << endl << "Prezime: " << i.prezime << endl << "Broj na dresu: " << i.dres << endl;
    cout << "Visina: " << i.visina;
    cout << "Datum rodjenja: ";
    ispisDatuma(i.datigr);
    cout << endl;
    cout << "Drzava i mesto rodjenja: ";
    ispisMesto(i.mestoigr);
}

///malo duza klasa za informacije o igracima
#endif // IGRAC_HPP_INCLUDED
