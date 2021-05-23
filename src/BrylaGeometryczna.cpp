#include "BrylaGeometryczna.hh"






// void BrylaGeometryczna::move(const Vector<3> &v)
// {
//     for (int i = 0; i < (int)pkt1.size(); i++)
//     {
//         pkt1[i] = pkt1[i] + v;
//     }
// }



void BrylaGeometryczna::move(const Vector<3> &v)
{
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = macierzobrotZ(katOZ)*(macierzobrotX(katOX)*(pkt1[i]))+v;
    }
}

/*mozna v zamienic z przesuniecie wtedy "bedzie kontakt z baza" */



void BrylaGeometryczna::obrotP(double kat)
{
    Vector<3> tmp;
    tmp = (pkt1[1] - pkt1[0])/2 +tmp;
    tmp = (pkt1[2] - pkt1[0])/2 +tmp; 

    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}



void BrylaGeometryczna::obrotW(double kat)
{
    Vector<3> tmp;
    tmp= pkt1[0];
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
    }
}


void BrylaGeometryczna::obrotW1(double kat)
{
    Vector<3> ujem;
    ujem[0]=-1;
    ujem[1]=-1;
    ujem[2]=-1;
    Vector<3> tmp;
    tmp= pkt1[0];
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ1(kat)*((pkt1[i] - tmp))) + tmp  ;
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
