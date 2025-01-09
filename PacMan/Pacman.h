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
			std::cerr << "B³¹d";
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
		float vel = 0.2;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			pozycja = Pacman_S.getPosition();
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
		std::vector<sf::RectangleShape> polapocz¹tkowe;
		Plansza plansza(a, b);
		sf::RectangleShape* pola = plansza.getPlansza();
		for (int i = 0; i < a * b; i++) {
			if (pola[i].getFillColor() != sf::Color::Cyan) {
				polapocz¹tkowe.push_back(pola[i]);
			}
		}
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1, polapocz¹tkowe.size());
		pozycja = polapocz¹tkowe[dist(rng)].getPosition();
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

