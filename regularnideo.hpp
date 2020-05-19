#ifndef REGULARNIDEO_HPP_INCLUDED
#define REGULARNIDEO_HPP_INCLUDED
#define BROJ_KOLA 30

#include "tabela.hpp"
#include "kolo.hpp"

///korisnik dobija opciju ispisa samo kola ili kola+tabela
///ovde je ispis ovih svih kola kao i ispis same tabele

class RegularniDeo
{
private:
    int brojtimova;
    vector <Kolo*> kolaa;
    vector <Utakmica*> svetekmicee;
    vector <Tim*> timoviregdeo;
public:
    RegularniDeo (int br)
    {
        brojtimova=br;
    }
    friend ostream& operator<<(ostream& izlaz, const RegularniDeo& rd)
    {
        izlaz << "Broj timova ucesnika: "<< rd.brojtimova << endl;
        /*for (int i=0; i<BROJ_KOLA; i++)
        {
            izlaz << rd.kola[i];
        }*/
        return izlaz;
    }
    void dodajtekme(Utakmica* utak)
    {
        svetekmicee.push_back(utak);
    }
    void ispisTekmice ()
    {
        for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
        {
            (*it)->ispistekme();
        }
    }
    void ispisSvihKola ()
    {
        for (auto it=kolaa.begin(); it<kolaa.end(); it++)
        {
            (*it)->ispisiKola();
        }
    }
    void dodajkolo(Kolo* kol)
    {
        kolaa.push_back(kol);
    }
    bool izbacikolo(Kolo &k)
    {
        for (auto it=kolaa.begin(); it<kolaa.end(); it++){
            if (k.getBrKolo()==(*it)->getBrKolo()){
                kolaa.erase(it);
                return true;
            }

        }
        return false;
    }
    bool izbaciutakmicuregdeo(Utakmica& u)
    {
        for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++){
            if (u.getBrpoen1()==(*it)->getBrpoen1() && u.getBrpoen2()==(*it)->getBrpoen2()){
                svetekmicee.erase(it);
                return true;
            }
        }
        return false;
    }
    void uspehtimdonekogkola (string imetima, int a)
    {
        int pob=0;
        int pobp=0;
        int por=0;
        int porp=0;
        for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
        {
            if ((*it)->getId()<a)
            {
                if (imetima==(*it)->getTim1 ())
                {
                    if ((*it)->getBrpoen1 () > (*it)->getBrpoen2())
                    {
                        if ((*it)->getProd ()==true)
                        {
                            pobp++;
                        }
                        if ((*it)->getProd ()!=true)
                        {
                            pob++;
                        }
                    }

                    if ((*it)->getBrpoen1 () < (*it)->getBrpoen2())
                    {
                        if ((*it)->getProd ()==true)
                        {
                            porp++;
                        }
                        if ((*it)->getProd ()!=true)
                        {
                            por++;
                        }
                    }
                }
                if (imetima==(*it)->getTim2 ())
                {
                    if ((*it)->getBrpoen2 () > (*it)->getBrpoen1())
                    {
                        if ((*it)->getProd ()==true)
                        {
                            pobp++;
                        }
                        if ((*it)->getProd ()!=true)
                        {
                            pob++;
                        }
                    }

                    if ((*it)->getBrpoen2 () < (*it)->getBrpoen1())
                    {
                        if ((*it)->getProd ()==true)
                        {
                            porp++;
                        }
                        if ((*it)->getProd ()!=true)
                        {
                            por++;
                        }
                    }
                }
            }
            if ((*it)->getId()==a)
            {
                break;
            }
        }
        cout << imetima << endl;
        cout << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
     }
    void pretrazipotim(string tim)
    {
        bool pronadjen = false;
        for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
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
    int kolikoJeKola()
    {
        return kolaa.size();
    }
};

#endif // REGULARNIDEO_HPP_INCLUDED
