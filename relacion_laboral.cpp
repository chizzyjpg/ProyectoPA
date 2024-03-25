#include "relacion_laboral.h"

//Constructor
RelacionLaboral::RelacionLaboral(float Sue, Fecha *Fech, Empresa *Empre){
    this->sueldo = Sue;
    this->fechaDesvinculacion = Fech;//cuando se crea aca seria nada supongo
    this->LaEmpre = Empre;
};

void RelacionLaboral::setSueldo(float Sue){
    this->sueldo = Sue;
}
void RelacionLaboral::setFechaDesvinculacion(Fecha *Fech){
    this->fechaDesvinculacion = Fech;
}
void RelacionLaboral::setLaEmpre(Empresa *Empre){
    this->LaEmpre = Empre;
}
float RelacionLaboral::getSueldo(){
    return this->sueldo;
}
Fecha* RelacionLaboral::getFechaDesvinculacion(){
    return this->fechaDesvinculacion;
}
Empresa* getLaEmpre(){
    return this->LaEmpre;
}
float RelacionLaboral::getSueldoLiquido (){
    return (this->getSueldo()*this->LaEmpre->getDescuento())//Algo asi?
}

RelacionLaboral::~RelacionLaboral(){
    
}