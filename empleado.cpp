#include "empleado.h"

// Constructor:
Empleado::Empleado(){
    this->ci = this->nombre = this->apellido = "";
    this->direccion = NULL;
    this->Relaciones[0] = NULL;
};

Empleado::Empleado(string Ci, string Nom, string Ape, Direccion* Dir){
    this->ci = Ci;
    this->nombre = Nom;
    this->apellido = Ape;
    this->direccion = Dir;
    this->Relaciones[0] = NULL;
};

Empleado::Empleado(string Ci, string Nom, string Ape, Direccion* Dir, RelacionLaboral* Rel){
    this->ci = Ci;
    this->nombre = Nom;
    this->apellido = Ape;
    this->direccion = Dir;
    this->Relaciones[0] = Rel;
};


// Funcionalidad:
void Empleado::agregarRel(RelacionLaboral *Rel){
    if(Relaciones[0] == NULL){
        this->Relaciones[0] = Rel;
    }else{
        int i = 0;
        while (i < 50 && this->Relaciones[i] != NULL){
            i++;
        }
        if(i < 50){
            Relaciones[i] = Rel;
        }else{
            cout << "Esta persona no puede tener mas trabajos";
        }
    }
};


//Setters:
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


// Getters:
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


// Destructor:
Empleado::~Empleado(){
    cout<< "Le dio deprecion...";
};
