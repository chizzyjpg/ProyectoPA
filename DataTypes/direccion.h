#ifndef DIRECCION_H
#define DIRECCION_H
#include <iostream>

using namespace std;

class Direccion {
    private:
        string pais, ciudad, numero, calle;
    public:
        Direccion();
        Direccion(string, string, string, string);
        string getPais();
        string getCiudad();
        string getNumero();
        string getCalle();
};

#endif