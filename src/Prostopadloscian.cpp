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

// Vector<3> Prostopadloscian::translacja(Vector<3> &trans)
// {
//     // Prostopadloscian przesuniete;
//     // Vector<  2> a2, b2, c2, d2;

//     // a2=pkt1[0];
//     // b2=pkt1[1];
//     // c2=pkt1[2];
//     // d2=pkt1[3];

//     // przesuniete.pkt1[0] = a2 + trans;
//     // przesuniete.pkt1[1] = b2 + trans;
//     // przesuniete.pkt1[2] = c2 + trans;

//     // return przesuniete;
// }

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

// /*
// \brief
//     *funkcja PrzykladZapisuWspolrzednychDoStrumienia
//     *sluzy do zapoisu kolejnych wierzcholkow Prostopadlosciana
//     * pomocna przy rysowaniu przez gnuplota naszego Prostopadlosciana w oknie graficznym
//     * zaczynamy od 1 wierzcholka i kolejno dla kazdego nasteonego wierzcholka wykonujemy taka sama operacje
//     * a nastepnie znowu uzywamy 1 wierzcholka aby program narysowal linie z ostatniego wierzcholka do 1

// */

// void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream&     StrmWy, Prostopadloscian Pr,   Vector<  2>  Przesuniecie)
// {
//     Pr[0]=Pr[0]+Przesuniecie;
//     Pr[1]=Pr[1]+Przesuniecie;
//     Pr[2]=Pr[2]+Przesuniecie;
//     Pr[3]=Pr[3]+Przesuniecie;

//     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
//     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
//     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[2] << std::endl;
//     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[3] << std::endl;
//     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
// }

//  bool Prostopadloscian::ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Prostopadloscian Pr , Vector<  2> Przesuniecie)
//  {

//   std::ofstream  StrmPlikowy;

//   StrmPlikowy.open(sNazwaPliku);
//   if (!StrmPlikowy.is_open())  {
//     std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
// 	 << ":(  nie powiodla sie." << std::endl;
//     return false;
//   }

//   PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy , Pr , Przesuniecie );

//   StrmPlikowy.close();
//   return !StrmPlikowy.fail();
//  }
