#include "fecha.h"


// Constructores: 
Fecha::Fecha (){
    this -> dia = this -> mes = this -> anio = 0;
}

Fecha::Fecha (int d, int m, int a){
    if ( d < 1 || d > 31 || m < 1 || m > 12 || a < 1900){
        throw invalid_argument("Fecha no valida");
    }else{
        this -> dia = d;
        this -> mes = m;
        this -> anio = a;
    }
};


// Getters:
int Fecha::getDia(){
    return this->dia;
};

int Fecha::getMes(){
    return this->mes;
};

int Fecha::getAnio(){
    return this->anio;
};