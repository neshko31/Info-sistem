#ifndef TRENER_HPP_INCLUDED
#define TRENER_HPP_INCLUDED

#include "datum.hpp"
#include "mesto.hpp"

class Trener
{
private:
    string ime;
    string prezime;
    Datum dat;
    Mesto mestasce;
public:
    Trener (string imq="Nenad", string prezq="Lukic", int d2q=1, int m2q=1, int g2q=1, string drq="da", string naq="dada") : ime(imq), prezime(prezq), dat (d2q, m2q, g2q), mestasce(drq, naq) {};
    friend void ispisTrenera (const Trener &t);
};

void ispisTrenera (const Trener &t)
{
    cout << "Ime: " << t.ime << endl << "Prezime: " << t.prezime << endl;
    cout << "Datum rodjenja: ";
    ispisDatuma(t.dat);
    cout << "Drzava i mesto rodjenja: ";
    ispisMesto(t.mestasce);
}

#endif // TRENER_HPP_INCLUDED
