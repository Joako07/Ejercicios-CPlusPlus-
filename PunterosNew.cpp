#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void pedirNotas();
void mostrar();

int num,*pun;

int main(){
	
	pedirNotas();
	mostrar();
	
	delete[] pun;//Libero la memoria q aloque con el New
	
	return 0;
}

void pedirNotas(){
	cout<<"Digite un numero "<<endl;
	cin>>num;
	
	pun= new int[num];//New para alocar memoria en el heap
	
	for(int i=0;i<num;i++){
		cout<<"\nIngresar un numero";
		cin>>*(pun+i);
	}
}

void mostrar(){
	cout<<"\nMostrando numero: "<<endl;
	for(int i=0;i<num;i++){
	cout<<pun[i]<<endl;	
	}	
}
