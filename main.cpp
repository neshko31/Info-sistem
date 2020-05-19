#include <iostream>
#include <fstream>
#include <vector>

///ideju za funkcionalnost cu da objasnim da li imam ovim high quality memom
///Well yes, but actually no.

///sprovedene metode:
///   TIM   plate igraca, prosecna starost, prosecna visina po timovima, najvisi igrac, najbolji igrac u svakom timu, sort po godinama, sort po visini
///   REGDEO   uspesi timova na 5, 10, 15, 25 i 30 utakmica, malo specifican nacin upotrebe, unosi se broj do poslednje utakmice zeljenog kola +1

///metode koje ce biti kao napravljene, a zapravo nece biti
///tabela na svakih nekoliko kola, u ovom slucaju 5 kola, samo se pozove

///u fazi sprovodjenja:
///   REGDEO   ispis za svaki tim kao domacin ili kao gost kako su igrali

///ideje koje imam za sad:
///za info o igracu, ako korisnik unes ime i prezime igraca kao i tim da mu program nadje tog igraca i ispise ostale stvari o njemu, ako budem imao vremena

///metode koje nisu sprovedene:
///nakon toga najbolji igrac tog dela sezone, za regularni deo i final four
///tabela koja pokazuje kako se koji tim pokazao kao domacin, a kako kao gost

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
void citajtabela(string tabela)
{
    string linija;
    ifstream fajl (tabela);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << linija << '\n';
        }
        fajl.close();
    }
}
void ispisimenikolo (Kolo k1)
{
    k1.ispisiKola();
}
void citajtimoveucesnike(string timo)
{
    int i=1;
    string linija;
    ifstream fajl (timo);
    if (fajl.is_open())
    {
        while ( getline (fajl,linija) )
        {
            cout << "Opcija " << i << ": ";
            cout << linija << '\n';
            i++;
        }
        fajl.close();
    }

    else
        cout << "Neuspesno otvoren fajl";

}
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
    Tim fenerbahce (25, 0, 2, 3, 50, 2504, 2237, "Fenerbahce", 1, 1, 1913, "Ulker Sports Arena", "Turska", "Istanbul", 13059, "Zeljko", "Obradovic", 9, 3, 1960, "SFRJ", "Cacak", 2500000);
    /*Igrac i1 (Tyler, Ennis, 11, 189, plejmejker, 24.8.1994., SAD, Brampton);
    Igrac i2 (Marko, Guduric, 23, 196, bek, 8.3.1995., SRJ, Priboj);
    Igrac i3 (Luigi, Datome, 70, 202, krilo, 27.11.1987., Italija, Montebelluna);
    Igrac i4 (Nikola, Kalinic, 12, 202, krilni_centar, 8.11.1991., SFRJ, /);
    Igrac i5 (Jan, Vesely, 24, 213, centar, 24.4.1990., Ceska, Ostrava);*/

    Tim cska (23, 1, 0, 6, 46, 2590, 2397, "CSKA Moskva", 23, 4, 1923, "Aleksandar Gomelski - Univerazlna sportska hala CSKA","Rusija", "Moskva", 5500, "Dimitros", "Itoudis", 8, 9, 1970, "Grcka", "Trikala", 2780000);
    /*Igrac i6 (Nando De Colo, 18, 196,plejmejker, 23.6.1987., Francuska, Bapaume);
    Igrac i7 (Sergio, Rodriguez, 13, 190, bek, 12.6.1986., Spanija, Sta. Cruz de Tenerife);
    Igrac i8 (Nikita, Kurbanov, 41, 202, krilo, 5.10.1986., Rusija, );
    Igrac i9 (Andrei, Vorontsevich, 20, 207, krilni_centar, 17.6.1987., Rusija, Omsk);
    Igrac i10 (Alec, Peters, 5, 206, centar, 13.4.1995., SAD, );*/

    Tim realmadrid (22, 0, 0, 8, 44, 2578, 2342, "Real Madrid", 8, 3, 1931, "WiZink Centar", "Spanija", "Madrid", 15000, "Pablo", "Laso", 13, 10, 1967, "Spanija", "Vitoria-Gastez", 3321000);
    /*Igrac i11 ();
    Igrac i12 ();
    Igrac i13 ();
    Igrac i14 ();
    Igrac i15 ();*/

    Tim anadoluefes (20, 0, 0, 10, 40, 2562, 2406, "Anadolu Efes", 1, 1, 1976, "Sinan Erdem Arena", "Turska", "Istanbul", 16000, "Ergin", "Ataman", 7, 1, 1966, "Turska", "Istanbul", 2010000);
    /*Igrac i16 ();
    Igrac i17 ();
    Igrac i18 ();
    Igrac i19 ();
    Igrac i20 ();*/

///    Tim barcelona (17, 1, 12, 0, 34, 2358, 2282, );
    /*Igrac i21 ();
    Igrac i22 ();
    Igrac i23 ();
    Igrac i24 ();
    Igrac i25 ();*/
///    Tim panathinaikos (16, 0, 13, 1, 32, 2382, 2345, );
    /*Igrac i26 ();
    Igrac i27 ();
    Igrac i28 ();
    Igrac i29 ();
    Igrac i30 ();*/

///    Tim baskonia (15, 0, 14, 1, 30, 2449, 2378, );
    /*Igrac i31 ();
    Igrac i32 ();
    Igrac i33 ();
    Igrac i34 ();
    Igrac i35 ();
    */

///    Tim zalgiriskaunas (14, 1, 13, 2, 28, 2360, 2323, );
    /*Igrac i36 ();
    Igrac i37 ();
    Igrac i38 ();
    Igrac i39 ();
    Igrac i40 ();
    */

///    Tim olympiacos (14, 1, 15, 0, 28, 2326, 2301, );
    /*Igrac i41 ();
    Igrac i42 ();
    Igrac i43 ();
    Igrac i44 ();
    Igrac i45 ();*/

///   Tim maccabitelaviv (14, 0, 16, 0, 28, 2376, 2346, );
    /*Igrac i46 ();
    Igrac i47 ();
    Igrac i48 ();
    Igrac i49 ();
    Igrac i50 ();*/

///   Tim bayern (13, 1, 16, 0, 26, 2348, 2404, );
    /*Igrac i51 ();
    Igrac i52 ();
    Igrac i53 ();
    Igrac i54 ();
    Igrac i55 ();*/

    ///  Tim olimpiamilano (13, 1, 16, 0, 26, 2601, 2600, );
    /*Igrac i56 ();
    Igrac i57 ();
    Igrac i58 ();
    Igrac i59 ();
    Igrac i60 ();*/

    /// Tim khimki (8, 1, 21, 0, 16, 2333, 2449, );
    /*Igrac i61 ();
    Igrac i62 ();
    Igrac i63 ();
    Igrac i64 ();
    Igrac i65 ();*/

///    Tim grancanaria (8, 0, 21, 1, 16, 2317, 2616, );
    /*Igrac i66 ();
    Igrac i67 ();
    Igrac i68 ();
    Igrac i69 ();
    Igrac i70 ();*/

    ///  Tim buducnost (6, 0, 24, 0, 12, 2230, 2550, );
    /*Igrac i71 ();
    Igrac i72 ();
    Igrac i73 ();
    Igrac i74 ();
    Igrac i75 ();*/

///   Tim darussafaka (5, 0, 25, 0, 10, 2238, 2576, );
    /*Igrac i76 ();
    Igrac i77 ();
    Igrac i78 ();
    Igrac i79 ();
    Igrac i80 ();*/

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
                fenerbahce.ispisiInfoTim();
                break;
            case 2:
                cska.ispisiInfoTim();
                break;
            case 3:
                realmadrid.ispisiInfoTim();
                break;
            case 4:
                anadoluefes.ispisiInfoTim();
                break;
            case 5:
                nasFajl = "barcelona 18.19.txt";
                break;
            case 6:
                nasFajl = "panathinaikos 18.19.txt";
                break;
            case 7:
                nasFajl = "baskonia 18.19.txt";
                break;
            case 8:
                nasFajl = "zalgiris 18.19.txt";
                break;
            case 9:
                nasFajl = "olympiakos 18.19.txt";
                break;
            case 10:
                nasFajl = "maccabi tel aviv 18.19.txt";
                break;
            case 11:
                nasFajl = "bayern 18.19.txt";
                break;
            case 12:
                nasFajl = "olimpia milano 18.19.txt";
                break;
            case 13:
                nasFajl = "khimki 18.19.txt";
                break;
            case 14:
                nasFajl = "gran canaria 18.19.txt";
                break;
            case 15:
                nasFajl = "buducnost 18.19.txt";
                break;
            case 16:
                nasFajl = "darussafaka 18.19.txt";
                break;
            default:
                break;
            }
        }
        while (e!=0);
    }
}
void meniplejof (int po, string sez)
{
    TopOsam tooo (8);
    ///Utakmica u1(1,12,10,2018,"Fenerbahce","GranCanaria",97,72,false);
    Utakmica u1 (1,1,05,2019,"Anadolu Efes","Barcelona",80,71,false);
    Utakmica u2 (2,26,4,2019,"Barcelona","Anadolu Efes",82,72,false);
    Utakmica u3 (3,26,4,2019,"Baskonia","CSKA Moscow",83,92,false);
    Utakmica u4 (4,25,4,2019,"Zalgiris Kaunas","Fenerbahce",82,99,false);
    Utakmica u5 (5,24,4,2019,"Barcelona","Anadolu Efes",68,102,false);
    Utakmica u6 (6,24,4,2019,"Baskonia","CSKA Moscow",77,84,false);
    Utakmica u7 (7,23,4,2019,"Panathinaikos","Real Madrid",82,89,false);
    Utakmica u8 (8,23,4,2019,"Zalgiris Kaunas","Fenerbahce",57,66,false);
    Utakmica u9 (9,19,4,2019,"Real Madrid","Panathinaikos",78,63,false);
    Utakmica u10 (10,19,4,2019,"Anadolu Efes","Barcelona",72,74,false);
    Utakmica u11 (11,18,4,2019,"Fenerbahce","Zalgiris Kaunas",80,82,false);
    Utakmica u12 (12,18,4,2019,"CSKA Moscow","Baskonia",68,78,false);
    Utakmica u13 (13,17,4,2019,"Real Madrid","Panathinaikos",75,72,false);
    Utakmica u14 (14,17,4,2019,"Anadolu Efes","Barcelona",75,68,false);
    Utakmica u15 (15,16,4,2019,"Fenerbahce","Zalgiris Kaunas",76,43,false);
    Utakmica u16 (16,16,4,2019,"CSKA Moscow","Baskonia",94,68,false);
    tooo.dodajtekme(&u1);
    tooo.dodajtekme(&u2);
    tooo.dodajtekme(&u3);
    tooo.dodajtekme(&u4);
    tooo.dodajtekme(&u5);
    tooo.dodajtekme(&u6);
    tooo.dodajtekme(&u7);
    tooo.dodajtekme(&u8);
    tooo.dodajtekme(&u9);
    tooo.dodajtekme(&u10);
    tooo.dodajtekme(&u11);
    tooo.dodajtekme(&u12);
    tooo.dodajtekme(&u13);
    tooo.dodajtekme(&u14);
    tooo.dodajtekme(&u15);
    tooo.dodajtekme(&u16);

    Tim fenerbahce (25, 0, 2, 3, 50, 2504, 2237, "Fenerbahce", 1, 1, 1913, "Ulker Sports Arena", "Turska", "Istanbul", 13059, "Zeljko", "Obradovic", 9, 3, 1960, "SFRJ", "Cacak", 2500000);
    /*Igrac i1 (Tyler, Ennis, 11, 189, plejmejker, 24.8.1994., SAD, Brampton);
    Igrac i2 (Marko, Guduric, 23, 196, bek, 8.3.1995., SRJ, Priboj);
    Igrac i3 (Luigi, Datome, 70, 202, krilo, 27.11.1987., Italija, Montebelluna);
    Igrac i4 (Nikola, Kalinic, 12, 202, krilni_centar, 8.11.1991., SFRJ, /);
    Igrac i5 (Jan, Vesely, 24, 213, centar, 24.4.1990., Ceska, Ostrava);*/

    Tim cska (23, 1, 0, 6, 46, 2590, 2397, "CSKA Moskva", 23, 4, 1923, "Aleksandar Gomelski - Univerazlna sportska hala CSKA","Rusija", "Moskva", 5500, "Dimitros", "Itoudis", 8, 9, 1970, "Grcka", "Trikala", 2780000);
    /*Igrac i6 (Nando De Colo, 18, 196,plejmejker, 23.6.1987., Francuska, Bapaume);
    Igrac i7 (Sergio, Rodriguez, 13, 190, bek, 12.6.1986., Spanija, Sta. Cruz de Tenerife);
    Igrac i8 (Nikita, Kurbanov, 41, 202, krilo, 5.10.1986., Rusija, );
    Igrac i9 (Andrei, Vorontsevich, 20, 207, krilni_centar, 17.6.1987., Rusija, Omsk);
    Igrac i10 (Alec, Peters, 5, 206, centar, 13.4.1995., SAD, );*/

    Tim realmadrid (22, 0, 0, 8, 44, 2578, 2342, "Real Madrid", 8, 3, 1931, "WiZink Centar", "Spanija", "Madrid", 15000, "Pablo", "Laso", 13, 10, 1967, "Spanija", "Vitoria-Gastez", 3321000);
    /*Igrac i11 ();
    Igrac i12 ();
    Igrac i13 ();
    Igrac i14 ();
    Igrac i15 ();*/

    Tim anadoluefes (20, 0, 0, 10, 40, 2562, 2406, "Anadolu Efes", 1, 1, 1976, "Sinan Erdem Arena", "Turska", "Istanbul", 16000, "Ergin", "Ataman", 7, 1, 1966, "Turska", "Istanbul", 2010000);
    /*Igrac i16 ();
    Igrac i17 ();
    Igrac i18 ();
    Igrac i19 ();
    Igrac i20 ();*/

///    Tim barcelona (17, 1, 12, 0, 34, 2358, 2282, );
    /*Igrac i21 ();
    Igrac i22 ();
    Igrac i23 ();
    Igrac i24 ();
    Igrac i25 ();*/
///    Tim panathinaikos (16, 0, 13, 1, 32, 2382, 2345, );
    /*Igrac i26 ();
    Igrac i27 ();
    Igrac i28 ();
    Igrac i29 ();
    Igrac i30 ();*/

///    Tim baskonia (15, 0, 14, 1, 30, 2449, 2378, );
    /*Igrac i31 ();
    Igrac i32 ();
    Igrac i33 ();
    Igrac i34 ();
    Igrac i35 ();
    */

///    Tim zalgiriskaunas (14, 1, 13, 2, 28, 2360, 2323, );
    /*Igrac i36 ();
    Igrac i37 ();
    Igrac i38 ();
    Igrac i39 ();
    Igrac i40 ();
    */
    string imetimaa;
    do
    {
        cout << "Plej-of" << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Utakmice" << endl;
        cout << "Opcija 2: Utakmice nekog odredjenog tima" << endl;
        cout << "Opcija 3: Timovi ucesnici" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> po;
        switch  (po)
        {
        case 1:
            tooo.ispisTekmice();
            break;
        case 2:
            cout << "Izabrana je opcija pretrage utakmica po nazivu tima" << endl;
            cout << "Unesi naziv tima: " ;
            cin >> imetimaa;
            tooo.pretrazipotim(imetimaa);
            break;
        case 3:
            fenerbahce.ispisiInfoTim();
            cska.ispisiInfoTim();
            realmadrid.ispisiInfoTim();
            anadoluefes.ispisiInfoTim();
            break;
        default:
            break;
        }
    }
    while (po!=0);
}
void regdeo (int d, string sez)
{
    RegularniDeo regDeo(16);
    Kolo k1(1);
    Utakmica u1(1,12,10,2018,"Fenerbahce","GranCanaria",97,72,false);
    Utakmica u2(2,12,10,2018,"Khimki","Olympiacos",66,87,false);
    Utakmica u3(3,12,10,2018,"Zalgiris Kaunas","Baskonia",79,87,false);
    Utakmica u4(4,12,10,2018,"Buducnost","Olimpia Milano",71,82,false);
    Utakmica u5(5,11,10,2018,"Real Madrid","Darussafaka",109,93,false);
    Utakmica u6(6,11,10,2018,"Bayern","Anadolu Efes",71,90,false);
    Utakmica u7(7,11,10,2018,"Panathinaikos","Maccabi Tel Aviv",89,84,false);
    Utakmica u8(8,11,10,2018,"CSKA Moscow","Barcelona",95,75,false);

    k1.dodajtekmu(&u1);
    k1.dodajtekmu(&u2);
    k1.dodajtekmu(&u3);
    k1.dodajtekmu(&u4);
    k1.dodajtekmu(&u5);
    k1.dodajtekmu(&u6);
    k1.dodajtekmu(&u7);
    k1.dodajtekmu(&u8);

    regDeo.dodajtekme(&u1);
    regDeo.dodajtekme(&u2);
    regDeo.dodajtekme(&u3);
    regDeo.dodajtekme(&u4);
    regDeo.dodajtekme(&u5);
    regDeo.dodajtekme(&u6);
    regDeo.dodajtekme(&u7);
    regDeo.dodajtekme(&u8);

    string timImeUnos;
    int brojUnos, a;
    do
    {
        cout << "Regularni deo" << endl;
        cout << "-------------------------" << endl;
        cout << "Opcija 1: Kola" << endl;
        cout << "Opcija 2: Tabela" << endl;
        cout << "Opcija 3: Uspeh timova do odredjenog kola" << endl;
        cout << "Opcija 4: Utakmice nekog odredjenog tima" << endl;
        cout << "Opcija 5: Timovi ucesnici" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> d;
        switch  (d)
        {
        case 1:
            ispisimenikolo(k1);
            break;
        case 2:
            citajtabela("tabela 18.19.txt");
            break;
        case 3:
            cout << "Izabrana opcija trazi unos do kojeg kola zelite da vidite uspeh nekog tima" << endl;
            cout << "Unos do odredjenog kola: ";
            cin >> brojUnos;
            cout << "Unos naziva tima: ";
            cin >> timImeUnos;
            a=(brojUnos*8)+1;
            regDeo.uspehtimdonekogkola(timImeUnos, a);
            break;
        case 4:
            cout << "Izabrana opcija trazi unos naziva tima:"<< endl;
            cout << "Naziv tima: ";
            cin >> timImeUnos;
            regDeo.pretrazipotim(timImeUnos);
            break;
        case 5:
            menitimovi(d, sez);
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
        cout << "Opcija 4: Budzet svih timova" << endl;
        cout << "Opcija 0: Nazad" << endl;
        cout << "Unesi zeljenu opciju: ";
        cin >> c;
        switch  (c)
        {
        case 1:
            regdeo(c, sez);
            break;
        case 2:
            meniplejof(c, sez);
            break;
        case 3:
            break;
        case 4:
            menibudzet(bu1, sez);
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
        default:
            cout << "Sportski pozdrav!";
            break;
        }
    }
    while (a!=0);
}
///samo da naglasim, nijedno kolo ne ide u fajlove sve ce biti u mainu
///utakmice final foura i plejofa ce najverovatnije biti u fajlovima
///timovi se nalaze u mainu dok se igraci navedenih timova nalaze u fajlovima, ova ideja je takodje propala u vodu
///SVE OD ONOGA STO JE TREBALO BITI U FAJLOVIMA, ALI SAM IPAK ODLUCIO DA SE NALAZI U MAINU

int main()
{
    ///ispisimenikolo(k1);
    Kolo llaal(3);
    Utakmica u9(9,17,10,2018,"Baskonia","Olympiacos",80,85,false);
    llaal.dodajtekmu(&u9);
    llaal.pretrazipotim("Baskonia");
    llaal.pretrazipoid(9);
    int a=0;
    menizapocetak(a);
    /*
    Kolo k2(2);
    Utakmica u9(9,17,10,2018,"Baskonia","Olympiacos",80,85,false);
    Utakmica u10(10,17,10,2018,"Olimpia Milano","Real Madrid",85,91,false);
    Utakmica u11(11,17,10,2018,"Fenerbahce","Khimki",93,85,false);
    Utakmica u12(12,17,10,2018,"Anadolu Efes","Zalgiris Kaunas",79,93,false);
    Utakmica u13(13,16,10,2018,"Gran Canaria","Barcelona",87,86,false);
    Utakmica u14(14,16,10,2018,"Bayern","Panathinaikos",80,79,false);
    Utakmica u15(15,16,10,2018,"Maccabi Tel Aviv","CSKA Moscow",86,89,false);
    Utakmica u16(16,16,10,2018,"Darussafaka","Buducnost",71,63,false);

    k2.dodajtekmu(&u9);
    k2.dodajtekmu(&u10);
    k2.dodajtekmu(&u11);
    k2.dodajtekmu(&u12);
    k2.dodajtekmu(&u13);
    k2.dodajtekmu(&u14);
    k2.dodajtekmu(&u15);
    k2.dodajtekmu(&u16);

    ispisimenikolo(k2);

    Kolo k3(3);
    Utakmica u17(17,19,10,2018,"Real Madrid","Baskonia",97,79,false);
    Utakmica u18(18,19,10,2018,"Olympiacos","Olimpia Milano",75,99,false);
    Utakmica u19(19,19,10,2018,"Zalgiris Kaunas","Fenerbahce",75,82,false);
    Utakmica u20(20,19,10,2018,"Khimki","Anadolu Efes",84,85,false);
    Utakmica u21(21,18,10,2018,"Barcelona","Bayern",83,73,false);
    Utakmica u22(22,18,10,2018,"Buducnost","Maccabi Tel Aviv",68,78,false);
    Utakmica u23(23,18,10,2018,"Panathinaikos","Gran Canaria",102,87,false);
    Utakmica u24(24,18,10,2018,"CSKA Moscow","Darussafaka",79,75,false);

    k3.dodajtekmu(&u17);
    k3.dodajtekmu(&u18);
    k3.dodajtekmu(&u19);
    k3.dodajtekmu(&u20);
    k3.dodajtekmu(&u21);
    k3.dodajtekmu(&u22);
    k3.dodajtekmu(&u23);
    k3.dodajtekmu(&u24);

    ispisimenikolo(k3);

    Kolo k4(4);
    Utakmica u25(25,26,10,2018,"Gran Canaria","CSKA Moscow",91,106,false);
    Utakmica u26(26,26,10,2018,"Panathinaikos","Zalgiris Kaunas",83,87,true);
    Utakmica u27(27,26,10,2018,"Darussafaka","Barcelona",71,79,false);
    Utakmica u28(28,25,10,2018,"Olympiacos","Maccabi Tel Aviv",88,80,false);
    Utakmica u29(29,25,10,2018,"Real Madrid","Buducnost",89,55,false);
    Utakmica u30(30,25,10,2018,"Olimpia Milano","Khimki",81,80,false);
    Utakmica u31(31,25,10,2018,"Bayern","Baskonia",77,71,false);
    Utakmica u32(32,25,10,2018,"Anadolu Efes","Fenerbahce",89,83,false);

    k4.dodajtekmu(&u25);
    k4.dodajtekmu(&u26);
    k4.dodajtekmu(&u27);
    k4.dodajtekmu(&u28);
    k4.dodajtekmu(&u29);
    k4.dodajtekmu(&u30);
    k4.dodajtekmu(&u31);
    k4.dodajtekmu(&u32);

    ispisimenikolo(k4);

    Kolo k5(5);
    Utakmica u33(33,02,11,2018,"Olimpia Milano","Anadolu Efes",81,80,false);
    Utakmica u34(34,02,11,2018,"Buducnost","Panathinaikos",67,72,false);

    Utakmica u35(35,02,11,2018,"Zalgiris Kaunas","Real Madrid",79,90,false);
    Utakmica u36(36,02,11,2018,"Khimki","Gran Canaria",87,72,false);

    Utakmica u37(37,01,11,2018,"Barcelona","Maccabi Tel Aviv",74,58,false);
    Utakmica u38(38,01,11,2018,"Fenerbahce","Bayern",88,84,false);

    Utakmica u39(39,01,11,2018,"Baskonia","Darussafaka",82,56,false);
    Utakmica u40(40,01,11,2018,"CSKA Moscow","Olympiacos",69,65,false);

    k5.dodajtekmu(&u33);
    k5.dodajtekmu(&u34);
    k5.dodajtekmu(&u35);
    k5.dodajtekmu(&u36);
    k5.dodajtekmu(&u37);
    k5.dodajtekmu(&u38);
    k5.dodajtekmu(&u39);
    k5.dodajtekmu(&u40);

    ispisimenikolo(k5);

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

    ispisimenikolo(k6);

    Kolo k7(7);
    Utakmica u49(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u50(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u51(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u52(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u53(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u54(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u55(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u56(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k7.dodajtekmu(&u49);
    k7.dodajtekmu(&u50);
    k7.dodajtekmu(&u51);
    k7.dodajtekmu(&u52);
    k7.dodajtekmu(&u53);
    k7.dodajtekmu(&u54);
    k7.dodajtekmu(&u55);
    k7.dodajtekmu(&u56);

    k7.ispisiKola();

    Kolo k8(8);
    Utakmica u57(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u58(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u59(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u60(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u61(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u62(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u63(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u64(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k8.dodajtekmu(&u57);
    k8.dodajtekmu(&u58);
    k8.dodajtekmu(&u59);
    k8.dodajtekmu(&u60);
    k8.dodajtekmu(&u61);
    k8.dodajtekmu(&u62);
    k8.dodajtekmu(&u63);
    k8.dodajtekmu(&u64);

    k8.ispisiKola();

    Kolo k9(9);
    Utakmica u65(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u66(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u67(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u68(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u69(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u70(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u71(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u72(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k9.dodajtekmu(&u65);
    k9.dodajtekmu(&u66);
    k9.dodajtekmu(&u67);
    k9.dodajtekmu(&u68);
    k9.dodajtekmu(&u69);
    k9.dodajtekmu(&u70);
    k9.dodajtekmu(&u71);
    k9.dodajtekmu(&u72);

    k9.ispisiKola();

    Kolo k10(10);
    Utakmica u73(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u74(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u75(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u76(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u77(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u78(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u79(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u80(48,8,11,2018,"Bayern","Darussafaka",116,70,false);


    k10.dodajtekmu(&u73);
    k10.dodajtekmu(&u74);
    k10.dodajtekmu(&u75);
    k10.dodajtekmu(&u76);
    k10.dodajtekmu(&u77);
    k10.dodajtekmu(&u78);
    k10.dodajtekmu(&u79);
    k10.dodajtekmu(&u80);
    k10.ispisiKola();

    Kolo k11(11);
    Utakmica u1(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false); Utakmica u2(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);
    Utakmica u3(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false); Utakmica u4(44,9,11,2018,"Khimki","Barcelona",80,87,false);
    Utakmica u5(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false); Utakmica u6(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);
    Utakmica u7(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false); Utakmica u8(48,8,11,2018,"Bayern","Darussafaka",116,70,false);
    k1.dodajtekmu(&u1); k1.dodajtekmu(&u2);
    k1.dodajtekmu(&u3); k1.dodajtekmu(&u4);
    k1.dodajtekmu(&u5); k1.dodajtekmu(&u6);
    k1.dodajtekmu(&u7); k1.dodajtekmu(&u8);
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

    Kolo k7(7);
    Utakmica u49(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u50(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u51(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u52(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u53(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u54(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u55(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u56(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k7.dodajtekmu(&u49);
    k7.dodajtekmu(&u50);
    k7.dodajtekmu(&u51);
    k7.dodajtekmu(&u52);
    k7.dodajtekmu(&u53);
    k7.dodajtekmu(&u54);
    k7.dodajtekmu(&u55);
    k7.dodajtekmu(&u56);

    k7.ispisiKola();

    Kolo k8(8);
    Utakmica u57(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u58(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u59(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u60(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u61(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u62(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u63(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u64(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k8.dodajtekmu(&u57);
    k8.dodajtekmu(&u58);
    k8.dodajtekmu(&u59);
    k8.dodajtekmu(&u60);
    k8.dodajtekmu(&u61);
    k8.dodajtekmu(&u62);
    k8.dodajtekmu(&u63);
    k8.dodajtekmu(&u64);

    k8.ispisiKola();

    Kolo k9(9);
    Utakmica u65(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u66(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u67(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u68(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u69(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u70(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u71(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u72(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k9.dodajtekmu(&u65);
    k9.dodajtekmu(&u66);
    k9.dodajtekmu(&u67);
    k9.dodajtekmu(&u68);
    k9.dodajtekmu(&u69);
    k9.dodajtekmu(&u70);
    k9.dodajtekmu(&u71);
    k9.dodajtekmu(&u72);

    k9.ispisiKola();

    Kolo k10(10);
    Utakmica u73(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u74(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u75(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u76(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u77(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u78(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u79(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u80(48,8,11,2018,"Bayern","Darussafaka",116,70,false);


    k10.dodajtekmu(&u73);
    k10.dodajtekmu(&u74);
    k10.dodajtekmu(&u75);
    k10.dodajtekmu(&u76);
    k10.dodajtekmu(&u77);
    k10.dodajtekmu(&u78);
    k10.dodajtekmu(&u79);
    k20.dodajtekmu(&u80);
    k20.ispisiKola();

    Kolo k1(1);
    Utakmica u1(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false); Utakmica u2(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);
    Utakmica u3(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false); Utakmica u4(44,9,11,2018,"Khimki","Barcelona",80,87,false);
    Utakmica u5(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false); Utakmica u6(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);
    Utakmica u7(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false); Utakmica u8(48,8,11,2018,"Bayern","Darussafaka",116,70,false);
    k1.dodajtekmu(&u1); k1.dodajtekmu(&u2);
    k1.dodajtekmu(&u3); k1.dodajtekmu(&u4);
    k1.dodajtekmu(&u5); k1.dodajtekmu(&u6);
    k1.dodajtekmu(&u7); k1.dodajtekmu(&u8);
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

    Kolo k7(7);
    Utakmica u49(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u50(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u51(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u52(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u53(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u54(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u55(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u56(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k7.dodajtekmu(&u49);
    k7.dodajtekmu(&u50);
    k7.dodajtekmu(&u51);
    k7.dodajtekmu(&u52);
    k7.dodajtekmu(&u53);
    k7.dodajtekmu(&u54);
    k7.dodajtekmu(&u55);
    k7.dodajtekmu(&u56);

    k7.ispisiKola();

    Kolo k8(8);
    Utakmica u57(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u58(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u59(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u60(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u61(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u62(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u63(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u64(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k8.dodajtekmu(&u57);
    k8.dodajtekmu(&u58);
    k8.dodajtekmu(&u59);
    k8.dodajtekmu(&u60);
    k8.dodajtekmu(&u61);
    k8.dodajtekmu(&u62);
    k8.dodajtekmu(&u63);
    k8.dodajtekmu(&u64);

    k8.ispisiKola();

    Kolo k9(9);
    Utakmica u65(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u66(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u67(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u68(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u69(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u70(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u71(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u72(48,8,11,2018,"Bayern","Darussafaka",116,70,false);

    k9.dodajtekmu(&u65);
    k9.dodajtekmu(&u66);
    k9.dodajtekmu(&u67);
    k9.dodajtekmu(&u68);
    k9.dodajtekmu(&u69);
    k9.dodajtekmu(&u70);
    k9.dodajtekmu(&u71);
    k9.dodajtekmu(&u72);

    k9.ispisiKola();

    Kolo k10(10);
    Utakmica u73(41,9,11,2018,"Baskonia","Fenerbahce",72,74,false);
    Utakmica u74(42,9,11,2018,"Panathinaikos","Olympiacos",93,80,false);

    Utakmica u75(43,9,11,2018,"Buducnost","Zalgiris Kaunas",60,72,false);
    Utakmica u76(44,9,11,2018,"Khimki","Barcelona",80,87,false);

    Utakmica u77(45,8,11,2018,"Gran Canaria","Anadolu Efes",90,94,false);
    Utakmica u78(46,8,11,2018,"Olimpia Milano","CSKA Moscow",85,90,false);

    Utakmica u79(47,8,11,2018,"Maccabi Tel Aviv","Real Madrid",66,87,false);
    Utakmica u80(48,8,11,2018,"Bayern","Darussafaka",116,70,false);


    k10.dodajtekmu(&u73);
    k10.dodajtekmu(&u74);
    k10.dodajtekmu(&u75);
    k10.dodajtekmu(&u76);
    k10.dodajtekmu(&u77);
    k10.dodajtekmu(&u78);
    k10.dodajtekmu(&u79);
    k10.dodajtekmu(&u80);
    k10.ispisiKola();*/
    return 0;
}
