#include <iostream>
#include "Vehicul.h"
#include "Masina.h"
#include "Motocicleta.h"
#include <fstream>

      /*
         MODELE MASINI: Dacia_Logan, MazdaRX8,Peugeot207
         MODELE MOTOCICLETE: moto1, moto2, moto3
         
         Masina obj(model masina)
         Motocicleta obj(model motocicleta)
         
         DATE FISIER:
         AN FABRICATIE
         KM LA BORD
         VOLUM MOTOR (FLOAT)
         
         */

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
