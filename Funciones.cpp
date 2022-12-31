#include <iostream>
#include <stdlib.h>


using namespace std;

int expo(int,int);

int main(){
	
	cout<<expo()<<endl;
	
	return 0;
}

int expo(int ini,int fin){
	int num=0;

	if(ini== fin){
		num=ini;
		cout<<num;
	}else{
		num = num + expo(ini,fin-1);	
	}
	return num;
}

