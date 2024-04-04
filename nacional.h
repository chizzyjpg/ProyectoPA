#ifndef NACIONAL_H
#define NACIONAL_H

#include "empresa.h"
class Empresa;

class Nacional: public Empresa{
    public:
        Nacional(string Id, Direccion* Dir, string Rut);
        void SetRut(string Rut);
        string GetRut();
        float getDescuento();
        ~Nacional();
    private:
        string rut;
};

#endif