#pragma once
#include <random>
#include <vector>
#include <iostream>
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist(0,6);
class Plansza {
private:
	sf::Vector2f Rozmiar;
	sf::RectangleShape Ramka;
public:

	std::vector<sf::RectangleShape> pola;
	std::vector<sf::RectangleShape> przeszkoda;
	std::vector<sf::RectangleShape> amam;

	Plansza(int yr, int xr) {
		Ramka.setPosition(3, 120);
		Ramka.setSize(sf::Vector2f(60 * yr, 60 * xr));
		Ramka.setOutlineColor(sf::Color::Blue);
		Ramka.setOutlineThickness(3);
		Ramka.setFillColor(sf::Color::Transparent);
		int a = 0;
		int b = 0;
		std::vector<std::vector<int>> tablica(xr, std::vector<int>(yr));
		for (int i = 0; i < xr; i++) {
			for (int j = 0; j < yr; j++) {
				tablica[i][j] = dist(rng);
			}
		}

		for (int i = 0; i < xr; i++) {
			for (int j = 0; j < yr; j++) {
				if (tablica[i][j] == 6) {
					sf::RectangleShape pole;
					pole.setSize(sf::Vector2f(60, 60));
					pole.setPosition(3 + j * 60, 123 + i * 60);
					pole.setFillColor(sf::Color::Cyan);
					pola.push_back(pole);
					przeszkoda.push_back(pole);
				}
				else {
					sf::RectangleShape pole;
					sf::RectangleShape jedzenie;
					pole.setSize(sf::Vector2f(60, 60));
					pole.setPosition(3 + j * 60 + 20, 123 + i * 60 + 20);
					pole.setFillColor(sf::Color::Transparent);
					jedzenie.setSize(sf::Vector2f(10, 10));
					jedzenie.setPosition(3 + j * 60 + 25, 123 + i * 60 + 25);
					jedzenie.setFillColor(sf::Color::Yellow);
					amam.push_back(jedzenie);
					pola.push_back(pole);
				}
			}
		}
	}

	
	//Zwracanie Planszy Test
	std::vector<sf::RectangleShape> getPlansza() {
		return pola;
	}
	sf::RectangleShape getRamka() {
		return Ramka;
	}
	std::vector<sf::RectangleShape> getPrzeszkoda() {
		return przeszkoda;
	}
	std::vector<sf::RectangleShape>& getJedzenie() {
		return amam;
	}
};