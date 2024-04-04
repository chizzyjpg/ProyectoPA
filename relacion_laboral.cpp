#include "relacion_laboral.h"

// Constructor:
RelacionLaboral::RelacionLaboral(float Sue, Empresa* Empre){
    this->sueldo = Sue;
    this->empresa = Empre;
    this->fechaDesvinculacion = NULL;
};


// Funcionalidad:
float RelacionLaboral::getSueldoLiquido (){
    return 0;
    // return (this->getSueldo() * this->empresa->getDescuento());
};


// Setters:
void RelacionLaboral::setSueldo(float Sue){
    this->sueldo = Sue;
};

void RelacionLaboral::setFechaDesvinculacion(Fecha* Fecha){
    this->fechaDesvinculacion = Fecha;
};

void RelacionLaboral::setEmpresa(Empresa* Empre){
    this->empresa = Empre;
};


// Getters:
float RelacionLaboral::getSueldo(){
    return this->sueldo;
};

Fecha* RelacionLaboral::getFechaDesvinculacion(){
    return this->fechaDesvinculacion;
};

Empresa* RelacionLaboral::getEmpresa(){
    return this->empresa;
};


// Destructor: 
RelacionLaboral::~RelacionLaboral(){
    
};