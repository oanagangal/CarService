#include "Directie_moto.h"


Directie_moto::Directie_moto(): Directie_auto()
{
  ghidon_stramb = false;
}

Directie_moto::Directie_moto(const Directie_moto &dm): Directie_auto(dm)
{
  ghidon_stramb = dm.ghidon_stramb;
}

Directie_moto::~Directie_moto() = default;

Directie_moto &Directie_moto::operator=(Directie_moto dm){

  roata_stramba = dm.roata_stramba;
  def_capitala = dm.def_capitala;
  ghidon_stramb = dm.ghidon_stramb;
  return *this;
}

bool Directie_moto::stare_ghidon()
{

  srand(static_cast<unsigned int>(time(nullptr)));
  ghidon_stramb = static_cast<bool>(rand() % 2);
  return ghidon_stramb;
}

