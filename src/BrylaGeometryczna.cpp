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


void BrylaGeometryczna::obrotOZ(double kat)
{
    // Vector<3> tmp;
    // tmp = (pkt1[1] - pkt1[0])/2 +tmp;
    // tmp = (pkt1[2] - pkt1[0])/2 +tmp; 

    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] ))) ;
    }
}


void BrylaGeometryczna::obrotP(double kat, Vector<3> a)
{
    Vector<3> tmp;
    tmp[0]=0;
    tmp[1]=0;
    tmp[2]=0;
    // tmp = (pkt1[1] - a)/2 +tmp ;
    // tmp = (pkt1[2]- a)/2 +tmp;
    double q=15,w=15;
    // q = 
    tmp[0] = (q + a[0]) /*+tmp*/ ;
    tmp[1] = (w + a[1]) /*+tmp*/; 
    
    // tmp[0]= 15;
    // tmp[1]= 15;

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


void BrylaGeometryczna::obrotW1(double kat,Vector<3> b)
{
    // Vector<3> ujem;
    // ujem[0]=-1;
    // ujem[1]=-1;
    // ujem[2]=-1;
    // Vector<3> tmp;
    // tmp[0]+= 15;
    // tmp[1]+= 15;
    double z=15;
    Vector<3> tmp;
    tmp[0]=0;
    tmp[1]=0;
    tmp[2]=0;
    tmp[0] = (z + b[0]) /*+tmp*/ ;
    tmp[1] = (z + b[1]) /*+tmp*/; 
    for (int i = 0; i < (int)pkt1.size(); i++)
    {
        pkt1[i] = (macierzobrotZ(kat)*((pkt1[i] - tmp))) + tmp  ;
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
