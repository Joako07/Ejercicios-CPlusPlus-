#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;	
	Nodo *padre;
};

void menu();
Nodo *crearNodo(int,Nodo *);
bool buscarUnNodo(Nodo *,int);
void insertarNodo(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol=NULL;

int main(){
	
	menu();
	
	return 0;
}

void menu(){
	
	int dato,opcion,contador = 0;
	
	do{
		cout<<"\t.:MENU:."<<endl;
		cout<<"1)Insertar un nuevo nodo"<<endl;
		cout<<"2)Mostrar arbol"<<endl;
		cout<<"3)Buscar un elemento en el arbol"<<endl;
		cout<<"4)Mostrar en Pre Orden"<<endl;
		cout<<"5)Mostrar en In-Orden"<<endl;
		cout<<"6)Mostrar en Post Orden"<<endl;
		cout<<"7)Eliminar un Nodo"<<endl;
		cout<<"8)Salir"<<endl;
		cout<<"Opcion: ";cin>>opcion;
		
		switch(opcion){
			case 1:cout<<"\nDigite un numero: ";cin>>dato;
					insertarNodo(arbol,dato,NULL);
					cout<<"\n";
					system("pause");
					break;
			case 2:cout<<"\nMostrando Arbol"<<endl;
					mostrarArbol(arbol,contador);
					cout<<"\n";
					system("pause");
					break;
			case 3:cout<<"\nDigite el elemento a buscar: ";cin>>dato;
					if(buscarUnNodo(arbol,dato) == true ){
						cout<<"\nElemento "<<dato<<" a sido encontrado"<<endl;
					}else{
						cout<<"\nElemento No encontrado\n";
					}
					cout<<"\n";
					system("pause");
					break;
			case 4:cout<<"\nRecorrido en Pre Orden: ";
					preOrden(arbol);
					cout<<"\n";
					system("pause");
					break;
			case 5:cout<<"\nRecorrido en In-Orden: ";
					inOrden(arbol);
					cout<<"\n";
					system("pause");
					break;
			case 6:cout<<"\nRecorrido en Post-Orden: ";
					postOrden(arbol);
					cout<<"\n";
					system("pause");
					break;
			case 7:cout<<"\nDigite el nodo que desea eliminar: ";cin>>dato;
					eliminar(arbol,dato);
					cout<<"\n";
					system("pause");
					break;
			case 8:break;
		}
		system("cls");
	}while(opcion != 8);
}

//Funcion para crear un Nodo
Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevoNodo = new Nodo();
	
	nuevoNodo->dato=n;
	nuevoNodo->der =NULL;
	nuevoNodo->izq=NULL;
	nuevoNodo->padre=padre;
	
	return nuevoNodo;
}

//Funcion para Insertar un Nodo en el arbol
void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
	if(arbol == NULL){//Si esta vacio
		Nodo *nuevoNodo = crearNodo(n,padre);
		arbol = nuevoNodo;
	}else{//Si no esta vacio
		int valorRaiz = arbol->dato;//Obtenemos el valor de la raiz
		if(n<valorRaiz){//Si el elemento es menor a raiz, lo insertamos a la izq
			insertarNodo(arbol->izq,n,arbol);
		}else{//Si el elemento es mayor a raiiz, lo insertamos a la der
			insertarNodo(arbol->der,n,arbol);
		}
	}
}

//Funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol==NULL){//Si el arbol esta vacio no muestro nada
		return;
	}else{//Si el arbol tiene algun nodo, arranco mostrando lo de la derecha
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){//Este for es solo para dar espacios entre c/nodo
			cout<<"    ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);//Muestro lo de la izquierda
	}
}

//Funcion para buscar un Nodo en el arbol
bool buscarUnNodo(Nodo *arbol,int n){
	if(arbol == NULL){//Si arbol esta vacio retorna false
		return false;
	}else if(arbol->dato == n){//Si el elemento que bscamos es igual al primer nodo
		return true;
	}else if(n < arbol->dato){//Si el elemento que buscamos es menor al primer nodo busca por la izq
		return buscarUnNodo(arbol->izq,n);
	}else{//Si el elemento que buscamos es mayor al primer nodo busca por la derecha
		return buscarUnNodo(arbol->der,n);
	}
}

//Funcion para mostrar los datos en pre-orden
//Muestra primero la raiz, despues el subarbol izq y despues el der
void preOrden(Nodo *arbol){
	if(arbol== NULL){
		return;
	}else{
		cout<<arbol->dato<<"-";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

//Funcion para mostrar los datos en in-orden
//Muestra primero el subarbol izq, luego la raiz y luego el subarbol der
void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<"-";
		inOrden(arbol->der);
	}
}

//Funcion para mostrar los datos en post-orden
//Muestra primero el subarbol izq, luego el subarbol der y la raiz
void postOrden(Nodo *arbol){
	if(arbol== NULL){
		return;
	}else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<"-";
	}
}

//Funcion para encontrar el nodo que queremos eliminar
void eliminar(Nodo *arbol,int n){
	if(arbol == NULL){
		return;
	}else if(n<arbol->dato) {
		eliminar(arbol->izq,n);
	}else if(n>arbol->dato){
		eliminar(arbol->der,n);
	}else{
		eliminarNodo(arbol);
	}
}

//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
	if(arbol->padre){
		//Hago que el padre apunte al siguiente nodo
		//para que no quede un hueco.
		if(arbol->dato==arbol->padre->izq->dato){
			arbol->padre->izq=nuevoNodo;
		}else if(arbol->dato==arbol->padre->der->dato){
			arbol->padre->der=nuevoNodo;
		}
	}
	//Hacemos que el siguiente nodo apunte a su nuevo padre
	if(nuevoNodo){
		nuevoNodo->padre=arbol->padre;
	}
}

//Funcion para determinar el nodo mas izq del que queremos eliminar
Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){
		return NULL;
	}if(arbol->izq){ // Si tiene hijo izq
		return minimo(arbol->izq);//Buscar la parte mas izq
	}else{//Si no tiene hijo izq
		return arbol;//retornamos el mismo nodo
	}
}

//Funcion para destruir el nodo que quede suelto
void destruirNodo(Nodo *nodo){
	//hacemos que se olvide de sus hijos y luego lo destruimos
	nodo->izq=NULL;
	nodo->der=NULL;
	delete nodo;
}

//Funcion para eliminar el nodo encontrado cuando tiene 2 hijos
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){//SI EL NODO TIENE UN HIJO IZQ Y UNO DER
		Nodo *menor=minimo(nodoEliminar->der);//Aplica la funcion minimo sobre el subarbderecho
		nodoEliminar->dato = menor->dato;//Remplaza el nodo que quiere eliminar por el mas izq
		eliminarNodo(menor);//Elimina el mas izq para que no quede repetido
	}
	else if(nodoEliminar->izq){//SI EL NODO TIENE SOLO UN HIJO IZQ
		reemplazar(nodoEliminar,nodoEliminar->izq);
		destruirNodo(nodoEliminar);//destruimos el nodo que queda suelto
	}
	else if(nodoEliminar->der){//SI EL NODO TIENE SOLO UN HIJO DER
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{//SI EL NODO NO TIENE HIJOS
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}
