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
protected:
    int rednibr;
    vector <Utakmica*> tekme;
public:
    Kolo (int n)
    {
        rednibr=n;
    }
    void pisiTxt(string nazivFajla, string tekst,char mode='a')
    {
                    ofstream fajl;
                    if (mode=='a'){
                        fajl.open (nazivFajla, ios_base::app);
                    }
                    else{
                        fajl.open (nazivFajla);}
                    ///fajl << k22.ime << "," << k22.prezime << "," << k22.kupacIliProd << "," << k22.brojTelefona << "," << k22.korisnickoIme << "," << k22.lozinka <<std::endl;
                    fajl << tekst << endl;
                    fajl.close();

    }
    friend ostream& operator<<(ostream& izlaz, const Kolo& ko)
    {
        izlaz << "Kolo broj: " << ko.rednibr << endl;
        /*for (auto it=tekme.begin(); it<tekme.end(); it++)
        {
            cout << (*it)->ispistekme();
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
    void pretrazipoid(int ide, char mode='a')
    {
        bool pronadjen = false;
        for (auto it=tekme.begin(); it<tekme.end(); it++)
        {
            if (ide==(*it)->getId())
            {
                (*it)->ispistekme();
                pronadjen=true;
                ofstream fajl;
                if (mode=='a')
                {
                    fajl.open ("baskonia 18.19.txt", ios_base::app);
                }
                else
                {
                    fajl.open ("baskonia 18.19.txt");
                }
                fajl << (*it)->getDan() << "." << (*it)->getMesec() << "." << (*it)->getGodina() << ". " << (*it)->getTim1() << " " << (*it)->getBrpoen1() << " " << (*it)->getTim2() << " " << (*it)->getBrpoen2() << endl;
                fajl.close();
            }
        }
        if (!pronadjen)
        {
            cout<<"Nema takve utakmice!"<<endl;
        }
    }
    void pretrazipotim(string tim, char mode='a')
    {
        bool pronadjen = false;
        for (auto it=tekme.begin(); it<tekme.end(); it++)
        {
            if (tim==(*it)->getTim1() || tim==(*it)->getTim2())
            {
                (*it)->ispistekme();
                pronadjen=true;
                ofstream fajl;
                if (mode=='a')
                {
                    fajl.open ("izvestaj.txt", ios_base::app);
                }
                else
                {
                    fajl.open ("izvestaj.txt");
                }
                Utakmica u1 ((*it)->getId(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGodina(), (*it)->getTim1(), (*it)->getTim2(), (*it)->getBrpoen1(), (*it)->getBrpoen2(), (*it)->getProd());
                fajl << u1 << endl;
                ///fajl << (*it)->getDan() << "." << (*it)->getMesec() << "." << (*it)->getGodina() << ". " << (*it)->getTim1() << " " << (*it)->getBrpoen1() << " " << (*it)->getTim2() << " " << (*it)->getBrpoen2() << endl;
                fajl.close();
            }
        }
        if (!pronadjen)
        {
            cout<<"Nema takve utakmice!"<<endl;
        }
    }
    bool izbaciutakmicukolo(Utakmica& u)
    {
        for (auto it=tekme.begin(); it<tekme.end(); it++){
            if (u.getBrpoen1()==(*it)->getBrpoen1() && u.getBrpoen2()==(*it)->getBrpoen2()){
                tekme.erase(it);
                return true;
            }
        }
        return false;
    }
    int getBrKolo ()
    {
        return rednibr;
    }
};

#endif // KOLO_HPP_INCLUDED
