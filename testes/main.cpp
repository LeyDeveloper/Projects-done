#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;

struct tipo_lista{
	int cod;
	struct tipo_lista *prox;	
};

struct tipo_lista *primeiro;
struct tipo_lista *ultimo;


void FLVazia();
int insere(int x);
void imprime();
void pesquisa(int x);




int main(int argc, char** argv) {
	char op = '2';
	int i, codigo;
	
	FLVazia();
	
	while(op != '0'){
		cout<<"Entre com o codigo: ";
		cin>>codigo;
		insere(codigo);
		cout<<"\n\n\nContinuar como cadastro? 1 = sim 0 = nao: \n\n";
		op = getch();
	}
	
	imprime();
	cout<<"\n\nEntre com um item para pesquisa: ";
	cin>> codigo;
	pesquisa(codigo);
	getch();

	cout<<"\n\nItem a ser removido: ";
	cin>>codigo;
	remove(codigo);
	getch();
	return 0;
}




void FLVazia(){
	struct tipo_lista *aux;
	
	aux = (struct tipo_lista*)malloc(sizeof(struct tipo_lista));
	primeiro = aux;
	ultimo = primeiro;
}

int insere(int x){
	struct tipo_lista *aux;
	
	aux = (struct tipo_lista*)malloc(sizeof(struct tipo_lista));
	aux->cod = x;
	ultimo->prox = aux;
	ultimo = ultimo->prox;
	aux->prox = NULL;
}

void imprime(){
	struct tipo_lista *aux;
	
	aux = primeiro->prox;
	while(aux != NULL){
		cout<<"\nitem: "<< aux->cod;
		aux = aux->prox;
	}
}

void pesquisa(int x){
	struct tipo_lista *aux;
	int flag = 0;
	
	aux = primeiro->prox;
	while(aux != NULL){
		if(aux->cod == x){
			cout<<"Achei o item: "<<x;
			flag = 1;
			aux = NULL;
		}else{
			aux = aux->prox;
		}
		
	}
		
	if(!flag){
		cout<<"Item não encontrado na lista!!";
	}
		
	
		
	
	
}
	
void remove(int x){
	struct tipo_lista *aux;
	struct tipo_lista *sentinela;
	int flag = 0;
	
	aux = primeiro->prox;
	sentinela = primeiro;
	while(aux != NULL){
		if(aux->cod == x){
			cout<<"Removem o item: "<<x;
			sentinela->prox = aux->prox;
			aux = NULL;
			flag = 1;
		}else{
			aux = aux->prox;
			sentinela = sentinela->prox;
		}
		
	}
		
	if(flag==0){
		cout<<"Item não encontrado na lista!!";
	}
	
}




