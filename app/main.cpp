// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "exampleConfig.h"
// #include "example.h"
#include "vector.hh"
#include "matrix.hh"
#include "Prostopadloscian.hh"
#include "Graniastoslup6.hh"
#include "Dron.hh"
// #include "Scena.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */

// #define DL_KROTKI_BOK 100
// #define DL_DLUGI_BOK 150

/*!
 * Przyklad zapisu wspolrzednych zbioru punktow do strumienia wyjściowego.
 * Dane sa odpowiednio sformatowane, tzn. przyjęto notację stałoprzecinkową
 * z dokładnością do 10 miejsca po przecinku. Szerokość wyświetlanego pola 
 * to 16 miejsc, sposób wyrównywania - do prawej strony.
 * \param[in] StrmWy - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] Przesuniecie - ten parameter jest tylko po to, aby pokazać
 *                          mozliwosc zmiany wspolrzednych i Prostopadlosciana
 *                          i zmiane jego polorzenia na okienku graficznym
 *                         rysownym przez gnuplota.
 * \retval true - gdy operacja zapisu powiodła się,
 * \retval false - w przypadku przeciwnym.
 */

void PrzykladZapisuWspolrzednychDoStrumienia(std::ostream &StrmWy, Graniastoslup Pr)
{
       StrmWy << Pr;
}


bool PrzykladZapisuWspolrzednychDoPliku(const char *sNazwaPliku,
                                        Graniastoslup Pr /*, Vector<  2> Przesuniecie*/)
{
       std::ofstream StrmPlikowy;

       StrmPlikowy.open(sNazwaPliku);
       if (!StrmPlikowy.is_open())
       {
              std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                        << ":(  nie powiodla sie." << std::endl;
              return false;
       }

       PrzykladZapisuWspolrzednychDoStrumienia(StrmPlikowy, Pr /*, Przesuniecie*/);
       StrmPlikowy << Pr[0] << endl;
       StrmPlikowy << Pr[1];
       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}



void PrzykladZapisuWspolrzednychDoStrumienia1(std::ostream &StrmWy, Prostopadloscian Pr)
{
       StrmWy << Pr;
}


bool PrzykladZapisuWspolrzednychDoPliku1(const char *sNazwaPliku,
                                        Prostopadloscian Pr /*, Vector<  2> Przesuniecie*/)
{
       std::ofstream StrmPlikowy;

       StrmPlikowy.open(sNazwaPliku);
       if (!StrmPlikowy.is_open())
       {
              std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                        << ":(  nie powiodla sie." << std::endl;
              return false;
       }

       PrzykladZapisuWspolrzednychDoStrumienia1(StrmPlikowy, Pr /*, Przesuniecie*/);
       StrmPlikowy << Pr[0] << endl;
       StrmPlikowy << Pr[1];
       StrmPlikowy.close();
       return !StrmPlikowy.fail();
}



int main()
{
       int nr=0;
       Matrix<3> m;
       Vector<3> zero;
       zero[0] = 0;
       zero[1] = 0;
       zero[2] = 0;
       char menu;
       double kat;
       // int n;
       Vector<3> wektor_trans;
       wektor_trans[0] = 50;
       wektor_trans[1] = 50;
       Vector<3> wektor;
       wektor[0] = 10;
       wektor[1] = 10;
       wektor[2] = 10;
       char os;

       Prostopadloscian Pr(zero, 50, 50, 30);
       Graniastoslup Ar(Pr[4], 20/*,10,10*/);

       Dron korpus(nr);
       Graniastoslup Ar1(Pr[5], 20/*,10,10*/);
       Graniastoslup Ar2(Pr[6], 20/*,10,10*/);
       Graniastoslup Ar3(Pr[7], 20/*,10,10*/);
       // Dron Ar4(i,Pr,Ar,Ar1,Ar2,Ar3);

       

       // double h=2, w=3; //wysokosc i długosc Prostopadlosciana
       std::cout << "Project Rotation 2D based on C++ Boiler Plate v"
                 << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
                 << "."
                 << PROJECT_VERSION_MINOR /* istotne zmiany */
                 << "."
                 << PROJECT_VERSION_PATCH /* naprawianie bugów */
                 << "."
                 << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
                 << std::endl;

       PzG::LaczeDoGNUPlota Lacze; // Ta zmienna jest potrzebna do wizualizacji
                                   // rysunku Prostopadlosciana

       //-------------------------------------------------------
       //  Wspolrzedne wierzcholkow beda zapisywane w pliku "Prostopadloscian.dat"
       //  Ponizsze metody powoduja, ze dane z pliku beda wizualizowane
       //  na dwa sposoby:
       //   1. Rysowane jako linia ciagl o grubosci 2 piksele
       //
       Lacze.DodajNazwePliku("../datasets/Prostopadloscian.dat", PzG::RR_Ciagly, 2);
       Lacze.DodajNazwePliku("../datasets/Rotor0.dat", PzG::RR_Ciagly, 2);
       Lacze.DodajNazwePliku("../datasets/Rotor1.dat", PzG::RR_Ciagly, 2);
       Lacze.DodajNazwePliku("../datasets/Rotor2.dat", PzG::RR_Ciagly, 2);
       Lacze.DodajNazwePliku("../datasets/Rotor3.dat", PzG::RR_Ciagly, 2);

       //
       //  Ustawienie trybu rysowania 3D, tzn. rysowany zbiór punktów
       //  znajduje się na wspólnej płaszczyźnie. Z tego powodu powoduj
       //  jako wspolrzedne punktow podajemy x,y,z.
       //
       Lacze.ZmienTrybRys(PzG::TR_3D);

       // Ustawienie zakresow poszczegolnych osi
       Lacze.UstawZakresY(-155, 155);
       Lacze.UstawZakresX(-155, 155);
       Lacze.UstawZakresZ(-155, 155);

       PrzykladZapisuWspolrzednychDoStrumienia1(std::cout, Pr /*, zero*/);
       if (!PrzykladZapisuWspolrzednychDoPliku1("../datasets/Prostopadloscian.dat", Pr ))
              return 1;

       PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar /*, zero*/);
       if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor0.dat", Ar ))
              return 1;

       PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar1 /*, zero*/);
       if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor1.dat", Ar1 ))
              return 1;

       PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar2 /*, zero*/);
       if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor2.dat", Ar2 ))
              return 1;

       PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar3 /*, zero*/);
       if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor3.dat", Ar3 ))
              return 1;

       Lacze.Rysuj();
       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar1);

       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor1.dat", Ar1))
       //        return 1;
       // Lacze.Rysuj();
       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar2);

       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor2.dat", Ar2))
       //        return 1;
       // Lacze.Rysuj();
       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar3);

       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor3.dat", Ar3))
       //        return 1;
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

       //----------------------------------------------------------
       // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
       //
       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar /*, wektor_trans*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Prostopadloscian.dat", Ar /*, wektor_trans*/))
       //        return 1;
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       // std::cin.ignore(100000, '\n');

       // Z bazy projektu-wydmuszki Boiler Plate C++:
       // Bring in the dummy class from the example source,
       // just to show that it is accessible from main.cpp.

       while (menu != 'k')
       {

              std::cout << "Wybierz jedna z dostepnych opcji: " << std::endl;
              std::cout << "o - obrot Prostopadlosciana o zadany kat" << std::endl;
              std::cout << "r - wyswietlenie macierzy rotacji" << std::endl;
              std::cout << "p - przesuniecie Prostopadlosciana o zadany wektor" << std::endl;
              std::cout << "w - wyswietlenie wspolrzednych wierzcholkow" << std::endl;
              std::cout << "s - sprawdzenie dlugosci przeciwleglych bokow " << std::endl;
              std::cout << "m - wyswietl menu" << std::endl;
              std::cout << "k - koniec dzialania programu" << std::endl;
              std::cin >> menu;

              switch (menu)
              {
              case 'o':
              {
                     // char os;
                     // while(1)
                     // {
                     // std::cout << "os?" << std::endl;
                     // std::cin >> os;

                     // if(os=='k')
                     // {
                     // break;
                     // }
                     std::cout << "Podaj wartość kąta obrotu w stopniach" << std::endl;
                     std::cin >> kat;

                     std::cout << "Podaj os obrotu wzgledem, ktorej chcesz dokonac rotacji" << std::endl;
                     std::cout << "OX - wprowadz x , OY - wprowadz y , OZ - wprowadz z, wzgledem wszytskich podaj q  " << std::endl;
                     std::cin >> os;

                     // if (os == 'z')
                     // {
                     //        Ar = macierzobrotZ(kat) * Ar;
                     // }
                     // if (os == 'x')
                     // {
                     //        Ar = macierzobrotX(kat) * Ar;
                     // }
                     // if (os == 'y')
                     // {
                     //        m = m * macierzobrotZ(kat);
                     // }
                     // if (os == 'q')
                     // {
                     //        Ar = macierzobrotZ(kat) * Ar;
                     //        Ar = macierzobrotY(kat) * Ar;
                     //        Ar = macierzobrotX(kat) * Ar;
                     // }

                     // }

                     // Ar = m * Ar;
                     // Ar = macierzobrotY(kat) * Ar;
                     // Ar = macierzobrotX(kat) * Ar;

                     std::cout << Ar;
                     if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Prostopadloscian.dat", Ar /*, wektor_trans*/))
                            return 1;
                     Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                     std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
                     std::cin.ignore(100000, '\n');
              }
              break;
              case 'r':
              {
                     std::cout << "Macierz obrotu o, ktora z osi chcesz zobaczyc ? " << std::endl;
                     std::cout << "OX - wprowadz x , OY - wprowadz y , OZ - wprowadz z  " << std::endl;
                     std::cin >> os;

                     if (os == 'x')
                            std::cout << macierzobrotX(kat) << std::endl;
                     if (os == 'y')
                            std::cout << macierzobrotY(kat) << std::endl;
                     if (os == 'z')
                            std::cout << macierzobrotZ(kat) << std::endl;
              }
              break;
              case 'p':
              {
                     std::cout << "Podaj wektor translacji" << std::endl;
                     std::cin >> wektor_trans;
                     // Ar.move(wektor_trans);
                     if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Prostopadloscian.dat", Ar /*, wektor_trans*/))
                            return 1;
                     Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                     std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
                     std::cin.ignore(100000, '\n');
              }
              break;
              case 'w':
              {
                     std::cout << Ar;
                     if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Prostopadloscian.dat", Ar /*, wektor_trans*/))
                            return 1;
                     Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                     std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
                     std::cin.ignore(100000, '\n');
              }
              break;

              case 'm':
              {
                     int a = 10, b = 20, c = 30;
                     std::cout << cztery(a, b, c, wektor);
              }
              break;
              case 'k':
              {
                     std::cout << "Koniec dzialania programu." << std::endl;
              }
              break;
              default:
                     std::cout << "Bledna opcja" << std::endl;
                     break;
              }
       }
       // return 0;
}
