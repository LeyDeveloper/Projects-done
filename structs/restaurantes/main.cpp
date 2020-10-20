#include <iostream>
#include <string.h>
using namespace std;

struct restaurante {
	int peso;
	int tipo;
	int qtdsobremesa;
	int qtdbebida;
	float valorbebida;
	float valorcomida;
	float valorsobremesa;
	float valortotal;
};

restaurante pacman;

void entradaDeDados();
float calcularComida(int t, int p);
float calcularBebida(int b);
float calcularSobremesa(int s);

int main(int argc, char** argv) {
	
	entradaDeDados();
	
	pacman.valorcomida = calcularComida(pacman.tipo, pacman.peso);
	pacman.valorbebida = calcularBebida(pacman.qtdbebida);
	pacman.valorsobremesa = calcularSobremesa(pacman.qtdsobremesa);
	pacman.valortotal = pacman.valorcomida + pacman.valorbebida + pacman.valorsobremesa;
	
	
	
	cout<<endl<<endl;
	cout<<"O valor da comida e: "<<pacman.valorcomida<<endl;
	cout<<"O valor da bebida e: "<<pacman.valorbebida<<endl;
	cout<<"O valor da sobremesa e: "<<pacman.valorsobremesa<<endl;
	cout<<"O valor total e: "<<pacman.valortotal;
	
	
	return 0;
}

void entradaDeDados(){
	cout<<"**************************************************"<<endl;
	cout<<"Tipo da comida. 1- com churrasco, 2- sem churrasco: ";
	cin>>pacman.tipo;
	cout<<"Peso em KG: ";
	cin>>pacman.peso;
	cout<<"Quantidade de bebidas: ";
	cin>>pacman.qtdbebida;
	cout<<"Quantidade de sobremesa: ";
	cin>>pacman.qtdsobremesa;
	cin.get();
}

float calcularComida(int t, int p){
	if(t == 1){
		return p * 32.5;
		
	}else if(t == 2){
		return p * 22.5;
		
	}
}

float calcularBebida(int b){
	return b*4.5;
}

float calcularSobremesa(int s){
	return s*3.5;
}
