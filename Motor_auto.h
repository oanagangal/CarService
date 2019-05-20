#ifndef TEMA_POO3_MOTOR_AUTO_H
#define TEMA_POO3_MOTOR_AUTO_H

#include "Motor_moto.h"

class Motor_auto: public Motor_moto {

    bool carburator_murdar;

public:
    Motor_auto();
    Motor_auto(const Motor_auto&);
    ~Motor_auto() override;

    Motor_auto&operator=(Motor_auto);
    bool stare_carburator();

};


#endif //TEMA_POO3_MOTOR_AUTO_H
