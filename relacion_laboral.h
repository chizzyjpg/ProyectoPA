#ifndef REL_LABORAL
#define REL_LABORAL
#include "empresa.h"
#include "empleado.h"
#include "./DataTypes/Fecha.h"

class RelacionLaboral {
    public:
        RelacionLaboral (float, Fecha*);
        void setSueldo(float);
        void setFechaDesvinculacion(Fecha*);
        float getSueldo();
        Fecha* getFechaDesvinculacion();
        float getSueldoLiquido ();
        ~RelacionLaboral();
    private:
        float sueldo;
        Fecha * fechaDesvinculacion;
};

#endif