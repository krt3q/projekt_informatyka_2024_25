#pragma once
#include "Interfejs.h"
#include <vector>
#include <iostream>
#include "zapis.h"

class Ustawienia
{
private:

	//Parametry
	int parametr1;
	int parametr2 = 0;
	int a = 350;
	int b = 220;
	int i = 0;

	int okno = 0;

	int flaga;

	//Tu b�dzie duszek
	sf::Sprite Duszek;
	sf::Texture tekstura;
	sf::Clock zegar;
	sf::IntRect klatki;
	int poczatekSprite = 0;
	int koniecSprite = 50;

	//Opis p�l i przycisku exit
	std::vector<sf::RectangleShape> pola;
	sf::RectangleShape poziom;
	sf::RectangleShape gracze;
	sf::ConvexShape exit;

	sf::Font czcionka;

	//Napisy
	std::vector<sf::Text> napisy;
	sf::Text textP;
	sf::Text textG;

	//Krzy�yk
	sf::ConvexShape krzy�;
	sf::IntRect cofka;
	//sf::RectangleShape test;


	sf::Text stopien;
	
	int level;
	std::string nazwaGracza;


	//Pora�ka
	sf::Sprite pacmanPor;
	sf::Texture teksturaPor;
	sf::Clock zegarPrz;
	sf::IntRect klatkiPor;
	int poczatekSpritePor = 0;
	int koniecSpritePor = 550;

public:

	//Konstruktor
	Ustawienia(int d) {

		zapis zapis(1);
		cofka.top = 0;
		cofka.left = 0;
		cofka.height = 70;
		cofka.width = 70;
		krzy�.setPointCount(12);
		krzy�.setPoint(0, sf::Vector2f(10, 10));
		krzy�.setPoint(1, sf::Vector2f(30, 30));
		krzy�.setPoint(2, sf::Vector2f(10, 50));
		krzy�.setPoint(3, sf::Vector2f(20, 60));
		krzy�.setPoint(4, sf::Vector2f(40, 40));
		krzy�.setPoint(5, sf::Vector2f(60, 60));
		krzy�.setPoint(6, sf::Vector2f(70, 50));
		krzy�.setPoint(7, sf::Vector2f(50, 30));
		krzy�.setPoint(8, sf::Vector2f(70, 10));
		krzy�.setPoint(9, sf::Vector2f(60, 0));
		krzy�.setPoint(10, sf::Vector2f(40, 20));
		krzy�.setPoint(11, sf::Vector2f(20, 0));
		krzy�.setPosition(1200, 10);
		krzy�.setTextureRect(cofka);

		if (!czcionka.loadFromFile("britanic.ttf")) {
			std::cerr << "B��d";
		}

		//Tworzenie p�l tekstowych
		parametr1 = 0;
		pola.push_back(poziom);
		pola.push_back(gracze);
		for (auto& pole : pola) {
			pole.setSize(sf::Vector2f(700, 150));
			pole.setOutlineThickness(3);
			pole.setOutlineColor(sf::Color::Blue);
			pole.setPosition(500, 250 + 200 * parametr1);
			parametr1 += 1;
		}

		//Tworzenie napis�w
		textP.setString("Poziom trudnosci: ");
		textG.setString("Wybierz gracza: ");
		napisy.push_back(textP);
		napisy.push_back(textG);
		for (auto& tekst : napisy) {
			tekst.setFont(czcionka);
			tekst.setFillColor(sf::Color::Cyan);
			tekst.setCharacterSize(54);
			tekst.setPosition(pola[i].getPosition().x, pola[i].getPosition().y + 37);
			i++;
			if (i == 2)
				a = b;
		}
		klatki.height = 40;
		klatki.width = 40;
		klatki.top = 0;
		klatki.left = 0;
		Duszek.setPosition(sf::Vector2f(60, 215));
		tekstura.loadFromFile("Duszki.png");
		Duszek.setTexture(tekstura);
		Duszek.setTextureRect(klatki);
		Duszek.setScale(sf::Vector2f(10, 10));

		klatkiPor.height = 40;
		klatkiPor.width = 40;
		klatkiPor.top = 0;
		klatkiPor.left = 5;
		pacmanPor.setPosition(sf::Vector2f(500, 300));
		teksturaPor.loadFromFile("przegranAnimacja.png");
		pacmanPor.setTexture(teksturaPor);
		pacmanPor.setTextureRect(klatkiPor);
		pacmanPor.setScale(sf::Vector2f(10, 10));
	}

	//Kolizja ze wszystkim
	void kolizja(sf::RenderWindow& window, int a) {
		flaga = 0;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			/*if (krzy�.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				std::cout << "b";
			}*/

			//Wyb�r poziomu trudno�ci
			if (flaga == 0 && pola[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && okno == 0) {
				okno = 1;
				flaga = 1;
				//std::cout << level;
			}
			while (flaga == 1) {
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					break;
			}
			if (flaga == 0 && pola[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && okno == 1) {
				okno = 2;
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					flaga = 1;
				//std::cout << level;
			}
			while (flaga == 1) {
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					break;
			}
			if (flaga == 0 && pola[0].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && okno == 2) {
				okno = 0;
				flaga = 1;
				//std::cout << level;
			}
			while (flaga == 1) {
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					break;
			}

			if (flaga == 0 && pola[1].getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))) && a == 1) {
				okno = 0;
				flaga = 1;
				std::cout << "Wybierz gracza z ponizszych (wpisujac jego nick): \n";

				std::ifstream plik("dane.json");
				if (!plik.is_open()) {
					std::cerr << "Nie mozna otworzyc pliku!";
				}
				if (czyPlikjestPusty("dane.json")) {
					json stanGry;
					plik >> stanGry;
					plik.close();
					for (const auto& [nazwaGracza, daneGracza] : stanGry.items()) {
						std::cout << nazwaGracza << std::endl;
					}
				}

				std::cin >> nazwaGracza;
				if (nazwaGracza == "exit") {
					nazwaGracza = "";
				}
				
			}
			while (flaga == 1) {
				if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
					break;
			}

		//Zmiana kolor�w
		}
		for (auto& pole : pola) {
			if (pole.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
				pole.setFillColor(sf::Color(148, 184, 242));
			}
			else
				pole.setFillColor(sf::Color(232, 215, 139));
		}
		if (krzy�.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
			krzy�.setFillColor(sf::Color(245, 108, 66));
		}
		else
			krzy�.setFillColor(sf::Color::Red);


	}

	//Zmiana napis�w przy poziomie trudno�ci
	sf::Text poziomT(sf::RenderWindow& window) {
		stopien.setCharacterSize(54);
		stopien.setFont(czcionka);
		stopien.setFillColor(sf::Color::Cyan);
		if (okno == 0) {
			stopien.setString("Latwy");
			stopien.setPosition(napisy[0].getPosition().x + 500, napisy[0].getPosition().y);
			level = 1;
		}
		if (okno == 1) {
			stopien.setString("Sredni");
			stopien.setPosition(napisy[0].getPosition().x + 500, napisy[0].getPosition().y);
			level = 2;
		}
		if (okno == 2) {
			stopien.setString("Trudny");
			stopien.setPosition(napisy[0].getPosition().x + 500, napisy[0].getPosition().y);
			level = 3;
		}
	
		//std::cout << level << std::endl;
	
		return stopien;
	}

	sf::Sprite getDuszek() {
		if (zegar.getElapsedTime().asMilliseconds() > 150.0f) {
			if (klatki.top == koniecSprite) {
				klatki.top = poczatekSprite;
			}
			else
				klatki.top += 50;
			Duszek.setTextureRect(klatki);
			zegar.restart();
		}
		return Duszek;
	}

	sf::Sprite getPacman() {
		if (zegarPrz.getElapsedTime().asMilliseconds() > 200.0f) {
			if (klatkiPor.top == koniecSpritePor) {
				klatkiPor.top = poczatekSpritePor;
			}
			else
				klatkiPor.top += 50;
			pacmanPor.setTextureRect(klatkiPor);
			zegarPrz.restart();
		}
		return pacmanPor;
	}

	bool czyPlikjestPusty(const std::string& nazwaPliku) {
		std::ifstream plik(nazwaPliku);
		if (!plik.is_open()) {
			std::cerr << "Nie mo�na otworzy� pliku: " << nazwaPliku << std::endl;
			return false; // Lub inna obs�uga b��du
		}
		char c;
		plik >> std::noskipws >> c;
		return !plik.eof();
	}
	//Zwracanie napis�w
	std::vector<sf::Text> getTekst() {
		return napisy;
	}

	//Zwracanie p�l tekstowych
	std::vector<sf::RectangleShape> getPola() {
		return pola;
	}


	//Zwraca krzy�yk
	sf::ConvexShape getX()
	{
		return krzy�;
	}

	//Zwracanie int level
	int getLevel() {
		return level;
	}

	//Zwracanie gracza
	std::string getGracz(){
		return nazwaGracza;
	}
};