#include "dtExtranjera.h"

// Constructor:
DtExtranjera::DtExtranjera(string Id, Direccion* Dir, string Nombre) : DtEmpresa(Id, Dir){
    this->nombreFantasia = Nombre;
};


// Getters:
string DtExtranjera::GetNombre(){
    return this->nombreFantasia;
};