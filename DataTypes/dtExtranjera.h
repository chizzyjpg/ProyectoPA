#ifndef DTEXTRANJERA_H
#define DTEXTRANJERA_H

#include "empresa.h"

class Extranjera: public Empresa{
    private:
        string nombreFantasia;
    public:
        Extranjera(string Id, Direccion* Dir, string Nombre);
        string GetNombre();
};

#endif