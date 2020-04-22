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
    friend void ispisArena (const Arena &a);
};

void ispisArena (const Arena &a)
{
    cout << "Arena: " << a.naziv << endl;
    cout << "Drzava i mesto: ";
    ispisMesto(a.mesot);
    cout << "Broj mesta: " << a.brojmesta << endl;
}

///ispis arene i sama klasa
#endif // ARENA_HPP_INCLUDED
