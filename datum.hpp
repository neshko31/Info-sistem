#ifndef DATUM_HPP_INCLUDED
#define DATUM_HPP_INCLUDED

class Datum
{
private:
    int dan;
    int mesec;
    int godina;
public:
    Datum (int d=1, int m=1, int g=1){
        dan=d;
        mesec=m;
        godina=g;
    }
    friend void ispisDatuma (const Datum &datumcic);
};

void ispisDatuma (const Datum &datumcic)
{
    cout <<datumcic.dan<<"."<<datumcic.mesec<<"."<<datumcic.godina<<".";
}

///prosta klasa sa konstruktorom i ispisom koji se poziva u drugim klasama
#endif // DATUM_HPP_INCLUDED
