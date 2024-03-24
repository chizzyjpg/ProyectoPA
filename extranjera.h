#ifndef EXTRANJERA_H
#define EXTRANJERA_H

#include "empresa.h"

class Extranjera: public Empresa{
    private:
        string nombreFantasia;
    public:
        Extranjera(string Id, Direccion* Dir, string Nombre);
        ~Extranjera();
        void SetNombre(string Nombre);
        string GetNombre();
        float getDescuento();
};

#endif