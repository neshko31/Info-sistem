#ifndef SEZONA_HPP_INCLUDED
#define SEZONA_HPP_INCLUDED

#include "regularnideo.hpp"
#include "toposam.hpp"
#include "finalfour.hpp"

class Sezona
{
private:
    string naziv;
    string sezonakojagodina;
    RegularniDeo reg;
    TopOsam top8;
    FinalFour top4;
public:
    ///ah simpatican deo koji bi trebao da objedini sve zivo
    ///meni za izbor da korisnik zna gde ide
    friend void ispisSezona (const Sezona& sez);
};

void ispisSezona (const Sezona& sez)
{
    cout << sez.naziv;
    cout << sez.sezonakojagodina;
    ispisRegularniDeo(sez.reg);
    ispisTopOsam(sez.top8);
    ispisFinalFour(sez.top4);
}
#endif // SEZONA_HPP_INCLUDED
