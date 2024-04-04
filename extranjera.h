#ifndef EXTRANJERA_H
#define EXTRANJERA_H

#include "empresa.h"

class Extranjera: public Empresa{
    public:
        Extranjera(string Id, Direccion* Dir, string Nombre);
        float getDescuento();
        void SetNombre(string Nombre);
        string GetNombre();
        ~Extranjera();
    private:
        string nombreFantasia;
};

#endif