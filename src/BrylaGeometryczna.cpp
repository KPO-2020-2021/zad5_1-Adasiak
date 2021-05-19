#include "BrylaGeometryczna.hh"
// #include "Graniastoslup6.cpp"
// #include "../include/lacze_do_gnuplota.hh"
// #include <iomanip>


void BrylaGeometryczna::move(const Vector<3> &v)
{
    for (int i = 0; i < 8; i++)
    {
        pkt1[i] = pkt1[i] + v;
    }
}

void BrylaGeometryczna::zapis(){
    ofstream plik;
    plik.open(nazwa_pliku_do_zapisu);
    for(int i=0; i<(int)pkt1.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<pkt1[i]<<endl;//robie enter co 2 linie
    }
    plik.close();
}
