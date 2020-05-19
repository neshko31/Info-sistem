#ifndef UTAKMICA_HPP_INCLUDED
#define UTAKMICA_HPP_INCLUDED

#include "datum.hpp"
#include "tim.hpp"

///broj koristimo samo kao numeraciju da se zna koju tekmu on treba da gleda u fajlu, zapravo ne treba ovo
///ako ne valja ova ideja slobodno odgovorite :)

class Utakmica
{
private:
    int id;
    int dan;
    int mesec;
    int godina;
    string tim1;
    string tim2;
    int brpojen1;
    int brpojen2;
    bool prod;
public:
    Utakmica (int id1, int d, int m, int g, string tim11, string tim22, int po1, int po2, bool pr)
    {
        id=id1;
        dan=d;
        mesec=m;
        godina=g;
        tim1=tim11;
        tim2=tim22;
        brpojen1=po1;
        brpojen2=po2;
        prod=pr;
    }
    friend ostream& operator<<(ostream& izlaz, const Utakmica& ut)
    {
        izlaz << ut.dan << "."<< ut.mesec<< "."<< ut.godina << endl;
        izlaz << "Domaci/Gosti: " << ut.tim1 << "/" << ut.tim2 << endl;
        izlaz << "Rezultat: " << ut.brpojen1 << ":" << ut.brpojen2 << endl;
        if (ut.prod==true)
        {
            izlaz << "produzeci" << endl;
        }
        return izlaz;
    }
    void ispistekme ()
    {
        cout << "Datum: " << dan << "." << mesec <<"." << godina << ". ";
        cout << tim1 << " " << brpojen1 << endl;
        cout << "                  " ;
        cout << tim2 << " " << brpojen2 << endl;
    }
    int getId ()
    {
        return id;
    }
    int getDan ()
    {
        return dan;
    }
    int getMesec ()
    {
        return mesec;
    }
    int getGodina ()
    {
        return godina;
    }
    string getTim1 ()
    {
        return tim1;
    }
    string getTim2 ()
    {
        return tim2;
    }
    int getBrpoen1 ()
    {
        return brpojen1;
    }
    int getBrpoen2 ()
    {
        return brpojen2;
    }
    bool getProd ()
    {
        return prod;
    }
};

#endif // UTAKMICA_HPP_INCLUDED
