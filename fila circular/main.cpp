#include <iostream>
#include <cstring>
#include <cctype>
#define MAX 5

using namespace std;

//definindo struct

struct queue{
	float circular[MAX];
	int total,inicio,final;
};

void entra(queue &fil);
void deleta(queue &fil);
void lista(queue &fil);


//programa principal
int main() {
	
	queue fila;
	int x;
	char resp[40], s;
	fila.inicio=0;
	fila.total=0;
	fila.final=0;
	
	for(x=0;x<=5;x++){
		cout<<"\n***************";
		cout<<"\n *I-Inserir *";
		cout<<"\n *L-Listar *";
		cout<<"\n *R-Remover *";
		cout<<"\n *S-Sair *";
		cout<<"\n **************\n";
		cin.getline(resp,40);
		s=toupper(resp[0]);
		
		
			switch(s){
				case 'I': entra(fila);
					cin.get();
					break;
				
				case 'L': lista(fila);
					break;
					
				case 'R': deleta(fila);
					break;
					
				case 'S': system("pause");
				exit(0);
			}
			
			cout<<"\n\n";
			system("pause");
			
	}

	
	
	return 0;
}

void entra(queue &fil){
	int valor;
	if(fil.total==MAX){
		cout<<"\nATENCAO. Fila Cheia\n";
	}else{
		cout<<"\nDigite valor: ";
		cin>>valor;
		fil.circular[fil.final]=valor;
		fil.final++;
		fil.total++;
		
		if(fil.final==MAX){
			fil.final=0;
			fil.total++;
		}
	}
}

void deleta(queue &fil){
	if(fil.total==0){
		cout<<"\nATENCAO. Fila Vazia\n";
	}else{
		cout<<"\nRemovido: "<<fil.circular[fil.inicio]<<"\n\n";
		fil.inicio++;
		if(fil.inicio==MAX){
			fil.inicio=0;
			fil.total--;
		}
	}
}

void lista(queue &fil){
	if(fil.total==0){
		cout<<"\nATENCAO. Fila Vazia\n";
	}else if(fil.total==MAX){
		cout<<"\nATENCAO. Fila Cheia\n";
	}else{
		cout<<"\nElementos presentes na fila: "<<fil.total<<"\n";
		cout<<"\nEspacos vazios na fila: "<<MAX - fil.total<<"\n";
	}
}




