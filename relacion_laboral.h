#ifndef REL_LABORAL
#define REL_LABORAL
#include "empresa.h"
#include "empleado.h"
#include "./DataTypes/Fecha.h"

class RelacionLaboral {
    public:
        RelacionLaboral (float, Fecha*, La);
        float getSueldoLiquido ();
        ~RelacionLaboral();
    private:
        float sueldo;
        Fecha * fechaDesvinculación;
        Empresa * LaEmpre;
};

#endif