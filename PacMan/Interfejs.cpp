//#include <iostream>
//#include <random>
//#include <SFML/Graphics.hpp>
//#include <fstream>
//#include <string>
//#include "Pacman.h"
//#include "Przeszkoda.h"
//#include "Plansza.h"
//#include "json.hpp"
//#include "zapis.h"
//
//
//using json = nlohmann::json;
//
//
//int main() {
//	zapis zapis(1);
//	json stanGry;
//	std::fstream plik("dane.json", std::ios::in);
//	if (!plik.is_open()) {
//		std::cerr << "KUPA\n";
//		return -1;
//	}
//
//	zapis.odczytywanie("dane.json", "asd", 20, 10);
//
//    std::random_device dev;
//    std::mt19937 rng(dev());
//    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 4);
//    for(int i=0;i<10;i++)
//	std::cout << dist(rng);
//
//    //sf::RenderWindow window(sf::VideoMode(1300, 1000), "SFML works!");
//    //sf::CircleShape shape(100.f);
//    //shape.setFillColor(sf::Color::Green);
//
//    //while (window.isOpen())
//    //{
//    //    sf::Event event;
//    //    while (window.pollEvent(event))
//    //    {
//    //        if (event.type == sf::Event::Closed)
//    //            window.close();
//    //    }
//
//    //    window.clear();
//    //    for (const auto& pola : zapis.zapisanePola()) {
//    //        //std::cout << pola.getPosition().x << std::endl;
//    //        window.draw(pola);
//    //    }
//    //    for (const auto& amam : zapis.zapisaneJedzenie()) {
//    //        // std::cout << amam.getPosition().x << std::endl;
//    //        window.draw(amam);
//    //    }
//    //    //window.draw(shape);
//    //    window.display();
//    //}
//	return 0;
//}