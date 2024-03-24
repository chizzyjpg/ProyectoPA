#include "Empresa.h"

Empresa::Empresa(){
    this->id="NULL";
    this->dir;
};

Empresa::Empresa(string Id, Direccion Dir){
    this->id=Id;
    this->dir=Dir;
};

Empresa::~Empresa() {
    cout << "Fundio" << endl;
};

void SetId(string Id){
    this->id=Id;
};

void SetDir(Direccion Dir){
    this->dir=Dir;
};

string GetId(){
    return this->id;
};

Direccion GetDir(){
    return this->dir;
};