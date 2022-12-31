#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Nodo{
	char dat;
	Nodo *siguiente;	
};

void insertar(Nodo *&,Nodo *&,char);
void menu();
void vaciar(Nodo *&,Nodo *&,char &);
bool vacio(Nodo *);

int main (){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
 	
 	char l,ptr;
 	int opcion;
 	Nodo *frente = NULL;
 	Nodo *fin = NULL;
 	
 	do{
 		cout<<"\t******"<<endl;
 		cout<<"\t*MENU*"<<endl;
 		cout<<"\t******"<<endl;
 		cout<<"\n1)Insertar nuevo caracter a la cola"<<endl;
 		cout<<"2)Mostrar Cola"<<endl;
 		cout<<"3)Salir\n"<<endl;
 		cin>>opcion;
 		
 		switch(opcion){
 			case(1):do{
 				cout<<"Ingresar un caracter"<<endl;
 				cin>>l;
 				insertar(frente,fin,l);
 				
 				cout<<"\tDesea Ingresar otro caracter?"<<endl;
 				cout<<"\t\t**Presione s**"<<endl;
 				cin>>ptr;
 				}while((ptr == 's')||(ptr == 'S'));
				break; 
 			
			 case(2):
			 cout<<"\t*************************"<<endl;	
			 cout<<"\t*La cola es la siguiente*"<<endl;	
			cout<<"\t*************************\n"<<endl;
			 while(frente != NULL){
			 		vaciar(frente,fin,l);
			 		
			 		if(frente != NULL){
			 			cout<<l<<" , ";
			 		}else{
			 			cout<<l<<" .FIN"<<endl;
			 		}
			 }
			 cout<<"\n";
			 system("pause");
			 break;
			 
			 case(3):break;
 		}
 		system("cls");
 	}while(opcion != 3);
}

void insertar(Nodo *&frente,Nodo *&fin,char d){
	
	Nodo *nuevonodo = new Nodo();
	
	nuevonodo->dat= d;
	nuevonodo->siguiente = NULL;
	
	if(vacio(frente)){
		frente =  nuevonodo;
	}else{
		fin->siguiente=nuevonodo;
	}
	fin = nuevonodo;
	
	cout<<"\nElemento "<<d<<" Insertado correctamente"<<endl;
}

bool vacio(Nodo *frente){
	return (frente == NULL)? true:false;
}

void vaciar(Nodo *&frente,Nodo *&fin,char &d){
	
	d=frente->dat;
	Nodo *aux = frente;
	
	if(frente == fin){
		frente = NULL;
		fin = NULL;
	}else{
		frente= frente->siguiente;
	}
	delete aux;
}
