#ifndef DTNACIONAL_H
#define DTNACIONAL_H

#include "dtEmpresa.h"

class DtNacional: public DtEmpresa{
    private:
        string rut;
    public: 
        DtNacional(string Id, Direccion* Dir, string Rut);
        string GetRut();
};

#endif