#ifndef TEMA_POO3_VEHICUL_H
#define TEMA_POO3_VEHICUL_H

#include <iostream>

using namespace std;
enum autoT {Dacia_Logan,MazdaRX8,Peugeot207};
enum motoT {moto1,moto2,moto3};

template <typename T>
struct caract
{
    T model;
    int an_fab;
    double km;
};

template <typename T>
class Vehicul {

protected:
    int r;  // roti
    caract<T> c;

    explicit Vehicul(T,int r1 = 0);
    Vehicul(const Vehicul&ob);
    virtual ~Vehicul();

    istream& scan(istream&);
    ostream& print(ostream&);

public:
    static int pret_surub;
    static float volum;
    caract<T> get_caract();
    virtual void calcul_cost() = 0;

    template <typename T1>
    friend istream&operator>>(istream&,Vehicul<T1> &ob);
    template <typename T2>
    friend ostream&operator<<(ostream&,Vehicul<T2> &ob);


};

template <typename T>
float Vehicul<T>::volum = 0.0;
template <typename T>
int Vehicul<T>::pret_surub = 1;


template<typename T>
Vehicul<T>::Vehicul(T mdl,int r1)
{
    r = r1;
    c.model = mdl;
    c.an_fab = 0;
    c.km = 0.0;
}

template<typename T>
Vehicul<T>::~Vehicul() = default;

template<typename T>
Vehicul<T>::Vehicul(const Vehicul &ob)
{
    r = ob.r;
    c.model = ob.c.model;
    c.an_fab = ob.c.an_fab;
    c.km = ob.c.km;
}

template<typename T>
istream &Vehicul<T>::scan(istream &in)
{
    in>>c.an_fab;
    in>>Vehicul<T>::volum;
    in>>c.km;
    return in;
}

template<typename T>
ostream &Vehicul<T>::print(ostream &out)
{
    out<<"An fabricatie: "<<c.an_fab<<endl;
    out<<"Volum motor: "<<Vehicul<T>::volum<<endl;
    out<<"Km bord: "<<c.km<<endl;
    return out;
}
template<typename T1>
istream &operator>>(istream &i, Vehicul<T1> &ob) {
    return ob.scan(i);
}

template<typename T2>
ostream &operator<<(ostream &o, Vehicul<T2> &ob) {
    return ob.print(o);
}

template<typename T>
caract<T> Vehicul<T>::get_caract()
{
    return c;
}

#endif //TEMA_POO3_VEHICUL_H
