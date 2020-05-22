#ifndef TOPOSAM_HPP_INCLUDED
#define TOPOSAM_HPP_INCLUDED

#include "tabela.hpp"
#include "utakmica.hpp"
#define MAX 20

class TopOsam
{
private:
    int brojtimova;
    vector <Utakmica*> tekmeplejof;
    vector <Tim*> timovipo;
public:
    TopOsam (int a)
    {
        brojtimova=a;
    }
    ///ovde ce bato da bude da uzima prvih osam
    ///spaja timove
    ///treba da racuna koliko ko ima pobeda
    ///pobede dobijamo iz onog brojaca, funkcije, koja ce biti u utakmica.hpp, oke ipak bez ovoga sto covek da se muci
    ///nakon toga 4 pobednika
    ///radi ako je verovati mom instinktu
    friend ostream& operator<<(ostream& izlaz, const TopOsam& to)
    {

        return izlaz;
    }
    void dodajtekme(Utakmica* utak)
    {
        tekmeplejof.push_back(utak);
    }
    void ispisTekmice ()
    {
        for (auto it=tekmeplejof.begin(); it<tekmeplejof.end(); it++)
        {
            (*it)->ispistekme();
        }
    }
    bool izbaciutakmicu(int idd)
    {
        for (auto it=tekmeplejof.begin(); it<tekmeplejof.end(); it++){
            if (idd==(*it)->getId()){
                cout << "Izbacena je utakmica: " << (*it)->getTim1()<< " / " << (*it)->getTim2() << endl << (*it)->getBrpoen1() << " " << (*it)->getBrpoen2() << endl;
                tekmeplejof.erase(it);
                return true;
            }
        }
        return false;
    }
    void pretrazipotimtoposam(string tim, char mode='a')
    {
        if (tim=="GranCanaria" || tim=="Canaria")
        {
            tim="Gran Canaria";
        }
        if (tim=="Zalgiris" || tim=="ZalgirisKaunas")
        {
            tim="Zalgiris Kaunas";
        }
        if (tim=="Real" || tim=="RealMadird")
        {
            tim="Real Madrid";
        }
        if (tim=="Olimpia" || tim=="OlimpiaMilano")
        {
            tim="Olimpia Milano";
        }
        if (tim=="Anadolu" || tim=="Efes" || tim=="Anadolu Efes")
        {
            tim="Anadolu Efes";
        }
        if (tim=="Maccabi" || tim=="MaccabiTelAviv")
        {
            tim="Maccabi Tel Aviv";
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
        for (auto it=tekmeplejof.begin(); it<tekmeplejof.end(); it++)
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
    void pretrazipoidtoposam(int ide, char mode='a')
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
        bool pronadjen = false;
        for (auto it=tekmeplejof.begin(); it<tekmeplejof.end(); it++)
        {
            if (ide==(*it)->getId())
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


#endif // TOPOSAM_HPP_INCLUDED
