#ifndef enum_class_hpp
#define enum_class_hpp

//enum class.hpp

enum class menu
{
	gameRules, //game
    easy,
    medium,
    hard,
    extreme,
    przejscieDoSecretWarunki,
    przejscieDoSecret,
    /////////////////
	fabula_secret, //mini game
	intro,
	Hel_dworzec,
	Hel_zabka,
	Hel_park,
	Hel_wydmy,
	Hel_szpital,
	Hel_autobus,
	Hel_port,
};

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



#endif
