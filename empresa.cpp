#include "empresa.h"

// Constructor:
Empresa::Empresa(){
    this->id = "";
    this->dir = NULL;
};
 
Empresa::Empresa(string Id, Direccion* Dir){
    this->id = Id;
    this->dir = Dir;
};


// Setters:
void Empresa::SetId(string Id){
    this->id = Id;
};

void Empresa::SetDir(Direccion* Dir){
    this->dir = Dir;
};


// Getters:
string Empresa::GetId(){
    return this->id;
};

Direccion* Empresa::GetDir(){
    return this->dir;
};

float getDescuento(){
    return 0;
}
// Destructor:
Empresa::~Empresa() {
    cout << "Fundio" << endl;
};