#pragma once
//Ciekawe mo¿liwe rozwi¹zania
sf::Vertex* linia = new sf::Vertex[2];
linia[0].position = sf::Vector2f(200 + j * 100, 200 + i * 100);
linia[0].color = sf::Color::Red;
linia[1].position = sf::Vector2f(300 + j * 100, 200 + i * 100);
linia[1].color = sf::Color::Red;

linie.push_back(*linia);