#include "dtExtranjera.h"

DtExtranjera::DtExtranjera(string Id, Direccion* Dir, string Nombre) : DtEmpresa(Id, Dir){
    this->nombreFantasia=Nombre;
};

string DtExtranjera::GetNombre(){
    return this->nombreFantasia;
};