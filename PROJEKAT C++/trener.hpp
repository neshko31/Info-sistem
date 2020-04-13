#ifndef TRENER_HPP_INCLUDED
#define TRENER_HPP_INCLUDED

#include "datum.hpp"
#include "mesto.hpp"

class Trener
{
private:
    string ime;
    string prezime;
    Datum dat;
    Mesto mestasce;
public:
    Trener (string imq="Nenad", string prezq="Lukic", int d2q=1, int m2q=1, int g2q=1, string drq="da", string naq="dada") : ime(imq), prezime(prezq), dat (d2q, m2q, g2q), mestasce(drq, naq) {};
    string getImeTr ()const
    {
        return ime;
    }
    string getPrezimeTr ()const
    {
        return prezime;
    }
    int getDanTr ()const
    {
        return dat.getDan();
    }
    int getMesecTr ()const
    {
        return dat.getMesec();
    }
    int getGodinaTr ()const
    {
        return dat.getGodina();
    }
    string getDrzavaTr ()const
    {
        return mestasce.getDrzava();
    }
    string getNazivMestaTr ()const
    {
        return mestasce.getNazivmesto();
    }
    void setImeTr (string im)
    {
        ime=im;
    }
    void setPrezimeTr (string pr)
    {
        prezime=pr;
    }
    void setDanTr (int dw)
    {
        dat.setD(dw);
    }
    void setMesecTr (int mw)
    {
        dat.setM(mw);
    }
    void setGodinaTr (int gw)
    {
        dat.setG(gw);
    }
    void setDrzavaTr (string d3)
    {
        mestasce.setD(d3);
    }
    void setNazivmestoTr (string n3)
    {
        mestasce.setN(n3);
    }
    friend void ispisTrenera (const Trener &t);
};

void ispisTrenera (const Trener &t)
{
    cout << "Ime: " << t.ime << endl << "Prezime: " << t.prezime << endl;
    cout << "Datum rodjenja: ";
    ispisDatuma(t.dat);
    cout << "Drzava i mesto rodjenja: ";
    ispisMesto(t.mestasce);
}

#endif // TRENER_HPP_INCLUDED
