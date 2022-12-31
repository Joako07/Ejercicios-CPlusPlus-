#include <iostream>
#include <stdlib.h>
using namespace std;

class Rectangulo{
	private://atributos siempre son privados
		string name;
		int largo;
		int ancho;
	public://metodos son publicos
		Rectangulo(string,int,int);//Constructor
		~Rectangulo();//Destructor
		void perimetro();
		void area();
};

//Herencia de clases
class Alumno : public Rectangulo{
	private:
		string codigoGrafico;
		float otroDato;
	public:
		Alumno(string,int,int,string,float);
		void mostrarAlumno();
		
};

//Creo el constructor de las cases que sirve para inicializarla
Rectangulo::Rectangulo(string _name,int _largo,int _ancho){
	name = _name;
	largo = _largo;
	ancho = _ancho;
}

//En el constructor de la clase hija, llamas al final el contructor de la clase padre. 
//Y adentro pedis solo los datos de la clase hija
Alumno::Alumno(string _name,int _largo,int _ancho,string _codigo, float _otroDato) : Rectangulo(_name,_largo,_ancho){
	codigoGrafico = _codigo;
	otroDato = _otroDato;
}

//Creo el destructor que va a destruir todos los objetos creados.
//No lleva parametros ni nada adentro
Rectangulo::~Rectangulo(){	
};

void Rectangulo::perimetro(){
	
	int perimetro;
	
	perimetro = (largo*2)+(ancho*2);
	
	cout<<"el perimetro es: "<<perimetro<<endl;
}

void Rectangulo::area(){
	
	int area;
	
	area = ancho*largo;
	
	cout<<"El area es: "<<area<<endl;
}

void Alumno::mostrarAlumno(){
	perimetro();
	area();
	cout<<"Codigo: "<<codigoGrafico<<endl;
	cout<<"Otro Dato: "<<otroDato<<endl;
}

int main(){
	
	Rectangulo r1("RectA",10,10);//Instancio una clase osea creo un objeto del a clase
	Rectangulo r2("RectB",2,2);	
	Alumno alumno1("RectC",4,4,"321654",15.6);
	
	r1.area();
	r2.perimetro();
	cout<<"\n";
	alumno1.mostrarAlumno();
	
	return 0;
};
