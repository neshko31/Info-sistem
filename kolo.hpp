#ifndef KOLO_HPP_INCLUDED
#define KOLO_HPP_INCLUDED
#define BROJ_UTAKMICA 9

#include "datum.hpp"
#include "utakmica.hpp"
#include <vector>
///inace ovaj opis ovde ne valja, lepse je objasnjeno u mainu
///evo ga i funkcija za kola da vidimo mi to
///vec se nazire da je najveci problem ovog projekta sama baza podataka
///ovde ide dodela za igraca kola i racunanje ko ima najvise tih igraca, pa se proglasava igracem regularnog dela
///ili samo za kompletno po proseku indeksa korsinosti, pa po svakom timu se odredi igrac i od tih se uzimaju najbolji iz svakog tima
///nakon sto imamo sve iz svih timova uzimamo najbolje i opet trazimo najboljeg i time proglasavamo najboljeg igraca
///slican sistem ide i za final four


///ovo nije testirano u mainu pa cemo samo reci da valja

class Kolo
{
public:
    int rednibr;
    vector <Utakmica*> tekme;
public:
    Kolo (int n)
    {
        rednibr=n;
    }
    friend ostream& operator<<(ostream& izlaz, const Kolo& ko)
    {
        izlaz << "Kolo broj: " << ko.rednibr << endl;
        /*for (auto it=tekme.begin(); it<tekme.end(); it++){
          (*it)->cout << tekme();
        }*/
        return izlaz;
    }
    void dodajtekmu(Utakmica* utak)
    {
        tekme.push_back(utak);
    }
    void ispisiKola()
    {
        cout << "Kolo: " << rednibr << endl;
        for (auto it=tekme.begin(); it<tekme.end(); it++)
        {
            (*it)->ispistekme();
        }
    }
    void ispisTekmeeee ()
    {
        for (auto it=tekme.begin(); it<tekme.end(); it++)
        {
            (*it)->ispistekme();
        }
    }
    int kolikoJeKola()
    {
        return tekme.size();
    }
    void pretrazipoid(int ide)
    {
        bool pronadjen = false;
        for (auto it=tekme.begin(); it<tekme.end(); it++)
        {
            if (ide==(*it)->getId())
            {
                (*it)->ispistekme();
                pronadjen=true;
            }
        }
        if (!pronadjen)
        {
            cout<<"Nema takve utakmice!"<<endl;
        }
    }
    void pretrazipotim(string tim)
    {
        bool pronadjen = false;
        for (auto it=tekme.begin(); it<tekme.end(); it++)
        {
            if (tim==(*it)->getTim1() || tim==(*it)->getTim2())
            {
                (*it)->ispistekme();
                pronadjen=true;
            }
        }
        if (!pronadjen)
        {
            cout<<"Nema takve utakmice!"<<endl;
        }
    }
};


#endif // KOLO_HPP_INCLUDED
