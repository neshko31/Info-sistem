#ifndef TIM_HPP_INCLUDED
#define TIM_HPP_INCLUDED

#define BROJ_IGRACA 30

///ovde jos jedan primerak, racunamo proseke nekih stvari
///ovi proseci ce biti kao komentar dokle god ne nadjem nacin da ubacim igrace u konstruktor

#include "igrac.hpp"
#include "datum.hpp"
#include "mesto.hpp"
#include "arena.hpp"
#include "trener.hpp"
#include "timucinak.hpp"
#include <fstream>
#include <sstream>
#include <vector>

///klasa koja objedinjuje igrace, trenera i daje ostale info o timu
///imamo metodu za ispis svega
///funkcija za ispis samo naziva tima
///funkcija za ispis koja se koristi u tabeli

class Tim: public TimUcinak
{
    ///ovde sam stavio public jer nemam blage kako da ispis utakmice pristupi ako je protected
public:
    string nazivtima;
    Datum osnovano;
    Arena ar;
    Trener tren;
    vector <Igrac*> igraci;
    static int budzet;
public:
    Tim ():TimUcinak(0, 0, 0, 0, 0, 0, 0), nazivtima("mani mani"), osnovano (1, 1, 1), ar("as", "serbija", "ns", 13200), tren("nenad", "lukic", 1, 1, 1, "lele", "lala")
    {
        budzet+=1000;
    };

    friend ostream& operator<<(ostream& izlaz, const Tim& t)
    {
        izlaz<<"Tim: "<<t.nazivtima<<endl;
        izlaz << t.osnovano;
        izlaz << t.ar;
        izlaz << t.tren;
        return izlaz;
    }
    static int getStatickiBudzet()
    {
        return budzet;
    }
    static int setBudzet (int a)
    {
        budzet=a;
        return budzet;
    }
    void dodaj(Igrac* igr)
    {
        igraci.push_back(igr);
    }
    void dodajIgraca (Igrac* igrac1)
    {
        igraci.push_back(igrac1);
    }
    void ispisiInfoTim()
    {
        cout<<"Naziv tima: "<< nazivtima <<endl;
        cout << "Datum osnivanja tima: ";
        osnovano.ispisidatum();
        cout << "Arena: ";
        ar.ispisihala();
        TimUcinak::ispisiInfoTim();
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            (*it)->predstavise();
        }
    }
    int kolikoJeIgraca()
    {
        return igraci.size();
    }

    bool izbaci(Igrac& igr)
    {
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            if (igr.getIme()==(*it)->getIme() && igr.getPrezime()==(*it)->getPrezime())
            {
                igraci.erase(it);
                return true;
            }
        }
        return false;

    }
    ///metode za povecavanje i smanjivanje rade na neki nacin, ali zapravo ne rade
    ///s obzirom na to da on ne zna koja je vrednost u txt fajlu
    ///oke ipak rade

    static void povecajBudzet (int a, string budzetfajl)
    {
        budzet=dajbudzet(budzetfajl);
        budzet=budzet+a;

        ofstream fajl;
        fajl.open (budzetfajl);
        fajl << budzet << endl;
        fajl.close();
    }
    static void smanjiBudzet (int a, string budzetfajl)
    {
        budzet=dajbudzet(budzetfajl);
        budzet=budzet-a;

        ofstream fajl;
        fajl.open (budzetfajl);
        fajl << budzet << endl;
        fajl.close();
    }
    static int dajbudzet (string naziv)
    {
        int b;
        string linija;
        ifstream fajl (naziv);
        if (fajl.is_open())
        {
            getline (fajl,linija);

            stringstream ss;
            ss << linija;
            ss >> b;
            fajl.close();
            return b;
        }
        else
        {
            cout << "Neuspesno otvoren fajl";
            return 0;
        }
    }
    static void citajBudzetFajl (string nazivFajla)
    {
        string linija;
        ifstream fajl (nazivFajla);
        if (fajl.is_open())
        {
            while ( getline (fajl,linija) )
            {
                cout << linija << '\n';
            }
            fajl.close();
        }
        else
        {
            cout << "Neuspesno otvoren fajl";
        }

    }
    ///ovo su te kao neke metode
    void najboljiigracutimu ()
    {
        int najbolji;
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            if ((*it)->getIndex()>najbolji)
            {
                najbolji=(*it)->getIndex();
            }
        }
        ///ispis te linije iz fajla
    }
    /*void prosekstarosti ()
    {
        int godine=0;
        int i;
        for (i=0; i<BROJ_IGRACA; i++)
        {
            godine=2020-igraci[i].dat.godina;
        }
        int prosek1;
        prosek1=prosek1/i;
        cout << prosek1;
    }

    void prosekvisina ()
    {
        int vis=0;
        int j=0;
        for (j=0; j<BROJ_IGRACA; j++)
        {
            vis=igraci[i].visina;
        }
        vis=vis/j;
    }*/
};

int Tim::budzet=0;

#endif // TIM_HPP_INCLUDED
