#ifndef TRENER_HPP_INCLUDED
#define TRENER_HPP_INCLUDED

#include "datum.hpp"
#include "mesto.hpp"
#include "pozicijautimu.hpp"

class Trener
{
private:
    string ime;
    string prezime;
    Datum dat;
    Mesto mestasce;
public:
    Trener (string im="Nenad", string pr="Lukic", int a=1, int b=1, int c=1, string d="lele", string n="lala"): ime(im), prezime(pr), dat(a, b, c), mestasce(d, n) {};
    friend ostream& operator<<(ostream& izlaz, const Trener& t)
    {
        izlaz<<"Trener: "<<endl;
        izlaz<<"Ime: "<<t.ime<<endl;
        izlaz<<"Prezime: "<<t.prezime<<endl;
        izlaz << t.dat;
        izlaz << t.mestasce;
        return izlaz;
    }
};

///osnovne info o treneru

#endif // TRENER_HPP_INCLUDED
