#ifndef DTEMPRESA_H
#define DTEMPRESA_H

#include <iostream>
#include "./DataTypes/direccion.h"
using namespace std;

class Empresa{
    public:
        Empresa();
        Empresa(string Id, Direccion* Dir);
        string GetId();
        Direccion* GetDir();
    private:
        string id;
        Direccion* dir;
};

#endif