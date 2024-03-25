#ifndef DTEMPRESA_H
#define DTEMPRESA_H

#include <iostream>
#include "direccion.h"
using namespace std;

class DtEmpresa{
    private:
        string id;
        Direccion*dir;
    public:
        DtEmpresa();
        DtEmpresa(string Id, Direccion *Dir);
        string GetId();
        Direccion *GetDir();

};

#endif