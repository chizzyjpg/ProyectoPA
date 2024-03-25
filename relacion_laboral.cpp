#include "relacion_laboral.h"

//Constructor
RelacionLaboral::RelacionLaboral(float Sue, Empresa *Empre){
    this->sueldo = Sue;
    this->fechaDesvinculacion = NULL;
    this->LaEmpre = Empre;
};

void RelacionLaboral::setSueldo(float Sue){
    this->sueldo = Sue;
};
void RelacionLaboral::setFechaDesvinculacion(Fecha *Fech){
    this->fechaDesvinculacion = Fech;
};
void RelacionLaboral::setLaEmpre(Empresa *Empre){
    this->LaEmpre = Empre;
};
float RelacionLaboral::getSueldo(){
    return this->sueldo;
};
Fecha* RelacionLaboral::getFechaDesvinculacion(){
    return this->fechaDesvinculacion;
};
Empresa* RelacionLaboral::getLaEmpre(){
    return this->LaEmpre;
};
float RelacionLaboral::getSueldoLiquido (){

    /*float descuento;
    descuento = (this->getSueldo()*this->LaEmpre->getDescuento()/100)
    return (this->getSueldo() - descuento)*/

    /*return (this->getSueldo()*this->LaEmpre->getDescuento());   Algo asi?*/
};

RelacionLaboral::~RelacionLaboral(){
    
};