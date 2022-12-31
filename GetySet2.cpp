#include <iostream>
#include <stdlib.h>
using namespace std;

//CREO LAS CLASES

class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string,int);
		~Persona();
		void setPersona(string,int);
		string getPersonaNombre();
		int getPersonaEdad();
		void mostrarPersona();
};	

class Empleado : public Persona{
	private:
		int cuil;
	public:
		Empleado(string,int,int);
		~Empleado();
		void setEmpleado(int);
		int getEmpleadoCuil();
};

class Estudiante : public Persona{
	private:
		float legajo;
	public:
		Estudiante(string,int,float);
		~Estudiante();
		void setEstudiante(float);
		float getEstudianteLegajo();
		void mostrarEstudiante();
};

class Universitario : public Estudiante{
	private:
		string nombreUni;
	public:
		Universitario(string,int,float,string);
		void setUniversitario(string);
		string getUniversitarioNombre();
		void mostrarUniversitario();
};

//CREO LOS CONSTRUCTORES----------------------

Persona :: Persona(string _nombre,int _edad){
	nombre = _nombre;
	edad = _edad;
}

Empleado :: Empleado (string _nombre,int _edad,int _cuil) : Persona(_nombre,_edad){
	cuil = _cuil;
}

Estudiante :: Estudiante (string _nombre,int _edad,float _legajo) : Persona(_nombre,_edad){
	legajo = _legajo;
}

Universitario :: Universitario (string _nombre,int _edad,float _legajo,string _nombreUni) : Estudiante(_nombre,_edad,_legajo){
	nombreUni = _nombreUni;
}

//CREO SETTER Y GETTER-------------------------

//-----------------SETTERS------------------------     

void Persona::setPersona(string _nombre,int _edad){
	nombre = _nombre;
	edad = _edad;
}

void Empleado::setEmpleado(int _cuil){
	cuil = _cuil;
}

void Estudiante::setEstudiante(float _legajo){
	legajo = _legajo;
}

void Universitario::setUniversitario(string _nombreUni){
	nombreUni = _nombreUni;
}

//-----------------GETTERS----------------------------

string Persona::getPersonaNombre(){
	return nombre;
}

int Persona::getPersonaEdad(){
	return edad;
}

int Empleado::getEmpleadoCuil(){
	return cuil;
}

float Estudiante::getEstudianteLegajo(){
	return legajo;
}

string Universitario::getUniversitarioNombre(){
	return nombreUni;
}

//----------------DESTRUCTORES-----------------

Persona::~Persona(){
};

Empleado::~Empleado(){
};

Estudiante::~Estudiante(){
};


//------------------METODOS MOSTRAR---------------

void Persona::mostrarPersona(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

void Estudiante::mostrarEstudiante(){
	mostrarPersona();
	cout<<"Legajo: "<<legajo<<endl;
}

void Universitario::mostrarUniversitario(){
	mostrarEstudiante();
	cout<<"Nombre Universidad: "<<nombreUni<<endl;
}

//-----------------MAIN---------------------------

int main(){
	
	Estudiante e1("Jose",18,2.7);
	Universitario u1("Marcelo",20,1.7,"UTN");

	cout<<"Nombre: "<<e1.getPersonaNombre()<<endl;
	cout<<"Edad: "<<e1.getPersonaEdad()<<endl;
	cout<<"Legajo: "<<e1.getEstudianteLegajo()<<endl;
	cout<<"\n";
	
	u1.mostrarUniversitario();
	
	return 0;
}
