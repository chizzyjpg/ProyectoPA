<<<<<<< Updated upstream
#include <iostream>
#include "direccion.h"

using namespace std;
=======
#include "direccion.h"

Direccion::Direccion(){
    this->calle = this->ciudad = this->numero = this->pais = "";
};
Direccion::Direccion(string p, string ci, string ca, string n){
    this->pais = p;
    this->ciudad = ci;
    this->calle = ca;
    this->numero = n;
};
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
>>>>>>> Stashed changes
