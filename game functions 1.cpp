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

//game functions 1.cpp

using namespace std;

menu gameRules()
{
    SetConsoleOutputCP(65001);

    cout << "===Rules===";
    cout << "\nJe?li tu jeste? to oznacza ?e, grasz w to po raz pierwszy.\n";
    cout << "1.Poziomy- ilo??, punktacja: \n";
    cout << "Mamy 4 poziomy które musisz przej?? po kolei,\ninaczej autor gry po adresie IP Ci? znajdzie i ze?le na ?agry na Syberii na 5 lat.\n";
    cout << "-easy \n-medium\n-hard\n-extreme\n";
    cout << "Za poziom easy masz ??cznie 250 pkt, medium 500 pkt, hard 750 pkt, oraz extreme 1000 pkt.\n ??cznie jest 3500 pkt na ca?? gr?. (nie, nie 2000 a czemu dowiesz si? na ko?cu)\n";
    cout << "Aby pokona? poziomy na 100% to musisz mie? nie wi?cej ni?: \n";
    cout << "-12/20 prób na easy\n-7/10 prób na medium\n-5/8 prób na hard\n-3/4 prób na extreme\n";
    cout << "Po pokonaniu poziomów co? si? stanie, lecz to jest co? do czego musisz samodzielnie dotrze?\n";
    cout << "2.Fabu?a gry\n";
    cout << "Sama gra polega na zgadywaniu liczb 1-100 a jak widzisz to nie jest takie proste jak si? wydaje jak masz limit prób.\nPami?taj- znak < oznacza ?e musisz wpisa? mniejsz? liczb? od tej któr? wpisa?e?/-a?,\na znak > oznacza, ?e musisz wpisa? wi?ksz? liczb? od tej któr? wpisa?e?/-a?\n";
    cout << "Powodzenia!\n";
    cout << "-Autor gry\n";
    string pomidor;
    menu wybor;
    cout << "Wpisz: tak, aby przej?? do easy\n";
    cin >> pomidor;
    
    if(pomidor == "tak")
    {
        return menu::easy;
    }
    
    return menu::gameRules;
}

menu easy()
{
    SetConsoleOutputCP(65001);

    int licznik = 0;
    int r = rand() % 100 + 1;
    
    cout << "\n===Easy===";
    cout << "\nWypisz liczb? od 1 do 100\n";

    while (true)
    {
        int a;
        cin >> a;
        licznik++;

        if (licznik >= 20)
        {
            string powrot;

            cout << "Przegra?e?/-a?!\n";
            cout << "Wpisz \"come back\": ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, powrot);

            if (powrot == "come back")
                return menu::easy;

            cout << "Niepoprawna komenda.\n";
            continue;
        }

        if (a > 100)
        {
            cout << "Za du?a liczba!\n";
        }
        else if (a > r)
        {
            cout << "<\n";
        }
        else if (a < r)
        {
            cout << ">\n";
        }
        else if(licznik <= 12)
        {
            string puzzle;

            cout << "Gratulacje! Masz 100% punktów, w zamian dostajesz pierwsz? cz??? puzzli- litery to: ez\n";
            cout << "Przej?? do medium? (tak/nie) ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, puzzle);

            if (puzzle == "tak")
                return menu::medium;

            cout << "Niepoprawna komenda.\n";
            continue;
        }
        else
        {
            cout << "Gratulacje!\n";
            cout << "Zgad?e?/-a? liczb? w " << licznik << " próbach.\n";

            string odp;

            cout << "Przej?? do medium? (tak/nie): ";
            cin >> odp;

            if (odp == "tak" || odp == "Tak")
                return menu::medium;

            return menu::medium;
        }
    }
}

menu medium()
{
    SetConsoleOutputCP(65001);

    int licznik = 0;
    int r = rand() % 100 + 1;
    
    cout << "\n===Medium===";
    cout << "\nWypisz liczb? od 1 do 100\n";

    while (true)
    {
        int a;
        cin >> a;
        licznik++;

        if (licznik >= 10)
        {
            string powrot;

            cout << "Przegra?e?/-a?!\n";
            cout << "Wpisz \"come back\": ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, powrot);

            if (powrot == "come back")
                return menu::easy;

            cout << "Niepoprawna komenda.\n";
            continue;
        }
        

        if (a > 100)
        {
            cout << "Za du?a liczba!\n";
        }
        else if (a > r)
        {
            cout << "<\n";
        }
        else if (a < r)
        {
            cout << ">\n";
        }
        
        else if(licznik <= 7)
        {
            string puzzle;

            cout << "Gratulacje! Masz 100% punktów, w zamian dostajesz drug? cz??? puzzli- litery to: ot\n";
            cout << "Przej?? do hard? (tak/nie) ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, puzzle);

            if (puzzle == "tak")
                return menu::hard;

            cout << "Niepoprawna komenda.\n";
            continue;
        }
        else
        {
            cout << "Gratulacje!\n";
            cout << "Zgad?e?/-a? liczb? w " << licznik << " próbach.\n";

            string odp;

            cout << "Przej?? do hard? (tak/nie): ";
            cin >> odp;

            if (odp == "tak" || odp == "Tak")
                return menu::hard;

            return menu::hard;
        }
    }
}

menu hard()
{
    SetConsoleOutputCP(65001);

    int licznik = 0;
    int r = rand() % 100 + 1;

    cout << "\n===Hard===";
    cout << "\nWypisz liczb? od 1 do 100\n";

    while (true)
    {
        int a;
        cin >> a;
        licznik++;

        if (licznik >= 8)
        {
            string powrot;

            cout << "Przegra?e?/-a?!\n";
            cout << "Wpisz \"come back\": ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, powrot);

            if (powrot == "come back")
                return menu::easy;

            cout << "Niepoprawna komenda.\n";
            continue;
        }

        if (a > 100)
        {
            cout << "Za du?a liczba!\n";
        }
        else if (a > r)
        {
            cout << "<\n";
        }
        else if (a < r)
        {
            cout << ">\n";
        }
        else if(licznik <= 5)
        {
            string puzzle;

            cout << "Gratulacje! Masz 100% punktów, w zamian dostajesz trzeci? cz??? puzzli- litery to: er\n";
            cout << "Przej?? do extreme? (tak/nie) ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, puzzle);

            if (puzzle == "tak")
                return menu::extreme;

            cout << "Niepoprawna komenda.\n";
            continue;
        }
        else
        {
            cout << "Gratulacje!\n";
            cout << "Zgad?e?/-a? liczb? w " << licznik << " próbach.\n";

            string odp;

            cout << "Przej?? do extreme? (tak/nie): ";
            cin >> odp;

            if (odp == "tak" || odp == "Tak")
                return menu::extreme;

            return menu::extreme;
        }
    }
}

menu extreme()
{
    SetConsoleOutputCP(65001);

    int licznik = 0;
    int r = rand() % 100 + 1;

    cout << "\n===Extreme===";
    cout << "\nWypisz liczb? od 1 do 100\n";

    while (true)
    {
        int a;
        cin >> a;
        licznik++;

        if (licznik >= 5)
        {
            string powrot;

            cout << "Przegra?e?/-a?!\n";
            cout << "Wpisz \"come back\": ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, powrot);

            if (powrot == "come back")
                return menu::easy;

            cout << "Niepoprawna komenda.\n";
            continue;
        }

        if (a > 100)
        {
            cout << "Za du?a liczba!\n";
        }
        else if (a > r)
        {
            cout << "<\n";
        }
        else if (a < r)
        {
            cout << ">\n";
        }
        else if(licznik <= 3)
        {
            string puzzle;

            cout << "Gratulacje! Masz 100% punktów, w zamian dostajesz ostatni? cz??? puzzli- litery to: yka\n";
            cout << "Przej?? do kolejnego nieznanego etapu? (tak/nie) ";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, puzzle);

            if (puzzle == "tak")
                return menu::przejscieDoSecretWarunki;

            cout << "Niepoprawna komenda.\n";
            continue;
        }
        else
        {
            cout << "Gratulacje!\n";
            cout << "Zgad?e?/-a? liczb? w " << licznik << " próbach.\n";

            string odp;

            cout << "Przej?? do kolejnego nieznanego etapu? (tak/nie): ";
            cin >> odp;

            if (odp == "tak" || odp == "Tak")
                return menu::przejscieDoSecretWarunki;

            return menu::przejscieDoSecretWarunki;
        }
    }
}

menu przejscieDoSecretWarunki()
{
    SetConsoleOutputCP(65001);

    string odpowiedz;
    string potwierdzenie;
    cout << "Wpisz has?o aby przej?? do tajemniczego poziomu: \n";
    cin >> odpowiedz;
    if(odpowiedz == "ezoteryka")
    {
        cout << "Gratulacje! Mo?esz przej?? do poziomu secret, to niez?y wyczyn. Aby tam przej?? wpisz: tak \n";
        cin >> potwierdzenie;
        
        if(potwierdzenie == "tak" || potwierdzenie == "Tak")
            return menu::przejscieDoSecret;
    }
    else if(odpowiedz != "ezoteryka")
    {
        cout << "\nWitaj! Gratulacje, ?e uda?o Ci si? przej?? wszystkie 4 poziomy gry. Je?li tu jeste?, to znaczy, ?e nie zdoby?e? do ko?ca 100% punktów lub nie zrobi?e?/-a? tego, co w?a?nie b?dzie wspomniane.\n";
        cout << "Je?li tu jeste?, to znaczy, ?e nie zdoby?e? do ko?ca 100% punktów lub nie zrobi?e?/-a? tego, co w?a?nie b?dzie wspomniane.\n";
        cout << "Wró?, aby zebra? 100% punktów, poniewa? po zdobyciu 100% punktów z ka?dego poziomu otrzymasz tzw. puzzle do rozwi?zania zagadki — litery s?owa, które po po??czeniu w jeden wyraz odblokuj? Secret.\n";
        cout << "Wracaj po ukryte litery i widzimy si? na nowym, innym, a zarazem ostatnim poziomie — Secret :D\n";
    }
    
    string odp;

    cout << "Przej?? do easy od pocz?tku? (tak/nie): ";
    cin >> odp;

    if (odp == "tak" || odp == "Tak")
        return menu::easy;
    else if(odp == "nie" || odp == "Nie")
        return menu::przejscieDoSecretWarunki;
    else
    {
        cout << "Niepoprawny wybór z?y cz?owieku, wracaj do easy bo inaczej wy?l? Ci? do sp8 w pewnym mie?cie, albo do szpitala psychiatrycznego w Choroszczy- znajd? Ci? po adresie IP :D";
        return menu::easy;  
    }

    return menu::easy;
}