#include <iostream>
#include <stdlib.h>
using namespace std;

class Punto{
	private:
		int x,y;
	public:
		Punto();//Constructor vacio
		void setPunto(int,int);//Para asignar un valor a los atributos
		int getPuntoX();//Para mostrar x
		int getPuntoY();//Para mostrar y
};

//Constructor Vacio
Punto::Punto(){
};

//Metodo set para cambiar los atributos
void Punto::setPunto(int _x,int _y){
	x=_x;
	y=_y;
}

//Metodo get para mostrar un atributo X
int Punto::getPuntoX(){
	return x;
}

//Metodo get para mostrar un atributo y
int Punto::getPuntoY(){
	return y;
}



int mani(){
	Punto p1;
	
	p1.setPunto(15,10);
	cout<<p1.getPuntoX()<<endl;
	cout<<p1.getPuntoY()<<endl;
	
	return 0;
}
