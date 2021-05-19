#pragma once
#include "vector.hh"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class BrylaGeometryczna
{
protected:
    // Vector<  3> a,b,c,d;
    vector<Vector<3>> pkt1;
    string nazwa_pliku;
    string nazwa_pliku_do_zapisu;

public:

    Vector<3> operator[](int Ind) const { return pkt1[Ind]; } //wypisywanie

    Vector<3> &operator[](int Ind) { return pkt1[Ind]; } //wpisywanie

    void move(const Vector<3> &v);

    void zapis();

    // void set_katOX(double kat){katOX+=kat;}
    // void set_katOZ(double kat){katOZ+=kat;}
    // void set_katOY(double kat){katOY=kat;}

};

