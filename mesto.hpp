#ifndef MESTO_HPP_INCLUDED
#define MESTO_HPP_INCLUDED

class Mesto
{
protected:
    string drzava;
    string naziv;
public:
    Mesto(){
        drzava="evropa";
        naziv="grad u evropi";
    }
    Mesto (string drz="evropa", string naz="grad u evropi")
    {
        drzava=drz;
        naziv=naz;
    }
    Mesto (const Mesto &me)
    {
        drzava=me.drzava;
        naziv=me.naziv;
    }
    friend void ispisMesto (const Mesto &mestice);
};

void ispisMesto (const Mesto &mestice)
{
    cout << mestice.drzava << ", "<< mestice.naziv << endl;
}

///prosta klasa sa konstruktorom i ispisom koji se poziva u drugim klasama
#endif // MESTO_HPP_INCLUDED
