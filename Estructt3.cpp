#include <iostream>
#include <string.h>

#define MAX 3

using namespace std;

float may=0, men=99999;
int i,posMay,posMen;

struct empleados{
	char nombre[20];
	float salario;
}emp[MAX];

struct empleados (*p)[MAX];

void mayor(empleados pun){
		if(pun.salario > may){
			may=pun.salario;
			posMay= i;
		}
}

void menor(empleados pun){
		if(pun.salario < men){
			men=pun.salario;
			posMen=i;
		}	
}


int main(){
	
	p=&emp;
	
	for(i=0;i<MAX;i++){
		fflush(stdin);
		cout<<"Ingresar datos del empleado "<<i+1<<endl;
		cout<<"Ingresar Nombre: "<<endl;
		cin.getline((*p)[i].nombre,20,'\n');
		cout<<"Ingresar salario: "<<endl;
		cin>>(*p)[i].salario;
		cout<<"\n";	
	}
	
	for(i=0;i<MAX;i++){
		mayor(emp[i]);
	}
	
	for(i=0;i<MAX;i++){
		menor(emp[i]);
	}
	
	
	cout<<"\nEl empleado con mayor salario es el numero: "<<posMay+1<<endl;
	cout<<"Nombre: "<<(*p)[posMay].nombre<<endl;
	cout<<"Salari: "<<(*p)[posMay].salario<<endl;
	cout<<"\n";
	cout<<"\nEl empleado con menor salario es el numero: "<<posMen+1<<endl;
	cout<<"Nombre: "<<(*p)[posMen].nombre<<endl;
	cout<<"Salari: "<<(*p)[posMen].salario<<endl;

	return 0;
}

