#include "dtEmpresa.h"
#include "dtExtranjera.h"
#include "dtNacional.h"
class DtNacional;
class DtExtranjera;
// Constructor:
DtEmpresa::DtEmpresa(){
    this->id = "";
    this->dir = NULL;
};
 
DtEmpresa::DtEmpresa(string Id, Direccion* Dir){
    this->id = Id;
    this->dir = Dir;
};


// Getters:
string DtEmpresa::GetId(){
    return this->id;
};

Direccion* DtEmpresa::GetDir(){
    return this->dir;
};

ostream& operator<<(ostream& os, DtEmpresa* emp){
    os << "Id Empresa: " << emp->GetId() << endl;
    os << "Direccion: " << emp->GetDir()->getPais() << ", " << emp->GetDir()->getCiudad() << ": " << emp->GetDir()->getCalle() << " Nro " << emp->GetDir()->getNumero() << endl;
    DtNacional * nac = (DtNacional*)emp;
    if (nac != NULL){
        string rutEmpresa = nac->GetRut();
        os << "RUT: " << rutEmpresa;
    }else{
        DtExtranjera * extr = (DtExtranjera*)emp;
        string nombreFantasia = extr->GetNombre();
        os << "Nombre Fantasia: " << nombreFantasia;

    }
}
