#ifndef FINALFOUR_HPP_INCLUDED
#define FINALFOUR_HPP_INCLUDED

#include "toposam.hpp"
#include "utakmica.hpp"
#include "arena.hpp"

class FinalFour
{
private:
    Tim cetirkomada [4];
    Utakmica tekmice[3];
    Arena aren;
public:
    ///ovde su dva polu i jedno finale
    ///fakticki samo ispis za 3 tekme
    ///nista preterano bitno ali okej
    friend ostream& operator<<(ostream& izlaz, const FinalFour& ff)
    {
        int i=0;
        izlaz << "Timovi ucesnici: "<<endl;
        for (i=0; i<4; i++)
        {
            cout <<  ff.cetirkomada[i].nazivtima;
        }
        for (i=0; i<2; i++)
        {
            izlaz << "Polufinale broj " << i << endl;
            cout << ff.tekmice[i];
        }
        i++;
        izlaz << "Finale" << endl;
        cout << ff.tekmice[i];
        return izlaz;
    }
    friend void ispisFinalFour (const FinalFour& ff);
};

void ispisFinalFour (const FinalFour& ff)
{
    int i;
    cout << "Utakmice se igraju u: " << endl;
///    ispisArena(ff.aren);
    cout << "U ovosezonskom izdanju Final Four igrace: ";
    for (i=0; i<4; i++)
    {
        ispisNazivaTima(ff.cetirkomada[i]);
    }
    i=0;
    cout << "Prvo polufinale: Final Four " << endl;
///    ispisUtakmica (ff.tekmice[i]);

    cout << "Drugo polufinale Final four " << endl;
   /// ispisUtakmica(ff.tekmice[i++]);

    cout << "Finale: " << endl;
 ///   ispisUtakmica(ff.tekmice[i++]);

}
#endif // FINALFOUR_HPP_INCLUDED
