#include <iostream>
#include <stdlib.h>


using namespace std;

int tam,	int j=0 vec[100],vec2[100];

void ingDat();
void func(int x[],int);
void mostrar(int x[],int);

int main(){
	
	cout<<"Ingresar tamaño del vector"<<endl;
	cin>>tam;
	
	ingDat();
	func(vec,tam);
	mostrar(vec2,tam);
	
	return 0;
}

void ingDat(){
	
	for(int i=0;i<tam;i++){
	cout<<"\nIngresar valor en la posicion "<<i+1<<endl;
	cin>>vec[i];
	}
}

void func(int x[],int a){

	for(int i=0;i<tam;i++){
		if(x[i]%2 != 0){
			 vec2[j]=x[i];
			 j++;	 
		}
	}
}

void mostrar(int x[],int a){
	for(int i=0;i<j;i++){
		cout<<x[i]<<endl;
	}
}
