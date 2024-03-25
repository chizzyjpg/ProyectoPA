#include "extranjera.h"

// Constructor:
Extranjera::Extranjera(string Id, Direccion* Dir, string Nombre) : Empresa(Id, Dir){
    this->nombreFantasia = Nombre;
};


// Setters:
void Extranjera::SetNombre(string Nombre){
    this->nombreFantasia = Nombre;
};


// Getters:
string Extranjera::GetNombre(){
    return this->nombreFantasia;
};

float Extranjera::getDescuento(){
    return 0.80;
};

Extranjera::~Extranjera(){
    cout <<"La compraron"<< endl;
};