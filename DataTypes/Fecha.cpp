#include "Fecha.h"


// Constructores: 
Fecha::Fecha (){
    this -> dia = this -> mes = this -> anio = NULL;
}

Fecha::Fecha (int d, int m, int a){
    this -> dia = d;
    this -> mes = m;
    this -> anio = a;
};


// Getters:
int Fecha::getDia(){
    return this->dia;
};

int Fecha::getMes(){
    return this->dia;
};

int Fecha::getAnio(){
    return this->dia;
};