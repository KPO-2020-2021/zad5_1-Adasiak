#include "Prostopadloscian.hh"
#include "../include/lacze_do_gnuplota.hh"
#include <iomanip>


/*!
    \brief
    *Konstruktor Prostopadlosciana. 
    *Tworzymy Prostopadlosciana wzgledem 1 wierzcholak (jego wspolrzednych ), 
    * a nastepnie kolejne wierzcholki dodajac do 1 wierzcholka szerokosc i wysokosc w zaleznosci od kolejnego wierzcholka
    *
    *  

*/

Prostopadloscian::Prostopadloscian(Vector<3> pkt, double h, double w, double d)
{
    pkt1.resize(8);
    for (int i = 0; i < 8; i++)
    {
        pkt1[i] = pkt;
    }
    pkt1[1][0] += w;

    pkt1[2][1] += h;

    pkt1[3][0] += w;
    pkt1[3][1] += h;

    pkt1[4][1] += h;
    pkt1[4][2] += d;

    pkt1[5][0] += w;
    pkt1[5][1] += h;
    pkt1[5][2] += d;

    pkt1[6][2] += d;

    pkt1[7][0] += w;
    pkt1[7][2] += d;
}

/*!
    \brief
    *Funkcja rotacji Prostopadlosciana
    *do kazdego kolejnego wierzcholka Prostopadlosciana wzgeledm odpowiedneij funkcji trygonometrycznej obliczamy jego umiejscownie w ukladzie wsporzenych
    * 
    * 

*/


std::ostream &operator<<(std::ostream &Strm,
                         const Prostopadloscian &Pr)
{

    for (int i = 0; i < 8; i++)
    {
        Strm << Pr[i] << endl;
        if ((i + 1) % 2 == 0)
            Strm << endl;
    }

    return Strm;
}



// Matrix<3> Prostopadloscian::operator *  (Matrix<3> tmp)
// {
//     Prostopadloscian wynik;
//     for(int i=0; i < 8 ; ++i)
//     {
//         wynik[i] = *this[i] * tmp;  
//     }
// }


// Prostopadloscian Prostopadloscian::operator*(Matrix<3> tmp)
//     {
//         Prostopadloscian wynik;
//         for (int i = 0; i < 8; i++)
//         {

//             wynik[i] = tmp * (*this)[i];
//         }
//         return wynik;
//     }

