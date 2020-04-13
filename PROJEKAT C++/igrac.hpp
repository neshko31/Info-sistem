#ifndef IGRAC_HPP_INCLUDED
#define IGRAC_HPP_INCLUDED

#include "mesto.hpp"
#include "datum.hpp"

class Igrac
{
private:
    string ime;
    string prezime;
    int dres;
    Datum dat;
    Mesto mestasc;
public:
    Igrac (string im="Nenad", string prez="Lukic", int dr2=31, int d2=1, int m2=1, int g2=1, string dr="da", string na="dada") : ime(im), prezime(prez), dres(dr2), dat (d2, m2, g2), mestasc(dr, na) {};
    string getImeIgr ()const
    {
        return ime;
    }
    string getPrezimeIgr ()const
    {
        return prezime;
    }
    int getDresIgr ()const
    {
        return dres;
    }
    int getDanIgrac ()const
    {
        return dat.getDan();
    }
    int getMesecIgrac ()const
    {
        return dat.getMesec();
    }
    int getGodinaIgrac ()const
    {
        return dat.getGodina();
    }
    string getDrzavaIgrac ()const
    {
        return mestasc.getDrzava();
    }
    string getNazivMestaIgrac ()const
    {
        return mestasc.getNazivmesto();
    }
    void setImeIgr (string im)
    {
        ime=im;
    }
    void setPrezimeIgr (string pr)
    {
        prezime=pr;
    }
    void setDresIgr (int d33)
    {
        dres=d33;
    }
    void setDanIgr (int dw)
    {
        dat.setD(dw);
    }
    void setMesecIgr (int mw)
    {
        dat.setM(mw);
    }
    void setGodinaIgr (int gw)
    {
        dat.setG(gw);
    }
    void setDrzavaIgr (string d3)
    {
        mestasc.setD(d3);
    }
    void setNazivmestoIgr (string n3)
    {
        mestasc.setN(n3);
    }
    friend void ispisIgraca (const Igrac &i);
};

void ispisIgraca (const Igrac &i)
{
    cout << "Ime: " << i.ime << endl << "Prezime: " << i.prezime << endl << "Broj na dresu: " << i.dres << endl;
    cout << "Datum rodjenja: ";
    ispisDatuma(i.dat);
    cout << "Drzava i mesto rodjenja: ";
    ispisMesto(i.mestasc);
}

#endif // IGRAC_HPP_INCLUDED
