#ifndef NACIONAL_H
#define NACIONAL_H

#include "empresa.h"

class Extranjera: public Empresa{
    private:
        string nombreFantasia;
    public:
        Extranjera(string Nombre);
        ~Extranjera();
        void SetNombre(string Nombre);
        string GetNombre();
        float getDescuento();
};

#endif