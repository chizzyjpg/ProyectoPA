#define MAX_EMPLEADOS 100
#define MAX_EMPRESAS 100

#include "empresa.h"
#include "nacional.h"
#include "extranjera.h"
#include "empleado.h"
#include "relacion_laboral.h"
#include "./DataTypes/dtEmpleado.h"
#include "./DataTypes/dtExtranjera.h"
#include "./DataTypes/dtNacional.h"

Empleado** empleados = new Empleado* [MAX_EMPLEADOS];
Empresa** empresas = new Empresa* [MAX_EMPRESAS];

void agregarEmpleado(string, string, string, Direccion*);
void agregarEmpresa(DtEmpresa*);
dtEmpleado** listarEmpleados(int&);
void agregarRelacionLaboral(string, string, float);
void finalizarRelacionLaboral(string, string, Fecha*);
DtEmpresa** obtenerInfoEmpresaPorEmpleado(string, int&);

Direccion * pedirDireccion();

int main(){
    empleados[0] = NULL;
    empresas[0] = NULL;
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << "Seleccione una opción:" << endl;
        cout << "1. Agregar Empleado" << endl;
        cout << "2. Agregar Empresa" << endl;
        cout << "3. Listar Empleados" << endl;
        cout << "4. Agregar Relación Laboral" << endl;
        cout << "5. Finalizar Relación Laboral" << endl;
        cout << "6. Obtener Información de Empresa por Empleado" << endl;
        cout << "7. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string ci, nombre, apellido;
                cout << "Ingrese CI: "<<endl;
                cin >> ci;
                cout << "Ingrese Nombre: "<<endl;
                cin >> nombre;
                cout << "Ingrese Apellido: "<<endl;
                cin >> apellido;           
                Direccion *dir = pedirDireccion();
                agregarEmpleado(ci, nombre, apellido, dir);
                break;
            }
            case 2: {
                string id;
                cout << "Ingrese id de la empresa: ";
                cin >> id;
                Direccion* dir = pedirDireccion();
                //HACER PARA NACIONAL O EXTRANJERA
                string expression="0";
                DtEmpresa *nuevaEmpresa;
                while (expression != "1" && expression != "2"){
                    cout<<"Seleccione el tipo de Empresa: "<<endl;
                    cout<<"1. Nacional"<<endl;
                    cout<<"2. Extranjera"<<endl;
                    cin>>expression;
                    string expression = "1";
                    if (expression == "1") {
                        //Nacional
                        string RUT;
                        cout<<"Ingrese el RUT: ";
                        cin>>RUT;
                        nuevaEmpresa=new DtNacional(id,dir,RUT);
                    } else if (expression == "2") {
                        //Extranjera
                        string nombre;
                        cout<<"Ingrese el nombre: ";
                        cin>>nombre;
                        nuevaEmpresa=new DtExtranjera(id,dir,nombre);
                    } else
                        cout<<"Opcion no Valida..."<<endl;
                    /*
                    switch (expression){
                    case "1":
                        //Nacional
                        string RUT;
                        cout<<"Ingrese el RUT: ";
                        cin>>RUT;
                        nuevaEmpresa=new DtNacional(id,dir,RUT);
                        break;
                    case 2:   
                        //Extranjera
                        string nombre;
                        cout<<"Ingrese el nombre: ";
                        cin>>nombre;
                        nuevaEmpresa=new DtExtranjera(id,dir,nombre);
                        break;
                    default:
                        cout<<"Opcion no Valida..."<<endl;
                        break;
                    }*/
                }    
                agregarEmpresa(nuevaEmpresa);
                break;
            }
            case 3: {
                int cantEmpleados;
                cout << "Indique la cantidad de empleados que desea ver: ";
                cin >> cantEmpleados;
                dtEmpleado** empleados = listarEmpleados(cantEmpleados);
                for (int i = 0; i < cantEmpleados; ++i){
                    cout<<"Empleado: "<<empleados[i]->getNombre()<<", "<<empleados[i]->getApellido()<<", "<<empleados[i]->getCi()<<endl;//CREO ASI ESTA BIEN?
                }
                // BORRAR EL COSO
                for (int i = 0; i < cantEmpleados; ++i) {
                    delete empleados[i];
                }
                delete[] empleados;
                break;
            }
            case 4: {
                string ci, id;
                float sueldo;
                cout << "Ingrese ci del empleado: ";
                cin >> ci;
                cout << "Ingrese id de la empresa: ";
                cin >> id;
                cout << "Ingrese sueldo: ";
                cin >> sueldo;
                agregarRelacionLaboral(ci, id, sueldo);
                break;
            }
            case 5: {
                string ci, id;
                int d,m,a;              
                cout << "Ingrese ci del empleado: "<<endl;
                cin >> ci;
                cout << "Ingrese id de la empresa: "<<endl;
                cin >> id;
                cout << "Ingrese el dia actual: "<<endl;
                cin>>d;
                cout << "Ingrese mes actual: "<<endl;
                cin>>m;
                cout << "Ingrese el año actual: "<<endl;
                cin>>a;
                Fecha *desvinculacion=new Fecha(d,m,a);
                finalizarRelacionLaboral(ci, id, desvinculacion);
                break;
            }
            case 6: {
                string ciEmpleado;
                int cantEmpresas;
                cout << "Ingrese ci del empleado: ";
                cin >> ciEmpleado;
                cout << "Cantidad de empresas a mostrar: ";
                cin>>cantEmpresas;
                DtEmpresa** empresas = obtenerInfoEmpresaPorEmpleado(ciEmpleado, cantEmpresas);
                for (int i = 0; i < cantEmpresas; ++i) {
                    cout << "Empresa: " << empresas[i]->GetId()<<", "<< empresas[i]->GetDir()<<", "<< endl;//NOSE
                }
                // BORRAR
                for (int i = 0; i < cantEmpresas; ++i) {
                    delete empresas[i];
                }
                delete[] empresas;
                break;
            }
            case 7: {
                salir = true;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
            }
        }
    }
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
    Empresa* nuevaEmpresa;

    DtNacional * nac = (DtNacional*)empresa;
    if (nac != NULL){
        Empresa* nuevaEmpresa = new Nacional(nac->GetId(), nac->GetDir(), nac->GetRut());
    }else{
        DtExtranjera * extr = (DtExtranjera*)empresa;
        Empresa* nuevaEmpresa = new Extranjera(extr->GetId(), extr->GetDir(), extr->GetNombre());
    }

    empresas[i++] = nuevaEmpresa;
    if(i != MAX_EMPRESAS)
        empresas[i] = NULL;
};


/*
c) DtEmpleado** listarEmpleados(int & cantEmpleados)
Retorna un arreglo de DtEmpleado* con todos los empleados del sistema. 
El largo del arreglo de empleados está dado por el parámetro cantEmpleados.
*/
dtEmpleado** listarEmpleados(int & cantEmpleados){
    if(empleados[0] == NULL || cantEmpleados < 1 || cantEmpleados > MAX_EMPLEADOS){
        cout<<"error"<< endl;
        return NULL;
    }
    dtEmpleado** ArreEmpl = new dtEmpleado *[cantEmpleados];
    int i = 0;
    float sueldoLiquidoTotal = 0.0;;
    Empleado* empleado;
    while(i < cantEmpleados && empleados[i] != NULL){
        empleado = empleados[i];
        for (int j = 0; j < MAX_RELACIONES && empleados[i]->getRel(j) != NULL; j++) {
            if(empleado->getRel(j)->getFechaDesvinculacion() == NULL)
                sueldoLiquidoTotal += empleado->getRel(j)->getSueldoLiquido();
        }
        ArreEmpl[i] = new dtEmpleado(empleado->getCi(), empleado->getNom(), empleado->getApe(), empleado->getDir(), sueldoLiquidoTotal);
        i++;
        sueldoLiquidoTotal = 0.0;
    };
    cantEmpleados = i;
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
    while (numEmpresa < MAX_EMPRESAS && empresas[numEmpresa] != NULL && empresas[numEmpresa]->GetId() != idEmpresa){
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
void finalizarRelacionLaboral(string ciEmpleado, string idEmpresa, Fecha* desvinculación){
    int numEmpleado = 0;
    while (numEmpleado < MAX_EMPLEADOS && empleados[numEmpleado] != NULL && empleados[numEmpleado]->getCi() != ciEmpleado){
        numEmpleado++;
    };
    if(numEmpleado == MAX_EMPLEADOS || empleados[numEmpleado] == NULL){
        throw invalid_argument("No se encontró al empleado");
    }
    int numEmpresa = 0;
    while (numEmpresa < MAX_RELACIONES && empleados[numEmpleado]->getRel(numEmpresa) != NULL && empleados[numEmpleado]->getRel(numEmpresa)->getEmpresa()->GetId() != idEmpresa){
        numEmpresa++;
    };
    if(numEmpresa == MAX_RELACIONES || empleados[numEmpleado]->getRel(numEmpresa) == NULL){
        throw invalid_argument("No se encontró la empresa");
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
    while (numEmpleado < MAX_EMPLEADOS && empleados[numEmpleado] != NULL && empleados[numEmpleado]->getCi() != ciEmpleado){
        numEmpleado++;
    };
    if(numEmpleado == MAX_EMPLEADOS || empleados[numEmpleado] == NULL){
        throw invalid_argument("No se encontró al empleado");
    }
    if(cantEmpresas < 1 || cantEmpresas > MAX_RELACIONES){
        throw invalid_argument("Seleccione un número válido");
    }
    DtEmpresa** empresasEmpleado = new DtEmpresa*[cantEmpresas];
    int contadorEmpresas = 0;
    Empresa* empresa;
    for (int j = 0; j < cantEmpresas && empleados[numEmpleado]->getRel(j) != NULL; j++){
        if(empleados[numEmpleado]->getRel(j)->getFechaDesvinculacion() == NULL){
            empresa = empleados[numEmpleado]->getRel(j)->getEmpresa();
            Nacional * nac = (Nacional*)empresa;
            if (nac != NULL){
                string rutEmpresa = nac->GetRut();
                empresasEmpleado[contadorEmpresas++] = new DtNacional(empresa->GetId(), empresa->GetDir(), rutEmpresa);
            }else{
                Extranjera * extr = (Extranjera*)empresa;
                string nombreFantasia = extr->GetNombre();
                empresasEmpleado[contadorEmpresas++] = new DtExtranjera(empresa->GetId(), empresa->GetDir(), nombreFantasia);
            }
        }
    }
    cantEmpresas = contadorEmpresas;
    return empresasEmpleado;
};



// FUNCIONES AUXILIARES
Direccion * pedirDireccion(){
    string pais, ciud, calle, numero;
    cout<< "Ingrese Pais: "<<endl;
    cin >> pais;
    cout<< "Ingrese Ciudad: "<<endl;
    cin >> ciud;
    cout<< "Ingrese Calle: "<<endl;
    cin >> calle;
    cout<< "Ingrese Numero: "<<endl;
    cin >> numero;
    Direccion *dir = new Direccion(pais, ciud, calle, numero);
    return dir;
}
