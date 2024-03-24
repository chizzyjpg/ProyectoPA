#include "empleado.h"

Empleado::Empleado(string Ci, string Nom, string Ape, Direccion * Dir){
    this->ci = Ci;
    this->nombre = Nom;
    this->apellido = Ape;
    this->direccion = Dir;
    this->Relaciones[0] = NULL; // Hay que arreglar esto para que permita añadirlo a un arreglo
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

void Empleado::setDir(Direccion* Dir){
    this->direccion = Dir;
};

void Empleado::agregarRel(RelacionLaboral *Rel){
    this->Relaciones[0] = Rel; // Hay que arreglar esto para que permita añadirlo a un arreglo
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

Direccion* Empleado::getDir(){
    return this->direccion;
};

Empleado::~Empleado(){
    cout<< "Le dio deprecion...";
};
