#include <iostream>
#include <string.h>

using namespace std;

	struct info_direccion{
		char direccion[30];
		char ciudad[20];
		char provincia[20];
	};
	
	struct empleado{
		char nombre[20];
		struct info_direccion dir_empleado;
		int salario;
	}persona[2];
	
	struct empleado *p_punte;
	

int main(){
	
	p_punte = persona; 
	
	for (int i=0;i<2;i++){
		fflush(stdin); // Sirve para vaciar el buffer t permitir digitar mas valores.
		cout<<"Ingrese nombre "<<endl;
		cin.getline(p_punte->nombre,20,'\n');
		cout<<"\nIngrese direccion "<<endl;
		cin.getline(p_punte->dir_empleado.direccion,30,'\n');
		cout<<"\nIngrese ciudad "<<endl;
		cin.getline(p_punte->dir_empleado.ciudad,20,'\n');
		cout<<"\nIngrese provincia "<<endl;
		cin.getline(p_punte->dir_empleado.provincia,20,'\n');
		cout<<"\nIngrese salario "<<endl;
		cin>>p_punte->salario;
		p_punte++;
	}
		
	/*
	for (int i=0;i<2;i++){
		cout<<"\nDatos del usuario "<<i+1<<endl;
		cout<<"Nombre: "<<persona[i].nombre<<endl;
		cout<<"Direccion: "<<persona[i].dir_empleado.direccion<<endl;
		cout<<"Ciudad: "<<persona[i].dir_empleado.ciudad<<endl;
		cout<<"Provincia: "<<persona[i].dir_empleado.provincia<<endl;
		cout<<"Salario: "<<persona[i].salario<<endl;
		
	}
	*/
	
	for (int i=0;i<2;i++){
		cout<<"\nDatos Empleado Numero : "<<i+1<<endl;
		cout<<"Nomre: "<<p_punte->nombre<<endl;
		cout<<"Direccion: "<<p_punte->dir_empleado.direccion<<endl;
		cout<<"Ciutdad: "<<p_punte->dir_empleado.ciudad<<endl;
		cout<<"Provincia: "<<p_punte->dir_empleado.provincia<<endl;
		cout<<"Salario: "<<p_punte->salario<<endl;
		p_punte++;
	}	

	return 0;
}
