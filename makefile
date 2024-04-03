all: Fecha.o Direccion.o DtEmpleado.o DtEmpresa.o DtExtranjera.o DtNacional.o empresa.o nacional.o extranjera.o empleado.o relacion_laboral.o main.o
	g++ Fecha.o Direccion.o DtEmpleado.o DtEmpresa.o DtExtranjera.o DtNacional.o empresa.o nacional.o extranjera.o empleado.o relacion_laboral.o main.o -o programa


# Data types
Fecha.o:
	g++ -c "DataTypes/Fecha.cpp"

Direccion.o:
	g++ -c "DataTypes/direccion.cpp"

DtEmpleado.o:
	g++ -c "DataTypes/dtEmpleado.cpp"

DtEmpresa.o:
	g++ -c "DataTypes/dtEmpresa.cpp"

DtExtranjera.o: DtEmpresa.o
	g++ -c "DataTypes/dtExtranjera.cpp"

DtNacional.o: DtEmpresa.o
	g++ -c "DataTypes/dtNacional.cpp"


# Clases
empresa.o: Direccion.o
	g++ -c empresa.cpp

nacional.o: empresa.o
	g++ -c nacional.cpp

extranjera.o: empresa.o
	g++ -c extranjera.cpp	

empleado.o: Direccion.o
	g++ -c empleado.cpp	
	
relacion_laboral.o: empresa.o empleado.o Fecha.o
	g++ -c relacion_laboral.cpp	


main.o: 
	g++ -c main.cpp


clean:
	rm -f Fecha.o Direccion.o DtEmpleado.o DtEmpresa.o DtExtranjera.o DtNacional.o empresa.o nacional.o extranjera.o empleado.o relacion_laboral.o main.o programa
run:
	make clean
	make
	clear
	./programa