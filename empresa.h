#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include "./DataTypes/direccion.h"
using namespace std;

class Empresa{
    public:
        Empresa();
        Empresa(string Id, Direccion* Dir);
        ~Empresa();
        void SetId(string);
        void SetDir(Direccion*);
        string GetId();
        Direccion* GetDir();
        virtual float getDescuento()=0;
    private:
        string id;
        Direccion* dir;
};

#endif