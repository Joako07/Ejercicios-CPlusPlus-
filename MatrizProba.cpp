#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	
	int fil,col,fil2,col2;
	
	goback:;
	
	cout<<"Ingresar numero de filas de la mtraiz 1---> ";cin>>fil;
	cout<<"Ingresar numero de columnas de la matriz 1---> ";cin>>col;
	cout<<"Ingresar numero de filas de la mtraiz 2---> ";cin>>fil2;
	cout<<"Ingresar numero de columnas de la matriz 2---> ";cin>>col2;
	
	float matriz[fil][col];
	float matriz2[fil2][col2];
	
	if(col != fil2){
		cout<<"\nEstas matrices no se pueden multiplicar"<<endl;
		cout<<"Reingrese los valores\n"<<endl;
		goto goback;	
	}

	cout<<"\nIngresar la primera matriz"<<endl;
	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
		cout<<"Ingresar el valor en la posicion "<<i<<j<<"--->";cin>>matriz[i][j];	
		}
	}
	
	cout<<"\nIngresar la segunda matriz"<<endl;
	for(int i=0;i<fil2;i++){
		for(int j=0;j<col2;j++){
		cout<<"Ingresar el valor en la posicion "<<i<<j<<"--->";cin>>matriz2[i][j];	
		}
	}
	
	float matrizMul[fil][col2];
		
	for(int i=0;i<fil;i++){
		for(int j=0;j<col2;j++){
			matrizMul[i][j]=0;
			for(int k=0;k<col;k++){
				matrizMul[i][j] += matriz[i][k]*matriz2[k][i];
			}	
		}
	}
	
	
	cout<<"\nMultiplico las matrizes\n";
	for(int i=0;i<fil;i++){
		for(int j=0;j<col2;j++){
			cout<<"("<<matrizMul[i][j]<<")";
		}
		cout<<"\n";
	}
	
	return 0;
}
	
