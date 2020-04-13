#ifndef KOLO_HPP_INCLUDED
#define KOLO_HPP_INCLUDED
#define BROJ_UTAKMICA 9

#include "datum.hpp"
#include "utakmica.hpp"

class Kolo
{
private:
    int rednibr;
    Datum daet;
    Utakmica tekme[BROJ_UTAKMICA];
};

#endif // KOLO_HPP_INCLUDED
