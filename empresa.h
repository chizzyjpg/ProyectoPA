#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include "direccion.h"
using namespace std;

class Empresa{
    public:
        Empresa();
        Empresa(string, Direccion);
        ~Empresa();
        void SetId(string);
        void SetDir(Direccion);
        string GetId();
        Direccion GetDir();
        virtual float getDescuento()=0;
    private:
        string id;
        Direccion dir;
};

#endif