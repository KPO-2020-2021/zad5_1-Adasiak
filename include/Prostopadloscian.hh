#pragma once

#include "vector.hh"
#include "BrylaGeometryczna.hh"

// #include "matrix.hh"
#include "size.hh"
// #include "../include/lacze_do_gnuplota.hh"
#include <stdlib.h>
#include <fstream>
#include <string>
#include "BrylaGeometryczna.hh"
using namespace std;
class Prostopadloscian : public BrylaGeometryczna
{
  

public:
    Prostopadloscian(){};

    Prostopadloscian(Vector<3> pkt, double h, double w, double d);

    // bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr, Vector<  3> Przesuniecie);

    // void rysuj();
};

// void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream&     StrmWy, Prostopadloscian Prostopadloscian,  /*double*/ Vector<  3>  Przesuniecie);

// bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr);

std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr);