#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"
#include "Interfejs.h"
#include "Ustawienia.h"
#include "Krzy¿yk.h"
#include "zapis.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(1300, 1000), "SFML works!");
	sf::Event event;


	int a = 14;
	int b = 7;
	int poczatekSprite=0;
	int koniecSprite = 100;
	

	Plansza plansza(a,b);

	sf::Clock zegar;

	int flaga=0;

	bool inicjacja{};

	sf::IntRect ksztaltPacmana(0,0,40,40);

	Pacman pacman(a,b);

	Interfejs interfejs(5);

	Ustawienia ustawienia(5);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		
		
		if (interfejs.getOkna(window) == 0 || flaga == 1) {
			if (ustawienia.getLevel() == 1) {
				plansza = Plansza(6, 3);
				a = 6;
				b = 3;
			}
			else if (ustawienia.getLevel() == 2) {
				plansza = Plansza(14, 7);
				a = 14;
				b = 7;
			}
			else if (ustawienia.getLevel() == 3) {
				plansza = Plansza(20, 10);
				a = 20;
				b = 10;
			}
			
			pacman.zerujPunkty();
			window.clear();
			interfejs.kolizja(window);
			for (const auto& pole : interfejs.getPola()) {
				window.draw(pole);
			}

			for (const auto& tekst : interfejs.getTekst()) {
				window.draw(tekst);
			}
			window.draw(interfejs.getPacman());
			window.draw(interfejs.napis());
		}
		

		if (interfejs.getOkna(window) == 1 && flaga != 1) {
			window.clear();
			if (!inicjacja) {
				
				if (ustawienia.getLevel() == 1) {
					plansza = Plansza(6,3);
					a = 6;
					b = 3;
				}
				else if (ustawienia.getLevel() == 2) {
					plansza = Plansza(14, 7);
					a = 14;
					b = 7;
				}
				else if (ustawienia.getLevel() == 3) {
					plansza = Plansza(20, 10);
					a = 20;
					b = 10;
				}
				inicjacja=true;
			}
			for (const auto& pole : plansza.getPlansza()) {
				window.draw(pole);
			}
			for (const auto& amam : plansza.getJedzenie()) {
				window.draw(amam);
			}

			if (zegar.getElapsedTime().asMilliseconds() > 150.0f) {

				pacman.animuj();
				zegar.restart();
			}

			for (const auto& przeszkoda : plansza.getPrzeszkoda()) {
				pacman.kolizja(pacman.getPacman(), przeszkoda);
			}

			pacman.kolizjaamam(pacman.getPacman(), plansza, window);
			pacman.poruszanie(a, b);

			pacman.kolizjaamam(pacman.getPacman(), plansza, window);
			if (plansza.kontrolaWygranej() == 1) {
				window.draw(interfejs.getWygrana());
			}
			
			ustawienia.kolizja(window);

			window.draw(plansza.getRamka());
			window.draw(pacman.getPacman());
			window.draw(ustawienia.getX());
			window.draw(pacman.getNapis());
			window.draw(pacman.getWynik());
		}

		if (interfejs.getOkna(window) == 3) {
			window.clear(sf::Color(145, 230, 167));
			ustawienia.kolizja(window);
			for (const auto& pole : ustawienia.getPola()) {
				window.draw(pole);
			}

			for (const auto& tekst : ustawienia.getTekst()) {
				window.draw(tekst);
			}/*
			window.draw(interfejs.getPacman());
			window.draw(interfejs.napis());*/
			ustawienia.kolizja(window);
			window.draw(ustawienia.getX());
			window.draw(ustawienia.poziomT(window));
		}
			
		
		window.display();
	}


	return 0;
}