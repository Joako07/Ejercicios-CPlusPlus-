#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <fstream>//Libreria para manicuar archivos

using namespace std;

void escribir();
void lectura();
void aniadir();

int main(){
	
	int opc;
	
	
	do{
		cout<<".:MENU:."<<endl;
		cout<<"1)Escribir"<<endl;
		cout<<"2)Lectura"<<endl;
		cout<<"3)Aniadir"<<endl;
		cout<<"4)Salir"<<endl;
		cout<<"Opcion: ";cin>>opc;
		
		switch(opc){
			case 1: escribir();
					break;
			case 2:	lectura();
					system("pause");
					break;
			case 3: aniadir();
					system("pause");
					break;
			case 4: break;
		}
		system("cls");
	}while(opc != 4);

	system("pause");
	return 0;
}

void escribir(){
	char opc;
	ofstream nameArchivo; //para escribir en un archivo;ofstream() de la libreria fstream
	string name,texto;
	
	fflush(stdin);
	cout<<"Dele un nombre al archivo: "<<endl;
	getline(cin,name);
	
	nameArchivo.open(name.c_str(),ios::out);//Abrimos el archivo. Si no existe lo crea
	
	if(nameArchivo.fail()){//el fail()Funciona como un asert Si el archivo no se puede abrir o crear
		cout<<"No se puede abrir el archivo";
		exit(1);
	}
	
	//nameArchivo<<"Hola que tal?";//Escribir en el archivo directamente
	
	//Para pedirle al usuario que escriba lo que quiera
	do{
		fflush(stdin);
		cout<<"\nEscriba el contenido del archivo"<<endl;
		getline(cin,texto);
		nameArchivo<<texto<<"\n";
	
		cout<<"\nSi Desea ingresar otra frase precione s/S"<<endl;
		cin>>opc;
			
	}while((opc == 's')||(opc == 'S'));
	
	nameArchivo.close();//Cerramos el archivo	
}

void lectura(){
	ifstream nameArchivo;//Para leer un archivo ifstream() de la libreria fstream
	string name,texto;
	
	fflush(stdin);
	cout<<"Escribe el nombre del archivo que deseas abrir"<<endl;
	getline(cin,name);
	system("cls");
	
	nameArchivo.open(name.c_str(),ios::in);//Abrimos un archivo ya creado en modo LECTURA
	
	if(nameArchivo.fail()){
		cout<<"No se pudo abrir";
		exit(1);
	}
	
	while(!nameArchivo.eof()){//Mientras no sea el final del archivo-
								//eof() pertenece a la libreria fstream y te rrecorre todo el archivo
		getline(nameArchivo,texto);	//Copia todo lo que encuentra en el archivo dentro de la variable texto
		cout<<texto<<endl;//Imprimo el texto
	}
	nameArchivo.close();
}

void aniadir(){
	ofstream nameArchivo;
	string name,texto;
	char rpt;
	
	fflush(stdin);
	cout<<"Escribe el nombre del archivo en el que deseas agregar texto"<<endl;
	getline(cin,name);
	system("cls");
	
	nameArchivo.open(name.c_str(),ios::app);//Abrimos el archivo en modo ANIADIR
	
	if(nameArchivo.fail()){
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	
	do{
		fflush(stdin);
		cout<<"\Digite el texto que desea añiadir"<<endl;
		getline(cin,texto);
		nameArchivo<<texto<<"\n";
		
		cout<<"Si desea ingresar mas texto precione  s/S"<<endl;
		cin>>rpt;
		
	}while((rpt=='s')||(rpt=='S'));
	
}
