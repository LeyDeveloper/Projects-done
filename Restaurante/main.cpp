#include <iostream>
using namespace std;

struct data{
	int dia, mes, ano;
};


struct comecome{
	int tipo , sobremesa, bebida;
		float total, valcomida, valbebida, valsobremesa, mediapeso, peso ;
	data atual;
};



float calcComida(int t,float p);                
float calcBebida(int b);
float calcSobremesa(int s);




int main() {
	int i, qtdsob=0, qtdcomanda=0, mesref, anoref, type;
	float somatot=0, somap=0, somacom=0 , mediap ;
	comecome c[3];
	
	
	
	for(i=0;i<3;i++){
	cout<<"Tipo de comida: 1- com churrasco.  2-sem churrasco: ";
	cin>>c[i].tipo;
	cout<<"peso a kg: ";
	cin>>c[i].peso;
	cout<<"quantidade de bebida: ";
	cin>>c[i].bebida;
	cout<<"quantidade de sobremesa: ";
	cin>>c[i].sobremesa;
	cout<<"dia: ";
	cin>>c[i].atual.dia;
	cout<<"mes: ";
	cin>>c[i].atual.mes;
	cout<<"ano: ";
	cin>>c[i].atual.ano;
	
	
	
	c[i].valcomida = calcComida(c[i].tipo,c[i].peso);                    
	c[i].valbebida = calcBebida(c[i].bebida);
	c[i].valsobremesa = calcSobremesa(c[i].sobremesa);
	c[i].total = c[i].valcomida + c[i].valbebida + c[i].valsobremesa;
	
	
	
	cout<<"-----------------------------------------------------"<<endl;
	cout<<"valor gasto com comida: R$"<<c[i].valcomida<<endl;
	cout<<"valor gasto com bebida: R$"<<c[i].valbebida<<endl;
	cout<<"valor gasto com sobremesa: R$"<<c[i].valsobremesa<<endl;
	cout<<"Total da comanda: R$"<<c[i].total<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	
	
	qtdsob = qtdsob + c[i].sobremesa;
	somap = somap + c[i].peso;
	qtdcomanda = qtdcomanda + 1;
	mediap = somap / qtdcomanda;
	somatot = somatot + c[i].total;
	
	
}


cout<<"total arrecadado com as comandas: R$"<<somatot<<endl;
cout<<"media de peso consumido: "<<mediap<<endl;
cout<<"quantidade de sobremesa vendida: "<<qtdsob<<endl;
cout<<"------------------------------------------------"<<endl;
cout<<"------------------------------------------------"<<endl;


cout<<"deseja checar a arrecadação por mes e ano de referencia? sim-1, não-2 ";
cin>>type;
	if (type == 1){
		cout<<"digite o mes referencia: ";
		cin>>mesref;
		cout<<"digite o ano de referencia: ";
		cin>>anoref;
		for(i=0;i<3;i++){
	
	if(mesref == c[i].atual.mes && anoref == c[i].atual.ano){
		somacom = somacom + c[i].total;
	}
	
}

	
cout<<"------------------------------------------------"<<endl;
cout<<"soma total: "<<somacom<<endl;
	}else{
	}
		
	

	
	
	

	
	


	return 0;

}




float calcComida(int t,float p){
float valor;

	if(t==1){
		valor = 47.9 * p;
	}else if(t==2){
		valor = 38.9 * p;
	}
	return valor;
	
}




float calcBebida(int b){
	
	return b * 5.9;
}


float calcSobremesa(int s){
	
	return s * 7.5;
}

