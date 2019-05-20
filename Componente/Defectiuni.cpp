#include "Defectiuni.h"

Defectiuni::Defectiuni()
{
    def_capitala = false;
}

Defectiuni::Defectiuni(const Defectiuni &ob)
{
  def_capitala = ob.def_capitala;
}

bool Defectiuni::dcapitala()
{
  srand(static_cast<unsigned int>(time(nullptr)));
    def_capitala = static_cast<bool>(rand() % 2);
    return def_capitala;
}
