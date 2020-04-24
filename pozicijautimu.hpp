#ifndef POZICIJAUTIMU_HPP_INCLUDED
#define POZICIJAUTIMU_HPP_INCLUDED

#include "datum.hpp"
#include "mesto.hpp"

class Osoba
{
protected:
    string ime;
    string prezime;
    Datum dat;
    Mesto mestasce;
public:
    Osoba (string im="Nenad", string pr="Lukic", int d1=1, int m1=1, int g1=1, string dr="neshto", string naz="opet neshto"): ime(im), prezime(pr), dat(d1, m1, g1), mestasce (dr, naz){};
    void ispisPozicijaUTimu ()
    {
        cout << "Ime: " << ime << "Prezime: " << prezime << endl;
        ispisDatuma(dat);
        cout << endl;
        ispisMesto(mestasce);
    }
};

#endif // POZICIJAUTIMU_HPP_INCLUDED
