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

    friend ostream& operator<<(ostream& izlaz, const Sezona& sez)
    {
        izlaz << sez.naziv << " "<<sez.sezonakojagodina<< endl;
        izlaz << sez.reg;
        izlaz << sez.top8;
        izlaz << sez.top4;
        return izlaz;
    }
};

#endif // SEZONA_HPP_INCLUDED
