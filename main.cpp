#include <iostream>
#include "Vehicul.h"
#include "Masina.h"
#include "Motocicleta.h"
#include <fstream>

//enum autoT {Dacia_Logan,BMW_Seria3,Peugeot207};

using namespace std;

int main()
{
    ifstream f;
    f.open("date_vehicul");
    Vehicul<autoT> *M;
    Masina M1(MazdaRX8);
    M = &M1;
    f>>(*M);
    cout<<(*M);
    M->calcul_cost();

    /*Masina M1(Dacia_Logan);
    M = &M1;
    f>>(*M);
    cout<<(*M);
    M->calcul_cost();*/

     f.close();
    return 0;
}