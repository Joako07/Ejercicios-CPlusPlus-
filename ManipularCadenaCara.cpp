#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
	
	char palabra1[30],palabra2[30],palabra3[30];

	int longitud=0;
	
	cout<<"Ingresar la palabra1"<<endl;
	cin.getline(palabra1,30,'\n');
	
	cout<<"Ingresar la palabra 2"<<endl;
	cin.getline(palabra2,30,'\n');
	
	longitud = strlen(palabra1);
	
	if(longitud > 10){
		cout<<"\nLa cadena tiene---> "<<longitud<<" Y dice: "<<palabra1<<endl;
	}else{
		strcpy(palabra3,palabra1);
		cout<<"\nLa cadena tiene ---> "<<longitud<<" y dice: "<<palabra3<<endl;
	}
	
	if(strcmp(palabra1,palabra2) == 0){
		cout<<palabra1<<" (T)Es igual a "<<palabra2<<endl;
	}else if(strcmp(palabra1,palabra2) >0 ){
		cout<<palabra1<<" Es mayor alfabeticamente que "<<palabra2<<endl;
	}else{
		cout<<palabra2<<" Es mayor alfabeticamente que "<<palabra1<<endl;
	}
	
	//strcpy(palabra3,palabra1); Para copiar cadenas
	
	//strcat(cad3,nom); para juntar cadenas 
	
	//strrev(nom); Invierte la cadena
	
	//strupr(cad1); Pasar la cadena a Mayuscula
	
	//strlwr(cad1); Pasar la cadena a Minuscula
	
	/*int num = atoi(cad1); Convierte la cadena en un int
      float num = atof(cad1); Convierte la cadena en un float 	
	video 48
	*/
		
	return 0;
}
