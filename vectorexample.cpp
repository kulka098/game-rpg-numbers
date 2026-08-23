#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> ekwipunek;

    ekwipunek.push_back("telefon");
    ekwipunek.push_back("portfel");
    ekwipunek.push_back("latarka");

    cout << "Liczba przedmiotow: " << ekwipunek.size() << "\n\n";

    cout << "EKWIPUNEK:\n";

    for (string przedmiot : ekwipunek)
    {
        cout << "- " << przedmiot << "\n";
    }

    return 0;
}
