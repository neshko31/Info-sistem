#ifndef KOLO_HPP_INCLUDED
#define KOLO_HPP_INCLUDED
#define BROJ_UTAKMICA 9

#include "datum.hpp"
#include "utakmica.hpp"

///evo ga i funkcija za kola da vidimo mi to
///vec se nazire da je najveci problem ovog projekta sama baza podataka

class Kolo
{
private:
    int rednibr;
    Datum odk;
    Datum dok;
    Utakmica tekme[BROJ_UTAKMICA];
public:
    friend void ispisKola (const Kolo &ko);
};

void ispisKola (const Kolo &ko)
{
    cout << "Kolo: " << ko.rednibr << endl;
    cout << "Pocetak kola: ";
    ispisDatuma(ko.odk);
    cout << endl;
    cout << "Kraj kola: ";
    ispisDatuma(ko.dok);
    cout << endl;
    int i;
    for (i=1; i<=BROJ_UTAKMICA; i++)
    {
        ispisUtakmica(ko.tekme[i]);
    }
}
#endif // KOLO_HPP_INCLUDED
