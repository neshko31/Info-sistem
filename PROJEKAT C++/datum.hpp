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
    int getDan ()const
    {
        return dan;
    }
    int getMesec ()const
    {
        return mesec;
    }
    int getGodina ()const
    {
        return godina;
    }
    void setD (int d1)
    {
        dan=d1;
    }
    void setM (int m1)
    {
        mesec=m1;
    }
    void setG (int g1)
    {
        godina=g1;
    }

    friend void ispisDatuma (const Datum &datumcic);
};

    void ispisDatuma (const Datum &datumcic)
    {
        cout <<datumcic.dan<<"."<<datumcic.mesec<<"."<<datumcic.godina<<"."<<endl;
    }

#endif // DATUM_HPP_INCLUDED
