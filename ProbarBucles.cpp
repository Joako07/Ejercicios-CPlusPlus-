#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main(){
	
	int num,aleat,count=0;
	
	srand(time(NULL));//Cambia el valo semilla, para q no de siempre los mismos numeros
	aleat = rand()%(5); // Guarada el numero aleatorio entre 1 y 5 en aleat
	// Si arranca desde el 1 pones solamente hasta donde va.
	//Si no pones (desde-hasta)+desde;
	//Ej un numero aleatorio entre el 5 y el 10 :
	//rand()%(5-10)+5;
	
	do{
		cout<<"Digite un numero para adivinar---->";cin>>num;
		
		if(num<aleat){
			cout<<"\nDigite un numero Mayor"<<endl;
		}
		if(num>aleat){
			cout<<"\nDigite un numero Menor"<<endl;
		}	
		
	count ++;
	
	}while(num != aleat);
	
	cout<<"\nFelicitaciones Adivinaste\n\tEl numero es "<<num<<endl;
	cout<<"Adivinaste en "<<count<<" Intentos"<<endl;
	
	system("pause");
	return 0;
}
