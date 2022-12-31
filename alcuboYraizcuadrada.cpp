#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	int num,num2;
	float RaizCub,RaizCuadra,pot2,pot3,pot32;
	
	cout<<"Ingrese un numero: "<<endl;
	cin>>num;
	
	cout<<"Seleccione una opcion del menu"<<endl;
	cout<<"\t1)R3,R2,P2,P3,P32 de "<<num<<endl;
	cout<<"\t2)"<<num<<" Es par o impar"<<endl;
	cout<<"\t3)Salir"<<endl; 
	
	cin>>num2;	
	       
	
	switch (num2){
		case 1:
			pot2=pow(num,2);
			pot3=pow(num,3);
			pot32=pow(num,32);
			RaizCub=cbrt(num);
			RaizCuadra=sqrt(num);
		
			
			cout<<"Los calculos de "<<num<<" son "<<pot2
			    <<"--"<<pot3
			    <<"--"<<pot32<<"--"<<RaizCub
			    <<"--"<<RaizCuadra<<endl;break;
			
		case 2:
			if(num % 2 == 0){
				cout<<num<<" Es un número par";
			}else{
				cout<<num<<" Es un número impar";break;
			}
		case 3:	break;
		
	}
	
	return 0;
}
