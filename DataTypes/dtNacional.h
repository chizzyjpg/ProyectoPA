#ifndef DTNACIONAL_H
#define DTNACIONAL_H

#include "dtEmpresa.h"


class DtNacional: public DtEmpresa{
    public: 
        DtNacional(string Id, Direccion* Dir, string Rut);
        string GetRut();
    private:
        string rut;
};

#endif