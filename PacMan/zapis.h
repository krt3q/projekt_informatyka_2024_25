#pragma once
#include <iostream>
#include <stdio.h>

class zapis {

private:




public:
	zapis(int a) {
		FILE* fp;
		fp = fopen("Dane_graczy.dat", "w");
		if (fp == NULL) {
		
		}
		typedef struct {
			int id;
			char nazwa[20];
			int punkty;
			sf::Vector2f pozycjaPacmana;
			std::vector<sf::RectangleShape> Jedzenie;
			std::vector<sf::RectangleShape> Pola;
			std::vector<sf::RectangleShape> Przeszkody;

		} gracze;
	
	
	}



};