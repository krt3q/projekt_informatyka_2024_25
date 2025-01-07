#include <iostream>
#include <random>
#include <SFML/Graphics.hpp>
#include "Pacman.h"
#include "Przeszkoda.h"
#include "Plansza.h"




int main()
{
	sf::Vector2f wektorpomocniczy;
	wektorpomocniczy.x = 100;
	wektorpomocniczy.y = 100;
	/*sf::Vector2f Rozmiarokna;
	Rozmiarokna.x = 1000;
	Rozmiarokna.y = 800;*/
	sf::RenderWindow window(sf::VideoMode(1500, 1300), "SFML works!");

	//Plansza plansza(800, 400, 100, 200);
	Plansza plansza(8,4);
	/*sf::RectangleShape kulko;
	kulko.setPosition(sf::Vector2f(830.f, 30.f));*/

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		//window.draw(plansza.getPlansza_1());
		//window.draw(plansza.getPlansza_2());
		sf::RectangleShape* pola = plansza.getPlansza();
		for (int i = 0; i < 64; i++) {
			window.draw(pola[i]); 
		}
		/*sf::Vertex* ramka = plansza.getRamka();
		for (int i = 0; i < 64; i++) {
			window.draw(ramka, 2, sf::Lines);
		}*/
		window.display();
	}



	return 0;
}