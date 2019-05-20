#include "Directie_auto.h"

Directie_auto::Directie_auto(): Defectiuni()
{
    roata_stramba = false;
}

Directie_auto::Directie_auto(const Directie_auto &obj): Defectiuni(obj)
{
    roata_stramba = obj.roata_stramba;
}

Directie_auto::~Directie_auto() = default;

Directie_auto &Directie_auto::operator=(Directie_auto ob){

    roata_stramba = ob.roata_stramba;
    def_capitala = ob.def_capitala;
    return *this;
}

bool Directie_auto::stare_roata()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    roata_stramba = static_cast<bool>(rand() % 2);
    return roata_stramba;
}






