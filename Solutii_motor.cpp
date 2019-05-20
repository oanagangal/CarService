#include "Solutii_motor.h"

int Solutii_motor::pret_ulei = 48;
int Solutii_motor::agent_curatare = 18;
int Solutii_motor::pret_segmenti_motor = 30;
int Solutii_motor::ore_om = 80;

Solutii_motor::Solutii_motor() = default;

float Solutii_motor::spalare_motor_auto()
{
    return static_cast<float>(Solutii_motor::agent_curatare + 0.1 * Solutii_motor::ore_om);
}

float Solutii_motor::spalare_filtru_ulei()
{
    return static_cast<float>(0.05 * Solutii_motor::ore_om + Solutii_motor::agent_curatare);
}

float Solutii_motor::demontat_motor()
{
    return static_cast<float>(0.2 * Solutii_motor::ore_om);
}

float Solutii_motor::montat_segmenti()
{
    return static_cast<float>(Solutii_motor::ore_om * 0.45);
}

float Solutii_motor::montare_motor()
{
    return static_cast<float>(0.2 * Solutii_motor::ore_om);
}

float Solutii_motor::spalare_motor_moto()
{
    return static_cast<float>(Solutii_motor::agent_curatare + 0.1 * Solutii_motor::ore_om);;
}

double Solutii_motor::segmentare_motor_auto(float v)
{
  double pas1 = v * 0.2 * demontat_motor();
  double pas2 = spalare_motor_auto() + montat_segmenti() * 0.2 * v;
  double pas3 = v * 0.2 * montare_motor();

  return pas1 + pas2 + pas3;

}

double Solutii_motor::segmentare_motor_moto(float v)
{
    double pas1 = v * 0.1 * demontat_motor();
    double pas2 = spalare_motor_moto() + montat_segmenti() * 0.2 * v;
    double pas3 = v * 0.1 * montare_motor();

    return pas1 + pas2 + pas3;
}

double Solutii_motor::schimb_ulei(float v)
{
    return spalare_filtru_ulei() + v * 0.5 * Solutii_motor::pret_ulei;
}

double Solutii_motor::spalare_carburator(float v)
{
    return Solutii_motor::schimb_ulei(v) + 0.2*Solutii_motor::ore_om + 3 * Solutii_motor::agent_curatare;
}


