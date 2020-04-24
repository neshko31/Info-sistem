#ifndef TRENER_HPP_INCLUDED
#define TRENER_HPP_INCLUDED

#include "datum.hpp"
#include "mesto.hpp"
#include "trenerdatum.hpp"

class Trener : public TrenerDatum
{
private:
    string ime;
    string prezime;
    Mesto mestasce;
public:
    ///ovo cu doraditi kasnije
    ///Trener (int d2q=1, int m2q=1, int g2q=1, string imq="Nenad", string prezq="Lukic", string drq="da", string naq="dada") : TrenerDatum (d2q, m2q, g2q), ime(imq), prezime(prezq), mestasce(drq, naq) {};
    void ispisTrenera ()
    {
        cout << "Ime: " << ime << "Prezime: " << prezime << endl;
        TrenerDatum::datumTrenera();
        ispisMesto(mestasce);
    }

};

///osnovne info o treneru

#endif // TRENER_HPP_INCLUDED
