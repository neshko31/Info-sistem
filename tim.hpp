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

///klasa koja objedinjuje igrace, trenera i daje ostale info o timu
///imamo metodu za ispis svega
///funkcija za ispis samo naziva tima
///funkcija za ispis koja se koristi u tabeli

class Tim: public TimUcinak
{
///ovde sam stavio public jer nemam blage kako da ispis utakmice pristupi ako je protected
protected:
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
    Tim (int a1, int a2, int a3, int a4, int a5, int a6, int a7, string na, int d1, int d2, int d3, string naa, string draa, string mea, int aa, string nt, string pt, int dt1, int dt2, int dt3, string drt, string nat, int aaa): TimUcinak(a1, a2, a3, a4, a5, a6, a7), nazivtima(na), osnovano(d1, d2, d3),ar (naa, draa, mea, aa), tren(nt, pt, dt1, dt2, dt3, drt, nat)
    {
        budzet+=aaa;
    }
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
    void ispisiInfoTim()
    {
        cout<<"Naziv tima: "<< nazivtima <<endl;
        cout << "Datum osnivanja tima: ";
        osnovano.ispisidatum();
        cout << "Arena: ";
        ar.ispisihala();
        TimUcinak::ispisiInfoTim();
        cout << "Igraci:" << endl;
        cout << "--------------------------" << endl;
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
    void najboljiigracutimu (char mode='a')
    {
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        double najbolji=0;
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            if ((*it)->getIndex()>najbolji)
            {
                najbolji=(*it)->getIndex();
            }
        }
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            if ((*it)->getIndex()==najbolji)
            {
                Igrac i1((*it)->getIme(), (*it)->getPrezime(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGod (), (*it)->getDrzava (), (*it)->getMesto (), (*it)->getDres(), (*it)->getVisina(), (*it)->getPoz(), (*it)->getZarada (),(*it)->getIndex());
                fajl << i1 << endl;
                (*it)->predstavise();
            }
        }
        fajl.close ();
    }
    void prosekstarosti (char mode='a')
    {
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        int godinee=0;
        double prosek=0;
        int n=0;
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            n=(*it)->getGod ();
            godinee=godinee+(2020-n);
        }
        int a=igraci.size();
        prosek=godinee/a;
        cout << "Prosek godina ovog tima je: " << prosek << endl;
        fajl << "Prosek godina ovog tima je: " << prosek << endl;
        fajl.close ();
    }
    void prosekvisina (char mode='a')
    {
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        int visina=0;
        double prosek=0;
        int n=0;
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            n=(*it)->getVisina ();
            visina=visina+n;
        }
        int a=igraci.size();
        prosek=visina/a;
        cout << "Prosek visine ovog tima je: " << prosek << endl;
        fajl << "Prosek visine ovog tima je: " << prosek << endl;
        fajl.close ();
    }
    void najvisiigrac (char mode='a')
    {
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        int najvisi=0;
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            if ((*it)->getVisina()>najvisi)
            {
                najvisi=(*it)->getVisina();
            }
        }
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            if ((*it)->getVisina()==najvisi)
            {
                Igrac i1((*it)->getIme(), (*it)->getPrezime(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGod (), (*it)->getDrzava (), (*it)->getMesto (), (*it)->getDres(), (*it)->getVisina(), (*it)->getPoz(), (*it)->getZarada (),(*it)->getIndex());
                fajl << i1 << endl;
                (*it)->predstavise();
            }
        }
        fajl.close ();
    }
    void plateigraca (string imee, char mode='a')
    {
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        bool pronadjen;
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            if ((*it)->getIme()==imee)
            {
                Igrac i1((*it)->getIme(), (*it)->getPrezime(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGod (), (*it)->getDrzava (), (*it)->getMesto (), (*it)->getDres(), (*it)->getVisina(), (*it)->getPoz(), (*it)->getZarada (),(*it)->getIndex());
                fajl << i1 << endl;
                (*it)->zaradaigr();
                pronadjen=true;
                fajl.close ();
            }
        }
        if (pronadjen==false)
        {
            cout << "Nema takvog igraca!" << endl;
            fajl << "Nema takvog igraca!" << endl;
            fajl.close ();
        }
    }


    ///POKUSAJ DVE METODE

    /*void sortgodine (char mode='a')
    {
        vector <Igrac*> slozeniigraci;
        int god1, god2;
        int a, b;
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            for (auto ite=igraci.begin(); ite<igraci.end(); ite++)
            {
                Igrac i1((*it)->getIme(), (*it)->getPrezime(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGod (), (*it)->getDrzava (), (*it)->getMesto (), (*it)->getDres(), (*it)->getVisina(), (*it)->getPoz(), (*it)->getZarada (),(*it)->getIndex());
                Igrac i2((*ite++)->getIme(), (*ite++)->getPrezime(), (*ite++)->getDan(), (*ite++)->getMesec(), (*ite++)->getGod (), (*ite++)->getDrzava (), (*ite++)->getMesto (), (*ite++)->getDres(), (*ite++)->getVisina(), (*ite++)->getPoz(), (*ite++)->getZarada (),(*ite++)->getIndex());
                ///Igrac i2((*ite)->getIme(), (*ite)->getPrezime(), (*ite)->getDan(), (*ite)->getMesec(), (*ite)->getGod (), (*ite)->getDrzava (), (*ite)->getMesto (), (*ite)->getDres(), (*ite)->getVisina(), (*ite)->getPoz(), (*ite)->getZarada (),(*ite)->getIndex());
                a=i1.getGod();
                b=i2.getGod();
                a=(*ite)->getGod ();
                b=(*ite++)->getGod ();
                god1=2020-a;
                god2=2020-b;
                if (i1.getGod()<i2.getGod())
                {
                    i1.zaradaigr();
                }
                else
                {
                    i2.zaradaigr();
                }
                if (god1>god2)
                {
                    (*ite)->predstavise();
                    ///Igrac i1((*ite)->getIme(), (*ite)->getPrezime(), (*ite)->getDan(), (*ite)->getMesec(), (*ite)->getGod (), (*ite)->getDrzava (), (*ite)->getMesto (), (*ite)->getDres(), (*ite)->getVisina(), (*ite)->getPoz(), (*ite)->getZarada (),(*ite)->getIndex());
                    slozeniigraci.push_back (&i1);
                    Igrac i1((*ite)->getIme(), (*ite)->getPrezime(), (*ite)->getDan(), (*ite)->getMesec(), (*ite)->getGod (), (*ite)->getDrzava (), (*ite)->getMesto (), (*ite)->getDres(), (*ite)->getVisina(), (*ite)->getPoz(), (*ite)->getZarada (),(*ite)->getIndex());
                    Igrac i2((*ite++)->getIme(), (*ite++)->getPrezime(), (*ite++)->getDan(), (*ite++)->getMesec(), (*ite++)->getGod (), (*ite++)->getDrzava (), (*ite++)->getMesto (), (*ite++)->getDres(), (*ite++)->getVisina(), (*ite++)->getPoz(), (*ite++)->getZarada (),(*ite++)->getIndex());
                    swap((*ite), (*ite++));
                }
            }
        }
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
                Igrac i1((*it)->getIme(), (*it)->getPrezime(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGod (), (*it)->getDrzava (), (*it)->getMesto (), (*it)->getDres(), (*it)->getVisina(), (*it)->getPoz(), (*it)->getZarada (),(*it)->getIndex());
                fajl << i1 << endl;
                (*it)->predstavise();
        }
    }
    void sortvisina ()
    {
        for (auto it=igraci.begin(); it<igraci.end(); it++)
        {
            for (auto ite=igraci.begin(); ite<igraci.end(); ite++)
            {
                if ((*ite)->getVisina ()<(*ite++)->getVisina ())
                {
                    swap((*ite), (*ite++));
                }
            }
        }
    }
    */
};

int Tim::budzet=0;

#endif // TIM_HPP_INCLUDED
