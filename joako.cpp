#include <iostream>
#include <string.h>

#define MAX 2

using namespace std;

struct corredor{
	char nombre[20];
	char sexo;
	char club[20];
	int edad;
}jugador[MAX];

struct corredor (*punt)[MAX];

void func (corredor p);

void func(corredor p){
	
	if(p.edad<=18){
	   cout<<"Categoria: Juvenil"<<endl;
	}else if(p.edad > 18 && p.edad <= 40){
		cout<<"Categoria: Senior"<<endl;
	}else{
		cout<<"Categoria: Veterano"<<endl;
	}
}

int main(){
	
	punt=&jugador;
	
	for(int i=0;i<MAX;i++){
		cout<<"Ingresar datos del jugador "<<i+1<<endl;
		cout<<"\nIngresar nombre "<<endl;
		cin.getline((*punt)[i].nombre,30,'\n');
		cout<<"\nIngresar edad "<<endl;
		cin>>(*punt)[i].edad;
		cout<<"\nIngresar sexo "<<endl;
		cin>>(*punt)[i].sexo;
		fflush(stdin);
		cout<<"\nIngresar club "<<endl;
		cin.getline((*punt)[i].club,30,'\n');
		cout<<"\n";
	}

	for(int i=0;i<MAX;i++){
		cout<<"\nDatos del corredor numero "<<i+1<<endl;
		cout<<"Nombre: "<<(*punt)[i].nombre<<endl;
		cout<<"Edad: "<<(*punt)[i].edad<<endl;
		cout<<"Sexo: "<<(*punt)[i].sexo<<endl;
		cout<<"Club: "<<(*punt)[i].club<<endl;
		func(jugador[i]);
}
}
