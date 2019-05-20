#include "Motor_moto.h"

Motor_moto::Motor_moto(): Defectiuni()
{
   motor_topit = false;
}

Motor_moto::Motor_moto(const Motor_moto &moto): Defectiuni(moto)
{
   motor_topit = moto.motor_topit;
}

Motor_moto::~Motor_moto() = default;

Motor_moto &Motor_moto::operator=(Motor_moto moto){

    def_capitala = moto.def_capitala;
    motor_topit = moto.motor_topit;

    return *this;
}

bool Motor_moto::stare_motor()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    motor_topit = static_cast<bool>(rand() % 2);
    return motor_topit;
}


