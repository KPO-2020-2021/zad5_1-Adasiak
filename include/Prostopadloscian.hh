#pragma once

#include "BrylaGeometryczna.hh"

// #include "matrix3x3.hh"


// #include "../include/lacze_do_gnuplota.hh"
#include <stdlib.h>

// #include "BrylaGeometryczna.hh"
using namespace std;
class Prostopadloscian : public BrylaGeometryczna
{
  

public:
    Prostopadloscian(){};

    Prostopadloscian(Vector<3> pkt, double h, double w, double d, string nazwa_pliku, string nazwa_pliku_do_zapisu);
    
    // Prostopadloscian(double dlugosc, double szerokosc, double wysokosc, string nazwa_pliku, string nazwa_pliku_do_zapisu);

    

};


std::ostream &operator<<(std::ostream &Strm, const Prostopadloscian &Pr);







    // bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr, Vector<  3> Przesuniecie);

    // Matrix<3> operator * (Matrix<3> tmp);
    
    // void move(const Vector<3> &v);

    

    // Prostopadloscian operator*(Matrix<3> tmp)
    //     {
    //     Prostopadloscian wynik;
    //     for (int i = 0; i < 7; i++)
    //     {

    //         wynik[i] = tmp * (*this)[i];
    //     }
    //     return wynik;
    // }

    //  Prostopadloscian operator*(Matrix<3> tmp)
    //     {
    //     Prostopadloscian wynik;
    //     for (int i = 0; i < 7; i++)
    //     {

    //         wynik[i] = tmp * wynik[i];
    //     }
    //     return wynik;
    // }
   


// void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream&     StrmWy, Prostopadloscian Prostopadloscian,  /*double*/ Vector<  3>  Przesuniecie);

// bool ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr);



