#ifndef REL_LABORAL
#define REL_LABORAL
#include "empresa.h"
#include "empleado.h"
#include "./DataTypes/Fecha.h"

class Empresa;
class Empleado;
class Fecha;

class RelacionLaboral {
    public:
        RelacionLaboral (float, Fecha);
        float getSueldoLiquido ();
    private:
        float sueldo;
        Fecha * fechaDesvinculación;
};

#endif