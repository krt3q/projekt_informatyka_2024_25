#pragma once
#include "Plansza.h"
#include <iostream>;
class Pacman
{
private:
	//sf::CircleShape Pakman;
	sf::Vector2f pozycja;
	int poczatekSprite;
	int koniecSprite;
	sf::Sprite Pacman_S;
	//sf::Event event;
	sf::Texture tekstura;
	sf::IntRect ksztaltPacmana;
public:
	Pacman(int a, int b) {
		if (!tekstura.loadFromFile("Pacman.png"))
			std::cerr << "Błąd";
		poczatekSprite = 0;
		koniecSprite = 100;
		tekstura.loadFromFile("Pacman.png");
		ksztaltPacmana.height = 40;
		ksztaltPacmana.width = 40;
		ksztaltPacmana.top = 0;
		ksztaltPacmana.left = 0;
		Pacman_S.setTextureRect(ksztaltPacmana);
		Pacman_S.setTexture(tekstura);
		Pacman_S.setPosition(pozycjaPacmana(a,b));
	}

	
	void poruszanie() {
		sf::Clock zegar;
		float vel = 0.1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			Pacman_S.setPosition(Pacman_S.getPosition().x, Pacman_S.getPosition().y - 0.1);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Pacman_S.move(0, vel);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Pacman_S.move(-vel, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			Pacman_S.move(vel, 0);
		}
	}
	void animuj() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			poczatekSprite = 450;
			koniecSprite = 550;
			ksztaltPacmana.top = poczatekSprite;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			poczatekSprite = 150;
			koniecSprite = 250;
			ksztaltPacmana.top = poczatekSprite;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			poczatekSprite = 300;
			koniecSprite = 400;
			ksztaltPacmana.top = poczatekSprite;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			poczatekSprite = 0;
			koniecSprite = 100;
			ksztaltPacmana.top = poczatekSprite;
		}
		if (ksztaltPacmana.top == koniecSprite) {
			ksztaltPacmana.top = poczatekSprite;
		}
		else
			ksztaltPacmana.top += 50;

		Pacman_S.setTextureRect(ksztaltPacmana);
	}
	sf::Vector2f pozycjaPacmana(int a, int b) {
		std::vector<sf::RectangleShape> polapoczątkowe;
		Plansza plansza(a, b);
		sf::RectangleShape* pola = plansza.getPlansza();
		for (int i = 0; i < a * b; i++) {
			if (pola[i].getFillColor() != sf::Color::Cyan) {
				polapoczątkowe.push_back(pola[i]);
			}
		}
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1, polapoczątkowe.size());
		pozycja = polapoczątkowe[dist(rng)].getPosition();
		pozycja.x += 5;
		pozycja.y += 5;
		return pozycja;
	}
	sf::Sprite getPacman() {
		return Pacman_S;
	}
	/*sf::IntRect ksztaltpacmana(){
		return ksztaltPacmana;
	}*/
};

