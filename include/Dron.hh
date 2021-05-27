#pragma once

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"


class Dron
{
int id;
Vector<3> droga;
// Matrix<3> mac;
Prostopadloscian  *korpus;
Graniastoslup *wirniki[4];
// string PLIK_TRASY_PRZELOTU;
public:

// Vector<3> droga;
// Dron(int id=0);
Dron(int id);
void ruch(Vector<3> droga, double katOZ, double katOY /*, double OX*/);
void obrot(double kat);

bool DodajTrasePrzelotu(PzG::LaczeDoGNUPlota &Lacze,double x1, double y1);

void AnimacjaLotuDrona(PzG::LaczeDoGNUPlota &Lacze, double x1, double y1);


void zwiad(Vector<3> promien);//1 wersja 
void zwiad2(PzG::LaczeDoGNUPlota &Lacze,double promien);//2 wersja 

void zapisz();



};

std::ostream &operator<<(std::ostream &Strm, /*const*/ Dron &P);