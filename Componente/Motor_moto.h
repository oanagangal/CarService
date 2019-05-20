#ifndef TEMA_POO3_MOTOR_MOTO_H
#define TEMA_POO3_MOTOR_MOTO_H

#include "Defectiuni.h"

class Motor_moto: public Defectiuni {

protected:
    bool motor_topit;

public:
    Motor_moto();
    Motor_moto(const Motor_moto&);
    ~Motor_moto() override;

    Motor_moto&operator=(Motor_moto);
    bool stare_motor();

};


#endif //TEMA_POO3_MOTOR_MOTO_H
