#include "extranjera.h"

Extranjera::Extranjera(string Id, Direccion* Dir, string Nombre) : Empresa(Id, Dir){
    this->nombreFantasia=Nombre;
};

Extranjera::~Extranjera(){
    cout <<"La compraron"<< endl;
};

void Extranjera::SetNombre(string Nombre){
    this->nombreFantasia = Nombre;
};

string Extranjera::GetNombre(){
    return this->nombreFantasia;
};

float Extranjera::getDescuento(){
    return 20;//return 0.80
};
