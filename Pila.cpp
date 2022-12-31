#include <iostream>
#include <stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void agregarPila(Nodo *&,int);
void sacarPila(Nodo *&,int &);

int main(){
	
	Nodo *pila= NULL;
	int data,cant;
	
	cout<<"Ingresar cantidad de nodos de la pila "<<endl;
	cin>>cant;
	
	for(int i=0;i<cant;i++){
	cout<<"Digite un numero: ";
	cin>>data;
	agregarPila(pila,data);
	}
	
	cout<<"\Sacando los elementos"<<endl;
	while(pila != NULL){
		sacarPila(pila,data);
		if(pila != NULL){
			cout<<data<<" , ";
		}else{
			cout<<data<<" . FIN";
		}
	}
	
}

void agregarPila(Nodo *&pila,int n){
	
	Nodo *nuevoNodo = new Nodo();
	nuevoNodo->dato= n;
	nuevoNodo->siguiente=pila;
	pila=nuevoNodo;
	
	cout<<"\nElemento "<<n<<" Cargado a la Pila"<<endl;
	cout<<"\n";
}

void sacarPila(Nodo *&pila,int &n){
	
	Nodo *aux= pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

