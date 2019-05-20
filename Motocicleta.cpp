//
// Created by Dragos on 18/05/2019.
//

#include "Motocicleta.h"

Motocicleta::Motocicleta(motoT mt, int k) : Vehicul<motoT>(mt,k)
{
    dmoto = new Directie_moto[r];
}

Motocicleta::Motocicleta(const Motocicleta &o): Vehicul<motoT>(o)
{
    dmoto = new Directie_moto[r];

    for(int i = 0;i < r;i++)
        dmoto[i] = o.dmoto[i];
}

Motocicleta::~Motocicleta()
{
    delete[]dmoto;
}

Motocicleta &Motocicleta::operator=(Motocicleta moto){

    delete[]dmoto;
    delete[]f;
    r = moto.r;
    dmoto = new Directie_moto[r];
    f = new Frane[r];
    mm = moto.mm;
    c.model = moto.c.model;
    c.an_fab = moto.c.an_fab;
    c.km = moto.c.km;



    for(int i = 0;i < r;i++)
    {
        dmoto[i] = moto.dmoto[i];
        f[i] = moto.f[i];
    }

    return *this;
}

void  Motocicleta::calcul_cost()
{
    cout<<"========================================"<<endl;
    cout<<"DEVIZ COSTURI: "<<endl;
    cout<<endl;
    srand(static_cast<unsigned int>(time(nullptr)));
    double price = 0.0;
    for(int i = 0;i < r;i++)
    {
        int prob = (rand()%20) + 1;
        int prob1 = (rand()%16) +1;

        if(prob >= 10)
        {
            if(i%2 == 0)
            {

                switch(c.model)
                {
                    case moto2 : price += Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<motoT >::pret_surub;
                        cout<<"Defectiune placuta frana fata   Cost: "<<Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<motoT >::pret_surub<<endl;
                        break;
                    case moto1 : price += 4 * Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<motoT >::pret_surub;
                        cout<<"Defectiune placuta frana fata   Cost: "<<3*Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case moto3 : price += 1.5 * Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<motoT>::pret_surub;
                        cout<<"Defectiune placuta frana fata   Cost: "<<2*Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<motoT>::pret_surub<<endl;
                        break;
                    default: cout<<"Nu exista piese de schimb pentru acest model"<<endl;
                }
            }
            else
            {
                switch(c.model)
                {
                    case moto2 : price += Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<motoT>::pret_surub;
                        cout<<"Defectiune placuta frana spate   Cost: "<<Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<motoT>::pret_surub<<endl;
                        break;
                    case moto1 : price += 3 * Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<motoT>::pret_surub;
                        cout<<"Defectiune placuta frana spate   Cost: "<<3*Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case moto3 : price += 2 * Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<motoT>::pret_surub;
                        cout<<"Defectiune placuta frana spate   Cost: "<<2*Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<motoT>::pret_surub<<endl;
                        break;
                    default: cout<<"Nu exista piese de schimb pentru acest model"<<endl;
                }
            }

        }
        if(prob1 >= 10)
        {
            switch(c.model)
            {
                case moto2 : price += Solutii_frane::inlocuit_discuri() + 5 * Vehicul<motoT>::pret_surub;
                    cout<<"Defectiune disc roata   Cost: "<<Solutii_frane::inlocuit_discuri() + 5 * Vehicul<motoT >::pret_surub<<endl;
                    break;
                case moto1 : price += 3 * Solutii_frane::inlocuit_discuri() + 5 * Vehicul<motoT >::pret_surub;
                    cout<<"Defectiune disc roata   Cost: "<<4*Solutii_frane::inlocuit_discuri() + 5 * Vehicul<motoT >::pret_surub<<endl;
                    break;
                case moto3 : price += 1.5 * Solutii_frane::inlocuit_discuri() + 5 * Vehicul<motoT >::pret_surub;
                    cout<<"Defectiune disc roata   Cost: "<<1.5*Solutii_frane::inlocuit_discuri() + 5 * Vehicul<motoT >::pret_surub<<endl;
                    break;
                default: cout<<"Nu exista piese de schimb pentru acest model"<<endl;
            }
        }

    }

    if(!mm.stare_motor())
    {
        if(c.model == moto1)
        {
            price += 2 * Solutii_motor::segmentare_motor_moto(Vehicul<motoT >::volum) + 15 * Vehicul<motoT >::pret_surub;
            cout<<"Segmentare motor   Cost: "<<2 * Solutii_motor::segmentare_motor_moto(Vehicul<motoT >::volum) + 15 * Vehicul<motoT>::pret_surub<<endl;
        }
        else
        {
            price += Solutii_motor::segmentare_motor_moto(Vehicul<motoT>::volum) + 15 * Vehicul<motoT>::pret_surub;
            cout<<"Segmentare motor   Cost: "<<Solutii_motor::segmentare_motor_moto(Vehicul<motoT>::volum) + 15 * Vehicul<motoT>::pret_surub<<endl;
        }
    }

    if(c.km >= 4000)
    {
        if(c.model == moto1)
        {
            price += 1.3 * Solutii_motor::schimb_ulei(Vehicul<motoT >::volum) + 5 * Vehicul<motoT >::pret_surub;
            cout<<"Schimb ulei   Cost: "<<1.3 * Solutii_motor::schimb_ulei(Vehicul<motoT >::volum) + 5 * Vehicul<motoT>::pret_surub<<endl;
        }
        else
        {
            price += Solutii_motor::schimb_ulei(Vehicul<motoT >::volum) + 5 * Vehicul<motoT >::pret_surub;
            cout<<"Schimb ulei   Cost: "<<Solutii_motor::schimb_ulei(Vehicul<motoT>::volum) + 5 * Vehicul<motoT>::pret_surub<<endl;
        }
    }

    cout<<endl<<"COST TOTAL:  "<<price<<endl;

}

