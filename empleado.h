#define MAX_RELACIONES 50

#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include "./DataTypes/direccion.h"
#include "relacion_laboral.h"
#include "./DataTypes/dtEmpleado.h"
class RelacionLaboral;
using namespace std;

class Empleado {
	public:
		Empleado();
		Empleado(string Ci, string Nom, string Ape, Direccion* Dir);
		Empleado(string Ci, string Nom, string Ape, Direccion* Dir, RelacionLaboral* Rel);
		void setNom(string Nom);
		void setApe(string Ape);
		void setCi(string Ci);
		void setDir(Direccion* Dir);
		void agregarRel(RelacionLaboral *Rel);
		string getNom();
		string getApe();
		string getCi();
		Direccion* getDir();
		RelacionLaboral* getRel(int);
		~Empleado();
	private:
		string ci;
		string nombre;
		string apellido;
		Direccion *direccion;
		RelacionLaboral *Relaciones[MAX_RELACIONES];
};

#endif