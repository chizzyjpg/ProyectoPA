#define MAX_EMPLEADOS 100
#define MAX_EMPRESAS 100

#include "empleado.h"
#include "relacion_laboral.h"
#include "./DataTypes/dtEmpleado.h"
#include "./DataTypes/dtExtranjera.h"
#include "./DataTypes/dtNacional.h"

Empleado* empleados [MAX_EMPLEADOS];
DtEmpresa* empresas [MAX_EMPRESAS];

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
void agregarEmpleado(string ci, string nombre, string apellido, Direccion* dir){
    int i = 0;
    while (i < MAX_EMPLEADOS && empleados[i] != NULL){
        if (empleados[i]->getCi() == ci){
            throw invalid_argument("Persona ya registrada");
        }
        i++;
    }
    if(i == MAX_EMPLEADOS){
        throw invalid_argument("Maximo de personas alcanzado");
    }
    Empleado* nuevoEmpleado = new Empleado(ci, nombre, apellido, dir);
    empleados[i++] = nuevoEmpleado;
    if(i != MAX_EMPLEADOS)
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
        if (empresas[i]->GetId() == empresa->GetId()){
            throw invalid_argument("Empresa ya registrada");
        }
        i++;
    }
    if(i == MAX_EMPRESAS){
        throw invalid_argument("Maximo de empresas alcanzado");
    }
    empresas[i++] = empresa;
    if(i != MAX_EMPRESAS)
        empresas[i] = NULL;
};


/*
c) DtEmpleado** listarEmpleados(int & cantEmpleados)
Retorna un arreglo de DtEmpleado* con todos los empleados del sistema. 
El largo del arreglo de empleados está dado por el parámetro cantEmpleados.
*/
dtEmpleado** listarEmpleados(int & cantEmpleados){
    if(empleados[0] == NULL || (cantEmpleados < 1 || cantEmpleados > MAX_EMPLEADOS)){
        cout<<"error"<< endl;
        return NULL;
    }
    dtEmpleado** ArreEmpl = new dtEmpleado*[cantEmpleados];
    int i = 0;
    float sueldoLiquidoTotal = 0.0;;
    Empleado* empleado;
    while(i < cantEmpleados && empleados[i] != NULL){
        empleado = empleados[i];
        for (int j = 0; j < MAX_RELACIONES && empleados[i]->getRel(j) != NULL; j++) {
            if(empleado->getRel(j)->getFechaDesvinculacion() == NULL)
                sueldoLiquidoTotal += empleado->getRel(j)->getSueldoLiquido();
        }
        ArreEmpl[i] = new dtEmpleado(empleado->getCi(), empleado->getNom(), empleado->getApe(), *(empleado->getDir()), sueldoLiquidoTotal);
        i++;
        sueldoLiquidoTotal = 0.0;
    };
    return ArreEmpl;
};
      
/*
d) void agregarRelacionLaboral(String ciEmpleado, string idEmpresa, float sueldo)
Vincula un empleado con una empresa. 
Si la empresa ya está dentro de las empresas que el empleado ha trabajado o trabaja se levanta una excepción std::invalid_argument.
*/
void agregarRelacionLaboral(string ciEmpleado, string idEmpresa, float sueldo){
    int numEmpleado = 0;
    while (numEmpleado < MAX_EMPLEADOS && empleados[numEmpleado] != NULL && empleados[numEmpleado]->getCi() != ciEmpleado){
        numEmpleado++;
    }
    if(numEmpleado == MAX_EMPLEADOS || empleados[numEmpleado] == NULL){
        throw invalid_argument("No se encontró al empleado");
    }
    int numEmpresa = 0;
    while (numEmpresa < MAX_EMPRESAS && empresas[numEmpresa] != NULL && empresas[numEmpresa]->GetId != idEmpresa){
        numEmpresa++;
    }
    if(numEmpresa == MAX_EMPRESAS || empresas[numEmpresa] == NULL){
        throw invalid_argument("No se encontró a la empresa");
    }
    for(int i=0; i < MAX_RELACIONES && empleados[numEmpleado]->getRel(i) != NULL; i++){
        if(empleados[numEmpleado]->getRel(i)->getEmpresa()->GetId()==idEmpresa)
            throw invalid_argument("Ya trabajo en esta empresa");
    }
    RelacionLaboral* relacion = new RelacionLaboral(sueldo, empresas[numEmpresa]);
    empleados[numEmpleado]->agregarRel(relacion);
};


/*
e) void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculación)
Desvincula al empleado de la empresa, registrando la fecha en que terminó el vinculo.
*/
void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha desvinculación){
    int numEmpleado = 0;
    while (numEmpleado < MAX_EMPLEADOS && empleados[numEmpleado] != NULL && empleados[numEmpleado]->getCi != ciEmpleado){
        numEmpleado++;
    };
    if(numEmpleado == MAX_EMPLEADOS || empleados[numEmpleado] == NULL){
        throw invalid_argument("No se encontró al empleado");
    }
    int numEmpresa = 0;
    while (numEmpresa < MAX_RELACIONES && empleados[numEmpleado]->getRel(numEmpresa) != NULL && empleados[numEmpleado]->getRel(numEmpresa)->getEmpresa()->GetId != idEmpresa){
        numEmpresa++;
    };
    if(numEmpresa == MAX_RELACIONES || empleados[numEmpleado]->getRel(numEmpresa) == NULL){
        throw invalid_argument("No se encontró al empleado");
    }
    empleados[numEmpleado]->getRel(numEmpresa)->setFechaDesvinculacion(desvinculación);
};


/*
f) DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int & cantEmpresas)
Retorna un arreglo con las empresas donde trabaja activamente el empleado. 
El largo del arreglo de empresas está dado por el parámetro cantEmpresas.
*/
DtEmpresa** obtenerInfoEmpresaPorEmpleado(string ciEmpleado, int & cantEmpresas){
    int numEmpleado = 0;
    while (numEmpleado < MAX_EMPLEADOS && empleados[numEmpleado] != NULL && empleados[numEmpleado]->getCi != ciEmpleado){
        numEmpleado++;
    };
    if(numEmpleado == MAX_EMPLEADOS || empleados[numEmpleado] == NULL){
        throw invalid_argument("No se encontró al empleado");
    }
    DtEmpresa** empresasEmpleado = new DtEmpresa*[cantEmpresas];
    int contadorEmpresas = 0;
    for (int j = 0; j < MAX_RELACIONES && empleados[numEmpleado]->getRel(j) != NULL; j++){
        if(empleados[numEmpleado]->getRel(j)->getFechaDesvinculacion() == NULL){
            if (dynamic_cast<Nacional*>(empresa) != NULL) {
                string rutEmpresa = dynamic_cast<Nacional*>(empresa)->GetRut();
                empresasEmpleado[contadorEmpresas++] = new DtNacional(empleados[numEmpleado]->getRel(j)->getEmpresa()->GetId(), empleados[numEmpleado]->getRel(j)->getEmpresa()->GetDir(), empleados[numEmpleado]->getRel(j)->getEmpresa()->GetRut());
            } 
            else if (dynamic_cast<Extranjera*>(empresa) != NULL) {
                string nombreFantasia = dynamic_cast<Extranjera*>(empresa)->GetNombre();
                empresasEmpleado[contadorEmpresas++] = new DtExtranjera(empleados[numEmpleado]->getRel(j)->getEmpresa()->GetId(), empleados[numEmpleado]->getRel(j)->getEmpresa()->GetDir(), empleados[numEmpleado]->getRel(j)->getEmpresa()->GetNombre());
            }
        }
    }
    return empresasEmpleado;
}



/*
Nota: A los efectos de este laboratorio, la función main mantendrá una colección de
empleados, implementada como un arreglo de tamaño MAX_EMPLEADOS. 
Lo mismo para las empresas del sistema con un máximo de MAX_EMPRESAS (ambas constantes). 
Puede implementar operaciones en las clases dadas en el modelo si
considera que le facilitan para la resolución de las operaciones pedidas en el main.
*/