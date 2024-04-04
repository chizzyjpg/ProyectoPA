#ifndef DTEMPRESA_H
#define DTEMPRESA_H

#include <iostream>
#include "direccion.h"

using namespace std;



class DtEmpresa{
    public:
        DtEmpresa();
        DtEmpresa(string Id, Direccion* Dir);
        string GetId();
        Direccion* GetDir();
        friend ostream& operator<<(ostream& os, DtEmpresa* emp);
    private:
        string id;
        Direccion* dir;
};

#endif