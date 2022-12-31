#include <iostream>
#include <stdlib.h>
using namespace std;

class Persona{
	private:
		string nombre;
		int edad;
	public:
		Persona(string,int);
		virtual void mostrar();//Esto es polimorfismo. LLeva la palabra Virtual(solo en la clase padre)
};

class Alumno : public Persona{
	private:
		float notaFinal;
	public:
		Alumno(string,int,float);
		void mostrar();//Metodo del polimorfismo
};

class Profesor : public Persona{
	private:
		string materia;
	public:
		Profesor(string,int,string);
		void mostrar();//Metodo del polimorfismo
};

Persona::Persona(string _nombre, int _edad){
	nombre = _nombre;
	edad = _edad;
}

void Persona::mostrar(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
}

Alumno::Alumno(string _nombre,int _edad,float _notaFinal) : Persona(_nombre,_edad){
	notaFinal = _notaFinal;
}

void Alumno::mostrar(){
	Persona::mostrar();
	cout<<"Nota Final: "<<notaFinal<<endl;
}

Profesor::Profesor(string _nombre,int _edad,string _materia) : Persona(_nombre,_edad){
	materia = _materia;
}

void Profesor::mostrar(){
	Persona::mostrar();
	cout<<"Materia: "<<materia<<endl;
}

int main(){
	
	Persona *pj[3];
	
	pj[0]=new Alumno("Goku",25,18.2);
	pj[1]=new Profesor("Miguel",45,"Matematicas");
	
	pj[0]->mostrar();
	cout<<"\n";
	pj[1]->mostrar();
	
	system("pause");
	return 0;
}
