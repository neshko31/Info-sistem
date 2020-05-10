#ifndef UTAKMICA_HPP_INCLUDED
#define UTAKMICA_HPP_INCLUDED

#include "datum.hpp"
#include "tim.hpp"

///broj koristimo samo kao numeraciju da se zna koju tekmu on treba da gleda u fajlu, zapravo ne treba ovo
///ako ne valja ova ideja slobodno odgovorite :)

class Utakmica
{
private:
    Datum dati;
    Tim tiim1;
    Tim tiim2;
    int brpojen1;
    int brpojen2;
    bool prod;
public:
    Utakmica ():dati(1, 1, 1),tiim1(), tiim2(), brpojen1(15), brpojen2(20), prod(false) {};
    friend ostream& operator<<(ostream& izlaz, const Utakmica& ut)
    {
        izlaz << ut.dati << endl;
        izlaz << "Domaci/Gosti: " << ut.tiim1.nazivtima << "/" << ut.tiim2.nazivtima << endl;
        izlaz << "Rezultat: " << ut.brpojen1 << ":" << ut.brpojen2 << endl;
        if (ut.prod==true)
        {
            izlaz << "produzeci" << endl;
        }
        return izlaz;
    }


};
/*
///ovde samo nesto za ispis utakmice
    ///za info o tekmi
    friend void ispisUtakmica (const Utakmica &ut);
void ispisUtakmica (const Utakmica &ut)
{
    cout << "Datum igranja" ;
///    ispisDatuma (ut.dati);
    cout << endl;
    ispisNazivaTima(ut.tiim1);
    cout << " " ;
    cout << endl;
    cout << ut.brpojen1;
    ispisNazivaTima(ut.tiim2);
    cout << " " ;
    cout << ut.brpojen2;
    cout << endl;
    cout << ut.prod << endl;
    if (ut.brpojen1>ut.brpojen2)
    {
        cout << "Pobednik: ";
        ispisNazivaTima(ut.tiim1);
    }
    else{
    cout << "Pobednik: ";
        ispisNazivaTima(ut.tiim2);
    }
}*/
#endif // UTAKMICA_HPP_INCLUDED
