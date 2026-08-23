#ifndef struct_Player_hpp
#define struct_Player_hpp
#include<string>
#include<vector>

using namespace std;

struct Player
{
	string imie;
    string plec;
    int wiek= 0;
    string opis;
    
    int hp=0;
	int maxHp=500;
	
	int sila=10;
	int obrona=5;
	int szybkosc=15;
	int szczescie=10;
	int inteligencja= 100;
	int pieniadze= 50;
	
	bool zyje;
	bool zatruty;
	bool zmeczony;
	bool glodny;
	
	bool maKlucz;
	bool znalazlMape;
	bool bylWszpitalu;
	bool kupilWode;
	bool spotkalNPC;
	bool znaTajemniceHelu;
};

#endif
