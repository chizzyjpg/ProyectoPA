#include "dtEmpresa.h"

// Constructor:
DtEmpresa::DtEmpresa(){
    this->id = "";
    this->dir = NULL;
};
 
DtEmpresa::DtEmpresa(string Id, Direccion* Dir){
    this->id = Id;
    this->dir = Dir;
};


// Getters:
string DtEmpresa::GetId(){
    return this->id;
};

Direccion* DtEmpresa::GetDir(){
    return this->dir;
};