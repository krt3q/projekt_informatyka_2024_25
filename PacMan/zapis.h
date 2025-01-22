#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

class zapis {
private:


public:

	std::vector<sf::RectangleShape> pole1;
	std::vector<sf::RectangleShape> przeszkoda1;
	std::vector<sf::RectangleShape> amam1;
	int pkt1;
	sf::Vector2f pozycja1;

	struct zapisz {
		int pkt;
		sf::Vector2f pozycja;
		std::vector<sf::RectangleShape> pole;
		std::vector<sf::RectangleShape> przeszkoda;
		std::vector<sf::RectangleShape> amam;
	};

	json stanGry;

	//Konstruktor
	zapis(int) {
		int test = 1;
	};

	

	//Zapisywanie
	void zapisywanie(const std::string& nazwaPliku,std::string nazwaGracza, int punkty, const sf::Vector2f pacman, std::vector<sf::RectangleShape> pola,
		std::vector<sf::RectangleShape> przeszkody, std::vector<sf::RectangleShape> jedzenie, int a, int b){
		//stanGry[nazwaGracza].clear();
		//Tworzenie zmiennej json
		stanGry[nazwaGracza]["Punkty"] = punkty;
		stanGry[nazwaGracza]["Pacman"][0] = pacman.x;
		stanGry[nazwaGracza]["Pacman"][1] = pacman.y;

		//Tworzenie miejsc dla pól
		for (const auto& pole : pola) {
			json danePola;
			danePola["pozycja"] = { pole.getPosition().x,pole.getPosition().y };
			danePola["rozmiar"] = { pole.getSize().x,pole.getSize().y };
			auto color = pole.getFillColor();
			danePola["kolor"] = { color.r, color.g, color.b, color.a };
			stanGry[nazwaGracza]["pola"].push_back(danePola);
		}

		//Tworzenie miejsc dla przeszkód
		for (const auto& pole : przeszkody) {
			json danePrzeszkody;
			danePrzeszkody["pozycja"] = { pole.getPosition().x,pole.getPosition().y };
			danePrzeszkody["rozmiar"] = { pole.getSize().x,pole.getSize().y };
			auto color = pole.getFillColor();
			danePrzeszkody["kolor"] = { color.r, color.g, color.b, color.a };
			stanGry[nazwaGracza]["przeszkody"].push_back(danePrzeszkody);
		}

		//Tworzenie miejsc na jedzenie
		for (const auto& pole : jedzenie) {
			json daneJedzenia;
			daneJedzenia["pozycja"] = { pole.getPosition().x,pole.getPosition().y };
			daneJedzenia["rozmiar"] = { pole.getSize().x,pole.getSize().y };
			auto color = pole.getFillColor();
			daneJedzenia["kolor"] = { color.r, color.g, color.b, color.a };
			stanGry[nazwaGracza]["jedzenie"].push_back(daneJedzenia);
		}

		//Zapis do pliku
		std::fstream plik("dane.json", std::ios::out | std::ios::app);
		if (plik.is_open()) {
			plik << stanGry.dump(4);
			plik.close();
		}
	}

	//Odczytywanie
	zapisz odczytywanie(const std::string& nazwaPliku, const std::string nazwaGracza, int a, int b) {
		std::ifstream plik(nazwaPliku);
		if (!plik.is_open()) {
			std::cerr << "Nie mozna otworzyc pliku!";
		}

		json stanGry;
		plik >> stanGry;
		plik.close();


		Pacman pcman(1);
		Plansza plansza(a, b);



		bool flaga = false;

		/*if (!stanGry.contains("Gracz") || !stanGry["Gracz"].is_array()) {
			stanGry["Gracz"] = json::array();
		}*/


		//Zapisywanie w przypadku odnalezienia gracza
		for (const auto& [nickGracza, daneGracza] : stanGry.items()) {
			if (nickGracza == nazwaGracza) {
				//Odczyt punktów
				int punkty = daneGracza.at("Punkty").get<int>();

				//Odczyt sprite
				sf::Vector2f pacman;
				pacman.x = daneGracza.at("Pacman")[0];
				pacman.y = daneGracza.at("Pacman")[1];

				//Odczyt pól
				std::vector<sf::RectangleShape> jedzenie;
				for (const auto& daneJedzenia : daneGracza.at("jedzenie")) {
					sf::RectangleShape jedzeñ;
					jedzeñ.setPosition(daneJedzenia["pozycja"][0], daneJedzenia["pozycja"][1]);
					jedzeñ.setSize(sf::Vector2f(daneJedzenia["rozmiar"][0], daneJedzenia["rozmiar"][1]));
					jedzeñ.setFillColor(sf::Color(daneJedzenia["kolor"][0], daneJedzenia["kolor"][1], daneJedzenia["kolor"][2], daneJedzenia["kolor"][3]));
					jedzenie.push_back(jedzeñ);
				}

				std::vector<sf::RectangleShape> pola;
				for (const auto& danePola : daneGracza.at("pola")) {
					sf::RectangleShape pole;
					pole.setPosition(danePola["pozycja"][0], danePola["pozycja"][1]);
					pole.setSize(sf::Vector2f(danePola["rozmiar"][0], danePola["rozmiar"][1]));
					pole.setFillColor(sf::Color(danePola["kolor"][0], danePola["kolor"][1], danePola["kolor"][2], danePola["kolor"][3]));
					pola.push_back(pole);
				}

				std::vector<sf::RectangleShape> przeszkody;
				for (const auto& danePrzeszkody : daneGracza.at("przeszkody")) {
					sf::RectangleShape przeszkoda;
					przeszkoda.setPosition(danePrzeszkody["pozycja"][0], danePrzeszkody["pozycja"][1]);
					przeszkoda.setSize(sf::Vector2f(danePrzeszkody["rozmiar"][0], danePrzeszkody["rozmiar"][1]));
					przeszkoda.setFillColor(sf::Color(danePrzeszkody["kolor"][0], danePrzeszkody["kolor"][1], danePrzeszkody["kolor"][2], danePrzeszkody["kolor"][3]));
					przeszkody.push_back(przeszkoda);
				}

				flaga = true;
				zapisz gracz;
				gracz.pkt = punkty;
				gracz.pozycja = pacman;
				gracz.pole = pola;
				gracz.przeszkoda = przeszkody;
				gracz.amam = jedzenie;
				pozycja1 = pacman;
				pkt1 = punkty;
				pole1 = pola;
				przeszkoda1 = przeszkody;
				amam1 = jedzenie;
				return gracz;
			}
		}
		if (flaga == false) {
			std::cout << "Nie odnaleziono gracza\n";
			return { 0, pcman.pozycjaPacmana(), plansza.getPlansza(), plansza.getPrzeszkoda(), plansza.getJedzenie() };
		}
	}

	int zapisanePunkty() {
		/*zapisz gracz;
		return gracz.pkt;*/
		return pkt1;
	}

	sf::Vector2f zapisanaPozycja() {
		/*zapisz gracz;
		return gracz.pozycja;*/
		return pozycja1;
	}

	std::vector<sf::RectangleShape> zapisanePola() {
		return pole1;
	}

	std::vector<sf::RectangleShape> zapisanePrzeszkody() {
		return przeszkoda1;
	}

	std::vector<sf::RectangleShape>& zapisaneJedzenie() {
		return amam1;
	}

};