#ifndef TEMA_POO3_FRANE_H
#define TEMA_POO3_FRANE_H

#include "Defectiuni.h"
#include <ctime>
#include <cstdlib>

class Frane: public Defectiuni {

     int placute;
     int discuri;

public:
    explicit Frane();
    ~Frane() override;
    Frane(const Frane&) = default;

    int stare_placute();
    int stare_discuri();

};


#endif //TEMA_POO3_FRANE_H
