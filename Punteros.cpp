#include <iostream>
#include <stdlib.h>

using namespace std;

int j,i,n,*pun;

void PedirDatos();
void Ordenar(int *p,int num);
//void Burbuja(int *p,int num);
void Mostrar(int *p,int num);

int main(){
	
	PedirDatos();
	Ordenar(pun,n);
//	Burbuja (pun,n);
	Mostrar(pun,n);
	
	delete[] pun;

	return 0;
}

void PedirDatos(){
	
	cout<<"Ingresar cantidad de numeros ";cin>>n;
	
	pun = new int[n];
	
	for(i=0;i<n;i++){
		cout<<"\nIngresar un numero en la posicion "<<i+1<<endl;
		cin>>*(pun+i);//Esto es igual que pun[i]
	}
}


void Ordenar(int *p,int num){
	int aux,min;
	
	for(i=0;i<num;i++){
		min=i;
		for(j=i+1;j<num;j++){
			if(*(p+j)<*(p+min)){
				min=j;
			}
		}
		aux=*(p+i);
		*(p+i)=*(p+min);
		*(p+min)=aux;
	}
}

/*
void Burbuja(int *p,int num){
	int aux;
	
	for (i=0;i<num;i++){
		for(j=0;j<num-1;j++){
			if(*(p+j)>*(p+j+1)){
			aux=*(p+j);
			*(p+j)= *(p+j+1);
			*(p+j+1)=aux;
			}
		}
	}	
}
*/

void Mostrar(int *p,int num){
	cout<<"\nMostrando numeros "<<endl;
	for(i=0;i<num;i++){
	cout<<*(p+i)<<endl;	
	}
}
