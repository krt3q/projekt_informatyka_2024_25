#pragma once
#include "Ustawienia.h"

sf::ConvexShape krzy¿;
sf::IntRect cofka;
sf::RectangleShape test;

sf::RectangleShape getCofka() {

	cofka.top = 0;
	cofka.left = 0;
	cofka.height = 70;
	cofka.width = 70;
	krzy¿.setPointCount(12);
	krzy¿.setPoint(0, sf::Vector2f(10, 10));
	krzy¿.setPoint(1, sf::Vector2f(30, 30));
	krzy¿.setPoint(2, sf::Vector2f(10, 50));
	krzy¿.setPoint(3, sf::Vector2f(20, 60));
	krzy¿.setPoint(4, sf::Vector2f(40, 40));
	krzy¿.setPoint(5, sf::Vector2f(60, 60));
	krzy¿.setPoint(6, sf::Vector2f(70, 50));
	krzy¿.setPoint(7, sf::Vector2f(50, 30));
	krzy¿.setPoint(8, sf::Vector2f(70, 10));
	krzy¿.setPoint(9, sf::Vector2f(60, 0));
	krzy¿.setPoint(10, sf::Vector2f(40, 20));
	krzy¿.setPoint(11, sf::Vector2f(20, 0));
	krzy¿.setPosition(10, 10);
	krzy¿.setFillColor(sf::Color::Red);
	krzy¿.setTextureRect(cofka);

	test.setSize(sf::Vector2f(50, 50));
	test.setPosition(10, 10);

	return test;

}


//int main1()
//{
//	//cross cross(1);
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(cross.getCofka());
//        window.display();
//    }
//
//    return 0;
//}