#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"
#include "json.hpp"


using json = nlohmann::json;

int main() {
	json stanGry;
	std::fstream plik("dane.json", std::ios::in);
	if (!plik.is_open()) {
		std::cerr << "KUPA\n";
		return -1;
	}

	plik >> stanGry;

	std::cout << "Lista graczy:\n";
	/*if (!stanGry["Gracz"].is_array()) {
		stanGry["Gracz"] = json::array();
	}*/
	for (const auto& gracz : stanGry["Gracz"]()) {
		std::cout << "Gracz: " << gracz["Gracz"].get<std::string>() << ", Punkty: " << gracz["Punkty"] << std::endl;
	}

	return 0;
}