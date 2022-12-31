#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	
	int num,sum =0, fact = 1;
	
	cout<<"Ingrese un numero: ";cin>>num;
	
	for(int i=1;i<=num;i++){
		fact*= i;
		sum += fact;
	}

    cout<<"\nEl factorial es: "<<fact<<endl;
	cout<<"\nLa suma es: "<<sum<<endl;
	
	return 0;
}
