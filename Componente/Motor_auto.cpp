#include "Motor_auto.h"

Motor_auto::Motor_auto(): Motor_moto()
{
    carburator_murdar = false;
}

Motor_auto::Motor_auto(const Motor_auto &a): Motor_moto(a)
{
    carburator_murdar = a.carburator_murdar;
}

Motor_auto::~Motor_auto() = default;

Motor_auto &Motor_auto::operator=(Motor_auto a){

    def_capitala = a.def_capitala;
    motor_topit = a.motor_topit;
    carburator_murdar = a.carburator_murdar;

    return *this;
}

bool Motor_auto::stare_carburator()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    carburator_murdar = static_cast<bool>(rand() % 2);
    return carburator_murdar;
}
