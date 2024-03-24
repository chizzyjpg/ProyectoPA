#define MAX_RELACIONES 50
#include <iostream>
#include "/DataTypes/direccion.h"
using namespace std;

class Empleado {
	public:
		Empleado(string Ci, string Nom, string Ape, Direccion Dir);
		void setNom(string Nom);
		void setApe(string Ape);
		void setCi(string Ci);
		void setDir(Direccion Dir);
		void agregarRel(relacionLaboral *Rel);
		string getNom();
		string getApe();
		string getCi();
		Direccion getDir();
		~Empleado();
	private:
		string ci;
		string nombre;
		string apellido;
		Direccion direccion;
		relacionLaboral *Relaciones[MAX_RELACIONES];
};