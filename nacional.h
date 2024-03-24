#ifndef NACIONAL_H
#define NACIONAL_H

#include "empresa.h"

class Nacional: public Empresa{
    private:
        string rut;
    public:
        Nacional(string Rut);
        ~Nacional();
        void SetRut(string Rut);
        string GetRut();
        float getDescuento();
};

#endif