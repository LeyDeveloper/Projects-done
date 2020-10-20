#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;

int Fibbo(int num);


int main(int argc, char** argv) {
	int num, i,*v;
	
	cout<<"escreva um numero: ";
	cin>>num;
	cout<<"\ncriei um vetor com o mesmo numero de posicoes que o digitado.";
	
	v = (int *)malloc(num * sizeof(int));
	
	for(i=0; i<num; i++){
		v[i] = Fibbo(i + 1);
		cout<<" "<<v[i];
	}
	
	return 0;
}


int Fibbo(int num){
	
	if(num == 1 || num == 2){
		return 1;
	}else{
		return Fibbo(num-1) + Fibbo(num-2);
	}
}
