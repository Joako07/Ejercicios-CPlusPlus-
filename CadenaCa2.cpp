#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main(){
	
	char cad1[30];
	int ca=0,ce=0,ci=0,co=0,cu=0;
	
	cout<<"Ingresar cadena de caracteres"<<endl;
	cin.getline(cad1,30,'\n');
	
	for(int i=0; i< strlen(cad1);i++){
		switch(cad1[i]){
			case 'a':ca++;break;
			case 'e':ce++;break;
			case 'i':ci++;break;
			case 'o':co++;break;
			case 'u':cu++;break;
			default:;
		}
	}
	
	cout<<"\n";
	cout<<cad1<<endl;
	cout<<"En esta cadena hay"<<endl; 
	cout<<"("<<ca<<")a"<<endl;
	cout<<"("<<ce<<")e"<<endl;
	cout<<"("<<ci<<")i"<<endl;
	cout<<"("<<co<<")o"<<endl;
	cout<<"("<<cu<<")u"<<endl;
	
	return 0;
}
