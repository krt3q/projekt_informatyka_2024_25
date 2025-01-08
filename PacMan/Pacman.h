#pragma once
#include "Plansza.h"
#include <iostream>;
class Pacman
{
private:
	//sf::CircleShape Pakman;
	sf::Vector2f vel;
	int poczatekSprite;
	int koniecSprite;
	sf::Sprite Pacman_S;
	sf::IntRect ksztaltPacmana;
	//sf::Event event;
	sf::Texture tekstura;
public:
	Pacman(int a) {
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
	}

	/*sf::Vector2f zmiana_vel() {
		sf::Event event;
		if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					vel.x = 0.0f;
					vel.y = -2.0f;
				}
				if (event.key.code == sf::Keyboard::S)
				{
					vel.x = 0.0f;
					vel.y = 2.0f;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					vel.x = -2.0f;
					vel.y = 0.0f;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					vel.x = 2.0f;
					vel.y = 0.0f;
				}
				return vel;
			}
		}*/
	void poruszanie() {
		
	}
	void animuj(sf::Event event) {
		/*if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::W)
			{
				std::cout << "a";
				poczatekSprite = 450;
				koniecSprite = 550;
				ksztaltPacmana.top = poczatekSprite;
			}

			if (event.key.code == sf::Keyboard::S)
			{
				std::cout << "a";
				poczatekSprite = 150;
				koniecSprite = 250;
				ksztaltPacmana.top = poczatekSprite;
			}
			if (event.key.code == sf::Keyboard::A)
			{
				std::cout << "a";
				poczatekSprite = 300;
				koniecSprite = 400;
				ksztaltPacmana.top = poczatekSprite;
			}
			if (event.key.code == sf::Keyboard::D)
			{
				std::cout << "a";
				poczatekSprite = 0;
				koniecSprite = 100;
				ksztaltPacmana.top = poczatekSprite;
			}
		}
		if (ksztaltPacmana.top == koniecSprite) {
			ksztaltPacmana.top = poczatekSprite;
		}
		else
			ksztaltPacmana.top += 50;

		Pacman_S.setTextureRect(ksztaltPacmana);*/
	}
	sf::Sprite getPacman() {
		return Pacman_S;
	}
	sf::IntRect ksztaltpacmana(){
		return ksztaltPacmana;
	}
};

