#ifndef TRENERDATUM_HPP_INCLUDED
#define TRENERDATUM_HPP_INCLUDED

///klasa samo iz razloga jer zelim da imam nasledjivanje :)

class TrenerDatum
{
protected:
    int dant;
    int mesect;
    int godinat;
public:
    TrenerDatum (int d, int m, int g)
    {
        dant=d;
        mesect=m;
        godinat=g;
    }
    TrenerDatum()
    {
        dant=1;
        mesect=1;
        godinat=1;
    }
    TrenerDatum (const TrenerDatum &td)
    {
        dant=td.dant;
        mesect=td.mesect;
        godinat=td.godinat;
    }
    void datumTrenera ()
    {
        cout << dant << "." << mesect << "." << godinat << ".";
    }
};

#endif // TRENERDATUM_HPP_INCLUDED
