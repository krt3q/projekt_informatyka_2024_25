#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"


int main() {

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::RectangleShape graj;
	sf::RectangleShape ustawienia;
	sf::RectangleShape exit;
	sf::RectangleShape zapis;
	sf::Font czycionka;
	sf::Text textG;
	sf::Text textZ;
	sf::Text textU;
	if (!czycionka.loadFromFile("britanic.ttf")) {
		std::cerr << "B³¹d";
		return 0;
	}
	graj.setSize(sf::Vector2f(500, 150));
	graj.setOutlineThickness(3);
	graj.setOutlineColor(sf::Color::Blue);
	graj.setPosition(400, 250);
	ustawienia.setSize(sf::Vector2f(500, 150));
	ustawienia.setOutlineThickness(3);
	ustawienia.setOutlineColor(sf::Color::Blue);
	ustawienia.setPosition(400, 450);
	zapis.setSize(sf::Vector2f(500, 150));
	zapis.setOutlineThickness(3);
	zapis.setOutlineColor(sf::Color::Blue);
	zapis.setPosition(400, 650);
	textG.setFont(czycionka);
	textG.setString("Graj !");
	textG.setFillColor(sf::Color::Blue);
	textG.setCharacterSize(54);
	textG.setPosition(graj.getPosition().x+350, graj.getPosition().y+37);
	textU.setFont(czycionka);
	textU.setString("Ustawienia");
	textU.setFillColor(sf::Color::Blue);
	textU.setCharacterSize(54);
	textU.setPosition(ustawienia.getPosition().x + 220, ustawienia.getPosition().y + 37);
	textZ.setFont(czycionka);
	textZ.setString("Zapis");
	textZ.setFillColor(sf::Color::Blue);
	textZ.setCharacterSize(54);
	textZ.setPosition(zapis.getPosition().x + 350, zapis.getPosition().y + 37);
	while (window.isOpen())
	{
		sf::Event event;
		graj.setFillColor(sf::Color(55, 72, 99));
		ustawienia.setFillColor(sf::Color(55, 72, 99));
		zapis.setFillColor(sf::Color(55, 72, 99));
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (graj.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
					std::cout << "gej";
				}
				if (ustawienia.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
					std::cout << "zesty";
				}
				if (zapis.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
					std::cout << "fruity";
				}
			}
		}
		if (graj.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
			graj.setFillColor(sf::Color(148, 184, 242));
		}
		if (ustawienia.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
			ustawienia.setFillColor(sf::Color(148, 184, 242));
		}
		if (zapis.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
			zapis.setFillColor(sf::Color(148, 184, 242));
		}
		window.clear();
		window.draw(graj);
		window.draw(ustawienia);
		window.draw(zapis);
		window.draw(textG);
		window.draw(textU);
		window.draw(textZ);
		window.display();
	}
	return 0;


	return 0;
}