#ifndef MESTO_HPP_INCLUDED
#define MESTO_HPP_INCLUDED

///ovde imamo prvi primerak metode koja nema smisla, ali menja stanje polja

class Mesto
{
private:
    string drzava;
    string naziv;
public:
    Mesto (string drz="evropa", string naz="grad u evropi")
    {
        drzava=drz;
        naziv=naz;
    }
    void zameniNazivmesto ()
    {
        if (naziv=="/")
        {
            naziv="nema informacija";
        }
    }
    friend ostream& operator<<(ostream& izlaz, const Mesto& m)
    {
        izlaz<<"Naziv mesta: "<<m.naziv<<endl;
        izlaz<<"Drzava: "<< m.drzava << endl;
        return izlaz;
    }
    void ispisimesto ()
    {
        cout << drzava << ", " << naziv << endl;
    }
    string getDrzava ()
    {
        return drzava;
    }
    string getMesto ()
    {
        return naziv;
    }
};

///prosta klasa sa konstruktorom i ispisom koji se poziva u drugim klasama
#endif // MESTO_HPP_INCLUDED
