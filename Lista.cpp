#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;		
};

Nodo *lista = NULL;

void buscarenlista(Nodo *,int);
void eliminarLista(Nodo *&,int &);
void eliminarElemento(Nodo *&,int);
void insertar(Nodo *&,int);
void mostrar(Nodo *);
void menu();


int main(){
	
	menu();
	
	getch();
	return 0;
}

void menu(){
	
	int opci,dat;
	char p;
	
	do{
		cout<<"\t.:MENU:.\n";
		cout<<"1)Insertar un elemento"<<endl;
		cout<<"2)Mostrar Lista"<<endl;
		cout<<"3)Buscar un elemento"<<endl;
		cout<<"4)Eliminar un elemento"<<endl;
		cout<<"5)Eliminar Lista"<<endl;
		cout<<"6)Salir"<<endl;
		cout<<"Opcion: ";
		cin>>opci;
		
		switch(opci){
			case 1:	do{
						cout<<"Ingresar un elemento: ";cin>>dat;
						insertar(lista,dat);
		
						cout<<"\n\t Si desea ingresar otro elemento precione s/S ";cin>>p;
						cout<<"\n";
						system("cls");
						}while((p == 's')||(p=='S'));break;
			case 2:
					mostrar(lista);
					cout<<"\n\n";
					system("pause");
					break;
			case 3:	
					cout<<"Diguite el elemento que desea buscar: ";cin>>dat;
					buscarenlista(lista,dat);
					cout<<"\n";
					system("pause");
					break;
			case 4:	
					cout<<"Diguite el elemento que desea eliminar: ";cin>>dat;
					eliminarElemento(lista,dat);
					cout<<"\n";
					system("pause");
					break;	
			case 5:
					while(lista != NULL){
					eliminarLista(lista,dat);
					cout<<dat<<"->";
					}
					cout<<"\n";
					system("pause");
					break;
		}
		system("cls");
	}while(opci != 6);
	
}

//Agrega los elementos ordenados
void insertar(Nodo *&lista,int n){
	
	Nodo *nuevonodo = new Nodo();
	nuevonodo->dato=n;
	
	Nodo *aux1 = lista;
	Nodo *aux2;
	
	while((aux1 != NULL)&&(aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	
	if(lista == aux1){
		lista = nuevonodo;
	}else{
		aux2->siguiente = nuevonodo;
	}
	nuevonodo->siguiente = aux1;
	
	cout<<"\tElemento "<<n<<" ingresado correctamente"<<endl;
}

void mostrar(Nodo *lista){
	Nodo *actual= new Nodo();
	
	actual= lista;
	
	while(actual != NULL){
		
		cout<<actual->dato<<"-";
		actual= actual->siguiente;
		
	}
}

void buscarenlista(Nodo *lista,int n){
	
	bool ban = false;
	
	Nodo *actual = new Nodo();//creo que esto no hace falta. Simplemente usas la variable "lista"
	actual = lista;
	
	while((actual != NULL)&& (actual->dato <= n)){
		if(actual->dato == n){
			ban = true;
		}else{
			actual=actual->siguiente;
		}
	}
	
	if(ban == true){
		cout<<"El elemento "<<n<<" se encontro en la lista"<<endl;
	}else{
		cout<<"El elemento "<<n<<" NO se encuentra en la lita"<<endl;
	}
}

void eliminarElemento(Nodo *&lista,int n){
	
	if(lista != NULL){
		Nodo *auxBorrar;
		Nodo *anterior = NULL;
		auxBorrar = lista;
		
		while((auxBorrar != NULL)&&(auxBorrar->dato != n)){
			anterior= auxBorrar;
			auxBorrar=auxBorrar->siguiente;
			
		}
		
		if(auxBorrar == NULL){
			cout<<"El elemento NO existe"<<endl;
		}else if(anterior == NULL){	//el primer elemento es el numero que eliminamos
			lista=lista->siguiente;
			cout<<"el elemento "<<n<<" ha sido borrado"<<endl;
			delete auxBorrar;
		}else{
			//elimina un elemento de la lista que no sea el primero
			anterior->siguiente = auxBorrar->siguiente;
			cout<<"el elemento "<<n<<" ha sido borrado"<<endl;
			delete auxBorrar;
		}
		
	}
}

void eliminarLista(Nodo *&lista,int &n){
	
	Nodo *aux = lista;
	n=aux->dato;
	lista= aux->siguiente;
	delete aux;
}

