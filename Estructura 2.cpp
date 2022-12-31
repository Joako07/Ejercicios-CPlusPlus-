#include <iostream>
#include <string.h>

#define MAX 3

using namespace std;

float better=0;
int pos;

struct alumno{
	char nombre[20];
	float promedio;
	int edad;
}jugador[MAX];

struct alumno (*punt)[MAX];

int main(){
	
	punt=&jugador;
	
	for(int i=0;i<MAX;i++){
		fflush(stdin);
		cout<<"Ingresar datos del alumno "<<i+1<<endl;
		cout<<"\nIngresar nombre "<<endl;
		cin.getline((*punt)[i].nombre,20,'\n');
		cout<<"\nIngresar edad "<<endl;
		cin>>(*punt)[i].edad;
		cout<<"\nIngresar promedio "<<endl;
		cin>>(*punt)[i].promedio;
		cout<<"\n";
	}
	
	for(int i=0;i<MAX;i++){
		if((*punt)[i].promedio > better){
			better=(*punt)[i].promedio;
			pos=i;
		}
	}

		cout<<"\nEl alumno de mejor promedio es "<<pos+1<<endl;
		cout<<"Nombre: "<<(*punt)[pos].nombre<<endl;
		cout<<"Edad: "<<(*punt)[pos].edad<<endl;
		cout<<"Promedio: "<<(*punt)[pos].promedio<<endl;


	return 0;
}
