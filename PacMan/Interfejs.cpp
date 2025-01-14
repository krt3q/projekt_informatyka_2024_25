#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"


int main() {

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::RectangleShape graj;
	sf::Font czycionka;
	if (!czycionka.loadFromFile("britanic.ttf")) {
		std::cerr << "B³¹d";
		return 0;
	}
	graj.setSize(sf::Vector2f(500, 150));
	graj.setOutlineThickness(3);
	graj.setOutlineColor(sf::Color::Blue);
	graj.setPosition(400, 300);
	while (window.isOpen())
	{
		sf::Event event;
		graj.setFillColor(sf::Color::Transparent);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				std::cout << "gej";
				if (graj.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
					
				}
			}
		}
		if (graj.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
			graj.setFillColor(sf::Color(148, 184, 242));
		}
		window.clear();
		window.draw(graj);
		window.display();
	}
	return 0;


	return 0;
}