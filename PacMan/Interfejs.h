#pragma once
#include <random>
#include <vector>
#include <iostream>



class Interfejs
{
private: 

	int parametr1;
	int parametr2 = 0;
	int a = 350;
	int b = 220;
	int i=0;

	std::vector<sf::RectangleShape> pola;
	sf::RectangleShape graj;
	sf::RectangleShape ustawienia;
	sf::RectangleShape exit;
	sf::RectangleShape zapis;

	sf::Font czycionka;

	std::vector<sf::Text> napisy;
	sf::Text textG;
	sf::Text textZ;
	sf::Text textU;
public:
	Interfejs(int d) {
		if (!czycionka.loadFromFile("britanic.ttf")) {
			std::cerr << "B³¹d";
		}
		parametr1 = 0;
		pola.push_back(graj);
		pola.push_back(ustawienia);
		pola.push_back(exit);
		for (auto& pole : pola) {
			pole.setSize(sf::Vector2f(500, 150));
			pole.setOutlineThickness(3);
			pole.setOutlineColor(sf::Color::Blue);
			pole.setPosition(700, 250+200*parametr1);
			parametr1 += 1;
		}

		textG.setString("Graj !");
		textZ.setString("Zapis");
		textU.setString("Ustawienia");
		napisy.push_back(textG);
		napisy.push_back(textZ);
		napisy.push_back(textU);
		for (auto& tekst : napisy) {
			tekst.setFont(czycionka);
			tekst.setFillColor(sf::Color::Blue);
			tekst.setCharacterSize(54);
			tekst.setPosition(pola[i].getPosition().x + a, pola[i].getPosition().y + 37);
			std::cout << pola[i].getPosition().y << std::endl;
			i++;
			if (i == 2)
				a = b;
		}
	}
	void kolizja(sf::RenderWindow& window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (pola[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				std::cout << "gej";
			}
			if (pola[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				std::cout << "zesty";
			}
			if (pola[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				std::cout << "fruity";
			}
		}
		for (auto& pole : pola) {
			if (pole.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				pole.setFillColor(sf::Color(148, 184, 242));
			}
			else
				pole.setFillColor(sf::Color::White);
		}
	}

	std::vector<sf::Text> getTekst() {
		return napisy;
	}
	std::vector<sf::RectangleShape> getPola() {
		return pola;
	}
};

