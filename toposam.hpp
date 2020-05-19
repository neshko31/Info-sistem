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
    bool izbaciutakmicu(Utakmica& u)
    {
        for (auto it=tekmeplejof.begin(); it<tekmeplejof.end(); it++){
            if (u.getBrpoen1()==(*it)->getBrpoen1() && u.getBrpoen2()==(*it)->getBrpoen2()){
                tekmeplejof.erase(it);
                return true;
            }
        }
        return false;
    }
    void pretrazipotim(string tim)
    {
        bool pronadjen = false;
        for (auto it=tekmeplejof.begin(); it<tekmeplejof.end(); it++)
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


#endif // TOPOSAM_HPP_INCLUDED
