#include <iostream>
#include <fstream>

///ideju za funkcionalnost cu da objasnim da li imam ovim high quality memom
///Well yes, but actually no.

///sprovedene metode:
///plate igraca, prosecna starost, prosecna visina po timovima,
///najbolji igrac u svakom timu

///ideje koje imam za sad:
///sortovi po visini u timovima i godinama
///nakon toga najbolji igrac tog dela sezone, za regularni deo i final four

///tabela na svakih nekoliko kola, u ovom slucaju 5 kola
///tabela koja pokazuje kako se koji tim pokazao kao domacin, a kako kao gost
///za info o igracu, ako korisnik unes ime i prezime igraca kao i tim da mu program nadje tog igraca i ispise ostale stvari o njemu

///kod izgleda veliko od ovih komentara
///imamo meni koji je potrebno jos malo doraditi
///imamo ispise za klasu tabela i za regularni deo

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
#include "regularnideo.hpp"
#include "toposam.hpp"
#include "finalfour.hpp"
#include "sezona.hpp"


void menitimovi (int e, string sez)
{
    string nasFajl;
    if (sez=="18/19")
    {
        do
        {
            cout << "Timovi uscesnici" << endl;
            cout << "Sezona: " << sez << endl;
            cout << "-------------------------" << endl;
            nasFajl = "timoviucesnici 18.19.txt";
            citajtimoveucesnike(nasFajl);
            cout << "Unesi zeljenu opciju: ";
            cin >> e;
            switch  (e)
            {
            case 1:
                nasFajl = "fenerbahce 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 2:
                nasFajl = "cska moskva 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 3:
                nasFajl = "real madrid 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 4:
                nasFajl = "anadolu efes 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 5:
                nasFajl = "barcelona 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 6:
                nasFajl = "panathinaikos 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 7:
                nasFajl = "baskonia 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 8:
                nasFajl = "zalgiris 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 9:
                nasFajl = "olympiakos 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 10:
                nasFajl = "maccabi tel aviv 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 11:
                nasFajl = "bayern 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 12:
                nasFajl = "olimpia milano 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 13:
                nasFajl = "khimki 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 14:
                nasFajl = "gran canaria 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 15:
                nasFajl = "buducnost 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            case 16:
                nasFajl = "darussafaka 18.19.txt";
                citajtimfajl(nasFajl);
                break;
            default:
                break;
            }
        }
        while (e!=0);
    }
}
void regdeo (int d, string sez)
{
    string nasFajl;
    do
    {
        cout << "Regularni deo" << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Kola" << endl;
        cout << "Opcija 2: Kola+Tabela" << endl;
        cout << "Opcija 3: Tabela" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> d;
        switch  (d)
        {
        case 1:
            ///ako nekad bude zatrebalo ako bude vise sezona
            if (sez=="18/19")
            {
                nasFajl = "kola 18.19.txt";
                citajregdeokola(nasFajl);
            }
            break;
        case 2:
            if (sez=="18/19")
            {
                nasFajl = "regdeo 18.18.txt";
                citajregdeokolatabela(nasFajl);
            }
            break;
        case 3:
            if (sez=="18/19")
            {
                nasFajl = "tabela 18.19.txt";
                citajregdeotabela(nasFajl);
            }
            break;
        default:
            break;
        }
    }
    while (d!=0);
}
void menideotakmicenja (int c, string sez)
{
    do
    {
        cout << "Izbor delova sezone" << endl;
        cout << "Odabrana sezona je: " << sez << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Regularni deo" << endl;
        cout << "Opcija 2: Top 8" << endl;
        cout << "Opcija 3: Final Four" << endl;
        cout << "Opcija 4: Timovi ucesnici" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> c;
        switch  (c)
        {
        case 1:
            regdeo(c, sez);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menitimovi(c, sez);
            break;
        default:
            break;
        }
    }
    while (c!=0);
}
void menisezone(int b)
{
    string sez;
    do
    {
        cout << "Izbor sezona Evroliga" << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Sezona 2018/19" << endl;
        cout << "Opcija 2: Ovde su kao druge neke sezone" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> b;
        switch  (b)
        {
        case 1:
            sez="18/19";
            menideotakmicenja(b, sez);
            break;
        case 2:
            break;
        default:
            break;
        }
    }
    while (b!=0);
}
void menizapocetak (int a)
{
    string i, p;
    do
    {
        cout << "Info sistem Evroliga" << endl;
        cout << "-------------------------" << endl;
        cout << endl;
        cout << "Opcija 1: Sezone" << endl;
        cout << "Opcija 2: Istorija Evrolige" << endl;
        cout << "Opcija 3: Pronadji igraca" << endl;
        cout << "Opcija 0: Izlaz" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> a;
        switch  (a)
        {
        case 1:
            menisezone(a);
            break;
        case 2:
            cout << "Evroliga ..." << endl;
            break;
        case 3:
            cout << "Unesi ime igraca: ";
            cin >> i;
            cout << "Unesi prezime igraca: ";
            cin >> p;
            ///ovo ce pretrazivati po jednom fajlu
            ///kako bi nasao igraca, kul i super
            break;
        default:
            cout << "Sportski pozdrav!";
            break;
        }
    }
    while (a!=0);
}
int main()
{
    int a=0;
    menizapocetak(a);
    return 0;
}
