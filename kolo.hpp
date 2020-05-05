#ifndef KOLO_HPP_INCLUDED
#define KOLO_HPP_INCLUDED
#define BROJ_UTAKMICA 9

#include "datum.hpp"
#include "utakmica.hpp"

///inace ovaj opis ovde ne valja, lepse je objasnjeno u mainu
///evo ga i funkcija za kola da vidimo mi to
///vec se nazire da je najveci problem ovog projekta sama baza podataka
///ovde ide dodela za igraca kola i racunanje ko ima najvise tih igraca, pa se proglasava igracem regularnog dela
///ili samo za kompletno po proseku indeksa korsinosti, pa po svakom timu se odredi igrac i od tih se uzimaju najbolji iz svakog tima
///nakon sto imamo sve iz svih timova uzimamo najbolje i opet trazimo najboljeg i time proglasavamo najboljeg igraca
///slican sistem ide i za final four

class Kolo
{
private:
    int rednibr;
    Utakmica tekme[BROJ_UTAKMICA];
public:
    friend void ispisKola (const Kolo &ko);
};

void ispisKola (const Kolo &ko)
{
    cout << "Kolo: " << ko.rednibr << endl;
    cout << endl;
    int i;
    for (i=1; i<=BROJ_UTAKMICA; i++)
    {
        ispisUtakmica(ko.tekme[i]);
    }
}
#endif // KOLO_HPP_INCLUDED
