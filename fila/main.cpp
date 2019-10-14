#include <iostream>
#define TAM 5
using namespace std;

struct queue{
	float f[TAM];
	int inicio,fim;
};

void enfileira(queue &fil);
void desenfileira(queue &fil);
void elemPrimeiro(queue &fil);
void situacaoFila(queue &fil);

int main() {
	char resp[10];
	int op;
	
	queue fila;
	fila.inicio=0;
	fila.fim=-1;
	
	do{
		cout<<"\nFila(FIFO - First In - First Out )\n\n";
		cout<<"\n1-Inserir um valor na fila";
		cout<<"\n2-Remover um valor da fila";
		cout<<"\n3-Mostrar o elemento inicial da fila";
		cout<<"\n4-Mostrar situacao da fila";
		cout<<"\n5-Sair";
		cout<<"\nOpcao desejada: ";
		cin>>op;
		
		
		switch(op){
			case 1 : enfileira(fila);
				break;
			
			case 2 : desenfileira(fila);
				break;
				
			case 3 : elemPrimeiro(fila);
				break;
				
			case 4 : situacaoFila(fila);
				break;
				
			case 5 : cout<<"\nPrograma basico da FILA\n";
				break;
				
			default: cout<<"\nOPCAO INVALIDA\n";		
		}
		
		cout<<"\n\n";
		system("pause");
		
	}while(op!=5);
	
	return 0;
}

void enfileira(queue &fil){
	float valor;
	
	if(fil.fim == TAM-1){
		cout<<"\nATENCAO. Fila Cheia.";	
	}else{
		cout<<"Digite o valor a ser enfileirado: ";
		cin>>valor;
		fil.fim++;
		fil.f[fil.fim] = valor;
	}
}

void desenfileira(queue &fil){
	if(fil.inicio > fil.fim){
		cout<<"\nATENCAO. Fila Vazia\n";
	}else{
		cout<<"\nValor Removido: "<<fil.f[fil.inicio];
		fil.inicio++;
	}
}

void elemPrimeiro(queue &fil){
	if(fil.inicio > fil.fim){
		cout<<"\nATENCAO. Fila Vazia\n";
	}else{
		cout<<"\nElementio do Inicio da fila: "<<fil.f[fil.inicio];
	}
}

void situacaoFila(queue &fil){
	int x;
	if (fil.inicio > fil.fim){
		cout<<"\nATENCAO.Fila Vazia\n";
	}else{
		cout<<"\nTotal de elementos na fila: "<<fil.fim-(fil.inicio+1)<<"\n";
		cout<<"\n\nEspaco disponivel na fila: "<<TAM-(fil.fim + 1)<<"\n";
		cout<<"\n\nPosicao do primeiro elemento da fila: "<<fil.inicio<<"\n";
		cout<<"\n\nPosicao do ultimo elemento da fila: "<< fil.fim<<"\n";
		cout<<"\nValor\tposicao do vetor\n";
		for(x=fil.inicio;x<=fil.fim;x++){
			cout<<"\n"<<fil.f[x]<<"\t"<<x;
		}
	}
}
