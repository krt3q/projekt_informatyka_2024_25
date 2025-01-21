#pragma once
#include <random>
#include <vector>
#include <iostream>
#include "Ustawienia.h"


class Interfejs
{
private: 

	//Parametry
	int parametr1;
	int parametr2 = 0;
	int a = 350;
	int b = 220;
	int i = 0;

	int okno = 0;

	//Pacman wraz z animacj¹
	sf::Sprite Pacman;
	sf::Texture tekstura;
	sf::Clock zegar;
	sf::IntRect klatki;
	int poczatekSprite = 0;
	int koniecSprite = 100;

	//Pola tekstowe
	std::vector<sf::RectangleShape> pola;
	sf::RectangleShape graj;
	sf::RectangleShape ustawienia;
	sf::RectangleShape exit;
	sf::RectangleShape zapis;

	sf::Font czycionka;

	//Wordart
	sf::Sprite tekst;
	sf::Texture teks;
	sf::Clock zegar1;

	//Napisy
	std::vector<sf::Text> napisy;
	sf::Text textG;
	sf::Text textZ;
	sf::Text textU;

	//Wygrana
	sf::Clock zegarW;
	sf::Sprite winek;
	sf::Texture wygrana;
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

		tekst.setPosition(sf::Vector2f(300, 150));
		teks.loadFromFile("wordart.png");
		tekst.setTexture(teks);
		tekst.setScale(0.5, 0.5);
		tekst.setOrigin((sf::Vector2f)teks.getSize() / 2.f);

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
			i++;
			if (i == 2)
				a = b;
		}

		if (!tekstura.loadFromFile("Pacman.png"))
			std::cerr << "B³¹d";
		klatki.height = 40;
		klatki.width = 40;
		klatki.top = 0;
		klatki.left = 0;
		Pacman.setPosition(sf::Vector2f(100, 330));
		tekstura.loadFromFile("Pacman.png");
		Pacman.setTexture(tekstura);
		Pacman.setTextureRect(klatki);
		Pacman.setScale(sf::Vector2f(10, 10));


		winek.setPosition(sf::Vector2f(650, 500));
		wygrana.loadFromFile("wordart2.png");
		winek.setTexture(wygrana);
		winek.setScale(0.5, 0.5);
	}
	void kolizja(sf::RenderWindow& window) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (pola[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				okno = 1;
			}
			if (pola[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				okno = 2;
			}
			if (pola[2].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				okno = 3;
			}
		}
		for (auto& pole : pola) {
			if (pole.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				pole.setFillColor(sf::Color(148, 184, 242));
			}
			else
				pole.setFillColor(sf::Color(232, 215, 139));
		}
	}



	std::vector<sf::Text> getTekst() {
		return napisy;
	}
	std::vector<sf::RectangleShape> getPola() {
		return pola;
	}
	int getOkna(sf::RenderWindow& window){
		Ustawienia ustawienia(5);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (ustawienia.getX().getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				okno = 0;
			}
		}
		return okno;
	}
	sf::Sprite getPacman() {
		if (zegar.getElapsedTime().asMilliseconds() > 150.0f) {
			if (klatki.top == koniecSprite) {
				klatki.top = poczatekSprite;
			}
			else
				klatki.top += 50;
			Pacman.setTextureRect(klatki);
			zegar.restart();
		}
		return Pacman;
	}
	sf::Sprite napis() {
		if (zegar1.getElapsedTime().asMilliseconds() > 100.0f) {
			tekst.rotate(10);
			zegar1.restart();
		}
		return tekst;
	}
	sf::Sprite getWygrana() {
		winek.setOrigin((sf::Vector2f)wygrana.getSize() / 2.f);

		if (zegarW.getElapsedTime().asMilliseconds() > 100.0f) {
			winek.rotate(10);
			zegarW.restart();
		}
		return winek;
	}

	int getOkna_tylkoINT() {
		return okno;
	}
};

