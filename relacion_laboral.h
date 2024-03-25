#ifndef REL_LABORAL
#define REL_LABORAL
#include "empresa.h"
#include "empleado.h"
#include "./DataTypes/Fecha.h"


class RelacionLaboral {
    public:
        RelacionLaboral (float, Empresa*);
        void setSueldo(float);
        void setFechaDesvinculacion(Fecha*);
        void setLaEmpre(Empresa*);
        float getSueldo();
        Fecha* getFechaDesvinculacion();
        Empresa* getLaEmpre();
        float getSueldoLiquido ();
        ~RelacionLaboral();
    private:
        float sueldo;
        Fecha * fechaDesvinculacion;
        Empresa * LaEmpre;
};

#endif