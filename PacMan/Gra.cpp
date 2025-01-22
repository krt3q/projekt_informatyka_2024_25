#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"
#include "Interfejs.h"
#include "Ustawienia.h"
#include "Krzy¿yk.h"
#include "zapis.h"



void wyczyœæKonsolê() {

	system("cls");
}



int main()
{
	sf::RenderWindow window(sf::VideoMode(1300, 1000), "SFML works!");
	sf::Event event;

	//Cyferki do planszy i pacmana
	int a = 14;
	int b = 7;
	int poczatekSprite=0;
	int koniecSprite = 100;
	
	//Konstruktor planszy
	Plansza plansza(a,b);

	//Zegar do animacji pacmana
	sf::Clock zegar;

	//Zmienne "markerowe"
	int flaga = 0;
	int pauza = 0;
	int nadpis = 0;
	int oknoZ = 0;

	//Zmienna inicjuj¹ca - funkcja/pêtla wykonuje siê tylko raz
	bool inicjacja = false;

	//String, który bêdzie definiowaæ nazwê gracza
	std::string nazwaGracza;

	//String, który bêdzie wywo³ywaæ zapis
	std::string kontynuacjaGracza;

	//Rozmiar Sprite Pacmana
	sf::IntRect ksztaltPacmana(0,0,40,40);

	//Dynamiczne tworzenie konstruktora pacmana
	Pacman* pacman = new Pacman(1);

	//Konstruktor interfejsu
	Interfejs interfejs(5);

	//Konstruktor ustawieñ
	Ustawienia ustawienia(5);

	//Konstruktor zapisu
	zapis zapis(1);


	struct zapisz {
		int punktyZ;
		sf::Vector2f pozycjaZ;
		std::vector<sf::RectangleShape> poleZ;
		std::vector<sf::RectangleShape> przeszkodaZ;
		std::vector<sf::RectangleShape> jedzenieZ;
	} gracz;
	





	//Otwarcie okna
	while (window.isOpen())
	{
		//Eventy
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		//Okno Interfejsu
		if (interfejs.getOkna(window) == 0 || flaga == 1) {
			inicjacja == false;
			interfejs.setOkno();
			flaga = 0;
			wyczyœæKonsolê();
			//Poziom trudnoœci nastawia odpowiednie parametry
			if (ustawienia.getLevel() == 1) {
				delete pacman;
				pacman = new Pacman(1);
				plansza = Plansza(6, 3);
				a = 6;
				b = 3;
			}
			else if (ustawienia.getLevel() == 2) {
				delete pacman;
				pacman = new Pacman(1);
				plansza = Plansza(14, 7);
				a = 14;
				b = 7;
			}
			else if (ustawienia.getLevel() == 3) {
				delete pacman;
				pacman = new Pacman(1);
				plansza = Plansza(20, 10);
				a = 20;
				b = 10;
			}
			
			//Zerowanie punktów i rysowanie interfejsu
			pacman->zerujPunkty();
			pacman->zeruj();
			window.clear();
			interfejs.kolizja(window);
			for (const auto& pole : interfejs.getPola()) {
				window.draw(pole);
			}

			for (const auto& tekst : interfejs.getTekst()) {
				window.draw(tekst);
			}
			window.draw(interfejs.getPacman());
			window.draw(interfejs.napis());
		}
		
		//Okno gry
		if (interfejs.getOkna(window) == 1 && flaga != 1) {
			window.clear();

			//Inicjacja - tworzenie parametrów
			if (!inicjacja) {
				
				if (ustawienia.getLevel() == 1) {
					plansza = Plansza(6,3);
					a = 6;
					b = 3;
				}
				else if (ustawienia.getLevel() == 2) {
					plansza = Plansza(14, 7);
					a = 14;
					b = 7;
				}
				else if (ustawienia.getLevel() == 3) {
					plansza = Plansza(20, 10);
					a = 20;
					b = 10;
				}
				inicjacja=true;
			}

			//Pauza
			while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || pauza == 1) {
				pauza = 1;
				int* opcja = new int;
				std::cout << "Kontynuuj [1]\n";
				std::cout << "Zapisz [2]\n";
				std::cin >> *opcja;

				//Kontynuacja
				if (*opcja == 1) {
					delete opcja;
					pauza = 0;
				}

				//Zapis
				else if (*opcja == 2) {
					delete opcja;
					zapis.zapisywanie("dane.json", ustawienia.getGracz(), pacman->getPunkty(), pacman->pozycjaPacmana(), plansza.getPlansza(), plansza.getPrzeszkoda(), plansza.getJedzenie(), a, b);
					wyczyœæKonsolê();
					pauza = 0;
				}
			}

			//Rysowanie planszy oraz pacmana, a tak¿e wywo³ywanie kolizji itp.
			if (nadpis == 0) {
				for (const auto& pole : plansza.getPlansza()) {
					window.draw(pole);
				}
				for (const auto& amam : plansza.getJedzenie()) {
					window.draw(amam);
				}

				if (zegar.getElapsedTime().asMilliseconds() > 150.0f) {

					pacman->animuj();
					pacman->animujDuszka();
					zegar.restart();
				}

				pacman->aktualizacja();

				for (const auto& przeszkoda : plansza.getPrzeszkoda()) {
					pacman->kolizja(pacman->getPacman(), przeszkoda);
				}

				for (const auto& przeszkoda : plansza.getPrzeszkoda()) {
					pacman->kolizjaDuszkaCz(pacman->getDuszekCz(), przeszkoda);
				}
				for (const auto& przeszkoda : plansza.getPrzeszkoda()) {
					pacman->kolizjaDuszkaR(pacman->getDuszekR(), przeszkoda);
				}
				for (const auto& przeszkoda : plansza.getPrzeszkoda()) {
					pacman->kolizjaDuszkaN(pacman->getDuszekN(), przeszkoda);
				}
				

				pacman->kolizjaamam(pacman->getPacman(), plansza.getJedzenie(), window);

				pacman->poruszanie(a, b);

				pacman->poruszanieDuszkaCz(a,b);
				pacman->poruszanieDuszkaR(a,b);
				pacman->poruszanieDuszkaN(a,b);

				//pacman->kolizjaamam(pacman->getPacman(), plansza, window);
				if (plansza.kontrolaWygranej() == 1) {
					window.draw(interfejs.getWygrana());
				}

				if (ustawienia.getLevel() == 3) {
					for (const auto& duszek : pacman->getDuszki()) {
						if (pacman->przegrana(pacman->getPacman(), duszek, window) == 1) {
							//window.draw(pacman->koniec());
							while (true) {
								window.draw(pacman->koniec()); 
								int koniec;
								std::cout << "Przegra³eœ, aby skonczyc wcisnij 1\n";
								std::cin >> koniec;
								if (koniec == 1) {
									flaga = 1;
									break;
								}
							}
						}
					}
					window.draw(pacman->getDuszekCz());
					window.draw(pacman->getDuszekR());
					window.draw(pacman->getDuszekN());
				}


				if (ustawienia.getLevel() == 2) {
					if (pacman->przegrana(pacman->getPacman(), pacman->getDuszekCz(), window)) {
						pacman->przegrana(pacman->getPacman(), pacman->getDuszekCz(), window);
						while (true) {
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (true) {
									int koniec;
									std::cout << "Przegra³eœ, aby skonczyc wcisnij 1\n";
									std::cin >> koniec;
									if (koniec == 1) {
										flaga = 1;
										break;
									}
								}
							}
						}
					}
					window.draw(pacman->getDuszekCz());
				}

				ustawienia.kolizja(window, 0);

				window.draw(plansza.getRamka());
				window.draw(pacman->getPacman());
				window.draw(ustawienia.getX());
				window.draw(pacman->getNapis());
				window.draw(pacman->getWynik(0));
			}
			if (nadpis == 1) {
				for (const auto& pole : zapis.zapisanePola()) {
					window.draw(pole);
				}
				for (const auto& amam : zapis.zapisaneJedzenie()) {
					window.draw(amam);
				}

				pacman->getPacman().setPosition(zapis.zapisanaPozycja());

				if (zegar.getElapsedTime().asMilliseconds() > 150.0f) {

					pacman->animuj();
					pacman->animujDuszka();
					zegar.restart();
				}

				pacman->kolizjaamam(pacman->getPacman(), zapis.zapisaneJedzenie(), window);

				pacman->aktualizacja();

				//std::cout << zapis.zapisanePunkty() << std::endl;
				for (const auto& przeszkoda : zapis.zapisanePrzeszkody()) {
					pacman->kolizja(pacman->getPacman(), przeszkoda);
				}
				for (const auto& przeszkoda : zapis.zapisanePrzeszkody()) {
					pacman->kolizjaDuszkaCz(pacman->getDuszekCz(), przeszkoda);
				}
				for (const auto& przeszkoda : zapis.zapisanePrzeszkody()) {
					pacman->kolizjaDuszkaR(pacman->getDuszekR(), przeszkoda);
				}
				for (const auto& przeszkoda : zapis.zapisanePrzeszkody()) {
					pacman->kolizjaDuszkaN(pacman->getDuszekN(), przeszkoda);
				}
				

				if (ustawienia.getLevel() == 3) {
					for (const auto& duszek : pacman->getDuszki()) {
						if (pacman->przegrana(pacman->getPacman(), duszek, window) == 1) {
							pacman->przegrana(pacman->getPacman(), duszek, window);
							while (true) {
								int koniec;
								std::cout << "Przegra³eœ, aby skonczyc wcisnij 1\n";
								std::cin >> koniec;
								if (koniec == 1) {
									flaga = 1;
									break;
								}
							}
						}
					}
					window.draw(pacman->getDuszekCz());
					window.draw(pacman->getDuszekR());
					window.draw(pacman->getDuszekN());
				}
				if (ustawienia.getLevel() == 2) {
					if (pacman->przegrana(pacman->getPacman(), pacman->getDuszekCz(), window)) {
						pacman->przegrana(pacman->getPacman(), pacman->getDuszekCz(), window);
						while (true) {
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
								while (true) {
									int koniec;
									std::cout << "Przegra³eœ, aby skonczyc wcisnij 1\n";
									std::cin >> koniec;
									if (koniec == 1) {
										flaga = 1;
										break;
									}
								}
							}
						}
					}
					window.draw(pacman->getDuszekCz());
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					std::cout << "test";
					if (ustawienia.getX().getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)))) {
						nadpis = 0;
					}
				}

				pacman->poruszanie(a, b);

				pacman->poruszanieDuszkaCz(a, b);
				pacman->poruszanieDuszkaR(a, b);
				pacman->poruszanieDuszkaN(a, b);

				pacman->kolizjaamam(pacman->getPacman(), zapis.zapisaneJedzenie(), window);
				if (plansza.kontrolaWygranej() == 1) {
					window.draw(interfejs.getWygrana());
				}

				ustawienia.kolizja(window, 0);

				window.draw(plansza.getRamka());
				window.draw(pacman->getPacman());
				window.draw(ustawienia.getX());
				window.draw(pacman->getNapis());
				window.draw(pacman->getWynik(zapis.zapisanePunkty()));
			}
			
		}

		//Okno Zapisu
		if (interfejs.getOkna(window) == 2 && flaga != 1) {
			//std::cout<<interfejs.getOkna(window);
			int wybór;
			std::cout << "Czy chcesz wczytaæ gracza?\nTak[1]\nNie[2]\n";
			std::cin >> wybór;
			if (wybór == 1) {
				//std::cout << ustawienia.getGracz();
				zapis.odczytywanie("dane.json", ustawienia.getGracz(), a, b);
				if (zapis.zapisanePunkty() != 0) {
					nadpis = 1;
				}
				flaga = 1;
			}
			else if (wybór == 2) {
				wyczyœæKonsolê();
				flaga = 1;
			}
		}

		//Okno Ustawieñ
		if (interfejs.getOkna(window) == 3) {
			window.clear(sf::Color(145, 230, 167));
			for (const auto& pole : ustawienia.getPola()) {
				window.draw(pole);
			}

			for (const auto& tekst : ustawienia.getTekst()) {
				window.draw(tekst);
			}/*
			window.draw(interfejs.getPacman());
			window.draw(interfejs.napis());*/
			ustawienia.kolizja(window, 1);
			window.draw(ustawienia.getX());
			window.draw(ustawienia.getDuszek());
			window.draw(ustawienia.poziomT(window));
		}
			
		
		window.display();
	}


	return 0;
}