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
    ///ovo cu doraditi kasnije
    ///Trener (int d2q=1, int m2q=1, int g2q=1, string imq="Nenad", string prezq="Lukic", string drq="da", string naq="dada") : TrenerDatum (d2q, m2q, g2q), ime(imq), prezime(prezq), mestasce(drq, naq) {};

    ///Trener (string i, string p, int d, int m, int g, string dr, string naz): ime(i), prezime(p), dat(d, m, g), mestasce(dr, naz) {};

    Trener (string im="Nenad", string pr="Lukic", int a=1, int b=1, int c=1, string d="", string n=""): ime(im), prezime(pr), dat(a, b, c), mestasce(d, n){};


    void ispisTrenera ()
    {
        cout << "Ime: " << ime << "Prezime: " << prezime << endl;
        cout << "Datum rodjenja: ";
        ispisDatuma(dat);
        cout << endl;
        cout << "Mesto rodjenja: ";
        ispisMesto(mestasce);
        cout << endl;
    }

};

///osnovne info o treneru

#endif // TRENER_HPP_INCLUDED
