#ifndef TEMA_POO3_DEFECTIUNI_H
#define TEMA_POO3_DEFECTIUNI_H

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Defectiuni {

protected:
    bool def_capitala;

    explicit Defectiuni();
    Defectiuni(const Defectiuni&);
    virtual ~Defectiuni() = default;

public:
    bool dcapitala();

};


#endif //TEMA_POO3_DEFECTIUNI_H
