#ifndef EMPRESA_H
#define EMPRESA_H

#include <iostream>
#include "./DataTypes/direccion.h"
using namespace std;

class Empresa {
    public:
        Empresa();
        Empresa(string Id, Direccion* Dir);
        virtual float getDescuento();
        void SetId(string);
        void SetDir(Direccion*);
        string GetId();
        Direccion* GetDir();
        virtual ~Empresa();
    private:
        string id;
        Direccion* dir;
};

#endif