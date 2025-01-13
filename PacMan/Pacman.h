#pragma once
#include "Plansza.h"
#include <iostream>;
class Pacman
{
private:
	sf::Vector2f pozycja;

	//Zmienne do animacji
	int poczatekSprite;
	int koniecSprite;

	//Sprite
	sf::Sprite Pacman_S;
	sf::Texture tekstura;
	sf::IntRect ksztaltPacmana;

	//Zmienne do kolizji
	int klawisz;
	int kol;
	sf::Vector2f vel;
public:
	//Konstruktor
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

	//Poruszanie klawiatura
	void poruszanie() {
		float velo = 0.1;
		Plansza plansza(20, 10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (kol != 1 && (bool)(Pacman_S.getPosition().y > (float)plansza.getRamka().getPosition().y) == 1) {
				Pacman_S.move(0, -velo);
				klawisz = 1;
				kol = 0;
			}
			else
				Pacman_S.move(0, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (kol != 2 && (bool)(Pacman_S.getPosition().y < (float)plansza.getRamka().getPosition().y+60*10-40) == 1) {
				Pacman_S.move(0, velo);
				klawisz = 2;
				kol = 0;
			}
			else
				Pacman_S.move(0, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (kol != 3 && (bool)(Pacman_S.getPosition().x > (float)plansza.getRamka().getPosition().x) == 1) {
				Pacman_S.move(-velo, 0);
				klawisz = 3;
				kol = 0;
			}
			else
				Pacman_S.move(0, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (kol != 4 && (bool)(Pacman_S.getPosition().x < (float)plansza.getRamka().getPosition().x+60*20-40) == 1) {
				Pacman_S.move(velo, 0);
				klawisz = 4;
				kol = 0;
			}
			else
				Pacman_S.move(0, 0);
		}
	}

	//Animacja + klawiatura
	void animuj() {
		sf::Clock zegar;
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
		zegar.restart();
		
	}

	//Zwracanie wektora losowej pozycji pocz¹tkowej Pacmana
	sf::Vector2f pozycjaPacmana(int a, int b) {
		std::vector<sf::RectangleShape> polapocz¹tkowe;
		Plansza plansza(a, b);
		for (int i = 0; i < a * b; i++) {
			if (plansza.getPlansza()[i].getFillColor() == sf::Color::Transparent) {
				polapocz¹tkowe.push_back(plansza.getPlansza()[i]);
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

	//Zwracanie Sprite
	sf::Sprite getPacman() {
		return Pacman_S;
	}

	//Sprawdzenie Kolizji, która zwraca 1 albo 0
	bool sprawdzenieKolizji(const sf::Sprite& pacman, const sf::RectangleShape& przeszkoda) {
		return pacman.getGlobalBounds().intersects(przeszkoda.getGlobalBounds());
	}

	//Je¿eli zaistnia³a kolizja to zmienia wartoœæ zmiennej kol w zale¿noœci od ostatniego wciœniêtego przycisku
	void kolizja(const sf::Sprite& pacman, const sf::RectangleShape& przeszkoda) {
		//kol = 0;
		if (sprawdzenieKolizji(pacman, przeszkoda)) {
			if (klawisz == 1)
				kol = 1;
			if (klawisz == 2)
				kol = 2;
			if (klawisz == 3)
				kol = 3;
			if (klawisz == 4)
				kol = 4;
		}
		/*if (!sprawdzenieKolizji(pacman, przeszkoda)) {
			std::cout << "1";
		}*/
	}
	/*sf::IntRect ksztaltpacmana(){
		return ksztaltPacmana;
	}*/
};

