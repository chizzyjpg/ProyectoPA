#include "nacional.h"

Nacional::Nacional(string Rut) : Empresa(Id, Dir){
    this->rut=Rut;
};

Nacional::~Nacional(){
    cout <<"La vendieron"<< endl;
}

void Nacional::SetRut(string Rut){
    this->rut = RUT;
};

string Nacional::GetRut(){
    return this->rut;
};

float getDescuento(){
    return 0.65
};