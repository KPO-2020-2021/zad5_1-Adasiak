#include "Dron.hh"
#include "lacze_do_gnuplota.hh"
#include <unistd.h>
#define PLIK_TRASY_PRZELOTU "..datasets/trasa_przelotu.dat"


Dron::Dron(int id)
{
    Dron::id++;
    // id=id;
    // Prostopadloscian pkt1 ;
    // Graniastoslup pkt2;
    // pkt1[5]=pkt2[0];
    // k[4]=w1[0];
    // k[5]=w2[0];
    // k[6]=w3[0];
    // k[7]=w4[0];

    // korpus = new Prostopadloscian(droga, 30, 30, 20 ,"../datasets/korp.dat","../datasets/korp2.dat");
    // wirniki[0] = new Graniastoslup((*korpus)[4], 12,12,10,"../datasets/s1.dat","../datasets/s1_2.dat");
    // wirniki[1] = new Graniastoslup((*korpus)[5], 12,12,10 ,"../datasets/s2.dat","../datasets/s2_2.dat");
    // wirniki[2] = new Graniastoslup((*korpus)[6], 12,12,10 ,"../datasets/s2.dat","../datasets/s2_2.dat");
    // wirniki[3] = new Graniastoslup((*korpus)[7], 12,12,10 ,"../datasets/s2.dat","../datasets/s2_2.dat");

  if(id==1){
    korpus = new Prostopadloscian( droga,30, 30, 20 ,"../datasets/korp.dat","../datasets/korp2.dat");
    wirniki[0] = new Graniastoslup((*korpus)[4], 12,12,10,"../datasets/wirnik1.dat","../datasets/wirnik1_2.dat");
    wirniki[1] = new Graniastoslup((*korpus)[5], 12,12,10 ,"../datasets/wirnik2.dat","../datasets/wirnik2_2.dat");
    wirniki[2] = new Graniastoslup((*korpus)[6], 12,12,10 ,"../datasets/wirnik3.dat","../datasets/wirnik3_2.dat");
    wirniki[3] = new Graniastoslup((*korpus)[7], 12,12,10 ,"../datasets/wirnik4.dat","../datasets/wirnik4_2.dat");
  }
  if(id==2){
    double a=-100,b=-100;
    dwojka[0]=a;
    dwojka[1]=b;

    korpus1 = new Prostopadloscian( dwojka,30, 30, 20 ,"../datasets/korp3.dat","../datasets/korp4.dat");
    wirniki1[0] = new Graniastoslup((*korpus1)[4], 12,12,10,"../datasets/wirnik1_3.dat","../datasets/wirnik1_4.dat");
    wirniki1[1] = new Graniastoslup((*korpus1)[5], 12,12,10 ,"../datasets/wirnik2_3.dat","../datasets/wirnik2_4.dat");
    wirniki1[2] = new Graniastoslup((*korpus1)[6], 12,12,10 ,"../datasets/wirnik3_3.dat","../datasets/wirnik3_4.dat");
    wirniki1[3] = new Graniastoslup((*korpus1)[7], 12,12,10 ,"../datasets/wirnik4_3.dat","../datasets/wirnik4_4.dat");

  }


}


// void Dron::Dron2()
// {
//     double a=-100,b=-100;
//     dwojka[0]=a;
//     dwojka[1]=b;

//     korpus = new Prostopadloscian( dwojka,30, 30, 20 ,"../datasets/korp3.dat","../datasets/korp4.dat");
//     wirniki[0] = new Graniastoslup((*korpus)[4], 12,12,10,"../datasets/wirnik1_3.dat","../datasets/wirnik1_4.dat");
//     wirniki[1] = new Graniastoslup((*korpus)[5], 12,12,10 ,"../datasets/wirnik2_3.dat","../datasets/wirnik2_4.dat");
//     wirniki[2] = new Graniastoslup((*korpus)[6], 12,12,10 ,"../datasets/wirnik3_3.dat","../datasets/wirnik3_4.dat");
//     wirniki[3] = new Graniastoslup((*korpus)[7], 12,12,10 ,"../datasets/wirnik4_3.dat","../datasets/wirnik4_4.dat");



// }



void Dron::ruch(Vector<3> droga, double katOZ, double katOY /*, double OX*/)
{
    wirniki[0]->set_katOZ(katOZ);
    // wirniki[0]->set_katOY(katOY);
    // wirniki[0]->set_katOX(3);
    wirniki[0]->obrotW(90);
    wirniki[0]->move(droga);

    wirniki[1]->set_katOZ(katOZ);
    // wirniki[1]->set_katOY(katOY);
    // wirniki[1]->set_katOX(3);
    wirniki[1]->obrotW(90);
    wirniki[1]->move(droga);

    wirniki[2]->set_katOZ(katOZ);
    // wirniki[2]->set_katOY(katOY);
    // wirniki[2]->set_katOX(3);
    wirniki[2]->obrotW(90);
    wirniki[2]->move(droga);

    // wirniki[3]->set_katOZ(katOZ);
    // wirniki[3]->set_katOY(katOY);
    // wirniki[3]->set_katOX(3);
    wirniki[3]->obrotW(90);
    wirniki[3]->move(droga);

    korpus->set_katOZ(katOZ);
    korpus->set_katOY(katOY);
    // korpus->obrotP(1);
    korpus->move(droga);

    wirniki[0]->zapis();
    wirniki[1]->zapis();
    wirniki[2]->zapis();
    wirniki[3]->zapis();

    korpus->zapis();
    
    Dron::droga = droga + Dron::droga;

    // Dron::dwojka = droga + Dron::dwojka;

}

void Dron::obrot(double kat)
{
    Vector<3> tmp;

    // wirniki[0]->set_katOZ(kat);
    // wirniki[0]->set_katOY(kat);
    // wirniki[0]->set_katOX(3);
    // wirniki[0]->move(tmp);

    // wirniki[1]->set_katOZ(kat);
    // wirniki[1]->set_katOY(kat);
    // wirniki[1]->set_katOX(3);
    // wirniki[1]->move(tmp);

    // wirniki[2]->set_katOZ(kat);
    // wirniki[2]->set_katOY(kat);
    // wirniki[2]->set_katOX(3);
    // wirniki[2]->move(tmp);

    // wirniki[3]->set_katOZ(kat);
    // wirniki[3]->set_katOY(kat);
    // wirniki[3]->set_katOX(3);
    // wirniki[3]->move(tmp);

    // korpus->set_katOZ(kat);
    // korpus->set_katOY(kat);
    // korpus->move(tmp);


    // korpus->obrotP(kat);


    // wirniki[0]->obrotOZ(kat);
    // wirniki[1]->obrotOZ(kat);
    // wirniki[2]->obrotOZ(kat);
    // wirniki[3]->obrotOZ(kat);

    // korpus->obrotOZ(kat);
     wirniki[0]->obrotW(90);
    wirniki[0]->obrotW1(kat,droga);
    
    wirniki[1]->obrotW(90);
    wirniki[1]->obrotW1(kat,droga);
    
    wirniki[2]->obrotW(90);
    wirniki[2]->obrotW1(kat,droga);
    
    wirniki[3]->obrotW(90);
    wirniki[3]->obrotW1(kat,droga);

    korpus->obrotP(kat, droga);



    wirniki[0]->zapis();
    wirniki[1]->zapis();
    wirniki[2]->zapis();
    wirniki[3]->zapis();

    korpus->zapis();
    
}

void Dron::zwiad(Vector<3> promien)
{
    // Vector<3> tmp;
    // tmp[0]=0;
    // tmp[1]= 0;
    // tmp[2]=80;

    // wirniki[0]->move(tmp);
    // wirniki[1]->move(tmp);
    // wirniki[2]->move(tmp);
    // wirniki[3]->move(tmp);
    // korpus->move(tmp);

    // promien=20;
    // Vector<3> tmp1;
    // tmp1[1]=promien;
    // tmp1[0]=0;
    // tmp1[2]=0;

    // ruch(tmp,0,0);

    // wirniki[0]->zapis();
    // wirniki[1]->zapis();
    // wirniki[2]->zapis();
    // wirniki[3]->zapis();

    // korpus->zapis();
    

    ruch(promien,0,0);

    wirniki[0]->obrotOZ(180.0);
    wirniki[1]->obrotOZ(180.0);
    wirniki[2]->obrotOZ(180.0);
    wirniki[3]->obrotOZ(180.0);
    korpus->obrotOZ(180.0);

    // wirniki[0]->move(tmp);
    // wirniki[1]->move(tmp);
    // wirniki[2]->move(tmp);
    // wirniki[3]->move(tmp);
    // korpus->move(tmp);


    // Lacze.rysuj();
    // wirniki[0]->move(tmp1);
    // wirniki[1]->move(tmp1);
    // wirniki[2]->move(tmp1);
    // wirniki[3]->move(tmp1);
    // korpus->move(tmp1);


    wirniki[0]->zapis();
    wirniki[1]->zapis();
    wirniki[2]->zapis();
    wirniki[3]->zapis();

    korpus->zapis();
    

}

    // korpus->move(droga);
    // wirniki[0]->move(droga);
    // wirniki[1]->move(droga);
    // wirniki[2]->move(droga);
    // wirniki[3]->move(droga);

    // korpus->zapis();
    // wirniki[0]->zapis();
    // wirniki[1]->zapis();
    // wirniki[2]->zapis();
    // wirniki[3]->zapis();



std::ostream &operator<<(std::ostream &Strm,
                         /*const*/ Dron &P)
{

    // Dron::korpus;

    // Prostopadloscian korpus;
    // Graniastoslup wirniki[4];


    Strm << P << endl;

    // for (int i = 0; i < 4; i++)
    // {
    //     Strm << P << endl;
    //     if ((i + 1) % 2 == 0)
    //         Strm << endl;
    // }

    return Strm;
}

bool Dron::DodajTrasePrzelotu(PzG::LaczeDoGNUPlota &Lacze ,double x2, double y2)
{

  // this->nazwa_pliku = nazwa_pliku;
  // this->nazwa_pliku_do_zapisu = nazwa_pliku_do_zapisu;

  ofstream  StrmWy(PLIK_TRASY_PRZELOTU);

  if (!StrmWy.is_open()) {
    cerr << endl
	 << " Nie mozna otworzyc do zapisu pliku: " << PLIK_TRASY_PRZELOTU << endl
	 << endl;
    return false;
  }

  double a,b;
  a=droga[0]+15;
  b=droga[1]+15;
  Vector<3> s,d,f,g;
  s[0]=a;
  s[1]=b;

  d=s;
  d[2]=80;

  f=d;
  f[0]+=x2;
  f[1]+=y2;

  g=f;
  g[2]=0;
  StrmWy << s << endl
	 << d << endl
	 << f << endl
	 << g << endl;
  Lacze.DodajNazwePliku(PLIK_TRASY_PRZELOTU);
  return !StrmWy.fail();
}

void Dron::AnimacjaLotuDrona(PzG::LaczeDoGNUPlota &Lacze, double x1,double y1)
{
  
  double x_dron = 20, y_dron = 20, z_dron = 0;
  // double KatOr_st = 0;

  //-------------------------------------
  // Wznoszenie ...
  //
  DodajTrasePrzelotu(Lacze,x1,y1);
  Vector<3> wznoszenie;
  wznoszenie[2]=2;
  cout << endl << "Wznoszenie ... " << endl;
  for (; z_dron <= 80; z_dron += 2) 
  {
      ruch(wznoszenie,0,0);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }

  z_dron -= 2;
  
  double c,d; 
  // katobr = atan2(y1,x1) ;
  c=atan2(y1,x1);
  std::cout << c  <<std::endl;
  d =c*180/M_PI ;
  std::cout << d  <<std::endl;

  cout << "Zmiana orientacji ... " << endl;
  if(d>0)
  {
      for ( int i=0; i <= d; i += 5) 
      {
        
        obrot(5);
        // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
        //     return false;
        
        usleep(100000);
        Lacze.Rysuj();
      }
  }
  else
  {
    d=d*(-1);
    for ( int i=0; i <= d; i += 5) 
      {
        
        obrot(-5);
        // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
        //     return false;
        
        usleep(100000);
        Lacze.Rysuj();
      }
  }

  // KatOr_st -= 5;

  //-------------------------------------
  // Lot do przodu ...
  //  
  double x,y;
  // double x1=150,y1=150;
  double q,w;
  q=(droga[0]-15.0);
  w=(droga[1]-15.0);
  x=(x1 - q)/50;
  y=(y1 - w)/50;
  Vector<3> lot;
  lot[0]=x;
  lot[1]=y;
  cout << "Lot do przodu ... " << endl;
  for (; /*(x_dron <= 100)&&*/(y_dron<=50) ; x_dron += 1, y_dron += 1) {
    
    ruch(lot,0,0);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000);
    Lacze.Rysuj();
  }  
  x_dron -= 1, y_dron -= 1;


  //-------------------------------------
  // Opadanie ...
  //
  Vector<3> opadanie;
    opadanie[2]=-2;
  cout << "Opadanie ... " << endl;
  for (; z_dron >= 0; z_dron -= 2) {
    
      ruch(opadanie,0,0);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }

//   return true;
}


void Dron::zwiad2(PzG::LaczeDoGNUPlota &Lacze,double promien)
{
  
  double x_dron = 20, y_dron = 20, z_dron = 0;
  double KatOr_st = 0;

  //-------------------------------------
  // Wznoszenie ...
  //
  Vector<3> wznoszenie;
  wznoszenie[2]=2;
  cout << endl << "Wznoszenie ... " << endl;
  for (; z_dron <= 80; z_dron += 2) 
  {
      ruch(wznoszenie,0,0);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }

  z_dron -= 2;
  
  // double katobr; 
  // katobr = atan2(y1,x1) ;
  cout << "Zmiana orientacji ... " << endl;
  for (; KatOr_st <= 45; KatOr_st += 5) {
    
    obrot(5);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000);
    Lacze.Rysuj();
  }
  KatOr_st -= 5;

  //-------------------------------------
  // Lot do przodu ...
  //  
  double x,y;
  // double x1=150,y1=150;
  double a,b;
  a=(droga[0]-15.0);
  b=(droga[1]-15.0);
  x=(promien -a)/50;
  y=(promien -b)/50;
  Vector<3> lot;
  lot[0]=x;
  lot[1]=y;
  cout << "Lot do przodu ... " << endl;
  for (; /*(x_dron <= 100)&&*/(y_dron<=50) ; x_dron += 1, y_dron += 1) {
    
    ruch(lot,0,0);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000);
    Lacze.Rysuj();
  }  
  x_dron -= 1, y_dron -= 1;


  // Dron::droga[0]=promien;
  // Dron::droga[1]=promien;

  cout << droga << endl;
  cout << "Zmiana orientacji ... 1 " << endl;
  for (int j=0; j <=90; j += 5) {
    
    obrot(5);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000);
    Lacze.Rysuj();
  }

  Vector<3> pomocniczy;
  pomocniczy=droga;
  cout << "pomocniczy =" << pomocniczy << endl;
  // KatOr_st -= 5;

  // Dron::droga[0] = pomocniczy[0] - Dron::droga[0];
  // Dron::droga[1] = pomocniczy[1] - Dron::droga[1];
  // Dron::droga[0]=0;
  // Dron::droga[1]=0;
  // Dron::droga[2]=0;
  // Dron::droga[1]=0;
  cout << "droga =" <<droga << endl;
  cout << "Zwiad...." << endl;
  // Vector<3> zw;
  // zw[0]=promien*sin();
  // zw[1]=-1;
// tmp[0]=srodek[0]+promien*sin(i*M_PI/180);
// tmp[1]=srodek[1]+promien*cos(i*M_PI/180);
  for(int i=0; i<=180; i++)
  {
    //   Vector<3> zw;
    //   zw[0]=promien*sin(i*M_PI/180);
    //   zw[1]=promien*cos(i*M_PI/180);
    // ruch(zw,0,0);

    // usleep(100000);
    // Lacze.Rysuj();

    Dron::droga[0]=-10;
    Dron::droga[1]=-10;
    // Dron::droga[2]=0;

     obrot(2);

    usleep(100000);
    Lacze.Rysuj();
  }


  Dron::droga[0]=pomocniczy[0];
    Dron::droga[1]=pomocniczy[1];
   cout << droga << endl;
  cout << "Zmiana orientacji ... 1 " << endl;
  for (int k=0; k <= 90; k += 5) {
    
    obrot(5);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000);
    Lacze.Rysuj();
  }


  // KatOr_st -= 5;

  cout<<"Powrót...."<<endl;
  Vector<3> powrot;
  powrot[0]=-(promien -10)/50;
  powrot[1]=-(promien -10)/50;
  for (int l=0; l<=50 ; l++) {
    
    ruch(powrot,0,0);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000);
    Lacze.Rysuj();
  }  
  // x_dron -= 1, y_dron -= 1;




  //-------------------------------------
  // Opadanie ...
  //
  Vector<3> opadanie;
    opadanie[2]=-2;
  cout << "Opadanie ... " << endl;
  for (; z_dron >= 0; z_dron -= 2) {
    
      ruch(opadanie,0,0);
    // if (!PrzemiescDrona(KatOr_st,x_dron,y_dron,z_dron)) 
    //     return false;
    
    usleep(100000); // 0.1 ms
    Lacze.Rysuj();
  }

//   return true;
}