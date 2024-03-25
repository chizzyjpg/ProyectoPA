#include "dtNacional.h"

// Constructor:
DtNacional::DtNacional(string Id, Direccion* Dir, string Rut) : DtEmpresa(Id, Dir){
    this->rut=Rut;
};


// Getters:
string DtNacional::GetRut(){
    return this->rut;
};