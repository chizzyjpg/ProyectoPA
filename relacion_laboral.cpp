#include "relacion_laboral.h"

//Constructor
RelacionLaboral::RelacionLaboral(float Sue, Fecha *Fech){
    this->sueldo = Sue;
    this->fechaDesvinculacion = Fech;
};

void RelacionLaboral::setSueldo(float Sue){
    this->sueldo = Sue;
}
void RelacionLaboral::setFechaDesvinculacion(Fecha *Fech){
    this->fechaDesvinculacion = Fech;
}
float RelacionLaboral::getSueldo(){
    return this->sueldo;
}
Fecha* RelacionLaboral::getFechaDesvinculacion(){
    return this->fechaDesvinculacion;
}
float RelacionLaboral::getSueldoLiquido (){
    
}
RelacionLaboral::~RelacionLaboral(){
    
}