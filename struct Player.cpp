#ifndef enum_class_hpp
#define enum_class_hpp

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
	
	vector<string> ekwipunek;
	vector<string> umiejetnosciDodatkowe;
	vector<string> aktywneZadania;
	vector<string> ukonczoneZadania;
};
