#pragma once

#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
// #include "matrix.hh"

class Dron
{
int id;
Vector<3> droga;
// Matrix<3> mac;
Prostopadloscian  korpus;
Graniastoslup wirniki[4];
public:

// Dron(int id=0);
Dron(int id);
void ruch(Vector<3>droga);
void obrot(double kat);
void zapisz();



};

std::ostream &operator<<(std::ostream &Strm, const Dron &P);