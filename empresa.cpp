#include "empresa.h"

Empresa::Empresa(){
    this->id="NULL";
    this->dir;
};
 
Empresa::Empresa(string Id, Direccion * Dir){
    this->id=Id;
    this->dir=Dir;
};

Empresa::~Empresa() {
    cout << "Fundio" << endl;
};

void Empresa::SetId(string Id){
    this->id=Id;
};

void Empresa::SetDir(Direccion *Dir){
    this->dir=Dir;
};

string Empresa::GetId(){
    return this->id;
};

Direccion* Empresa::GetDir(){
    return this->dir;
};