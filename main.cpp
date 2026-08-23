#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <clocale>
#include <algorithm>
#include <vector>
#include "enum class.hpp"
#include "struct Player.hpp"
#include "vectors.hpp"

//main.cpp

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    srand(time(0));
    
    while (true)
    {
        string tekst;
        menu wybor;

   		//cout << "Za¿ó³æ gêœl¹ jaŸñ\n";
        cout << "\n=== Levels ===\n";
        cout << "If you are here first time, write: rules, to get familiar with the rules of the game\n";
        cout << "(90% game is in Polish)\n";
        cout << "1.easy\n";
        cout << "2.medium\n";
        cout << "3.hard\n";
        cout << "4.extreme\n";
        cout << "\nChoose level or tutorial: ";

        cin >> tekst;

        if (tekst == "easy")
            wybor = menu::easy;
        else if (tekst == "medium")
            wybor = menu::medium;
        else if (tekst == "hard")
            wybor = menu::hard;
        else if (tekst == "extreme")
            wybor = menu::extreme;
        else if (tekst == "secret")
            wybor = menu::przejscieDoSecret;
        else if(tekst == "rules")
        	wybor = menu::gameRules;
        else
        {
            cout << "Nie ma takiego poziomu!\n";
            continue;
        }

        while (true)
        {
            switch (wybor)
            {
            case menu::easy:
                wybor = easy();

                if (wybor == menu::easy)
                    break;      // wróæ do menu

                continue;       // przejdŸ do medium

            case menu::medium:
                wybor = medium();

                if (wybor == menu::medium)
                    break;      // wróæ do menu

                continue;

            case menu::hard:
                wybor = hard();

                if (wybor == menu::hard)
                    break;      // wróæ do menu

                continue;

            case menu::extreme:
                wybor = extreme();

                if (wybor == menu::extreme)
                    break;      // wróæ do menu

                continue;
                
			case menu::przejscieDoSecretWarunki:
				wybor = przejscieDoSecretWarunki();
				
				if(wybor == menu::przejscieDoSecretWarunki)
				 	break;
				 	
				continue;

            case menu::przejscieDoSecret:
                wybor = przejscieDoSecret();

                if (wybor == menu::przejscieDoSecret)
                    break;      // wróæ do menu

                continue;
                
            case menu::gameRules:
            	wybor = gameRules();

    			if (wybor == menu::gameRules)
        			break;

    			continue;
    			
            case menu::intro:
                wybor = intro();
                break;

            case menu::fabula_secret:
                wybor = fabula_secret();
                break;

            case menu::Hel_zabka:
                wybor = Hel_zabka();
                break;

            case menu::Hel_dworzec:
                wybor = Hel_dworzec();
                break;

            case menu::Hel_park:
                wybor = Hel_park();
                break;

            case menu::Hel_port:
                wybor = Hel_port();
                break;

            case menu::Hel_szpital:
                wybor = Hel_szpital();
                break;

            case menu::Hel_wydmy:
                wybor = Hel_wydmy();
                break;

            case menu::Hel_autobus:
                wybor = Hel_autobus();
                break;
        }
    	}
    }

}

menu gameRules();
menu easy();
menu medium();
menu hard();
menu extreme();
menu przejscieDoSecretWarunki();
menu przejscieDoSecret();
////////////////
menu fabula_secret();
menu intro();
menu Hel_dworzec();
menu Hel_zabka();
menu Hel_park();
menu Hel_wydmy();
menu Hel_szpital();
menu Hel_autobus();
menu Hel_port();

