#include <iostream>

using namespace std;

#include "datum.hpp"
#include "mesto.hpp"
#include "arena.hpp"
#include "igrac.hpp"
#include "tim.hpp"
#include "trener.hpp"
#include "tabela.hpp"
#include "kolo.hpp"
#include "utakmica.hpp"
#include "gradodrzavanja.hpp"
#include "regularnideo.hpp"
#include "toposam.hpp"
#include "finalfour.hpp"
#include "sezona.hpp"


int main()
{
    Datum d231;
    ispisDatuma(d231);

    Mesto m1223;
    ispisMesto(m1223);

    Igrac igr1;
    ispisIgraca(igr1);

    Trener tr;
    ispisTrenera(tr);

    Arena ar2;
    ispisArena(ar2);
    return 0;
}
