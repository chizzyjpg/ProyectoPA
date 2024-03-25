#ifndef DTEXTRANJERA_H
#define DTEXTRANJERA_H

#include "dtEmpresa.h"

class DtExtranjera: public DtEmpresa{
    private: 
        string nombreFantasia;
    public:
        DtExtranjera(string Id, Direccion* Dir, string Nombre);
        string GetNombre();
};

#endif