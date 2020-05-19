#ifndef POZICIJAUTIMU_HPP_INCLUDED
#define POZICIJAUTIMU_HPP_INCLUDED

#include "datum.hpp"
#include "mesto.hpp"

///ne pise da metoda treba da bude komplikovana, niti kakva je neophodna da bude, vec samo da bude nasledjena i redefinisana
///i da se virtualnost prikaze u mainu, to mozda i nemam

class Osoba
{
protected:
    string ime;
    string prezime;
    Datum dat;
    Mesto mestasce;
public:
    Osoba (string im, string pr, int d1, int m1, int g1, string dr, string naz): ime(im), prezime(pr), dat(d1, m1, g1), mestasce (dr, naz) {};
    friend ostream& operator<<(ostream& izlaz, const Osoba& o)
    {
        izlaz<<"Ime: "<<o.ime<<endl;
        izlaz<<"Prezime: "<<o.prezime<<endl;
        izlaz << o.dat;
        izlaz << o.mestasce;
        return izlaz;
    }
    virtual void predstavise ()
    {
        cout << "Ime: " << ime << endl;
        cout << "Prezime: " << prezime << endl;
        dat.ispisidatum();
        mestasce.ispisimesto();
    }
};

#endif // POZICIJAUTIMU_HPP_INCLUDED
