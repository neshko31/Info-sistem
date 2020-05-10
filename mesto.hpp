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
};
///friend void ispisMesto (const Mesto &mestice);
///ako zatreba
/*Mesto(){
    drzava="evropa";
    naziv="grad u evropi";
}
Mesto (const Mesto &me)
{
    drzava=me.drzava;
    naziv=me.naziv;
}*/
/*void ispisMesto (const Mesto &mestice)
{
    cout << mestice.drzava << ", "<< mestice.naziv << endl;
}*/

///prosta klasa sa konstruktorom i ispisom koji se poziva u drugim klasama
#endif // MESTO_HPP_INCLUDED
