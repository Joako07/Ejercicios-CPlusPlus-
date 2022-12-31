#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

char Nombre[30];

void PedirNombre();
int CantiVocales(char *z);

int main(){
	
	PedirNombre();
	
	cout<<"\nLa cantidad de vocales es--->"<<CantiVocales(Nombre)<<endl;
	
	return 0;
}

void PedirNombre(){
	
	cout<<"Ingresar Nombre"<<endl;
	cin.getline(Nombre,30,'\n');
	
}

int CantiVocales(char *z){
	
	int Voc=0;
	
	for(int i=0;i<strlen(z);i++){
		switch (*(z+i)){
			case 'a':Voc++;break;
			case 'e':Voc++;break;	
			case 'i':Voc++;break;	
			case 'o':Voc++;break;
			case 'u':Voc++;break;	
			default:;	
		}
	}
	
	return Voc;
}
