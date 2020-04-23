#ifndef UTAKMICA_HPP_INCLUDED
#define UTAKMICA_HPP_INCLUDED

#include "datum.hpp"
#include "tim.hpp"

///broj koristimo samo kao numeraciju da se zna koju tekmu on treba da gleda u fajlu, zapravo ne treba ovo
///ako ne valja ova ideja slobodno odgovorite :)

class Utakmica
{
private:
    Tim tiim1;
    Tim tiim2;
    Datum dati;
    int brpojen1;
    int brpojen2;
public:
    ///ovde samo nesto za ispis utakmice
    ///za info o tekmi
    friend void ispisUtakmica (const Utakmica &ut);
};

void ispisUtakmica (const Utakmica &ut)
{
    cout << "Datum igranja" ;
    ispisDatuma (ut.dati);
    cout << endl;
    ispisNazivaTima(ut.tiim1);
    cout << " " ;
    cout << endl;
    cout << ut.brpojen1;
    ispisNazivaTima(ut.tiim2);
    cout << " " ;
    cout << ut.brpojen2;
    cout << endl;
    if (ut.brpojen1>ut.brpojen2)
    {
        cout << "Pobednik: ";
        ispisNazivaTima(ut.tiim1);
    }
    else{
    cout << "Pobednik: ";
        ispisNazivaTima(ut.tiim2);
    }
}
#endif // UTAKMICA_HPP_INCLUDED
