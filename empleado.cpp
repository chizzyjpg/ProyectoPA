#include "empleado.h"

Empleado::Empleado(string Ci, string Nom, string Ape, Direccion Dir){
    this->ci = Ci;
    this->nombre = Nom;
    this->apellido = Ape;
    this->direccion = Dir;
    this->Relaciones = NULL;
};

void Empleado::setNom(string Nom){
    this->nombre = Nom;
};

void Empleado::setApe(string Ape){
    this->apellido = Ape;
};

void Empleado::setCi(string Ci){
    this->ci = Ci;
};

void Empleado::setDir(Direccion Dir){
    this->direccion = Dir;
};

void Empleado::agregarRel(relacionLaboral *Rel){
    this->Relaciones = Rel;
};

string Empleado::getNom(){
    return this->nombre;
};

string Empleado::getApe(){
    return this->apellido;
};

string Empleado::getCi(){
    return this->ci;
};

Direccion Empleado::getDir(){
    return this->direccion;//(esto si ser asi)
};

Empleado::~Empleado(){
    cout<< "Le dio deprecion...";
};
