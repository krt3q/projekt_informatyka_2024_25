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
	int klawisz;
	int kol;
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (kol != 1)
				Pacman_S.move(0, -vel);
			else
				NULL;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			Pacman_S.move(0, vel);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Pacman_S.move(-vel, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			Pacman_S.move(vel, 0);
		}
	}
	void animuj() {
		sf::Clock zegar;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			poczatekSprite = 450;
			koniecSprite = 550;
			ksztaltPacmana.top = poczatekSprite;
			klawisz = 1;
			
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			poczatekSprite = 150;
			koniecSprite = 250;
			ksztaltPacmana.top = poczatekSprite;
			klawisz = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			poczatekSprite = 300;
			koniecSprite = 400;
			ksztaltPacmana.top = poczatekSprite;
			klawisz = 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			poczatekSprite = 0;
			koniecSprite = 100;
			ksztaltPacmana.top = poczatekSprite;
			klawisz = 4;
		}
		
		if (ksztaltPacmana.top == koniecSprite) {
			ksztaltPacmana.top = poczatekSprite;
		}
		else
			ksztaltPacmana.top += 50;
		Pacman_S.setTextureRect(ksztaltPacmana);
		zegar.restart();
		
	}
	sf::Vector2f pozycjaPacmana(int a, int b) {
		std::vector<sf::RectangleShape> polapoczątkowe;
		Plansza plansza(a, b);
		sf::RectangleShape* pola = plansza.getPlansza();
		for (int i = 0; i < a * b; i++) {
			if (pola[i].getFillColor() == sf::Color::Transparent) {
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
	bool sprawdzenieKolizji(const sf::Sprite& pacman, const sf::RectangleShape& przeszkoda) {
		Plansza plansza(20, 10);
		for (int i = 0; i < 20 * 10; i++) {
			if (plansza.getPlansza()[i].getFillColor()==sf::Color::Cyan)
				return pacman.getGlobalBounds().intersects(przeszkoda.getGlobalBounds());
		}
		return NULL;
		
	}
	void kolizja(const sf::Sprite& pacman, const sf::RectangleShape& przeszkoda) {
		if (sprawdzenieKolizji(pacman, przeszkoda)) {
			switch (klawisz) {
			case 1:
				kol = 1;
				std::cout << "gej";
			case 2:
				kol = 2;
			case 3:
				kol = 3;
			case 4:
				kol = 4;
			}
		}
	}
	/*sf::IntRect ksztaltpacmana(){
		return ksztaltPacmana;
	}*/
};

