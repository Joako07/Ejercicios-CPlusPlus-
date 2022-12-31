#include <iostream>
#include <stdlib.h>
#define ALM 5
#define NOT 3

using namespace std;

//Declaro los arreglos
int total=0,coun=0,i,j,alumnos[ALM][NOT];

//Prototipo de Funciones
void alumAprobAll(int alumn[][NOT],int n1);
void alumAprobOne(int alumn[][NOT],int n1);
void alumAprobLast(int alumn[][NOT],int n1);


//Codifico Funciones

//Alumnos que aprobaron todo
void alumAprobAll(int alumn[][NOT],int n1){
	
	for(i=0;i<ALM;i++){
		for(j=0;j<NOT;j++){
			if(alumn[i][j]>=7){
				coun++;
			}
		}
		if(coun == 3){
			total++;
		}
	coun = 0;
	}
    cout<<"\nAlumnos que aprobaron todos los examenes: "<<total<<endl;
    total=0;
}

//Alumnos que aprobaron por lo menos una
void alumAprobOne(int alumn[][NOT],int n1){
	
	for(i=0;i<ALM;i++){
		for(j=0;j<NOT;j++){
			if(alumn[i][j]>=7){
				coun++;
			}
		}
		if(coun>0 && coun<=2){
			total++;
		}
	coun=0;
	}
	cout<<"\nAlumnos que aprobaron al menos un examen: "<<total<<endl;
	total=0;
}

//Alumnos que aprobaron solo el ultimo
void alumAprobLast(int alumn[][NOT],int n1){
	
	for(i=0;i<ALM;i++){
		for(j=0;j<NOT;j++){
			if(alumn[i][j]>=7){
				coun++;
			}
		}
		if(coun == 1 && alumn[i][2] >=7){
			 total++;	
		}
	coun = 0;
	}	
	cout<<"\nAlumnos que aprobaron unicamente el ultimo examen "<<total<<endl;
	total=0;
}


int main(){
	
	int num,e=1,n=1;
	
	//Cargo las notas
	
	for(i=0;i<ALM;i++){
		for(j=0;j<NOT;j++){
			volver:;
			cout<<"Ingresar nota ("<<n<<") del alumno ("<<e<<")--->";cin>>num;
			if(num>0 && num<11){
			alumnos[i][j]=num;
		   }else{
		   	cout<<"\nLa nota ingresada debe ser entre 0 y 10"<<endl;
		   	goto volver;//Para volver al punto de ingresar nota
		   }
		   n++;
		}
		e++;
		n=1;
	}
	
	//LLamo las funciones
	
	alumAprobAll(alumnos,ALM);
	alumAprobOne(alumnos,ALM);
	alumAprobLast(alumnos,ALM);
	
	system("pause");
	return 0;
}
