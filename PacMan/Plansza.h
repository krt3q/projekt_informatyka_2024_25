#pragma once
#include <random>
std::random_device dev;
std::mt19937 rng(dev());
std::uniform_int_distribution<std::mt19937::result_type> dist6(0,1);
class Plansza {
private:
	sf::Vector2f Rozmiar;
	sf::Vector2f Pozycja_z;
	sf::Vector2f Pozycja_w;
	sf::Vector2f Rozmiar_c; //Wspó³rzêdne wewnêtrznej  ramki
	sf::ConvexShape Ramka_wewn;
	sf::RectangleShape Ramka_zewn;
	sf::RectangleShape pole[64];
	sf::Vertex Ramka[100];
	//std::vector <sf::Vertex> linie;
public:
	Plansza(int xr, int yr) {

		
		int a = 0;
		int b = 0;
		for (int i = 0; i < yr; i++) {
			for (int j = 0; j < xr; j++) {
				int* MAPA = new int[xr];
				srand((unsigned)time(0));
				MAPA[j] = dist6(rng);
				std::cout << MAPA[j];
			}
			std::cout << std::endl;
		}
		

		for (int i = 0; i < xr; i++) {
			for (int j = 0; j < yr; j++) {
				
				if ([i] == 1) {
					//new sf::RectangleShape = pole[a];
					pole[a].setSize(sf::Vector2f(100, 100));
					pole[a].setPosition(200 + j * 100, 200 + i * 100);
					pole[a].setFillColor(sf::Color::Green);
					a++;
				}
				if (MAPAy[i] == 0) {
					pole[a].setSize(sf::Vector2f(100, 100));
					pole[a].setPosition(200 + j * 100, 200 + i * 100);
					pole[a].setFillColor(sf::Color::White);
					a++;
				}
			}
		}
	}

	//Zwracanie Ramki zewnêtrznej
	sf::RectangleShape getPlansza_1() {
		return Ramka_zewn;
	}

	//Zwracanie Ramki Wewnêtrznej
	sf::ConvexShape getPlansza_2() {
		return Ramka_wewn;
	}

	//Zwracanie Planszy Test
	sf::RectangleShape* getPlansza() {
		return pole;
	}
};