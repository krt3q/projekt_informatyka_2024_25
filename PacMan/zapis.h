#pragma once
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

class zapis {

private:
	std::fstream plik;
	struct gracze{
		int id;
		std::string nazwa;
		int punkty;
	};


	int i = 0;

public:
	zapis(int a);

	//std::vector<gracze> graczedozapisania;

	void zapisywanie(int punkty_f, std::string nazwa_f) {
		plik.open("Gracze.dat", std::ios::out | std::ios::app);
		gracze gracz = {
		i,
		nazwa_f,
		punkty_f,
		};
		plik << gracz.id;
		plik << gracz.nazwa;
		plik << gracz.punkty;

		i++;
		plik.close();
	}

};