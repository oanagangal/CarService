#ifndef TEMA_POO3_SOLUTII_MOTOR_H
#define TEMA_POO3_SOLUTII_MOTOR_H


class Solutii_motor {

public:
    static int pret_ulei;
    static int agent_curatare;
    static int pret_segmenti_motor;
    static int ore_om;

    Solutii_motor();
    ~Solutii_motor() = default;
    Solutii_motor(const Solutii_motor&) = default;

    static double segmentare_motor_auto(float);
    static double segmentare_motor_moto(float);
    static double schimb_ulei(float v);
    static double spalare_carburator(float);

protected:
    static float spalare_motor_auto();
    static float spalare_motor_moto();
    static float spalare_filtru_ulei();
    static float demontat_motor();
    static float montat_segmenti();
    static float montare_motor();



};

#endif //TEMA_POO3_SOLUTII_MOTOR_H
