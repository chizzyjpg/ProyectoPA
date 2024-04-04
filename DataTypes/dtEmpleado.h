#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H

#include <iostream>
#include "direccion.h"
using namespace std;

class dtEmpleado{
    public:
        dtEmpleado(string ci, string nom, string ap, Direccion *dir, float sueldo);
        string getCi();
        string getNombre();
        string getApellido();
        Direccion* getDireccion();
        float getSueldoLiquido();
        ~dtEmpleado();
    private:
        string ci, nombre, apellido;
        Direccion *direccion;
        float sueldoLiquido;
};

#endif