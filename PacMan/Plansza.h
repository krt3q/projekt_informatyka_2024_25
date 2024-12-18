#pragma once

class Plansza {
private:
	sf::Vector2f Rozmiar;
	sf::ConvexShape Ramka_wewn;
	sf::RectangleShape Ramka_zewn;
public:
	Plansza(float x, float y) {
		Rozmiar.x = x;
		Rozmiar.y = y;
		Ramka_zewn.setSize(Rozmiar);
		Ramka_zewn.setPosition(30, 30);
		Ramka_zewn.setFillColor(sf::Color::Black);
		Ramka_zewn.setOutlineThickness(1);
		Ramka_zewn.setOutlineColor(sf::Color::Blue);
	}
	sf::RectangleShape getPlansza_1() {
		return Ramka_zewn;
	
	}

};