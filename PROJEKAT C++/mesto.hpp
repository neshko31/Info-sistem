#ifndef MESTO_HPP_INCLUDED
#define MESTO_HPP_INCLUDED

class Mesto
{
private:
    string drzava;
    string naziv;
public:
    Mesto (string drz="evropa", string naz="grad u evropi")
    {
        drzava=drz;
        naziv=naz;
    }
    string getDrzava ()const
    {
        return drzava;
    }
    string getNazivmesto ()const
    {
        return naziv;
    }
    void setD (string drz1)
    {
        drzava=drz1;
    }
    void setN (string naz1)
    {
        naziv=naz1;
    }
    friend void ispisMesto (const Mesto &mestice);
};

void ispisMesto (const Mesto &mestice)
{
    cout << mestice.drzava << ", "<< mestice.naziv << endl;
}

#endif // MESTO_HPP_INCLUDED
