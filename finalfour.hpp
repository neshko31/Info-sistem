#ifndef FINALFOUR_HPP_INCLUDED
#define FINALFOUR_HPP_INCLUDED

#include "toposam.hpp"
#include "utakmica.hpp"

class FinalFour
{
private:
    Tim cetirkomada [4];
    Utakmica tekmice[3];
public:
    ///ovde su dva polu i jedno finale
    ///fakticki samo ispis za 3 tekme
    ///nista preterano bitno ali okej
    friend void ispisFinalFour (const FinalFour& ff);
};

void ispisFinalFour (const FinalFour& ff)
{
    int i;
    cout << "U ovosezonskom izdanju Final Four igrace: ";
    for (i=0; i<4; i++)
    {
        ispisNazivaTima(ff.cetirkomada[i]);
    }
    i=0;
    cout << "Prvo polufinale: Final Four " << endl;
    ispisUtakmica (ff.tekmice[i]);

    cout << "Drugo polufinale Final four " << endl;
    ispisUtakmica(ff.tekmice[i++]);

    cout << "Finale: " << endl;
    ispisUtakmica(ff.tekmice[i++]);

}
#endif // FINALFOUR_HPP_INCLUDED
