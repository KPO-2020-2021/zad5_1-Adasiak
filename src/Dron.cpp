#include "Dron.hh"



Dron::Dron(int id)
{
    Dron::id++;
    id=id;
    // Prostopadloscian pkt1 ;
    // Graniastoslup pkt2;
    // pkt1[5]=pkt2[0];
    // k[4]=w1[0];
    // k[5]=w2[0];
    // k[6]=w3[0];
    // k[7]=w4[0];

    korpus = new Prostopadloscian(droga, 30, 30, 20 /*,"bryly/korp.dat","bryly/korp2.dat"*/);
    wirniki[0] = new Graniastoslup((*korpus)[4], 12,12,10 /*,"bryly/s1.dat","bryly/s1_2.dat"*/);
    wirniki[1] = new Graniastoslup((*korpus)[5], 12,12,10 /*,"bryly/s2.dat","bryly/s2_2.dat"*/);
    wirniki[2] = new Graniastoslup((*korpus)[6], 12,12,10 /*,"bryly/s2.dat","bryly/s2_2.dat"*/);
    wirniki[3] = new Graniastoslup((*korpus)[7], 12,12,10 /*,"bryly/s2.dat","bryly/s2_2.dat"*/);
}

void Dron::ruch(Vector<3> droga, double katOZ, double katOY /*, double OX*/)
{
    wirniki[0]->set_katOZ(katOZ);
    wirniki[0]->set_katOY(katOY);
    wirniki[0]->set_katOX(3);
    wirniki[0]->move(droga);

    wirniki[1]->set_katOZ(katOZ);
    wirniki[1]->set_katOY(katOY);
    wirniki[1]->set_katOX(3);
    wirniki[1]->move(droga);

    wirniki[2]->set_katOZ(katOZ);
    wirniki[2]->set_katOY(katOY);
    wirniki[2]->set_katOX(3);
    wirniki[2]->move(droga);

    wirniki[3]->set_katOZ(katOZ);
    wirniki[3]->set_katOY(katOY);
    wirniki[3]->set_katOX(3);
    wirniki[3]->move(droga);

    korpus->set_katOZ(katOZ);
    korpus->set_katOY(katOY);
    korpus->move(droga);

    wirniki[0]->zapis();
    wirniki[1]->zapis();
    wirniki[2]->zapis();
    wirniki[3]->zapis();

    korpus->zapis();
    

}

void Dron::obrot(double kat)
{
    Vector<3> tmp;

    wirniki[0]->set_katOZ(kat);
    wirniki[0]->set_katOY(kat);
    wirniki[0]->set_katOX(3);
    wirniki[0]->move(tmp);

    wirniki[1]->set_katOZ(kat);
    wirniki[1]->set_katOY(kat);
    wirniki[1]->set_katOX(3);
    wirniki[1]->move(tmp);

    wirniki[2]->set_katOZ(kat);
    wirniki[2]->set_katOY(kat);
    wirniki[2]->set_katOX(3);
    wirniki[2]->move(tmp);

    wirniki[3]->set_katOZ(kat);
    wirniki[3]->set_katOY(kat);
    wirniki[3]->set_katOX(3);
    wirniki[3]->move(tmp);

    korpus->set_katOZ(kat);
    korpus->set_katOY(kat);
    korpus->move(tmp);

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





// std::ostream &operator<<(std::ostream &Strm,
//                          const Graniastoslup &Pr)
// {

//     for (int i = 1; i < 25; i++)
//     {
//         Strm << Pr[i] << endl;
//         if ((i) % 2 == 0)
//             Strm << endl;
//     }

//     return Strm;
// }
