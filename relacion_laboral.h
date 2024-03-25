#ifndef REL_LABORAL
#define REL_LABORAL
#include "empresa.h"
#include "empleado.h"
#include "./DataTypes/Fecha.h"

class RelacionLaboral {
    public:
        RelacionLaboral (float, Fecha*, Empresa*);
        void setSueldo(float);
        void setFechaDesvinculacion(Fecha*);
        void setLaEmpre(Empresa*);//Bernardo
        float getSueldo();
        Fecha* getFechaDesvinculacion();
        Empresa* getLaEmpre();//bernardo
        float getSueldoLiquido ();
        ~RelacionLaboral();
    private:
        float sueldo;
        Fecha * fechaDesvinculacion;
        Empresa * LaEmpre;//Bernardo
};

#endif