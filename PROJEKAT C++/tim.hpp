#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED

#define BROJ_IGRACA 20

#include "igrac.hpp"
#include "datum.hpp"
#include "mesto.hpp"
#include "arena.hpp"
#include "trener.hpp"

class Tim
{
private:
    string nazivtima;
    Datum osnovano;
    Mesto mestasce;
    string trofeji;
    Arena ar;
    int pobede;
    int porazi;
    int bodovi;
    Igrac igraci[BROJ_IGRACA];
public:

};


#endif // TIM_HPP_INCLUDED
