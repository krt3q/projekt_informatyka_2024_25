#pragma once

class Plansza {
private:
	sf::Vector2f Rozmiar;
	sf::Vector2f Pozycja_z;
	sf::Vector2f Pozycja_w;
	sf::Vector2f Rozmiar_c; //Wspó³rzêdne wewnêtrznej  ramki
	sf::ConvexShape Ramka_wewn;
	sf::RectangleShape Ramka_zewn;
public:
	Plansza(float xr, float yr, float xp, float yp) {

		//Tworzenie wektorów
		Rozmiar.x = xr;
		Rozmiar.y = yr;
		Pozycja_z.x = xp;
		Pozycja_z.y = yp;
		Rozmiar_c.x = Pozycja_z.x + Rozmiar.x; //Pozycja -> Rozmiar
		Rozmiar_c.y = Pozycja_z.y + Rozmiar.y;


		//Opisywanie parametrów obramowañ

		//Ramka zewnêtrzna
		Ramka_zewn.setSize(Rozmiar);
		Ramka_zewn.setPosition(Pozycja_z);
		Ramka_zewn.setFillColor(sf::Color::Black);
		Ramka_zewn.setOutlineThickness(1);
		Ramka_zewn.setOutlineColor(sf::Color::Blue);

		//Ramka wewnêtrzna
		Pozycja_w.x = Pozycja_z.x + 10; //Rozmiar -> Pozycja
		Pozycja_w.y = Pozycja_z.y + 10;
		Ramka_wewn.setPointCount(20);
		//std::cout << Rozmiar_ << std::endl;
		Ramka_wewn.setPoint(0, sf::Vector2f(Pozycja_w.x, Pozycja_w.y));
		Ramka_wewn.setPoint(1, sf::Vector2f(Pozycja_z.x + 195, Pozycja_w.y));
		Ramka_wewn.setPoint(2, sf::Vector2f(Pozycja_z.x + 195, Pozycja_z.y + 100));
		Ramka_wewn.setPoint(3, sf::Vector2f(Pozycja_z.x + 205, Pozycja_z.y + 100));
		Ramka_wewn.setPoint(4, sf::Vector2f(Pozycja_z.x + 205, Pozycja_w.y));
		Ramka_wewn.setPoint(5, sf::Vector2f(Pozycja_z.x + 595, Pozycja_w.y));
		Ramka_wewn.setPoint(6, sf::Vector2f(Pozycja_z.x + 595, Pozycja_z.y + 100));
		Ramka_wewn.setPoint(7, sf::Vector2f(Pozycja_z.x + 605, Pozycja_z.y + 100));
		Ramka_wewn.setPoint(8, sf::Vector2f(Pozycja_z.x + 605, Pozycja_w.y));
		Ramka_wewn.setPoint(9, sf::Vector2f(Rozmiar_c.x - 10, Pozycja_z.y + 10));
		Ramka_wewn.setPoint(10, sf::Vector2f(Rozmiar_c.x - 10, Rozmiar_c.y - 10));
		Ramka_wewn.setPoint(11, sf::Vector2f(Rozmiar_c.x - 195, Rozmiar_c.y - 10));
		Ramka_wewn.setPoint(12, sf::Vector2f(Rozmiar_c.x - 195, Rozmiar_c.y - 100));
		Ramka_wewn.setPoint(13, sf::Vector2f(Rozmiar_c.x - 205, Rozmiar_c.y - 100));
		Ramka_wewn.setPoint(14, sf::Vector2f(Rozmiar_c.x - 205, Rozmiar_c.y - 10));
		Ramka_wewn.setPoint(15, sf::Vector2f(Rozmiar_c.x - 595, Rozmiar_c.y - 10));
		Ramka_wewn.setPoint(16, sf::Vector2f(Rozmiar_c.x - 595, Rozmiar_c.y - 100));
		Ramka_wewn.setPoint(17, sf::Vector2f(Rozmiar_c.x - 605, Rozmiar_c.y - 100));
		Ramka_wewn.setPoint(18, sf::Vector2f(Rozmiar_c.x - 605, Rozmiar_c.y - 10));
		Ramka_wewn.setPoint(19, sf::Vector2f(Pozycja_z.x + 10, Rozmiar_c.y - 10));
		Ramka_wewn.setOutlineThickness(1);  //Tutaj nale¿y pamiêtaæ, ¿e d³ugoœæ wewnêtrznej zmniejszyæ nale¿y o gruboœæ, a zewnêtrznej zwiêkszyæ o gruboœæ
		Ramka_wewn.setFillColor(sf::Color::Black);
		Ramka_wewn.setOutlineColor(sf::Color::Blue);


	}

	//Zwracanie Ramki zewnêtrznej
	sf::RectangleShape getPlansza_1() {
		return Ramka_zewn;
	}

	//Zwracanie Ramki Wewnêtrznej
	sf::ConvexShape getPlansza_2() {
		return Ramka_wewn;
	}
};