#pragma once
#include "Plansza.h"
#include <iostream>;
#include <sstream>;

class Pacman
{
private:
	sf::Vector2f pozycja;

	//Zmienne do animacji
	int poczatekSprite;
	int koniecSprite;
	int poczatekDucha;
	int koniecDucha;


	//Sprite
	sf::Sprite Pacman_S;
	sf::Texture tekstura;
	sf::IntRect ksztaltPacmana;

	//Zmienne do kolizji
	int klawisz;
	int kol;
	sf::Vector2f vel;
	int flaga;

	//Tekst do wyœwietlania punktów
	sf::Text twojwynik;
	sf::Text wynik;
	sf::Font czczionka;

	//Duszek czerwony
	sf::Sprite duszekCz;
	sf::Texture teksturaCZ;
	sf::IntRect ksztaltDuszkaCz;

	//Duszek ró¿owy
	sf::Sprite duszekR;
	sf::Texture teksturaR;
	sf::IntRect ksztaltDuszkaR;

	//Duszek niebieski
	sf::Sprite duszekN;
	sf::Texture teksturaN;
	sf::IntRect ksztaltDuszkaN;

	//Zbiór duszków
	std::vector<sf::Sprite> duszki;

	//Zmienne do kolizji duszków
	bool checkCz = false;
	bool checkR = false;
	bool checkN = false;
	int losowaCz;
	int losowaR;
	int losowaN;
	int auaCz;
	int auaR;
	int auaN;
	int kierunek;

public:

	//Punkty
	int punkty = 0;

	//Konstruktor
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
		Pacman_S.setPosition(pozycjaPacmana());
		twojwynik.setPosition(10, 10);
		czczionka.loadFromFile("BRITANIC.TTF");
		twojwynik.setString("Twoj wynik: ");
		twojwynik.setFont(czczionka);
		twojwynik.setFillColor(sf::Color::White);
		twojwynik.setCharacterSize(30);
		
		if (!teksturaCZ.loadFromFile("Duszki.png"))
			std::cerr << "B³¹d";
		teksturaR.loadFromFile("Duszki.png");
		teksturaN.loadFromFile("Duszki.png");
		poczatekDucha = 0;
		koniecDucha = 50;
		ksztaltDuszkaCz.height = 40;
		ksztaltDuszkaCz.width = 40;
		ksztaltDuszkaCz.top = 0;
		ksztaltDuszkaCz.left = 0;
		duszekCz.setTexture(teksturaCZ);
		duszekCz.setTextureRect(ksztaltDuszkaCz);
		duszekCz.setPosition(308,248);

		ksztaltDuszkaR.height = 40;
		ksztaltDuszkaR.width = 40;
		ksztaltDuszkaR.top = 0;
		ksztaltDuszkaR.left = 50;
		duszekR.setTexture(teksturaR);
		duszekR.setTextureRect(ksztaltDuszkaR);
		duszekR.setPosition(303, 183);

		ksztaltDuszkaN.height = 40;
		ksztaltDuszkaN.width = 40;
		ksztaltDuszkaN.top = 0;
		ksztaltDuszkaN.left = 100;
		duszekN.setTexture(teksturaN);
		duszekN.setTextureRect(ksztaltDuszkaN);
		duszekN.setPosition(308, 128);
	}

	//Poruszanie klawiatura
	void poruszanie(int a, int b) {
		float velo = 0.2;
		Plansza plansza(a, b);
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

	void animujDuszka() {
		sf::Clock duch;
		if (ksztaltDuszkaCz.top == koniecDucha) {
			ksztaltDuszkaCz.top = poczatekDucha;
		}
		else
			ksztaltDuszkaCz.top += 50;
		duszekCz.setTextureRect(ksztaltDuszkaCz);
		duch.restart();
	}

	void poruszanieDuszkaCz(int a, int b) {
		float vel = 1;
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1, 4);
		if (checkCz == false) {
			losowaCz = dist(rng);
			checkCz = true;
		}
		//std::cout << losowa;

		Plansza plansza(a, b);
		if (losowaCz == 1)
		{
			if (auaCz != 1 && (bool)(duszekCz.getPosition().y > (float)plansza.getRamka().getPosition().y) == 1) {
				duszekCz.move(0, -vel);
				kierunek++;
			}
			else {
				duszekCz.move(0, 0);
				checkCz = false;
			}
		}

		if (losowaCz == 2)
		{
			if (auaCz != 2 && (bool)(duszekCz.getPosition().y < (float)plansza.getRamka().getPosition().y + 60 * b - 40) == 1) {
				duszekCz.move(0, vel);
				kierunek++;
			}
			else {
				duszekCz.move(0, 0);
				checkCz = false;
			}
		}
		if (losowaCz == 3)
		{
			if (auaCz != 3 && (bool)(duszekCz.getPosition().x > (float)plansza.getRamka().getPosition().x) == 1) {
				duszekCz.move(-vel, 0);
			}
			else {
				duszekCz.move(0, 0);
				checkCz = false;
			}
		}
		if (losowaCz == 4)
		{
			if (auaCz != 4 && (bool)(duszekCz.getPosition().x < (float)plansza.getRamka().getPosition().x + 60 * a - 40) == 1) {
				duszekCz.move(vel, 0);
			}
			else {
				duszekCz.move(0, 0);
				checkCz = false;
			}
		}
	}

	void poruszanieDuszkaR(int a, int b) {
		float vel = 0.5;
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1, 4);
		if (checkR == false) {
			losowaR = dist(rng);
			checkR = true;
		}
		//std::cout << losowa;

		Plansza plansza(a, b);
		if (losowaR == 1)
		{
			if (auaR != 1 && (bool)(duszekR.getPosition().y > (float)plansza.getRamka().getPosition().y) == 1) {
				duszekR.move(0, -vel);
			}
			else {
				duszekR.move(0, 0);
				checkR = false;
			}
		}

		if (losowaR == 2)
		{
			if (auaR != 2 && (bool)(duszekR.getPosition().y < (float)plansza.getRamka().getPosition().y + 60 * b - 40) == 1) {
				duszekR.move(0, vel);
			}
			else {
				duszekR.move(0, 0);
				checkR = false;
			}
		}
		if (losowaR == 3)
		{
			if (auaR != 3 && (bool)(duszekR.getPosition().x > (float)plansza.getRamka().getPosition().x) == 1) {
				duszekR.move(-vel, 0);
			}
			else {
				duszekR.move(0, 0);
				checkR = false;
			}
		}
		if (losowaR == 4)
		{
			if (auaR != 4 && (bool)(duszekR.getPosition().x < (float)plansza.getRamka().getPosition().x + 60 * a - 40) == 1) {
				duszekR.move(vel, 0);
			}
			else {
				duszekR.move(0, 0);
				checkR = false;
			}
		}
	}
	void poruszanieDuszkaN(int a, int b) {
		float vel = 1;
		std::random_device dev;
		std::mt19937 rng(dev());
		std::uniform_int_distribution<std::mt19937::result_type> dist(1, 4);
		if (checkN == false) {
			losowaN = dist(rng);
			checkN = true;
		}
		//std::cout << losowa;

		Plansza plansza(a, b);
		if (losowaN == 1)
		{
			if (auaN != 1 && (bool)(duszekN.getPosition().y > (float)plansza.getRamka().getPosition().y) == 1) {
				duszekN.move(0, -vel);
			}
			else {
				duszekN.move(0, 0);
				checkN = false;
			}
		}

		if (losowaN == 2)
		{
			if (auaN != 2 && (bool)(duszekN.getPosition().y < (float)plansza.getRamka().getPosition().y + 60 * b - 40) == 1) {
				duszekN.move(0, vel);
			}
			else {
				duszekN.move(0, 0);
				checkN = false;
			}
		}
		if (losowaN == 3)
		{
			if (auaN != 3 && (bool)(duszekN.getPosition().x > (float)plansza.getRamka().getPosition().x) == 1) {
				duszekN.move(-vel, 0);
			}
			else {
				duszekCz.move(0, 0);
				checkN = false;
			}
		}
		if (losowaN == 4)
		{
			if (auaN != 4 && (bool)(duszekN.getPosition().x < (float)plansza.getRamka().getPosition().x + 60 * a - 40) == 1) {
				duszekN.move(vel, 0);
			}
			else {
				duszekN.move(0, 0);
				checkN = false;
			}
		}
	}

	//Zwracanie wektora (kiedyœ losowej) pozycji pocz¹tkowej Pacmana
	sf::Vector2f pozycjaPacmana() {
		/*std::vector<sf::Vector2f> polapocz¹tkowe;
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
		pozycja.y -= 10;*/
		pozycja.x = 13;
		pozycja.y = 133;
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

	void kolizjaDuszkaCz(const sf::Sprite& duszek, const sf::RectangleShape& przeszkoda) {
		if (sprawdzenieKolizji(duszek, przeszkoda)) {
			if (losowaCz == 1)
				auaCz = 1;
			if (losowaCz == 2)
				auaCz = 2;
			if (losowaCz == 3)
				auaCz = 3;
			if (losowaCz == 4)
				auaCz = 4;
		}
	}
	void kolizjaDuszkaR(const sf::Sprite& duszek, const sf::RectangleShape& przeszkoda) {
		if (sprawdzenieKolizji(duszek, przeszkoda)) {
			if (losowaR == 1)
				auaR = 1;
			if (losowaR == 2)
				auaR = 2;
			if (losowaR == 3)
				auaR = 3;
			if (losowaR == 4)
				auaR = 4;
		}
	}
	void kolizjaDuszkaN(const sf::Sprite& duszek, const sf::RectangleShape& przeszkoda) {
		if (sprawdzenieKolizji(duszek, przeszkoda)) {
			if (losowaN == 1)
				auaN = 1;
			if (losowaN == 2)
				auaN = 2;
			if (losowaN == 3)
				auaN = 3;
			if (losowaN == 4)
				auaN = 4;
		}
	}

	//Kolizja z jedzeniem
	void kolizjaamam(const sf::Sprite& pacman, Plansza& plansza, sf::RenderWindow& window) {
		for (auto& jedzenie : plansza.getJedzenie()) {
			if (sprawdzenieKolizji(pacman, jedzenie)) {
				jedzenie.setPosition(sf::Vector2f(1500, 1500));
				punkty++;
				//std::cout << "Twój wynik to: " << punkty << std::endl;;
			}
		}
	}

	//Zwracanie liczby punktów
	int getPunkty() {
		return punkty;
	}

	//Zerowanie punktów
	void zerujPunkty() {
		punkty = 0;
	}

	//Zwracanie tekstu z wynikiem
	sf::Text getWynik() {
		sf::Clock zegar;
		wynik.setPosition(200, 10);
		wynik.setFont(czczionka);
		wynik.setFillColor(sf::Color::White);
		wynik.setCharacterSize(30);
		if (zegar.getElapsedTime().asMilliseconds() < 150.0f) {
			wynik.setString(toString(punkty));
		}
		return wynik;
	}

	//Zwracanie wyniku
	sf::Text getNapis() {
		return twojwynik;
	}

	//Konwertowanie int na string
	std::string toString(int wynik) {
		std::stringstream os;
		os << wynik;
		return os.str();
	}

	sf::Sprite getDuszekCz() {
		return duszekCz;
	}

	sf::Sprite getDuszekR() {
		return duszekR;
	}

	sf::Sprite getDuszekN() {
		return duszekN;
	}

	void czekaj(int milisekundy) {
		std::this_thread::sleep_for(std::chrono::milliseconds(milisekundy));
	}

	void zeruj() {
		checkCz = false;
		checkR = false;
		checkN = false;
	}
};

