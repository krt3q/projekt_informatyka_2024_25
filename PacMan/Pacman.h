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
	int flaga;

	int punkty = 0;

	sf::Text twojwynik;
	sf::Text wynik;
	sf::Font czczionka;
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
		Pacman_S.setPosition(pozycjaPacmana(a, b));
		twojwynik.setPosition(10, 10);
		czczionka.loadFromFile("BRITANIC.TTF");
		twojwynik.setString("Twoj wynik: ");
		twojwynik.setFont(czczionka);
		twojwynik.setFillColor(sf::Color::White);
		twojwynik.setCharacterSize(30);
	}

	//Poruszanie klawiatura
	void poruszanie(int a, int b) {
		float velo = 0.1;
		Plansza plansza(20, 10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (kol != 1 && (bool)(Pacman_S.getPosition().y > (float)plansza.getRamka().getPosition().y) == 1) {
				Pacman_S.move(0, -velo);
				klawisz = 1;
				kol = 0;
				flaga = 0;
			}
			else
				Pacman_S.move(0, 0);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			if (kol != 2 && (bool)(Pacman_S.getPosition().y < (float)plansza.getRamka().getPosition().y + 60 * b - 40) == 1) {
				Pacman_S.move(0, velo);
				klawisz = 2;
				kol = 0;
				flaga = 0;
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
				flaga = 0;
			}
			else
				Pacman_S.move(0, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			if (kol != 4 && (bool)(Pacman_S.getPosition().x < (float)plansza.getRamka().getPosition().x + 60 * a - 40) == 1) {
				Pacman_S.move(velo, 0);
				klawisz = 4;
				kol = 0;
				flaga = 0;
			}
			else
				Pacman_S.move(0, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && flaga != 1)
		{
			Pacman_S.setPosition(Pacman_S.getPosition().x + 60, Pacman_S.getPosition().y - 60);
			flaga = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && flaga != 1)
		{
			Pacman_S.setPosition(Pacman_S.getPosition().x - 60, Pacman_S.getPosition().y - 60);
			flaga = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && flaga != 1)
		{
			Pacman_S.setPosition(Pacman_S.getPosition().x + 60, Pacman_S.getPosition().y + 60);
			flaga = 1;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && flaga != 1)
		{
			Pacman_S.setPosition(Pacman_S.getPosition().x - 60, Pacman_S.getPosition().y + 60);
			flaga = 1;
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
		std::vector<sf::Vector2f> polapocz¹tkowe;
		Plansza plansza(a, b);
		for (const auto& pole : plansza.getPlansza()) {
			if (pole.getFillColor() == sf::Color::Transparent) {
				polapocz¹tkowe.push_back(pole.getPosition());
			}
		}
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1, polapocz¹tkowe.size());
		pozycja = polapocz¹tkowe[dist(rng)];
		pozycja.x -= 10;
		pozycja.y -= 10;
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
	}
	void kolizjaamam(const sf::Sprite& pacman, Plansza& plansza, sf::RenderWindow& window) {
		for (auto& jedzenie : plansza.getJedzenie()) {
			if (sprawdzenieKolizji(pacman, jedzenie)) {
				jedzenie.setPosition(sf::Vector2f(1500, 1500));
				punkty++;
				std::cout << "Twój wynik to: " << punkty << std::endl;;
			}
		}
	}

	sf::Text getNapis() {
		return twojwynik;
	}
};

