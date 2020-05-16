#ifndef ARENA_HPP_INCLUDED
#define ARENA_HPP_INCLUDED

#include "mesto.hpp"

class Arena
{
private:
    string naziv;
    Mesto mesot;
    int brojmesta;
public:
    Arena (string naziv1="Nesto", string dre="Srbija", string naze="NS", int broj=13200) : naziv(naziv1), mesot(dre, naze), brojmesta(broj){};

    friend ostream& operator<<(ostream& izlaz, const Arena& a)
    {
        izlaz<<"Arena: "<< endl;
        izlaz<<"Naziv arene:"<<a.naziv<<endl;
        izlaz << a.mesot;
        izlaz << "Broj mesta: "<< a.brojmesta<< endl;
        return izlaz;
    }
    void ispisihala ()
    {
        cout << "Naziv hale: " << naziv << endl;
        cout << "Mesto: ";
        mesot.ispisimesto();
        cout << "Broj mesta: " << brojmesta << endl;
    }
};

///ispis arene i sama klasa
#endif // ARENA_HPP_INCLUDED
