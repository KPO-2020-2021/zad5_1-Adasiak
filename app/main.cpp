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
#include <vector>
#include <unistd.h>

#include "matrix3x3.hh"
#include "exampleConfig.h"
// #include "vector.hh"
// #include "Graniastoslup6.hh"
// #include "Prostopadloscian.hh"

#include "Dron.hh"
#include "Scena.hh"
#include "../include/lacze_do_gnuplota.hh"

/*!
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 * 
 * EDIT: dodane kreowanie wektorow i macierzy plus obsluga lacza do gnuplota
 */


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
       
       char menu;
       // double kat=1;
       // char os;
       int powierzchnia;
       // Matrix<3> m;
       Vector<3> zero;
       zero[0]=0;
       zero[1]=0;
       zero[2]=0;
       Vector<3> wektor_trans;
       wektor_trans[0]=50;
       wektor_trans[1]=50;
       wektor_trans[2]=30;
       Vector<3> skala;
       Vector<3> wektor;
       wektor[0] = 10;
       wektor[1] = 10;
       wektor[2] = 10;
       
       int nr=1;
       Dron Predator(nr);
       int Mariusz = 2;
       Dron Pudzianowski(Mariusz);

       // Pudzianowski.ruch(wektor_trans,0,0);
       
       double a=-90,b=90,c,d;
       c=atan2(b,a);
       std::cout << c  <<std::endl;
       d =c*180/M_PI ;
       std::cout << d  <<std::endl;

       // double h=2, w=3; //wysokosc i długosc Prostopadlosciana
       std::cout << "Project Dron based on C++ Boiler Plate v"
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
       // Lacze.DodajNazwePliku("../datasets/korpus.dat", PzG::RR_Ciagly, 2);
       Scena dno(500,500,0,"../datasets/dno.dat","../datasets/dno2.dat");
    dno.zapis();

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




       // Lacze.DodajNazwePliku("../datasets/korp2.dat");

       
       Lacze.DodajNazwePliku("../datasets/dno2.dat" );
       // Lacze.DodajNazwePliku("../datasets/trasa_przelotu.dat" );

       Lacze.DodajNazwePliku("../datasets/korp2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik1_2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik2_2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik3_2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik4_2.dat");
       Lacze.DodajNazwePliku("../datasets/czubek1_2.dat");

       Lacze.DodajNazwePliku("../datasets/korp4.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik1_4.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik2_4.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik3_4.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik4_4.dat");
       Lacze.DodajNazwePliku("../datasets/czubek2_2.dat");

       
       // double marcin=45;
       // Predator.obrot(marcin);
       Lacze.Rysuj();
       
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

       //----------------------------------------------------------
       // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
       //
 

       
       // Predator.obrot(90);
       // Pudzianowski.obrot(90);
       
       // Predator.AnimacjaLotuDrona(Lacze,a,b);
       // Pudzianowski.AnimacjaLotuDrona(Lacze,a,b);

       double kotek=50;
       Predator.zwiad2(Lacze,kotek);
       Pudzianowski.zwiad2(Lacze,kotek); 
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // }
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

              

       // Predator.ruch(kasia,0,0);
       // // Predator.obrot(1);
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // }
       // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       // std::cin.ignore(100000, '\n');

       while (menu != 'k')
       {

              std::cout << "Wybierz jedna z dostepnych opcji: " << std::endl;
              std::cout << "a - wybierz aktywnego drona" << std::endl;
              std::cout << "p - zadaj parametry przelotu" << std::endl;
              std::cout << "d - dodaj element powierzchni" << std::endl;
              std::cout << "u - usun element powierzchni" << std::endl;
              std::cout << "m - wyswietl menu" << std::endl;
              std::cout << "k - koniec dzialania programu" << std::endl;
              std::cin >> menu;

              int aktywny;
              switch (menu)
              {
              case 'a':
              {
                     std::cout << "1 - Polozenie (x,y):  " ;
                     Predator.wspolrzedne();
                     std::cout << "2 - Polozenie (x,y):  " ;
                     Pudzianowski.wspolrzedne();
                     std::cout<<"Podaj numer drona: ";
                     std::cin>>aktywny;

              }
              break;
              case 'p':
              {
                     std::cout<<"Podaj wspolzedne jakie ma osiagnac dron::";
                     double w1,w2;
                     std::cin>>w1;
                     std::cout<<" ";
                     std::cin>>w2;

                     if(aktywny==1){
                     Predator.AnimacjaLotuDrona(Lacze,w1,w2);
                     }
                     if(aktywny==2){
                     Pudzianowski.AnimacjaLotuDrona(Lacze,w1,w2);
                     }


              }
              break;
              case 'd':
              {
                     std::cout << "Wybierz rodzaj powierzchniowego elementu " << std::endl;
                     std::cout << "1 - Gora z ostrym sztytem" << std::endl;
                     std::cout << "2 - Gora z grania" << std::endl;
                     std::cout << "3 - Plaskowyz" << std::endl;
                     std::cin >> powierzchnia;

                     if (powierzchnia == 1)
                     {
                            std::cout << "Podaj scale wzdluz kolejnych osi OX, OY, OZ." << std::endl;
                            std::cin >> skala;

                     } 
                     
                     if (powierzchnia == 2)
                     {
                            std::cout << "Podaj scale wzdluz kolejnych osi OX, OY, OZ." << std::endl;
                            std::cin >> skala;

                     }
                     
                     if (powierzchnia == 3)
                     {
                            std::cout << "Podaj scale wzdluz kolejnych osi OX, OY, OZ." << std::endl;
                            std::cin >> skala;
                     }
                     

              }
              break;
              case 'u':
              {
                     

              }
              break;
              
              case 'm':
              {

              }
              break;
              case 'k':
              {
                     std::cout << "Koniec dzialania programu." << std::endl;
              }
              break;
              
              // break;
              default:
                     std::cout << "Bledna opcja" << std::endl;
                     break;
              }
       }
       // return 0;
}
