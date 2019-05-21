#include "Masina.h"

Masina::Masina(autoT mdl1,int k): Vehicul<autoT >(mdl1,4)
{
}


Masina::~Masina() = default;

Masina::Masina(const Masina &obj): Vehicul<autoT>(obj)
{
    crs = obj.crs;
    m = obj.m;
}

Masina &Masina::operator=(Masina ob){

    r = ob.r;
    crs = ob.crs;
    m = ob.m;
    c.model = ob.c.model;
    c.an_fab = ob.c.an_fab;
    c.km = ob.c.km;
    
    return *this;
}


void Masina::calcul_cost()
{
    cout<<"========================================"<<endl;
    cout<<"DEVIZ COSTURI: "<<endl;
    cout<<"FRANE - MOTOR: "<<endl;
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
                    case Dacia_Logan : price += Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune placuta frana fata   Cost: "<<Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case MazdaRX8 : price += 4 * Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune placuta frana fata   Cost: "<<4*Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case Peugeot207: price += 1.5 * Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune placuta frana fata   Cost: "<<1.5*Solutii_frane::inlocuit_placute_fata() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    default: cout<<"Nu exista piese de schimb pentru acest model"<<endl;
                }
            }
            else
            {
                switch(c.model)
                {
                    case Dacia_Logan : price += Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune placuta frana spate   Cost: "<<Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case MazdaRX8 : price += 4 * Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune placuta frana spate   Cost: "<<4*Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case Peugeot207: price += 1.5 * Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune placuta frana spate   Cost: "<<1.5*Solutii_frane::inlocuit_placute_spate() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    default: cout<<"Nu exista piese de schimb pentru acest model"<<endl;
                }
            }

        }
        if(prob1 >= 10)
        {
                switch(c.model)
                {
                    case Dacia_Logan : price += Solutii_frane::inlocuit_discuri() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune disc roata   Cost: "<<Solutii_frane::inlocuit_discuri() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case MazdaRX8 : price += 4 * Solutii_frane::inlocuit_discuri() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune disc roata   Cost: "<<4*Solutii_frane::inlocuit_discuri() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    case Peugeot207: price += 1.5 * Solutii_frane::inlocuit_discuri() + 5 * Vehicul<autoT>::pret_surub;
                        cout<<"Defectiune disc roata   Cost: "<<1.5*Solutii_frane::inlocuit_discuri() + 5 * Vehicul<autoT>::pret_surub<<endl;
                        break;
                    default: cout<<"Nu exista piese de schimb pentru acest model"<<endl;
                }
        }

    }
    if(m.stare_carburator())
    {
        price += Solutii_motor::spalare_carburator(Vehicul<autoT>::volum) + 5 * Vehicul<autoT>::pret_surub;
        cout<<"Spalare carburator   Cost: "<<Solutii_motor::spalare_carburator(Vehicul<autoT>::volum) + 5 * Vehicul<autoT>::pret_surub<<endl;
    }

    if(!m.stare_motor())
    {
        if(c.model == MazdaRX8)
        {
            price += 3 * Solutii_motor::segmentare_motor_auto(Vehicul<autoT>::volum) + 15 * Vehicul<autoT>::pret_surub;
            cout<<"Segmentare motor   Cost: "<<3 * Solutii_motor::segmentare_motor_auto(Vehicul<autoT>::volum) + 15 * Vehicul<autoT>::pret_surub<<endl;
        }
        else
        {
            price += Solutii_motor::segmentare_motor_auto(Vehicul<autoT>::volum) + 15 * Vehicul<autoT>::pret_surub;
            cout<<"Segmentare motor   Cost: "<<Solutii_motor::segmentare_motor_auto(Vehicul<autoT>::volum) + 15 * Vehicul<autoT>::pret_surub<<endl;
        }
    }

    if(c.km >= 60000)
    {
        if(c.model == MazdaRX8)
        {
            price += 2 * Solutii_motor::schimb_ulei(Vehicul<autoT>::volum) + 5 * Vehicul<autoT>::pret_surub;
            cout<<"Schimb ulei   Cost: "<<2 * Solutii_motor::schimb_ulei(Vehicul<autoT>::volum) + 5 * Vehicul<autoT>::pret_surub<<endl;
        }
        else
        {
            price += Solutii_motor::schimb_ulei(Vehicul<autoT>::volum) + 5 * Vehicul<autoT>::pret_surub;
            cout<<"Schimb ulei   Cost: "<<Solutii_motor::schimb_ulei(Vehicul<autoT>::volum) + 5 * Vehicul<autoT>::pret_surub<<endl;
        }
    }

    cout<<"========================================"<<endl;
    cout<<"CAROSERIE: "<<endl;
    price += calcul_cost_caroserie();
    cout<<endl<<"COST TOTAL:  "<<price<<endl;

}

double Masina::calcul_cost_caroserie()
{
    double price = 0;
    int stare = 0;

    if(crs.exista_rugina())
    {
        price += Solutii_Caroserie::indepartare_rugina(crs.suprafata_ruginita());
        cout<<"Indepartare rugina   Cost: "<<Solutii_Caroserie::indepartare_rugina(crs.suprafata_ruginita())<<endl;
    }
     stare = crs.stare_aripa_st();
    if(stare >= 12)
    {
        price += Solutii_Caroserie::schimb_aripa() + 10 * Vehicul<autoT>::pret_surub;
        cout<<"Schimbare aripa stanga   Cost: "<<Solutii_Caroserie::schimb_aripa() + 10 * Vehicul<autoT>::pret_surub<<endl;
    }
    else
    {
        price += Solutii_Caroserie::remediere_lovitura(stare);
        cout<<"Remediere lovitura aripa stanga  Cost: "<<Solutii_Caroserie::remediere_lovitura(stare)<<endl;
    }
    stare = crs.stare_aripa_dr();
    if(stare >= 12)
    {
        price += Solutii_Caroserie::schimb_aripa() + 10 * Vehicul<autoT>::pret_surub;
        cout<<"Schimbare aripa dreapta   Cost: "<<Solutii_Caroserie::schimb_aripa() + 10 * Vehicul<autoT>::pret_surub<<endl;
    }
    else
    {
        price += Solutii_Caroserie::remediere_lovitura(stare);
        cout<<"Remediere lovitura aripa dreapta Cost: "<<Solutii_Caroserie::remediere_lovitura(stare)<<endl;
    }

    stare = crs.stare_fata();
    if(stare >= 10)
    {
        price += Solutii_Caroserie::schimb_fataspate()+ 10 * Vehicul<autoT>::pret_surub;
        cout<<"Schimb fata   Cost: "<<Solutii_Caroserie::schimb_fataspate()+ 10 * Vehicul<autoT>::pret_surub<<endl;
    }
    else
    {
        price += Solutii_Caroserie::remediere_lovitura(stare);
        cout<<"Remediere lovitura fata  Cost: "<<Solutii_Caroserie::remediere_lovitura(stare)<<endl;

    }

    stare = crs.stare_spate();

    if(stare >= 11)
    {
        price += Solutii_Caroserie::schimb_fataspate()+ 10 * Vehicul<autoT>::pret_surub;
        cout<<"Schimb spate   Cost: "<<Solutii_Caroserie::schimb_fataspate()+ 10 * Vehicul<autoT>::pret_surub<<endl;
    }
    else
    {
        price += Solutii_Caroserie::remediere_lovitura(stare);
        cout<<"Remediere lovitura spate  Cost: "<<Solutii_Caroserie::remediere_lovitura(stare)<<endl;
    }

    stare = crs.stare_capota();

    if(stare >= 10)
    {
        price += Solutii_Caroserie::schimb_capota()+ 10 * Vehicul<autoT>::pret_surub;
        cout<<"Schimb capota   Cost: "<<Solutii_Caroserie::schimb_capota()+ 10 * Vehicul<autoT>::pret_surub;
    }
    else
    {
        price += Solutii_Caroserie::remediere_lovitura(stare);
        cout<<"Remediere lovitura capota  Cost: "<<Solutii_Caroserie::remediere_lovitura(stare)<<endl;

    }


    return price;
}


