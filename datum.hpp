#ifndef DATUM_HPP_INCLUDED
#define DATUM_HPP_INCLUDED

class Datum
{
protected:
    int dan;
    int mesec;
    int godina;
public:
    Datum (int d, int m, int g)
    {
        dan=d;
        mesec=m;
        godina=g;
    }
    friend ostream& operator<<(ostream& izlaz, const Datum& d)
    {
        izlaz<<"Datum: "<<d.dan<<"."<<d.mesec<<"."<<d.godina<<"."<<endl;
        return izlaz;
    }
    void ispisidatum()
    {
        cout << dan << "." << mesec << "." << godina << "." <<endl;
    }
    int getG ()
    {
        return godina;
    }
    int getD ()
    {
        return dan;
    }
    int getM ()
    {
        return mesec;
    }
};

///prosta klasa sa konstruktorom i ispisom koji se poziva u drugim klasama
#endif // DATUM_HPP_INCLUDED
