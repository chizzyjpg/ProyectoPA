#include "nacional.h"

Nacional::Nacional(string Id, Direccion* Dir, string Rut) : Empresa(Id, Dir){
    this->rut=Rut;
};

Nacional::~Nacional(){
    cout <<"La vendieron"<< endl;
}

void Nacional::SetRut(string Rut){
    this->rut = Rut;
};

string Nacional::GetRut(){
    return this->rut;
};

float Nacional::getDescuento(){
    return 0.65
};