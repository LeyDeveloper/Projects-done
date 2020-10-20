#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct no No; 

struct no {          
	int num;
	struct no *prox; 
};


No* inserir_no_fim(No* lista, int dado);
No* pesquisar(No*lista, int dado);
No* inserir_no_inicio(No* lista, int dado);
void imprimir_lista(No* lista);


int main(int argc, char** argv) {
	
	No *lista = NULL;                     
	lista = inserir_no_inicio(lista,10);
	lista = inserir_no_inicio(lista,20);
	lista = inserir_no_fim(lista,30);
	imprimir_lista(lista);
	
	return 0;
}



No* inserir_no_inicio(No* lista, int dado){ 
	No *novo_no = (No*)malloc(sizeof(No));   	         
	novo_no->num = dado;                 
	 
	if(lista == NULL){                   
		lista = novo_no;                 
		novo_no->prox = NULL;            
	}else{								 
		novo_no->prox = lista;           
		lista = novo_no;                 
	}
	
	return lista;                         
}


void imprimir_lista(No* lista){
	No *aux = lista;
	if (aux != NULL){
		cout<<"\nNumero: "<<aux->num;
		imprimir_lista(aux->prox);
	}
}

/*void imprimir_lista(No* lista){          
	No *aux = lista;                     
	
	while(aux != NULL){                  
		cout<<"\n"<<aux->num;            
		aux = aux->prox;                 
	}                                    
}*/

No* pesquisar(No* lista, int dado){
	No *aux = lista;
	int flag = 0;
	while(aux != NULL){
		if(aux->num == dado){
			flag = 1;
			cout<<"\nEncontrei o valor: "<<aux->num;
			aux = aux->prox;
		}else{
			aux = aux->prox;
		}
	}
	if(flag == 0){
		cout<<"\nSinto muito, nao encontrei o valor: ";
	}
}

No* inserir_no_fim(No* lista, int dado){
	No *novo_no = (No*)malloc(sizeof(No)); 
	novo_no->num = dado;
	No *aux = lista;
	
	if(lista == NULL){
		novo_no->prox=NULL;
		lista = novo_no;
		
	}else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		novo_no->prox = NULL;
		aux->prox = novo_no;		
	}
	
	return lista;
}



