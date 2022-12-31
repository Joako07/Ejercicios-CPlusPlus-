#include <iostream>
#include <stdlib.h>

using namespace std;


int **mat1,**mat2,nFil,nCol;

void PedirDatos();
void Sumar(int **,int **,int,int);
void Mostrar(int **,int,int);

int main (){
	
	PedirDatos();
	Sumar(mat1,mat2,nFil,nCol);
	Mostrar(mat1,nFil,nCol);
	
	//Liberando la memoria
	for (int i=0;i<nFil;i++){
		delete[] mat2[i];
	}
	delete[] mat2;
	
	for (int i=0;i<nFil;i++){
		delete[] mat1[i];
	}
	delete[] mat1;
	
	return 0;
}

void PedirDatos(){
	
	cout<<"Digite el numero de filas: ";
	cin>>nFil;
	cout<<"Digote el numero de columnas: ";
	cin>>nCol;
	
	//Reservo memoria para la primera matriz
	mat1 = new int *[nFil];
	for(int i=0;i<nFil;i++){
		mat1[i]= new int[nCol]; 
	}	
	
	//Reservo memoria para la segunda matriz
	mat2 = new int*[nFil];
	for(int i=0;i<nFil;i++){
		mat2[i] = new int[nCol];
	}
	
	//Cargo datos en la primer matriz
	for(int i=0;i<nFil;i++){
		for(int j=0;j<nCol;j++){
		cout<<"Digite un numero en la posicion ["<<i<<"]["<<j<<"]: ";
		cin>>*(*(mat1+i)+j); 	
		}
	}
		
	//Cargo datos en la segunda matriz
	for(int i=0;i<nFil;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Diguite un numero en la posicion ["<<i<<"]["<<j<<"]: ";
			cin>>*(*(mat2+i)+j);
		}
	}			
}

void Sumar(int **m1,int **m2,int f,int c){
	
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){	
			*(*(m1+i)+j) += *(*(m2+i)+j);
		}
	}
}

void Mostrar(int **m1,int f,int c){
	
	for(int i=0;i<f;i++){
		for(int j=0;j<c;j++){
			cout<<*(*(m1+i)+j)<<" ";
		}
		cout<<"\n";
	}
}
