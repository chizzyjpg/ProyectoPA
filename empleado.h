#define MAX_RELACIONES 50

#ifndef EMPLEADO
#define EMPLEADO

#include <iostream>
#include "./DataTypes/direccion.h"
#include "relacion_laboral.h"
using namespace std;

class Direccion;
class RelacionLaboral;

class Empleado {
	public:
		Empleado(string Ci, string Nom, string Ape, Direccion* Dir);
		void setNom(string Nom);
		void setApe(string Ape);
		void setCi(string Ci);
		void setDir(Direccion* Dir);
		void agregarRel(RelacionLaboral *Rel);
		string getNom();
		string getApe();
		string getCi();
		Direccion* getDir();
		~Empleado();
	private:
		string ci;
		string nombre;
		string apellido;
		Direccion *direccion;
		RelacionLaboral *Relaciones[MAX_RELACIONES];
};

#endif