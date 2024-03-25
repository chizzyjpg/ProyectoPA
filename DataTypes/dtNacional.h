#ifndef DTNACIONAL_H
#define DTNACIONAL_H

#include "empresa.h"

class Nacional: public Empresa{
    private:
        string rut;
    public:
        Nacional(string Id, Direccion* Dir, string Rut);
        string GetRut();
};

#endif