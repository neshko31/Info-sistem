#ifndef IGRAC_HPP_INCLUDED
#define IGRAC_HPP_INCLUDED

using namespace std;

enum Positions {plejmejker, bek, krilo, krilni_centar, centar};

#include "mesto.hpp"
#include "datum.hpp"
#include "pozicijautimu.hpp"

class Igrac : public Osoba
{
private:
    int dres;
    int visina;
    Positions pozicije;
public:
    ///ovi postoje ako zatrebaju
    ///Igrac(string imq="Nenad", string prezq="Lukic", int d2=1, int m2=1, int g2=1, string dr="da", string naz="dada", int dre=31, int vis2=196, Positions poz=centar) : ime(imq), prezime(prezq), dres(dre), visina(vis2), pozicije(poz), datigr (d2, m2, g2), mestoigr(dr, naz) {};
    ///Igrac ():Osoba("ime", "prezime", 1, 1, 1, "neshto", "opet neshto"), dres()

    Igrac (string i, string p, int a, int b, int c, string d, string n, int dr, int vis, Positions poz): Osoba(i, p, a, b, c, d, n), dres(dr), visina(vis), pozicije(poz) {};

    void ispisIgraca ()
    {
        Osoba::ispisPozicijaUTimu();
        cout << "Broj na dresu: " << dres << endl;
        cout << "Visina u cm: " << visina << endl;
        cout << "Pozicije ovog igrac: " << pozicije << endl;
    }
};
/*friend void ispisIgraca (const Igrac &i);
void ispisIgraca (const Igrac &i)
{
    cout << "Ime: " << i.ime << endl << "Prezime: " << i.prezime << endl << "Broj na dresu: " << i.dres << endl;
    cout << "Visina: " << i.visina;
    cout << "Datum rodjenja: ";
    ispisDatuma(i.datigr);
    cout << endl;
    cout << "Drzava i mesto rodjenja: ";
    ispisMesto(i.mestoigr);
}*/

///malo duza klasa za informacije o igracima
#endif // IGRAC_HPP_INCLUDED
