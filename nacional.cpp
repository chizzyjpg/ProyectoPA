#include "nacional.h"

// Constructor:
Nacional::Nacional(string Id, Direccion* Dir, string Rut) : Empresa(Id, Dir){
    this->rut = Rut;
};


// Setters:
void Nacional::SetRut(string Rut){
    this->rut = Rut;
};


// Getters:
string Nacional::GetRut(){
    return this->rut;
};

float Nacional::getDescuento(){
    return 0.65;
};


// Destructor:
Nacional::~Nacional(){
    cout <<"La vendieron"<< endl;
};