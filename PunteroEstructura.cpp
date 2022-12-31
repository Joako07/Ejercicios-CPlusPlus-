#include <iostream>


using namespace std;

int pos;

struct Alumno{
	char nombre[30];
	int edad;
	float promedio;	 
}per[3], *pPer= per;

void pedirDatos();
void may(Alumno *);
void mostr(Alumno *);

int main(){
	
	pedirDatos();
	may(pPer);
	mostr(pPer);
	
	return 0;
}

void pedirDatos(){
	
	for(int i=0;i<3;i++){
	fflush(stdin);
	cout<<"Ingresar Nombre del alumno "<<i+1<<endl;
	cin.getline((pPer+i)->nombre,30,'\n');
	cout<<"Ingresar edad de "<<(pPer+i)->nombre<<": ";
	cin>>(pPer+i)->edad;
	cout<<"Ingresar Promedio de "<<(pPer+i)->nombre<<": ";
	cin>>(pPer+i)->promedio;
	cout<<"\n";
 	}
		
}

void may(Alumno *p){
	
	float prom = 0.0;
	
	for(int i=0;i<3;i++){
		if((p+i)->promedio > prom){
			prom = (p+i)->promedio;
			pos=i;
		}
	}
}

void mostr(Alumno *a){
	
	cout<<"\n\n";
	cout<<"El alumno de mayor promedio es: "<<endl;
	cout<<"Nombre: "<<(a+pos)->nombre<<endl;
	cout<<"Edad: "<<(a+pos)->edad<<endl;
	cout<<"Promedio: "<<(a+pos)->promedio<<endl;
}
