#ifndef TEMA_POO3_DIRECTIE_AUTO_H
#define TEMA_POO3_DIRECTIE_AUTO_H

#include "Defectiuni.h"

class Directie_auto: public Defectiuni {

protected:
    bool roata_stramba;

public:
    explicit Directie_auto();
    Directie_auto(const Directie_auto&);
    ~Directie_auto() override;
    Directie_auto&operator=(Directie_auto ob);
    bool stare_roata();


};


#endif //TEMA_POO3_DIRECTIE_AUTO_H
