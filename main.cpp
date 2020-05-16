#include <iostream>
#include <fstream>
#include <vector>

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
void pretragatekmi (int ca, string sez)
{
    int ca1=0;
    do
    {
        cout << "Izbor delova sezone" << endl;
        cout << "Odabrana sezona je: " << sez << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Pretraga po nazivu tima" << endl;
        cout << "Opcija 2: Pretraga po ID-u tima" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> ca1;
        switch  (ca1)
        {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
        }
    }
    while (ca1!=0);
}
void menibudzet (int bu, string sez)
{
    string budzetf;
    do
    {
        cout << "Informacije o budzetu" << endl;
        cout << "Odabrana sezona je: " << sez << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Povecaj budzet" << endl;
        cout << "Opcija 2: Smanji budzet" << endl;
        cout << "Opcija 3: Ispisi stanje budzeta" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> bu;
        switch  (bu)
        {
        case 1:
            cout << "Izabrana opcija je povecavanje budzeta" << endl;
            cout << "Unesite iznos u evrima: ";
            int er;
            cin >> er;
            if (sez=="18/19")
            {
                budzetf="budzet 18.19.txt";
                Tim::povecajBudzet(er, budzetf);
            }
            break;
        case 2:
            cout << "Izabrana opcija je smanjivanje budzeta" << endl;
            cout << "Unesite iznos u evrima: ";
            int em;
            cin >> em;
            if (sez=="18/19")
            {
                budzetf="budzet 18.19.txt";
                Tim::smanjiBudzet(em, budzetf);
            }
            break;
        case 3:
            cout << "Trenutno stanje budzeta iznosi: " << endl;
            Tim::citajBudzetFajl("budzet 18.19.txt");
            break;
        default:
            break;
        }
    }
    while (bu!=0);
}
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
///            citajtimoveucesnike(nasFajl);
            cout << "Unesi zeljenu opciju: ";
            cin >> e;
            switch  (e)
            {
            case 1:
                nasFajl = "fenerbahce 18.19.txt";
///                citajtimfajl(nasFajl);
                break;
            case 2:
                nasFajl = "cska moskva 18.19.txt";
      ///          citajtimfajl(nasFajl);
                break;
            case 3:
                nasFajl = "real madrid 18.19.txt";
        ///        citajtimfajl(nasFajl);
                break;
            case 4:
                nasFajl = "anadolu efes 18.19.txt";
          //      citajtimfajl(nasFajl);
                break;
            case 5:
                nasFajl = "barcelona 18.19.txt";
            //    citajtimfajl(nasFajl);
                break;
            case 6:
                nasFajl = "panathinaikos 18.19.txt";
             //   citajtimfajl(nasFajl);
                break;
            case 7:
                nasFajl = "baskonia 18.19.txt";
              //  citajtimfajl(nasFajl);
                break;
            case 8:
                nasFajl = "zalgiris 18.19.txt";
              //  citajtimfajl(nasFajl);
                break;
            case 9:
                nasFajl = "olympiakos 18.19.txt";
               // citajtimfajl(nasFajl);
                break;
            case 10:
                nasFajl = "maccabi tel aviv 18.19.txt";
               // citajtimfajl(nasFajl);
                break;
            case 11:
                nasFajl = "bayern 18.19.txt";
               // citajtimfajl(nasFajl);
                break;
            case 12:
                nasFajl = "olimpia milano 18.19.txt";
                //citajtimfajl(nasFajl);
                break;
            case 13:
                nasFajl = "khimki 18.19.txt";
               // citajtimfajl(nasFajl);
                break;
            case 14:
                nasFajl = "gran canaria 18.19.txt";
                //citajtimfajl(nasFajl);
                break;
            case 15:
                nasFajl = "buducnost 18.19.txt";
                //citajtimfajl(nasFajl);
                break;
            case 16:
                nasFajl = "darussafaka 18.19.txt";
                //citajtimfajl(nasFajl);
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
     ///           citajregdeokola(nasFajl);
            }
            break;
        case 2:
            if (sez=="18/19")
            {
                nasFajl = "regdeo 18.18.txt";
              ///  citajregdeokolatabela(nasFajl);
            }
            break;
        case 3:
            if (sez=="18/19")
            {
                nasFajl = "tabela 18.19.txt";
///                citajregdeotabela(nasFajl);
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
    int bu1=0;
    do
    {
        cout << "Izbor delova sezone" << endl;
        cout << "Odabrana sezona je: " << sez << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Regularni deo" << endl;
        cout << "Opcija 2: Top 8" << endl;
        cout << "Opcija 3: Final Four" << endl;
        cout << "Opcija 4: Timovi ucesnici" << endl;
        cout << "Opcija 5: Budzet svih timova" << endl;
        cout << "Opcija 6: Pretraga utakmica" << endl;
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
        case 5:
            menibudzet(bu1, sez);
            break;
        case 6:
            pretragatekmi(c, sez);
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
    ///evo jednog kola, prvih 5 ide u fajlove
    ///samo da naglasim, nijedno kolo ne ide u fajlove sve ce biti u mainu

    ///utakmice final foura i plejofa ce najverovatnije biti u fajlovima
    Kolo k1(1);
    Utakmica u1(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u2(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u3(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u4(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u5(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u6(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u7(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u8(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k1.dodajtekmu(&u1);
    k1.dodajtekmu(&u2);
    k1.dodajtekmu(&u3);
    k1.dodajtekmu(&u4);
    k1.dodajtekmu(&u5);
    k1.dodajtekmu(&u6);
    k1.dodajtekmu(&u7);
    k1.dodajtekmu(&u8);

    k1.ispisiKola();

    Kolo k2(2);
    Utakmica u9(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u10(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u11(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u12(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u13(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u14(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u15(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u16(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k2.dodajtekmu(&u9);
    k2.dodajtekmu(&u10);
    k2.dodajtekmu(&u11);
    k2.dodajtekmu(&u12);
    k2.dodajtekmu(&u13);
    k2.dodajtekmu(&u14);
    k2.dodajtekmu(&u15);
    k2.dodajtekmu(&u16);

    k2.ispisiKola();

    Kolo k3(3);
    Utakmica u17(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u18(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u19(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u20(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u21(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u22(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u23(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u24(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k3.dodajtekmu(&u17);
    k3.dodajtekmu(&u18);
    k3.dodajtekmu(&u19);
    k3.dodajtekmu(&u20);
    k3.dodajtekmu(&u21);
    k3.dodajtekmu(&u22);
    k3.dodajtekmu(&u23);
    k3.dodajtekmu(&u24);

    k3.ispisiKola();

    Kolo k4(4);
    Utakmica u25(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u26(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u27(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u28(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u29(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u30(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u31(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u32(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k4.dodajtekmu(&u25);
    k4.dodajtekmu(&u26);
    k4.dodajtekmu(&u27);
    k4.dodajtekmu(&u28);
    k4.dodajtekmu(&u29);
    k4.dodajtekmu(&u30);
    k4.dodajtekmu(&u31);
    k4.dodajtekmu(&u32);

    k4.ispisiKola();

    Kolo k5(5);
    Utakmica u33(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u34(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u35(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u36(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u37(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u38(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u39(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u40(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k5.dodajtekmu(&u33);
    k5.dodajtekmu(&u34);
    k5.dodajtekmu(&u35);
    k5.dodajtekmu(&u36);
    k5.dodajtekmu(&u37);
    k5.dodajtekmu(&u38);
    k5.dodajtekmu(&u39);
    k5.dodajtekmu(&u40);

    k5.ispisiKola();

    Kolo k6(6);
    Utakmica u41(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u42(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u43(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u44(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u45(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u46(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u47(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u48(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k6.dodajtekmu(&u41);
    k6.dodajtekmu(&u42);
    k6.dodajtekmu(&u43);
    k6.dodajtekmu(&u44);
    k6.dodajtekmu(&u45);
    k6.dodajtekmu(&u46);
    k6.dodajtekmu(&u47);
    k6.dodajtekmu(&u48);

    k6.ispisiKola();

    cout << "LAKAKAKAKA" << endl;
    k6.pretrazipoid(41);
    k6.pretrazipotim("Bayern");
    return 0;
}
