#ifndef TIMUCINAK_HPP_INCLUDED
#define TIMUCINAK_HPP_INCLUDED

///ovo koristimo za tim kao nasledjivanje

class TimUcinak
{
protected:
    int pobede;
    int pobedeprod;
    int porazi;
    int poraziprod;
    int bodovi;
    int poenidati;
    int poeniprimljeni;
public:
    TimUcinak (int p1, int p2, int p3, int p4, int b, int pd, int pp)
    {
        pobede=p1;
        pobedeprod=p2;
        porazi=p3;
        porazi=p4;
        bodovi=b;
        poenidati=pd;
        poeniprimljeni=pp;
    }
        void ispisiInfoTim()
    {
        cout << "Pobede: " << pobede << " /Pobede: " << pobedeprod << endl;
        cout << "Pobede: " << porazi << " /Pobede: " << poraziprod << endl;
        cout << "Bodovi u ovoj sezoni: " << bodovi << endl;
        cout << "Dati poeni: " << poenidati << " /Poeni primljeni: " << poeniprimljeni << endl;
    }
};

#endif // TIMUCINAK_HPP_INCLUDED
