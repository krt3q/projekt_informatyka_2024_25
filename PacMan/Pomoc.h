#pragma once


class Pomoc {

private:

	sf::Sprite dekoracje;
	sf::Texture tekstura;
	sf::Clock zegar;
	sf::IntRect klatki;
	int poczatekSprite = 0;
	int koniecSprite = 500;

	//Napisy
	std::vector<sf::Text> napisy;
	sf::Text textW;
	sf::Text textS;
	sf::Text textA;
	sf::Text textD;
	sf::Text textQ;
	sf::Text textE;
	sf::Text textZ;
	sf::Text textC;

	//Czcionka
	sf::Font czcionka;

	//Marker
	int i = 1;

	//Ramka
	sf::RectangleShape ramka;
public:
	Pomoc(int a) {
		klatki.height = 40;
		klatki.width = 40;
		klatki.top = 0;
		klatki.left = 10;
		dekoracje.setPosition(sf::Vector2f(60, 215));
		if (!czcionka.loadFromFile("Dekoracje.png"))
			std::cerr << "eroor";
		tekstura.loadFromFile("Dekoracje.png");
		dekoracje.setTexture(tekstura);
		dekoracje.setTextureRect(klatki);
		dekoracje.setScale(sf::Vector2f(10, 10));

		if (!czcionka.loadFromFile("britanic.ttf"))
			std::cerr<<"eroor";
		textW.setString("W - ruch w gore");
		textA.setString("A - ruch w lewo");
		textS.setString("S - ruch w dol");
		textD.setString("D - ruch w prawo");
		textQ.setString("Uzywaj tylko wtedy, gdy to konieczne!!!!\n\nQ - skok po skosie gora/lewo");
		textE.setString("E - skok po skosie gora/prawo");
		textZ.setString("Z - skok po skosie dol/lewo");
		textC.setString("C - skok po skosie dol/prawo");
		napisy.push_back(textW);
		napisy.push_back(textA);
		napisy.push_back(textS);
		napisy.push_back(textD);
		napisy.push_back(textQ);
		napisy.push_back(textE);
		napisy.push_back(textZ);
		napisy.push_back(textC);
		for (auto& napis : napisy) {
			if (i == 6)
				i=i+2;
			napis.setPosition(550, 200 + 50 * i);
			napis.setPosition(550, 200 + 50 * i);
			napis.setFont(czcionka);
			napis.setCharacterSize(40);
			napis.setFillColor(sf::Color::Black);
			i++;
		}
		ramka.setPosition(500, 250);
		ramka.setSize(sf::Vector2f(770, 600));
		ramka.setFillColor(sf::Color::Green);
		ramka.setOutlineColor(sf::Color::Yellow);
		ramka.setOutlineThickness(6);
	}


	std::vector<sf::Text> getTekst() {
		return napisy;
	}


	sf::RectangleShape getRamka() {
		return ramka;
	}

	sf::Sprite getDekoracje() {
		if (zegar.getElapsedTime().asMilliseconds() > 150.0f) {
			if (klatki.top == koniecSprite) {
				klatki.top = poczatekSprite;
			}
			else
				klatki.top += 50;
			dekoracje.setTextureRect(klatki);
			zegar.restart();
		}
		return dekoracje;
	}
};