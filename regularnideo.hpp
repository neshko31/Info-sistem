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
        for (auto it=kolaa.begin(); it<kolaa.end(); it++)
        {
            if (k.getBrKolo()==(*it)->getBrKolo())
            {
                kolaa.erase(it);
                return true;
            }

        }
        return false;
    }
    bool izbaciutakmicuregdeo(int idd)
    {
        for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
        {
            if (idd==(*it)->getId())
            {
                cout << "Izbacena je utakmica: " << (*it)->getTim1()<< " / " << (*it)->getTim2() << endl << (*it)->getBrpoen1() << " " << (*it)->getBrpoen2() << endl;
                svetekmicee.erase(it);
                return true;
            }
        }
        return false;
    }
    void uspehtimdonekogkola (string imetima, int a, char mode='a')
    {
        if (imetima=="GranCanaria" || imetima=="Canaria")
        {
            imetima="Gran Canaria";
        }
        if (imetima=="Zalgiris" || imetima=="ZalgirisKaunas")
        {
            imetima="Zalgiris Kaunas";
        }
        if (imetima=="Real" || imetima=="RealMadird")
        {
            imetima="Real Madrid";
        }
        if (imetima=="Olimpia" || imetima=="OlimpiaMilano")
        {
            imetima="Olimpia Milano";
        }
        if (imetima=="Anadolu" || imetima=="Efes" || imetima=="Anadolu Efes")
        {
            imetima="Anadolu Efes";
        }
        if (imetima=="Maccabi" || imetima=="MaccabiTelAviv")
        {
            imetima="Maccabi Tel Aviv";
        }
        if (imetima=="CSKA" || imetima=="CSKAMoscow" || imetima=="CSKAMoskva")
        {
            imetima="CSKA Moscow";
        }
        int pob=0;
        int pobp=0;
        int por=0;
        int porp=0;
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
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
        ///pretrazipotim(imetima);
        cout << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
        fajl << imetima << endl;
        fajl << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
        fajl.close ();
    }
    int kolikoJeKola()
    {
        return kolaa.size();
    }
    void uspehtimdomacin(string tim, int a, bool sve, char mode='a')
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
        if (tim=="Anadolu" || tim=="Efes" || tim=="AnadoluEfes")
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
        int pob=0;
        int pobp=0;
        int por=0;
        int porp=0;
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        if (!sve)
        {
            bool pronadjen=false;
            for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
            {
                if ((*it)->getId()<a)
                {
                    if (tim==(*it)->getTim1 ())
                    {
                        if (tim==(*it)->getTim1 ())
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
                        pronadjen=true;
                    }
                }
            }
            cout << tim << endl;
            cout << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;

            fajl << tim << endl;
            fajl << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
            fajl.close ();
            if (!pronadjen)
            {
                cout<<"Nema takve utakmice!"<<endl;
                fajl << "Nema takve utakmice!"<<endl;
                fajl.close ();
            }
        }
        else
        {
            bool pronadjen=false;
            for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
            {
                if ((*it)->getId()<a)
                {
                    if (tim==(*it)->getTim1 ())
                    {
                        if (tim==(*it)->getTim1 ())
                        {
                            (*it)->ispistekme();
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
                        pronadjen=true;
                    }
                }
            }
            for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
            {
                if (tim==(*it)->getTim1 ()){
                Utakmica u1 ((*it)->getId(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGodina(), (*it)->getTim1(), (*it)->getTim2(), (*it)->getBrpoen1(), (*it)->getBrpoen2(), (*it)->getProd());
                cout << u1 << endl;
                fajl << u1 << endl;}
            }
            cout << tim << endl;
            cout << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
            fajl << tim << endl;
            fajl << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
            fajl.close ();

            ///uspehtimdonekogkola(tim, a);
            if (!pronadjen)
            {
                cout<<"Nema takve utakmice!"<<endl;
                fajl << "Nema takve utakmice!"<<endl;
                fajl.close ();
            }
        }
    }
    void uspehtimgost(string tim, int a, bool sve, char mode='a')
    {
        if (tim=="GranCanaria")
        {
            tim="Gran Canaria";
        }
        if (tim=="Canaria")
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
        int pob=0;
        int pobp=0;
        int por=0;
        int porp=0;
        ofstream fajl;
        if (mode=='a')
        {
            fajl.open ("izvestaj.txt", ios_base::app);
        }
        else
        {
            fajl.open ("izvestaj.txt");
        }
        if (!sve)
        {
            bool pronadjen=false;
            for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
            {
                if ((*it)->getId()<a)
                {
                    if (tim==(*it)->getTim2 ())
                    {
                        if (tim==(*it)->getTim2 ())
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
                        pronadjen=true;
                    }
                }
            }
            cout << tim << endl;
            cout << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
            fajl << tim << endl;
            fajl << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
            fajl.close ();
            if (!pronadjen)
            {
                cout<<"Nema takve utakmice!"<<endl;
                fajl << "Nema takve utakmice!" << endl;
                fajl.close ();
            }
        }


        else
        {
            bool pronadjen=false;
            for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
            {
                if ((*it)->getId()<a)
                {
                    if (tim==(*it)->getTim2 ())
                    {
                        if (tim==(*it)->getTim2 ())
                        {
                            (*it)->ispistekme();
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
                        pronadjen=true;
                    }
                }
            }
            for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
            {
                if (tim==(*it)->getTim2 ()){
                Utakmica u1 ((*it)->getId(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGodina(), (*it)->getTim1(), (*it)->getTim2(), (*it)->getBrpoen1(), (*it)->getBrpoen2(), (*it)->getProd());
                cout << u1 << endl;
                fajl << u1 << endl;}
            }
            cout << tim << endl;
            cout << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
            fajl << tim << endl;
            fajl << "Pobede: " << pob << " /Pobede nakon prod: " << pobp << " /Porazi: " << por << " /Porazi nakon prod: " << porp << endl << endl;
            fajl.close ();

            ///uspehtimdonekogkola(tim, a);
            if (!pronadjen)
            {
                cout<<"Nema takve utakmice!"<<endl;
                fajl << "Nema takve utakmice!"<<endl;
                fajl.close ();
            }
        }
    }
    void dodajtim (Tim* timm)
    {
        timoviregdeo.push_back (timm);
    }
    void ispistimova ()
    {
        for (auto it=timoviregdeo.begin(); it<timoviregdeo.end(); it++)
        {
            (*it)->ispisiInfoTim();
        }
    }
    void pretrazipoid(int ide, char mode='a')
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
        for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
        {
            if (ide==(*it)->getId())
            {
                (*it)->ispistekme();
                pronadjen=true;
                fajl << (*it)->getDan() << "." << (*it)->getMesec() << "." << (*it)->getGodina() << ". " << (*it)->getTim1() << " " << (*it)->getBrpoen1() << " " << (*it)->getTim2() << " " << (*it)->getBrpoen2() << endl;
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
    void pretrazipotim(string tim, char mode='a')
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
        for (auto it=svetekmicee.begin(); it<svetekmicee.end(); it++)
        {
            if (tim==(*it)->getTim1() || tim==(*it)->getTim2())
            {
                (*it)->ispistekme();
                pronadjen=true;
                Utakmica u1 ((*it)->getId(), (*it)->getDan(), (*it)->getMesec(), (*it)->getGodina(), (*it)->getTim1(), (*it)->getTim2(), (*it)->getBrpoen1(), (*it)->getBrpoen2(), (*it)->getProd());
                fajl << u1 << endl;
                ///fajl << (*it)->getDan() << "." << (*it)->getMesec() << "." << (*it)->getGodina() << ". " << (*it)->getTim1() << " " << (*it)->getBrpoen1() << " " << (*it)->getTim2() << " " << (*it)->getBrpoen2() << endl;
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

#endif // REGULARNIDEO_HPP_INCLUDED
