#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"




int main()
{
	sf::RenderWindow window(sf::VideoMode(1300, 1000), "SFML works!");
	sf::Event event;

	int a = 20;
	int b = 10;
	int poczatekSprite=0;
	int koniecSprite = 100;

	Plansza plansza(a,b);


	sf::Clock zegar;

	int flaga;

	sf::IntRect ksztaltPacmana(0,0,40,40);

	Pacman pacman(a,b);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			/*if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					poczatekSprite = 450;
					koniecSprite = 550;
					ksztaltPacmana.top = poczatekSprite;
				}

				if (event.key.code == sf::Keyboard::S)
				{
					poczatekSprite = 150;
					koniecSprite = 250;
					ksztaltPacmana.top = poczatekSprite;
				}
				if (event.key.code == sf::Keyboard::A)
				{
					poczatekSprite = 300;
					koniecSprite = 400;
					ksztaltPacmana.top = poczatekSprite;
				}
				if (event.key.code == sf::Keyboard::D)
				{
					poczatekSprite = 0;
					koniecSprite = 100;
					ksztaltPacmana.top = poczatekSprite;
				}
			}*/
		}
		if (zegar.getElapsedTime().asMilliseconds() > 150.0f) {

			pacman.animuj();
			zegar.restart();
		}
		for (const auto&przeszkoda : plansza.getPrzeszkoda()) {
			pacman.kolizja(pacman.getPacman(), przeszkoda);
		}
		/*for (const auto& jedzenie : plansza.getJedzenie()) {
			pacman.kolizjaamam(pacman.getPacman(), jedzenie, plansza);
		}*/
		pacman.poruszanie(a, b);
		window.clear();
		for (const auto&pole : plansza.getPlansza()) {
			window.draw(pole);
		}
		for (const auto& amam : plansza.getJedzenie()) {
			window.draw(amam);
		}
		window.draw(plansza.getRamka());
		window.draw(pacman.getPacman());
		window.display();
	}


	return 0;
}