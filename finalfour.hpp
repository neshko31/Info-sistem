#ifndef FINALFOUR_HPP_INCLUDED
#define FINALFOUR_HPP_INCLUDED

#include "toposam.hpp"
#include "utakmica.hpp"
#include "arena.hpp"

class FinalFour
{
private:
    int brojtimova;
    vector <Tim*> timoviff;
    vector <Utakmica*> tekmeff;
    Arena aren;
public:
    FinalFour (int br, string naz, string dra, string mesa, int broj): brojtimova(br), aren (naz, dra, mesa, broj) {};
    ///ovde su dva polu i jedno finale
    ///fakticki samo ispis za 3 tekme
    ///nista preterano bitno ali okej
    friend ostream& operator<<(ostream& izlaz, const FinalFour& ff)
    {
        /*int i=0;
        izlaz << "Timovi ucesnici: "<<endl;
        for (i=0; i<4; i++)
        {
            izlaz <<  ff.cetirkomada[i].nazivtima;
        }
        for (i=0; i<2; i++)
        {
            izlaz << "Polufinale broj " << i << endl;
            izlaz << ff.tekmice[i];
        }
        i++;
        izlaz << "Finale" << endl;
        izlaz << ff.tekmice[i];

	i++;
	izlaz << "Trece mesto" << endl;
	izlaz << ff.tekmice[i];*/
        return izlaz;
    }
    void dodajtekme(Utakmica* utak)
    {
        tekmeff.push_back(utak);
    }
    void ispisTekmice ()
    {
        for (auto it=tekmeff.begin(); it<tekmeff.end(); it++)
        {
            (*it)->ispistekme();
        }
    }
    bool izbaciutakmicu(Utakmica& u)
    {
        for (auto it=tekmeff.begin(); it<tekmeff.end(); it++){
            if (u.getBrpoen1()==(*it)->getBrpoen1() && u.getBrpoen2()==(*it)->getBrpoen2()){
                tekmeff.erase(it);
                return true;
            }
        }
        return false;
    }
    void dodajTim (Tim* timio)
    {
        timoviff.push_back (timio);
    }
    void timoviucesnici ()
    {
        for (auto it=timoviff.begin(); it<timoviff.end(); it++)
        {
            (*it)->ispisiInfoTim();
        }
    }
    void pametniispis ()
    {
        for (auto it=tekmeff.begin(); it<tekmeff.end(); it++)
        {
            (*it)->ispistekme();
            if ((*it)->getId () == 1 || (*it)->getId () == 2)
            {
                cout << "Polufinale" << endl;
                (*it)->ispistekme();
            }
            if ((*it)->getId () == 3)
            {
                cout << "Za trece mesto" << endl;
                (*it)->ispistekme();
            }
            if ((*it)->getId  ()== 4)
            {
                cout << "FINALE" << endl;
                (*it)->ispistekme();
            }
        }
    }
    void pronadjime (string tim, char mode='a')
    {
        if (tim=="Real" || tim=="RealMadird")
        {
            tim="Real Madrid";
        }
        if (tim=="Anadolu" || tim=="Efes" || tim=="Anadolu Efes")
        {
            tim="Anadolu Efes";
        }
        if (tim=="CSKA" || tim=="CSKAMoscow" || tim=="CSKAMoskva")
        {
            tim="CSKA Moscow";
        }
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        bool pronadjen = false;
        for (auto it=tekmeff.begin(); it<tekmeff.end(); it++)
        {
            if (tim==(*it)->getTim1() || tim==(*it)->getTim2())
            {
                (*it)->ispistekme();
                pronadjen=true;
                Utakmica u1 ((*it)->getId(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGodina(), (*it)->getTim1(), (*it)->getTim2(), (*it)->getBrpoen1(), (*it)->getBrpoen2(), (*it)->getProd());
                fajl << u1 << endl;
                fajl.close();
            }
        }
        if (!pronadjen)
        {
            cout<<"Nema takve utakmice!"<<endl;
            fajl << "Nema takve utakmice!" << endl;
            fajl.close ();
        }
    }
};


#endif // FINALFOUR_HPP_INCLUDED
