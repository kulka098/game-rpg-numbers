#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <clocale>
#include <algorithm>
#include <vector>
#include <windows.h>
#include "enum class.hpp"
#include "struct Player.hpp"
#include "vectors.hpp"

//game functions 2.cpp

using namespace std;

Player player;

menu przejscieDoSecret()
{
    SetConsoleOutputCP(65001);

    int postac;

    cout << "\n=== Escape From Hel ---> secret level ===";

    cout << "\n\nWitaj! W nagrod? trafi?e?/-a? na mini gierk?. Gra nazywa si?: Escape From Hel.\n";

    cout << "Gra polega na tym, ?e musisz si? wydosta? z Helu.\n";
    cout << "Po przegraniu wracasz na intro.\n";

    cout << "\nDo wyboru masz:\n";

    cout << "1. Turysta- umiej?tno?? przep?acania na atrakcjach czy dodatkach, wróg lokalnych mieszka?ców w za du?ej ilo?ci.\n Umiej?tno?ci: szybko??, pieni?dze = 200\n";
    cout << "2. Lokalny mieszkaniec z miasta obok- nienawidzi jak za du?o turystów nawiedza znane i cz?sto odwiedzane miasto.\n Umiej?tno?ci: dobra orientacja w terenie, kontakty z innymi lokalnymi postaciami, ?atwiej za?atwi co? od turysty.\n";
    cout << "3. Losowy mieszkaniec z innego miasta lub zadupia z 3 domami na krzy?- z jednej strony najgorsza mo?liwa posta? \nbo nic nie daje ale z drugiej ma wi?ksze zaufanie lokalnej ludno?ci,\nale totalnie nie orientuje si? w mie?cie czy sprawach z nim powi?zanych.\n";
    cout << "4. Stwórz w?asn? posta?.\nUwaga- jej HP nie mo?e przekracza? 500 oraz mie? nadprzyrodzonych umiej?tno?ci!\n";

    cout << "\nWpisz numer postaci: ";
    cin >> postac;


    while (cin.fail() || postac < 1 || postac > 4)
    {
        cout << "Z?y numer! Wpisz liczb? od 1 do 4: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cin >> postac;
    }


    // TURYSTA
    if (postac == 1)
    {
        player.pieniadze = 200;
        player.szybkosc = 20;
        player.hp = 300;
        
        cout << "Liczba umiejetnosci: " << umiejetnosciTurysta.size() << "\n\n";

        cout << "Umiej?tno?ci:\n";

        for (string umiejetnosc : umiejetnosciTurysta)
        {
            cout << "- " << umiejetnosc << "\n";
        }

        return menu::intro;
    }


    // LOKALNY
    else if (postac == 2)
    {
        player.pieniadze = 500;
        player.szybkosc = 35;
        player.hp = 300;
        
        cout << "Liczba umiejetnosci: " << umiejetnosciLokalny.size() << "\n\n";

        cout << "Umiej?tno?ci:\n";

        for (string umiejetnosc : umiejetnosciLokalny)
        {
            cout << "- " << umiejetnosc << "\n";
        }

        return menu::intro;
    }


    // LOSOWY MIESZKANIEC
    else if (postac == 3)
    {
        player.pieniadze = 50;
        player.szybkosc = 10;
        player.hp = 300;
        
        cout << "Liczba umiejetnosci: " << umiejetnosciLosowy.size() << "\n\n";

        cout << "Umiej?tno?ci:\n";

        for (string umiejetnosc : umiejetnosciLosowy)
        {
            cout << "- " << umiejetnosc << "\n";
        }

        return menu::intro;
    }


    // W?ASNA POSTA?
    else if (postac == 4)
    {
        cout << "\nImi?: ";
        cin >> player.imie;

        cout << "\nWiek: ";
        cin >> player.wiek;

        cout << "\nP?e?: ";
        cin >> player.plec;

        cout << "\nOpisz posta? z w?asnymi umiej?tno?ciami: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, player.opis);
        
        umiejetnosciWlasna.push_back(player.opis);
        
        cout << "Liczba umiej?tno?ci: " << umiejetnosciWlasna.size() << "\n\n";

        cout << "Umiej?tno?ci:\n";

        for (string umiejetnosc : umiejetnosciWlasna)
        {
            cout << "- " << umiejetnosc << "\n";
        }


        transform(
            player.opis.begin(),
            player.opis.end(),
            player.opis.begin(),
            ::tolower
        );


        vector<string> zakazane =
        {
            "magia",
            "czary",
            "teleport",
            "nie?miertel",
            "latanie",
            "niewidzialno??",
            "kontrola czasu",
            "kontrola umys?ów"
        };


        bool oszustwo = false;


        for (string slowo : zakazane)
        {
            if (player.opis.find(slowo) != string::npos)
            {
                oszustwo = true;
                break;
            }
        }


        if (oszustwo)
        {
            cout << "\nTa umiej?tno?? jest zabroniona!\n";
            return menu::przejscieDoSecret;
        }


        cout << "\nPodaj HP (maksymalnie 500): ";
        cin >> player.hp;


        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "To nie jest liczba!\n";

            return menu::przejscieDoSecret;
        }


        if (player.hp > 500)
        {
            cout << "Maksymalne HP to 500!\n";

            return menu::przejscieDoSecret;
        }


        return menu::intro;
    }


    return menu::przejscieDoSecret;
}

menu intro()
{
    SetConsoleOutputCP(65001);

    int opcja;
    menu wybor;
    cout << "\n===Escape From Hel===\n";
    cout << "Budzisz si? na dworcu kolejowym.\n\nSpogl?dasz na zegar. Jest **2:44**.\n\nW?a?nie odje?d?a ostatni nocny poci?g. Nast?pny odjedzie dopiero o **6:00**. T? informacj? odczytujesz z rozk?adu jazdy wisz?cego na starej, ceglanej ?cianie.\n\nSam dworzec wygl?da jak typowy polski dworzec – be?owe ?ciany, kilka drewnianych ?awek i kasy biletowe, za którymi \nsiedz? wyra?nie zm?czone kasjerki.\n\nNa zewn?trz panuje cisza. Wi?kszo?? miasta ju? ?pi.\n\nCo robisz?\n\n1. Idziesz do ?abki.\n\n2. Zostajesz na noc na dworcu.\n\n3. Idziesz spa? do pobliskiego parku.\n\n4. Idziesz na dworzec autobusowy i sprawdzasz, czy uda si? wróci? autobusem wcze?niej ni? poci?giem.\n";
    cin >> opcja;
    if(opcja == 1)
    {
        return menu::Hel_zabka;
    }
    else if(opcja == 2)
    {
        return menu::Hel_dworzec;
    }
    else if(opcja == 3)
    {
        return menu::Hel_park;
    }
    else if(opcja == 4)
    {
        return menu::Hel_autobus;
    }

    return menu::intro;
}   

menu fabula_secret()
{
    SetConsoleOutputCP(65001);

    cout << "Fabu?a";
    return menu::fabula_secret;
}

menu Hel_zabka()
{
    SetConsoleOutputCP(65001);

    while(true)
    {
        menu wybor;
        int opcja;
        
        cout << "\nJeste? w ?abce. Co kupujesz?\n";
        cout << "1.Sok\n";
        cout << "2.Wod?\n";
        cout << "3.Chipsy\n";
        cout << "Mo?esz tylko jedno bo w tej ?abce jest strasznie drogo- co si? dziwi?, to jest miejscowo?? turystyczna\n";

        cin >> opcja;
        
        if (cin.fail())
        {
            cout << "To nie jest liczba!\n";

            cin.clear(); // usuwa stan b??du
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // usuwa b??dny tekst z bufora

            continue; // wraca do pocz?tku p?tli
        }


        if (opcja == 1)
        {
            int decyzja;
            int pomidor;

            cout << "\nTen sok sprawi? ?e masz ostr? biegunk?, co robisz?\n";
            cout << "1. Robisz swoje w krzaki\n";
            cout << "2. Szukasz toalety nawet jakby mia?a by? p?atna\n";

            cin >> decyzja;


            if (decyzja == 1)
            {
                cout << "\nUda?o ci si?, cudem bo prawie z?apa?a ci? na tym starsza pani z psem. Teraz wolisz i?? na 1-dworzec czy 2-do parku spa??\n";
                cout << "Do hotelu nie pójdziesz bo jeste? typowym Polakiem i na kilka godzin nie zmarnujesz swoich ci??ko zarobionych pieni?dzy.\n";

                cin >> pomidor;


                if (pomidor == 1)
                {
                    return menu::Hel_dworzec;
                }
                else if (pomidor == 2)
                {
                    return menu::Hel_park;
                }
            }


            else if (decyzja == 2)
            {
                cout << "Znalaz?e?/-a? prawie darmowe toalety na ulicy Wiejskiej 141- trzeba by?o zap?aci? 5 z? za dwójk?, w twoim przypadku tak? zaawansowan?.\n";
                cout << "Co robisz dalej:\n";
                cout << "1.Idziesz na dworzec zobaczy? kiedy jest najbli?szy poci?g oraz opcjonalnie spa?\n";
                cout << "2.Idziesz spa? do parku bij?c si? z lokalnymi menelami o ?awk?\n";

                cin >> pomidor;


                if (pomidor == 1)
                {
                    return menu::Hel_dworzec;
                }
                else if (pomidor == 2)
                {
                    return menu::Hel_park;
                }
            }
        }


        else if (opcja == 2)
        {
            int kosmita;


            cout << "Gratulacje, masz wod?.\n";
            cout << "Teraz idziesz 1.na dworzec spa? czy 2.do parku?\n";
            cout << "Nie ma tu opcji hotel poniewa? jeste? typowym Polakiem i nie b?dziesz przep?aca? za kilka godzin\n";


            cin >> kosmita;


            if (kosmita == 1)
            {
                return menu::Hel_dworzec;
            }
            else if (kosmita == 2)
            {
                return menu::Hel_park;
            }
        }


        else if (opcja == 3)
        {
            int pomidor;


            cout << "Gratulacje, masz czipsy o smaku polskiej kie?basy z sol? morsk?.\n";
            cout << "Teraz idziesz 1.na dworzec spa? czy 2.do parku?\n";
            cout << "Nie ma tu opcji hotel poniewa? jeste? typowym Polakiem i nie b?dziesz przep?aca? za kilka godzin\n";


            cin >> pomidor;


            if (pomidor == 1)
            {
                return menu::Hel_dworzec;
            }
            else if (pomidor == 2)
            {
                return menu::Hel_park;
            }
        }
        else
        {
            cout << "Nie ma takiej opcji! Wpisz opcje ponownie\n";
            continue;
        }
    }
    return menu::Hel_zabka;
}

menu Hel_dworzec()
{
    SetConsoleOutputCP(65001);

    menu wybor;
    int pomidor;
    cout << "\nJeste? na dworcu z swoim zakupem (je?li by?e?/-a? w ?abce, jak nie to pomi? to zdanie.). Co robisz?\n1.Idziesz zobaczy? tablic? odjazdów\n2.Idziesz spa? w losowym miejscu na dworcu\n";
    cin >> pomidor;
    if(pomidor == 1)
    {
        cout << "\nIdziesz, ale...czujesz ch?ód i jakby kto? ci? obserwowa?. \nOgl?dasz si? za siebie ale nikogo nie widzisz.\nGdy podchodzisz do tablic odjazdu i przyjazdu nagle gasn? a ?wiat?a mrugaj?, za to panie za kasami si? w Ciebie niepokoj?co, intensywnie wpatruj?. Jeste? tak wystraszony/-na, ?e bierzesz swoje rzeczy i idziesz spa? do parku.";
        return menu::Hel_park;
    }
    else if(pomidor == 2)
    {
        int kapusta;
        cout << "Có?... nie ?yjesz, zatru?e?/-a? si? czadem a potem kto? Ci? zad?ga?. Aby si? odrodzi? od pocz?tku, wpisz: 1";
        cin >> kapusta;
        if(kapusta == 1)
        {
            return menu::intro;
        }
        else if(kapusta != 1)
        {
            cout << "?le! Wpisz ponownie.";
        }
    }
        
    return menu::Hel_dworzec;
}

menu Hel_park()
{
    SetConsoleOutputCP(65001);

    cout << "\nW parku jedynie dosz?o do bójki z menelami o butelki kaucyjne- przez brak pieni?dzy ukrad?e?/-a?\nim 50 butelek kaucyjnych.\nJednak uda?o Ci si? uciec przed nimi i znale?? miejsce do spania.\n";
    cout << "*ranek*\n";
    cout << "Jest ju? rano, nawet jest ?adna pogoda, ale niestety ?o??dek domaga si? o jedzenie. \nIdziesz do ?abki kupi? jedzenie i odda? butelki kaucyjne.\n";
    cout << "Po zjedzeniu czujesz, ?e ?le si? czujesz. Z minuty na minut? jest coraz gorzej, idziesz do pobliskiego szpitala.\n\n";
    return menu::Hel_szpital;
}

menu Hel_wydmy()
{
    SetConsoleOutputCP(65001);

    string pomidor;
    cout << "\nWydmy, piasek i trawa. Nic ciekawego ale daje ti to nutk? utraconej codzienno?ci, po kilku godzinach \nudajesz si? znowu do ?abki.\n";
    cout << "Wpisz: tak aby i?? do ?abki\nJe?li nie masz ochoty i?? do ?abki, to idziesz do ostatniej deski ratunku- portu.\nAby i?? do portu wpisz: nie \n";
    cin >> pomidor;
    if(pomidor == "tak" || pomidor == "TAK")
        return menu::Hel_zabka;
    
    else if(pomidor == "nie" || pomidor == "NIE")
        return menu::Hel_port;
        
    return menu::Hel_wydmy;
}

menu Hel_szpital()
{
    SetConsoleOutputCP(65001);

    cout << "Je?li trafi?e?/-a? tutaj przez jedzenie z ?abki, to si? okaza?o ?e tylko masz zatrucie pokarmowe, przep?ukali Ci ?o??dek, dali leki i odes?ali do domu (ty w Helu nie masz domu biedaku).\n";
    cout << "Aby si? wydosta? z tego przekl?tego miasta, uda?e?/-a? si? na dworzec autobusowy, skoro poci?gi s? jakie?... nawiedzone to innej opcji nie ma.\n\n";
    return menu::Hel_autobus;
}

menu Hel_autobus()
{
    SetConsoleOutputCP(65001);

    string pomidor;
    cout << "Okaza?o si?, ?e wycofali autobusy poza miasto ze wzgl?du na wielki remont dróg, jeste? bardzo wkurzony/-na i masz do??.\nTwoj? ostatni? nadziej? jest port, z którego dostaniesz si? do Gdyni a z Gdyni do twojego miasta docelowego.\n\n";
    cout << "Wpisz: tak aby uda? si? na wydmy bo nudzi ci si? w ?yciu- nie masz innej opcji bo ciekawi? ci? wydmy, prawda?\n";
    cin >> pomidor;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    if(pomidor == "tak" || pomidor == "TAK")
        return menu::Hel_wydmy;
        
    return menu::Hel_autobus;
}

menu Hel_port()
{
    SetConsoleOutputCP(65001);

    string pytanie;
    cout << "Po godzinie drogi nagle... O NIE, goni? Ci? te menele które chc? Ci? udusi? za te butelki kaucyjne\ni jakie?... dziwne stwory, co? pomi?dzy butelk? a cz?owiekiem\n";
    cout << "Te dziwne istoty wygl?daj? jak ludzie ale maj? po?yskuj?c?, jak plastik skór? oraz korki od butelek zamiast oczu,\nporuszaj? si? turlaj?c po powierzchni ale dziwnym sposobem nadal si? w ciebie wpatruj?.\nPoza tym maj? na skórze kilkaset znaczków: kaucja 50 gr";
    cout << "Widzisz port... za 5 min jest odp?yw a Ty jeste? 300 metrów dalej\ni na dodatek goni? Ci? menele i butelki kaucyjne";
    cout << "Ju? wyci?gaj? po ciebie r?ce i prawie ?api? za nog?...\nALE NIE, UCIEK?E?/-A? NIM I ZNIKASZ Z TEGO CHOLERNEGO MIASTA.\n";
    cout << "Gdy si? oddalasz... nagle miasto staje si? z dala normalne, bo poci?gi nagle si? pojawiaj? oraz autobusy\nm.in linii 666. A co najgorsze- butelki kaucyjne zmieniaj? si? w normalnych ludzi, \nkilka z nich jest ?udz?co podobne do pa? za kasami na dworcu czy przypadkowych ludzi na ulicy.\nCzy butelki kaucyjne by?y odpowiedzialne za uprowadzenie i próby zatrzymania Ci? tutaj? Tego si? nigdy nie dowiemy...";
    cout << "\nZanim jednak sko?czysz przygod? to musisz odpowiedzie? na jedno pytanie.\nJaka firma jest najwi?kszym producentem opon na ?wiecie?\n";
    cin >> pytanie;
    
    if(pytanie == "LEGO" || pytanie == "lego")
    {
        string kapusta;
        cout << "\nUdaje Ci si? opu?ci? miasto, a zarazem uko?czy? mini gr?.\nJe?li chcesz jej kontynuacj? wpisz: tak, aby przej?? do ca?ej gry bo to tylko jej 1 poziom, gry- Escape From Poland.\n";
        cin >> kapusta;
        
        if(kapusta == "tak" || kapusta == "TAK")
        {
            cout << "\nGra jeszcze nie istnieje, przepraszam.\nAutor gry.";
        }
    }
    else
    {
        string kapusta;
        cout << "Z?a odpowied?! G?upi cz?owieku, jak mo?esz? Butelki kaucyjne jak tylko to us?ysza?y to nagle zacz??y p?yn?? z pr?dko?ci? ?wiat?a bo je tym przywo?a?e?/-a? i.... zjad?y Ci? a nikt nic nie zauwa?y? bo tak szybko Ci? ju? nie ma.\nNie ?yjesz, przegra?e?/-a? mini gr?, aby si? odrodzi? wpisz: tak\n";
        cin >> kapusta;
        
        if(kapusta == "TAK")
        {
            return menu::intro;
        }
    }
    
    return menu::przejscieDoSecret;
}