#include "Graniastoslup6.hh"
#include "../include/lacze_do_gnuplota.hh"
#include <iomanip>


/*!
    \brief
    *Konstruktor Graniastoslupa. 
    *Tworzymy Graniastoslupa wzgledem 1 wierzcholak (jego wspolrzednych ), 
    * a nastepnie kolejne pkt1 dodajac do 1 wierzcholka szerokosc i wysokosc w zaleznosci od kolejnego wierzcholka
    *
    *  

*/


Graniastoslup::Graniastoslup(Vector<3> srodek,double promien/*,string nazwa_pliku, string nazwa_pliku_do_zapisu*/){
    // this->nazwa_pliku = nazwa_pliku;
    // this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;
    // double katOX = 0;
    // double katOY = 0;
    // double katOZ = 0;
    Vector<3> tmp;
    for(int i=0; i<=300; i+=60){
        tmp[2]=srodek[2];
        tmp[0]=srodek[0]+promien*sin(i*M_PI/180);
        tmp[1]=srodek[1]+promien*cos(i*M_PI/180);
        // srodek[0];
        pkt1.push_back(tmp);
        pkt1.push_back(tmp);
        tmp[2]=srodek[2]+10;
        tmp[0]=srodek[0]+promien*sin(i*M_PI/180);
        tmp[1]=srodek[1]+promien*cos(i*M_PI/180);
        // srodek[0];
        pkt1.push_back(tmp);
    }

    // srodek[0];
    // srodek[1];
    pkt1.push_back(pkt1[0]);
    pkt1.push_back(pkt1[1]);
    ofstream plik;
        plik.open(nazwa_pliku);
    for(int i=0; i<(int)pkt1.size(); i++)
    {
        if(i%2==0)
        plik<<endl;
        plik<<pkt1[i]<<endl;
    }
    plik.close();
    zapis();
}

// Graniastoslup::Graniastoslup(Vector<3> pkt, double h, double w, double d)
// {
//     pkt1.resize(25);
//     for (int i = 0; i < 25; i++)
//     {
//         pkt1[i] = pkt;
//     }
//     pkt1[1][0] -= w;

//     pkt1[2][0] -= w/2;
//     pkt1[2][1] -= h;

//     pkt1[3][0] -= w;
//     pkt1[3][2] += d;

//     pkt1[4][0] -= w/2;
//     pkt1[4][1] -= h;
//     pkt1[4][2] += d;

//     pkt1[5][0] -= w/2;
//     pkt1[5][1] -= h;

//     pkt1[6][0] += w/2;
//     pkt1[6][1] -= h;

//     pkt1[7][0] -= w/2;
//     pkt1[7][1] -= h;
//     pkt1[7][2] += d;

//     pkt1[8][0] += w/2;
//     pkt1[8][1] -= h;
//     pkt1[8][2] += d;
    

//     pkt1[9][0] += w/2;
//     pkt1[9][1] -= h;

//     pkt1[10][0] += w;


//     pkt1[11][0] += w/2;
//     pkt1[11][1] -= h;
//     pkt1[11][2] += d;

//     pkt1[12][0] += w;
//     pkt1[12][2] += d;


//     pkt1[13][0] += w;

//     pkt1[14][0] += w/2;
//     pkt1[14][1] += h;

//     pkt1[15][0] += w;
//     pkt1[15][2] += d;

//     pkt1[16][0] += w/2;
//     pkt1[16][1] += h;
//     pkt1[16][2] += d;


//     pkt1[17][0] += w/2;
//     pkt1[17][1] += h;

//     pkt1[18][0] -= w/2;
//     pkt1[18][1] += h;

//     pkt1[19][0] += w/2;
//     pkt1[19][1] += h;
//     pkt1[19][2] += d;

//     pkt1[20][0] -= w/2;
//     pkt1[20][1] += h;
//     pkt1[20][2] += d;


//     pkt1[21][0] -= w/2;
//     pkt1[21][1] += h;

//     pkt1[22][0] -= w;

//     pkt1[23][0] -= w/2;
//     pkt1[23][1] += h;    
//     pkt1[23][2] += d;    

//     pkt1[24][0] -= w;
//     pkt1[24][2] += d;

// }



// Graniastoslup::Graniastoslup(Vector<3> pkt, double h, double w, double d)
// {
//     pkt1.resize(20);
//     for (int i = 0; i < 20; i++)
//     {
//         pkt1[i] = pkt;
//     }
//     pkt1[1][0] -=w;

//     pkt1[2][0] -=w;
//     pkt1[2][2] +=d;

//     pkt1[3] = pkt1[0];

//     pkt1[4][0] -=w/2;
//     pkt1[4][1] -=h;

//     pkt1[5][0] -=w/2;
//     pkt1[5][1] -=h;
//     pkt1[5][2] +=d;

//     pkt1[6] = pkt1[0];
   
//     pkt1[7][0] +=w/2;
//     pkt1[7][1] -=h;

//     pkt1[8][0] +=w/2;
//     pkt1[8][1] -=h;
//     pkt1[8][2] +=d;

//     pkt1[9] = pkt1[0];

//     pkt1[10][0] +=w;

//     pkt1[11][0] +=w;
//     pkt1[11][2] +=d;

//     pkt1[12] = pkt1[0];

//     pkt1[13][0] +=w/2;
//     pkt1[13][1] +=h;

//     pkt1[14][0] +=w/2;
//     pkt1[15][1] +=h;
//     pkt1[15][2] +=d;

//     pkt1[16] = pkt1[0];

//     pkt1[17][0] -=w/2;
//     pkt1[17][1] +=h;

//     pkt1[18][0] -=w/2;
//     pkt1[18][1] +=h;
//     pkt1[18][2] +=d;

//     pkt1[19] = pkt1[0];
   



   


// }



// /*!
//     \brief
//     *Funkcja rotacji Graniastoslupa
//     *do kazdego kolejnego wierzcholka Graniastoslupa wzgeledm odpowiedneij funkcji trygonometrycznej obliczamy jego umiejscownie w ukladzie wsporzenych
//     *
//     *

// */

std::ostream &operator<<(std::ostream &Strm,
                         const Graniastoslup &Pr)
{

    for (int i = 1; i < 25; i++)
    {
        Strm << Pr[i] << endl;
        if ((i) % 2 == 0)
            Strm << endl;
    }

    return Strm;
}

// // /*
//         // \brief
// //     *funkcja PrzykladZapisuWspolrzednychDoStrumienia
// //     *sluzy do zapoisu kolejnych wierzcholkow Graniastoslupa
// //     * pomocna przy rysowaniu przez gnuplota naszego Graniastoslupa w oknie graficznym
// //     * zaczynamy od 1 wierzcholka i kolejno dla kazdego nasteonego wierzcholka wykonujemy taka sama operacje
// //     * a nastepnie znowu uzywamy 1 wierzcholka aby program narysowal linie z ostatniego wierzcholka do 1

// // */

// // void PrzykladZapisuWspolrzednychDoStrumienia( std::ostream&     StrmWy, Graniastoslup Pr,   Vector<  2>  Przesuniecie)
// // {
// //     Pr[0]=Pr[0]+Przesuniecie;
// //     Pr[1]=Pr[1]+Przesuniecie;
// //     Pr[2]=Pr[2]+Przesuniecie;
// //     Pr[3]=Pr[3]+Przesuniecie;

// //     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
// //     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
// //     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[2] << std::endl;
// //     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[3] << std::endl;
// //     StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
// // }

// //  bool Graniastoslup::ZapisWspolrzednychDoPliku(const char *sNazwaPliku, Graniastoslup Pr , Vector<  2> Przesuniecie)
// //  {

// //   std::ofstream  StrmPlikowy;

// //   StrmPlikowy.open(sNazwaPliku);
// //   if (!StrmPlikowy.is_open())  {
// //     std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
// // 	 << ":(  nie powiodla sie." << std::endl;
// //     return false;
// //   }

// //   PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy , Pr , Przesuniecie );

// //   StrmPlikowy.close();
// //   return !StrmPlikowy.fail();
// //  }
