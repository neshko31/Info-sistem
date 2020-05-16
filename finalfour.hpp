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
            izlaz <<  ff.cetirkomada[i].nazivtima;
        }
        for (i=0; i<2; i++)
        {
            izlaz << "Polufinale broj " << i << endl;
            izlaz << ff.tekmice[i];
        }
        i++;
        izlaz << "Finale" << endl;
        izlaz << ff.tekmice[i];

	i++;
	izlaz << "Trece mesto" << endl;
	izlaz << ff.tekmice[i];
        return izlaz;
    }

};


#endif // FINALFOUR_HPP_INCLUDED
