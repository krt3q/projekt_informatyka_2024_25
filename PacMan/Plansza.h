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
	sf::RectangleShape pole[500];
	sf::RectangleShape przeszkoda[500];
	sf::RectangleShape Ramka;
public:
	Plansza(int yr, int xr) {
		Ramka.setPosition(200, 200);
		Ramka.setSize(sf::Vector2f(50 * yr, 50 * xr));
		Ramka.setOutlineColor(sf::Color::Blue);
		Ramka.setOutlineThickness(3);
		Ramka.setFillColor(sf::Color::Transparent);
		int a = 0;
		int b = 0;
		std::vector<std::vector<int>> tablica(xr, std::vector<int>(yr));
		for (int i = 0; i < xr; i++) {
			for (int j = 0; j < yr; j++) {
				tablica[i][j] = dist(rng);
				//if (tablica[i][j - 1] == 6 /*&& tablica[i][j - 2] == 6*/) {
				//		tablica[i][j] = 0;
				//}
			}
		}

		for (int i = 0; i < xr; i++) {
			for (int j = 0; j < yr; j++) {
				if (tablica[i][j] == 6) {
					//new sf::RectangleShape = pole[a];
					pole[a].setSize(sf::Vector2f(50, 50));
					pole[a].setPosition(200 + j * 50, 200 + i * 50);
					pole[a].setFillColor(sf::Color::Cyan);
					przeszkoda[b] = pole[a];
					b++;
					a++;
				}
				else {
					pole[a].setSize(sf::Vector2f(50, 50));
					pole[a].setPosition(200 + j * 50, 200 + i * 50);
					pole[a].setFillColor(sf::Color::Transparent);
					a++;
				}
			}
		}
	}

	
	//Zwracanie Planszy Test
	sf::RectangleShape* getPlansza() {
		return pole;
	}
	sf::RectangleShape getRamka() {
		return Ramka;
	}
	sf::RectangleShape* getPrzeszkoda() {
		return przeszkoda;
	}
};