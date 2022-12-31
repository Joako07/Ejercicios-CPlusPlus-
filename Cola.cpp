#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void insertarCola(Nodo *&,Nodo *&,int);
bool cola_vacia(Nodo *);
void eliminarCola(Nodo *&,Nodo *&,int &);

int main(){
	
	Nodo *frente = NULL;
	Nodo *fin = NULL;
	
	int dato;
	char ptr;
	
	//Cargando nodo
	do{
	cout<<"Digite un numero: ";
	cin>>dato;
	insertarCola(frente,fin,dato);
	
	cout<<"Desea ingresar otro Nodo? precionar 'S'";
	cin>>ptr;
	}while((ptr == 's')||(ptr == 'S'));
	
	//Eliminando nodo
	cout<<"\nQuitando los nodos de la cola: ";
	while(frente != NULL){
		eliminarCola(frente,fin,dato);
		
		if(frente != NULL){
			cout<<dato<<" , ";
		}else{
			cout<<dato<<" .FIN";
		}
	}
	
	getch();
	return 0;
}

//Agregar un nodo a la cola
void insertarCola(Nodo *&frente,Nodo *&fin,int n){
	
	Nodo *nuevo_nodo= new Nodo();
	
	nuevo_nodo->dato=n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(frente)){
		frente = nuevo_nodo;
	}else{
		fin->siguiente = nuevo_nodo;
	}
	fin = nuevo_nodo;
	
	cout<<"Elemento "<<n<<" Insertado correctamente"<<endl;
}

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true:false;
}

//Eliminar un nodo a la cola

void eliminarCola(Nodo *&frente,Nodo *&fin,int &n){
	
	n = frente->dato;
	Nodo *aux = frente;
	
	if(frente == fin){//Significa que hay un solo elemento en la cola
		frente= NULL;//Asi que paso a frente y fin a apuntar a NULL
		fin=NULL;
	}else{//Si no significa que hay mas de un elemento en la cola
		frente=frente-> siguiente; //hago que frente apunte al nodo siguiente. fin ya estaria apuntando a el.
	}
	delete aux;
}
