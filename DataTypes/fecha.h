#ifndef FECHA_H
#define FECHA_H
#include <iostream>

using namespace std;

class Fecha {
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int d, int m, int a);
        int getDia();
        int getMes();
        int getAnio();
};

#endif