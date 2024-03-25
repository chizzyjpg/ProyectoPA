#include "dtEmpleado.h"

// Constructor:
dtEmpleado::dtEmpleado(string ci, string nom, string ap, Direccion dir, float sueldo){
    this->ci = ci;
    this->nombre = nom;
    this->apellido = ap;
    this->direccion = dir;
    this->sueldoLiquido = sueldo;
};


// Getters:
string dtEmpleado::getCi(){
    return this->ci;
};

string dtEmpleado::getNombre(){
    return this->nombre;
};

string dtEmpleado::getApellido(){
    return this->apellido;
};

Direccion dtEmpleado::getDireccion(){
    return this->direccion;
};

float dtEmpleado::getSueldoLiquido(){
    return this->sueldoLiquido;
};


// Destructor:
dtEmpleado::~dtEmpleado(){
    cout << "Se elimino al empleado..." << endl;
};
