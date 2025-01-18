#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"
#include "Interfejs.h"
#include "Ustawienia.h"
#include "Krzy¿yk.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(1300, 1000), "SFML works!");
	sf::Event event;


	int a = 20;
	int b = 10;
	int poczatekSprite=0;
	int koniecSprite = 100;
	

	Plansza plansza(a,b);


	sf::Clock zegar;

	int flaga;

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

		
		
		if (interfejs.getOkna(window) == 0) {
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
		

		if (interfejs.getOkna(window) == 1) {
			window.clear();
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
			window.draw(plansza.getRamka());
			window.draw(pacman.getPacman());
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