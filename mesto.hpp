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
    friend void ispisMesto (const Mesto &mestice);
};

void ispisMesto (const Mesto &mestice)
{
    cout << mestice.drzava << ", "<< mestice.naziv << endl;
}

#endif // MESTO_HPP_INCLUDED
