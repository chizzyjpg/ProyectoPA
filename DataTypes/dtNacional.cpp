#include "dtNacional.h"

DtNacional::DtNacional(string Id, Direccion* Dir, string Rut) : DtEmpresa(Id, Dir){
    this->rut=Rut;
};

string DtNacional::GetRut(){
    return this->rut;
};