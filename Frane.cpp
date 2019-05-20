#include "Frane.h"

Frane::Frane()
{
    placute = 0;
    discuri = 0;
}

int Frane::stare_placute()
{
   time_t t;
    srand(static_cast<unsigned int>(time(&t)));
    placute = (rand()%20) + 1;
    return placute;
}

int Frane::stare_discuri() {

    time_t t;
    srand(static_cast<unsigned int>(time(&t)));
    discuri = (rand()%20) + 1;
    return discuri;
}

Frane::~Frane() = default;








