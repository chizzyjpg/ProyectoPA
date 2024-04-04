#ifndef REL_LABORAL
#define REL_LABORAL
#include "empresa.h"
#include "./DataTypes/fecha.h"


class RelacionLaboral {
    public:
        RelacionLaboral (float sueldo, Empresa* empresa);
        void setSueldo(float);
        void setFechaDesvinculacion(Fecha*);
        void setEmpresa(Empresa*);
        float getSueldo();
        Fecha* getFechaDesvinculacion();
        Empresa* getEmpresa();
        float getSueldoLiquido();
        ~RelacionLaboral();
    private:
        float sueldo;
        Fecha* fechaDesvinculacion;
        Empresa* empresa;
};

#endif