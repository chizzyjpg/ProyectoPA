#define MAX_EMPLEADOS 100
#define MAX_EMPRESAS 100

#include "empleado.h"
#include "relacion_laboral.h"
#include "./DataTypes/dtEmpleado.h"
#include "./DataTypes/dtExtranjera.h"
#include "./DataTypes/dtNacional.h"

const Empleado** empleados [MAX_EMPLEADOS];
const DtEmpresa** empresas [MAX_EMPRESAS];

// int cantEmpleados = 0;
// int cantEmpresas = 0;

int main(){
    empleados[0] = NULL;
    empresas[0] = NULL;
    return 0;
};

/*
a) void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir) 
Crea un nuevo empleado en el sistema.
En caso de ya existir, levanta la excepción std::invalid_argument.
*/
void agregarEmpleado(string ci, string nombre, string apellido, Direccion dir){
    int i = 0;
    while (i < MAX_EMPLEADOS && empleados[i] != NULL){
        if (empleados[i]->ci == ci){
            throw invalid_argument("Persona ya registrada");
        }
        i++;
    }
    if(i == MAX_EMPLEADOS){
        throw invalid_argument("Maximo de personas alcanzado");
    }
    Empleado* nuevoEmpleado = new Empleado(ci, nombre, apellido, dir);
    empleados[i++] = nuevoEmpleado;
    empleados[i] = NULL;
};


/*
b) void agregarEmpresa(DtEmpresa * empresa), 
Crea una nueva empresa en el sistema. 
En caso de ya existir, levanta una excepción std::invalid_argument.
*/
void agregarEmpresa(DtEmpresa * empresa){
    int i = 0;
    while (i < MAX_EMPRESAS && empresas[i] != NULL){
        if (empresas[i]->id == empresa->id){
            throw invalid_argument("Empresa ya registrada");
        }
        i++;
    }
    if(i == MAX_EMPRESAS){
        throw invalid_argument("Maximo de empresas alcanzado");
    }
    empresas[i++] = empresa;
    empresas[i] = NULL;
};


/*
c) DtEmpleado** listarEmpleados(int & cantEmpleados)
Retorna un arreglo de DtEmpleado* con todos los empleados del sistema. 
El largo del arreglo de empleados está dado por el parámetro cantEmpleados.
*/


/*
d) void agregarRelacionLaboral(String ciEmpleado, string idEmpresa, float sueldo)
Vincula un empleado con una empresa. 
Si la empresa ya está dentro de las empresas que el empleado ha trabajado o trabaja se levanta una excepción std::invalid_argument.
*/


/*
e) void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculación)
Desvincula al empleado de la empresa, registrando la fecha en que terminó el vinculo.
*/


/*
f) DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int & cantEmpresas)
Retorna un arreglo con las empresas donde trabaja activamente el empleado. 
El largo del arreglo de empresas está dado por el parámetro cantEmpresas.
*/




/*
Nota: A los efectos de este laboratorio, la función main mantendrá una colección de
empleados, implementada como un arreglo de tamaño MAX_EMPLEADOS. 
Lo mismo para las empresas del sistema con un máximo de MAX_EMPRESAS (ambas constantes). 
Puede implementar operaciones en las clases dadas en el modelo si
considera que le facilitan para la resolución de las operaciones pedidas en el main.
*/