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



// void PrzykladZapisuWspolrzednychDoStrumienia2(std::ostream &StrmWy, Dron Pr)
// {
//        StrmWy << Pr;
// }


// bool PrzykladZapisuWspolrzednychDoPliku2(const char *sNazwaPliku,
//                                         Dron Pr /*, Vector<  2> Przesuniecie*/)
// {
//        std::ofstream StrmPlikowy;

//        StrmPlikowy.open(sNazwaPliku);
//        if (!StrmPlikowy.is_open())
//        {
//               std::cerr << ":(  Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
//                         << ":(  nie powiodla sie." << std::endl;
//               return false;
//        }

//        PrzykladZapisuWspolrzednychDoStrumienia2(StrmPlikowy, Pr /*, Przesuniecie*/);
//        StrmPlikowy << Pr << endl;
//        // StrmPlikowy << Pr;
//        StrmPlikowy.close();
//        return !StrmPlikowy.fail();
// }


// bool AnimacjaLotuDrona(PzG::LaczeDoGNUPlota &Lacze)
// {


//        //-------------------------------------
//   // Wznoszenie ...
//   //
//   Vector<3> tmp;
//   tmp[2]=2;
//   cout << endl << "Wznoszenie ... " << endl;
//   for (; z_dron <= 80; z_dron += 2) {
//     if (!ruch()) return false;
//     usleep(100000); // 0.1 ms
//     Lacze.Rysuj();
//   }
//   z_dron -= 2;
  
//   cout << "Zmiana orientacji ... " << endl;
//   for (; KatOr_st <= 45; KatOr_st += 5) {
//     if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) return false;
//     usleep(100000);
//     Lacze.Rysuj();
//   }
//   KatOr_st -= 5;

//   //-------------------------------------
//   // Lot do przodu ...
//   //  
//   cout << "Lot do przodu ... " << endl;
//   for (; x_dron <= 150; x_dron += 1, y_dron += 1) {
//     if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) return false;
//     usleep(100000);
//     Lacze.Rysuj();
//   }  
//   x_dron -= 1, y_dron -= 1;


//   //-------------------------------------
//   // Opadanie ...
//   //
//   cout << "Opadanie ... " << endl;
//   for (; z_dron >= 0; z_dron -= 2) {
//     if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) return false;
//     usleep(100000); // 0.1 ms
//     Lacze.Rysuj();
//   }

//   return true;



// }



int main()
{
       int nr=0;
       char menu;
       // double kat=1;
       char os;
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
 
       // Prostopadloscian Pr(zero, 50, 50, 30);

       // Graniastoslup Ar(Pr[4], 20,20,10);
       // Graniastoslup Ar1(Pr[5], 20,20,10);
       // Graniastoslup Ar2(Pr[6], 20,20,10);
       // Graniastoslup Ar3(Pr[7], 20,20,10);

       Dron Predator(nr);

       
       // Ar = macierzobrotZ(kat) * Ar;
       double a=-90,b=90,c,d;
       c=atan2(b,a);
       std::cout << c  <<std::endl;
       d =c*180/M_PI ;
       std::cout << d  <<std::endl;

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
       // Lacze.DodajNazwePliku("../datasets/korpus.dat", PzG::RR_Ciagly, 2);
       Scena dno(500,500,0,"../datasets/dno.dat","../datasets/dno2.dat");
    dno.zapis();


       // Lacze.DodajNazwePliku("../datasets/Prostopadloscian.dat", PzG::RR_Ciagly, 2);
       // Lacze.DodajNazwePliku("../datasets/Rotor0.dat", PzG::RR_Ciagly, 2);
       // Lacze.DodajNazwePliku("../datasets/Rotor1.dat", PzG::RR_Ciagly, 2);
       // Lacze.DodajNazwePliku("../datasets/Rotor2.dat", PzG::RR_Ciagly, 2);
       // Lacze.DodajNazwePliku("../datasets/Rotor3.dat", PzG::RR_Ciagly, 2);

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

       std::cout<<"Kasia"<<std::endl;
       
       // PrzykladZapisuWspolrzednychDoStrumienia2(std::cout, Predator /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku2("../datasets/korpus.dat", Predator))
       //        return 1;
       Lacze.DodajNazwePliku("../datasets/dno2.dat" );

       Lacze.DodajNazwePliku("../datasets/korp2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik1_2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik2_2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik3_2.dat");
       Lacze.DodajNazwePliku("../datasets/wirnik4_2.dat");

       // PrzykladZapisuWspolrzednychDoStrumienia1(std::cout, Pr /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku1("../datasets/Prostopadloscian.dat", Pr ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor0.dat", Ar ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar1 /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor1.dat", Ar1 ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar2 /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor2.dat", Ar2 ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar3 /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor3.dat", Ar3 ))
       //        return 1;
       // double marcin=45;
       // Predator.obrot(marcin);
       Lacze.Rysuj();
       
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

       //----------------------------------------------------------
       // Ponownie wypisuje wspolrzedne i rysuje prostokąt w innym miejscu.
       //
 
       std::cout << "Zosia" << std::endl;
       // std::cout << "Justyna" << std::endl;
       // Pr.set_katOZ(kat);
       // Pr.move(wektor_trans);
       // Ar.set_katOZ(kat);
       // Ar.move(wektor_trans);
       // Ar1.set_katOZ(kat);
       // Ar1.move(wektor_trans);
       // Ar2.set_katOZ(kat);
       // Ar2.move(wektor_trans);
       // Ar3.set_katOZ(kat);
       // Ar3.move(wektor_trans);


       // Pr.obrotP(kat);
       // for(int licznik; licznik < 1000000 ; licznik ++)
       // {
       // Ar.obrotW1(kat);
       // Ar1.obrotW(kat);
       // Ar2.obrotW1(kat);
       // Ar3.obrotW(kat);
       // std::cout << "Marysia" << std::endl;
       
       // Lacze.DodajNazwePliku("../datasets/dno2.dat" );
       // PrzykladZapisuWspolrzednychDoStrumienia1(std::cout, Pr /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku1("../datasets/Prostopadloscian.dat", Pr ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor0.dat", Ar ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar1 /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor1.dat", Ar1 ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar2 /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor2.dat", Ar2 ))
       //        return 1;

       // PrzykladZapisuWspolrzednychDoStrumienia(std::cout, Ar3 /*, zero*/);
       // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Rotor3.dat", Ar3 ))
       //        return 1;

       Vector<3> kasia;
       kasia[0]=-1;
       kasia[1]=-1;
       // double a=1,b=1,c;
       // c =atan2(b,a) ;
       // std::cout << c <<std::endl; 
       // Predator.ruch(wektor_trans,0,0);
       Predator.AnimacjaLotuDrona(Lacze,a,b);
       // double kotek=50;
       // Predator.zwiad2(Lacze,kotek);
       // Predator.zwiad(kasia);
       // usleep(1000000); 
       Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // }
       std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       std::cin.ignore(100000, '\n');

       // for (int i = 0; i < 360; i++)
       // {
              
       
       
       // // Predator.zwiad(zero);
       // Predator.ruch(kasia,0,0);
       // // Predator.obrot(1);
       // usleep(100000);
       // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
       // }
       // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
       // std::cin.ignore(100000, '\n');

       // Z bazy projektu-wydmuszki Boiler Plate C++:
       // Bring in the dummy class from the example source,
       // just to show that it is accessible from main.cpp.

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

              switch (menu)
              {
              case 'a':
              {
                     std::cout << "1 - Polozenie (x,y):  " ;

                     std::cout << "2 - Polozenie (x,y):  " ;
                     
                     

              }
              break;
              case 'p':
              {
                     

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
              //        int a = 10, b = 20, c = 30;
              //        std::cout << cztery(a, b, c, wektor);
              }
              break;
              case 'k':
              {
                     std::cout << "Koniec dzialania programu." << std::endl;
              }
              break;
              case 'r':
              {
                     std::cout << "Macierz obrotu o, ktora z osi chcesz zobaczyc ? " << std::endl;
                     std::cout << "OX - wprowadz x , OY - wprowadz y , OZ - wprowadz z  " << std::endl;
                     std::cin >> os;

                     // if (os == 'x')
                     //        std::cout << macierzobrotX(kat) << std::endl;
                     // if (os == 'y')
                     //        std::cout << macierzobrotY(kat) << std::endl;
                     // if (os == 'z')
                     //        std::cout << macierzobrotZ(kat) << std::endl;
              }
              break;
              case 'q':
              {
                     // std::cout << "Podaj wektor translacji" << std::endl;
                     // std::cin >> wektor_trans;
                     // // Ar.move(wektor_trans);
                     // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Prostopadloscian.dat", Ar /*, wektor_trans*/))
                     //        return 1;
                     // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                     // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
                     // std::cin.ignore(100000, '\n');
              }
              break;
              case 'w':
              {
                     // std::cout << Ar;
                     // if (!PrzykladZapisuWspolrzednychDoPliku("../datasets/Prostopadloscian.dat", Ar /*, wektor_trans*/))
                     //        return 1;
                     // Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
                     // std::cout << "Naciśnij ENTER, aby kontynuowac" << std::endl;
                     // std::cin.ignore(100000, '\n');
              }
              break;
              default:
                     std::cout << "Bledna opcja" << std::endl;
                     break;
              }
       }
       // return 0;
}
