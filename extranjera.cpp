#include "extranjera.h"

Extranjera::Extranjera(string Id, Direccion* Dir, string Nombre) : Empresa(Id, Dir){
    this->rut=Rut;
};

Extranjera::~Extranjera(){
    cout <<"La compraron"<< endl;
}

void Extranjera::SetNombre(string Nombre){
    this->nombreFantasia = Nombre;
};

string Extranjera::GetNombre(){
    return this->nombreFantasia;
};

float Extranjera::getDescuento(){
    return 0.80
};