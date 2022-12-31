#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu();
void CrearLista(Nodo *&,int);
void mostrar(Nodo *);
void mayorMenor(Nodo *);
void borrarLista(Nodo *&,int &);

Nodo *lista= NULL;

int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	
	int opcion,can,dat;
	
	do{
		cout<<"-:MENU:-"<<endl;
		cout<<"1)Ingresar Lista"<<endl;
		cout<<"2)Mostrar Lista"<<endl;
		cout<<"3)Mostrar Mayor y Menor elemento"<<endl;
		cout<<"4)Borrar Lista"<<endl;
		cout<<"5)Salir"<<endl;
		cout<<"Opcion: ";cin>>opcion;
		
		switch(opcion){
			case 1:
					cout<<"Ingresar Cantidad de elementos que tendra la lista: ";cin>>can;
					for(int i=0;i<can;i++){
						cout<<"Ingresar elemento "<<i+1<<endl;
						cin>>dat;
						CrearLista(lista,dat);
					}break;
			case 2:
					mostrar(lista);
					cout<<"\n\n";
					system("pause");
					break;
			case 3:
				    mayorMenor(lista);
					cout<<"\n";
					system("pause");
					break;
			case 4:
					while(lista != NULL){
						borrarLista(lista,dat);
						cout<<dat<<"-";
					}
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}while (opcion != 5);
	
	
}

//Agrega los elementos desordenados
void CrearLista(Nodo *&lista,int n){
	
	Nodo *newNodo = new Nodo();
	newNodo->dato=n;
	newNodo->siguiente=NULL;
	
	Nodo *aux;
	
	if(lista == NULL){//Si la lista esta vacia
		lista= newNodo;//Agrego el primer Nodo a la lista
	}else{
		aux=lista;//Aux apunta al inicio de la lista
		while(aux->siguiente != NULL){//Recorrer lista
		aux = aux->siguiente;
		}
		aux->siguiente=newNodo; // Agrego el nodo al final de la lista
	}
		
	cout<<"\tElemento "<<n<<" ingresado correctamente"<<endl;
}

void mostrar(Nodo *lista){

	while(lista != NULL){
		cout<<lista->dato<<"-";
		lista = lista->siguiente;
	}
}

void mayorMenor(Nodo *lista){
	
	int men=9999,may= 0;
	
	while(lista != NULL){
		if(lista->dato < men){
			men = lista->dato;
		}
		if(lista->dato > may){
			may=lista->dato;
		}
		lista = lista->siguiente;
	}
	
	cout<<"El elemento mayor es: "<<may<<endl;
	cout<<"El elemento menor es: "<<men<<endl;
}

void borrarLista(Nodo *&lista,int &n){
	
	Nodo *aux=lista;
	n=aux->dato;
	lista=aux->siguiente;
	delete aux;
}
