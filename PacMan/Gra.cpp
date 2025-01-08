#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(1300, 1000), "SFML works!");

	int a = 20;
	int b = 10;
	int poczatekSprite=0;
	int koniecSprite = 100;

	Plansza plansza(a,b);
	Pacman pacman(5);

	sf::Texture tekstura;
	if (!tekstura.loadFromFile("Pacman.png")) {
		std::cout << "B³¹d";
		return 0;
	}

	sf::RectangleShape* pola = plansza.getPlansza();

	sf::Clock zegar;

	int flaga;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (zegar.getElapsedTime().asMilliseconds() > 100.0f) {
				pacman.animuj(event);
				zegar.restart();
			}
			window.clear();
			//window.draw(plansza.getPlansza_1());
			//window.draw(plansza.getPlansza_2());
			for (int i = 0; i < a * b; i++) {
				window.draw(pola[i]);
			}
			window.draw(plansza.getRamka());
			window.draw(pacman.getPacman());
			window.display();
		}
	}


	return 0;
}