#pragma once 

#include <vector>
#include "vector.hh"
#include "matrix3x3.hh"
#include <fstream>
#include <string>

using namespace std;

class Scena
{   
    protected:
    double katOZ; // obrot do okola osi Z
    double katOY; // kat wznoszenia i opadania
    double katOX; // kat rotacji np. wirnikow

    vector<Vector<3>> scr1;
    Vector<3> Przesuniecie;
    Vector<3> srodek;
    string nazwa_pliku;
    string nazwa_pliku_do_zapisu;
    int k=0;// ilosc punktów na prostej
    public:

    // Scena(Vector<3> scr, double dlugosc, double szerokosc, double glebokosc );
    Scena(double dlugosc, double szeroksc,double glebokosc,  string nazwa_pliku, string nazwa_pliku_do_zapisu);

    void zapis();

    void move(const Vector<3> &v);

    void set_katOX(double kat){katOX+=kat;}
    void set_katOZ(double kat){katOZ+=kat;}
    void set_katOY(double kat){katOY=kat;}
    Vector<3> &operator [](int i){return scr1[i];}
    Vector<3> operator [](int i)const {return scr1[i];}



};
