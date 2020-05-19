#ifndef IGRAC_HPP_INCLUDED
#define IGRAC_HPP_INCLUDED

///ovde imam drugi primerak metode kao sto vidimo, menja stanje polja dva puta, prvi put da nam nesto izracuna, a drugi put da vrati na staro

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
    string pozicije;
    int zarada;
    double indexkor;
public:
    Igrac ():Osoba("ime", "prezime", 1, 1, 1, "neshto", "opet neshto"), dres(31), visina (200), pozicije("plejmejker"), zarada (2000), indexkor(12.2) {};
    Igrac (string i, string p, int d, int m, int g, string drz, string n, int dr, int vs, string poz, int zar, double ind): Osoba (i, p, d, m, g, drz, n), dres(dr), visina(vs), pozicije(poz), zarada(zar), indexkor(ind) {};
    string getIme ()
    {
        return ime;
    }
    string getPrezime ()
    {
        return prezime;
    }
    double getIndex ()
    {
        return indexkor;
    }
    void zaradaigr ()
    {
        cout << "Bruto zarada u evrima: " << zarada << endl;

        int pocetna;
        pocetna=zarada;

        zarada=zarada-(20*zarada/100);

        cout << "Neto zarada: " << zarada << endl;
        zarada=pocetna;
    }

    friend ostream& operator<<(ostream& izlaz, const Igrac& i)
    {
        izlaz<<"Igrac: "<<endl;
        izlaz<<"Ime: "<<i.ime<<endl;
        izlaz<<"Prezime: "<<i.prezime<<endl;
        izlaz << i.dat;
        izlaz << i.mestasce;
        izlaz<<"Pozicije: "<<i.pozicije<<endl;
        izlaz<<"Zarada: "<<i.zarada<<endl;
        izlaz<<"Indeks korisnosti: "<<i.indexkor<<endl;
        return izlaz;
    }
    void predstavise ()
    {
        Osoba::predstavise();
        cout << "Broj na dresu: " << dres <<endl;
        cout << "Visina u cm: " << visina << endl;
        cout << "Pozicije: " << pozicije << endl;
        cout << "Zarada: " << zarada <<endl;
        cout << "Indeks korisnosti: " << indexkor << endl;
    }
    int getGod ()
    {
        return dat.getG ();
    }
    int getVisina ()
    {
        return visina;
    }

};

///malo duza klasa za informacije o igracima
#endif // IGRAC_HPP_INCLUDED
