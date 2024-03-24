#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha {
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int, int, int);
        int getDia();
        int getMes();
        int getAnio();
};

#endif