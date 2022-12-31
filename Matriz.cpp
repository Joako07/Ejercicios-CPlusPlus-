#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	
	int fil,colm;
	
	cout<<"Ingresar el numero de filas---> ";cin>>fil;
	cout<<"Ingresar el numero de columnas---> ";cin>>colm;
	
	int matriz[fil][colm];
	
	cout<<"\n";
	for(int f=0;f<fil;f++){
		for(int c=0;c<colm;c++){
			cout<<"Ingresar valor en la posicion "<<f<<"-"<<c<<"--->";cin>>matriz[f][c];
		}
	}
	
	cout<<"\n";
	for(int f=0;f<fil;f++){
		for(int c=0;c<colm;c++){
			cout<<matriz[f][c];
		}
		cout<<"\n";
	}
	
	system("pause");
	return 0;
}
