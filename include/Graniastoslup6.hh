#pragma once

#include "vector.hh"
#include "BrylaGeometryczna.hh"

// #include "matrix.hh"
#include "size.hh"
// #include "../include/lacze_do_gnuplota.hh"
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;
class Graniastoslup : public BrylaGeometryczna
{

public:
    Graniastoslup(){};
    
    Graniastoslup(Vector<3> srodek,double promien/*, string nazwa_pliku, string nazwa_pliku_do_zapisu*/);


    // Graniastoslup(Vector<3> pkt, double h, double w, double d);

 
    // bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Graniastoslup Pr, Vector<  3> Przesuniecie);

    // void rysuj();
};

// void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream&     StrmWy, Graniastoslup Graniastoslup,  /*double*/ Vector<  3>  Przesuniecie);

// bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Graniastoslup Pr);

std::ostream &operator<<(std::ostream &Strm, const Graniastoslup &Pr);