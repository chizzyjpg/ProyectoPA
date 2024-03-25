#include "direccion.h"

// Constructor: 
Direccion::Direccion(){
    this->calle = this->ciudad = this->numero = this->pais = "";
};

Direccion::Direccion(string p, string ci, string ca, string n){
    this->pais = p;
    this->ciudad = ci;
    this->calle = ca;
    this->numero = n;
};


// Getters:
string Direccion::getPais(){
    return this -> pais;
};

string Direccion::getCiudad(){
    return this -> ciudad;
};

string Direccion::getNumero(){
    return this -> numero;
};

string Direccion::getCalle(){
    return this -> calle;
};