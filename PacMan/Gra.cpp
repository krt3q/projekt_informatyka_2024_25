#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"





int main()
{

	sf::RenderWindow window(sf::VideoMode(1000, 800), "SFML works!");

	Plansza plansza(800, 400);

	sf::RectangleShape kulko;
	kulko.setPosition(sf::Vector2f(830.f, 30.f));
	kulko.setSize(sf::Vector2f(100,100));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(plansza.getPlansza_1());
		window.draw(kulko);
		window.display();
	}




	return 0;
}