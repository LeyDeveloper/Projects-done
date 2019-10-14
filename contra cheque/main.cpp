#include <iostream>
#include <string>

using namespace std;

struct funcionario{	
	char nome[50], cargo[50], mat[15] ;
	int horas, diasfaltas, horaextra, faltas ;
	float valhoras, salB, salL, valdeIR, INSS,TA, VT, aliinss, totalfaltas, dep;
	float IR, horax;
};

funcionario f[5];
int i;

void cadastroFunc();
float calcSalB(int &h, float &vh);
float calcINSS(float &sb);
float calcImpostoRenda(float &sb, float &inss);
float calcHoraExtra(float &vh, int &he);
float calcVT(float &sb);
float calcTicketAlimentacao(float &sb);
float faltas(float &sb);





int main(){
	
	
	
	for(i=0;i<4;i++){

	cadastroFunc();

	
	
		
		
	f[i].salB = calcSalB(f[i].horas, f[i].valhoras);
	f[i].INSS = calcINSS(f[i].salB);
	f[i].VT = calcVT(f[i].salB);
	f[i].IR = calcImpostoRenda(f[i].salB, f[i].INSS);
	f[i].TA = calcTicketAlimentacao(f[i].salB);
	f[i].IR = calcImpostoRenda(f[i].salB, f[i].INSS);
	f[i].horax = calcHoraExtra(f[i].valhoras, f[i].horaextra);
	f[i].totalfaltas = faltas(f[i].salB) * f[i].diasfaltas;
	f[i].salL = ((((((f[i].salB - f[i].INSS) - f[i].IR) - f[i].VT) - f[i].TA) + f[i].horaextra) - f[i].totalfaltas);
	
	
	cout<<"*************************************************************************"<<endl;
	cout<<"*************************** Folha de pagamento***************************"<<endl;
	cout<<"*************************************************************************"<<endl;
	cout<<"Nome do funcionario: "<<f[i].nome<<endl;
	cout<<"Matricula: "<<f[i].mat<<endl;
	cout<<"cargo do funcionario: "<<f[i].cargo<<endl;
	cout<<"INSS: "<<f[i].INSS<<endl;
	cout<<"imposto de renda: "<<f[i].IR<<endl;
	cout<<"Vale Transporte: "<<f[i].VT<<endl;
	cout<<"Ticket alimentacao: "<<f[i].TA<<endl;
	cout<<"Horas extras: "<<f[i].horax<<endl;
	cout<<"Faltas: "<<f[i].diasfaltas<<endl;
	cout<<"Salario bruto: "<<f[i].salB<<" --- Salario Liquido: "<<f[i].salL<<endl;
	
	
	}

		
		
		
	
	
	
	
	
	

	
	
	return 0;

}

void cadastroFunc(){
	cout<<"\n************************************************************************";
	cout<<"\n************************ Cadastro de funcionario ***********************";
	cout<<"\n************************************************************************\n";
	
	cout<<"Digite o nome do funcionario ";
	cin.getline(f[i].nome,50);
	cout<<"Digite a matricula do funcionario: ";
	cin.getline(f[i].mat, 15);
	cout<<"Digite o cargo do funcionario: ";
	cin.getline(f[i].cargo,50);	
	cout<<"Digite o total de horas trabalhadas: ";
	cin>>f[i].horas;
	cout<<"Digite o valor das horas de cada funcionario: ";
	cin>>f[i].valhoras;
	cout<<"Digite a quantidade de faltas do usuario: ";
	cin>>f[i].diasfaltas;
	cout<<"hora extra: ";
	cin>> f[i].horaextra;
	cin.get();
}


float calcSalB(int &h, float &vh){
	return h * vh;
}

float calcINSS(float &sb){
	if(sb<=1659.38){
		return sb * 8 / 100;		
		
	}else if(sb>1659.39 && sb<=2765.66){
		
		return sb * 9 / 100;	
		
	}else{
		return sb * 11 / 100;
		
	}
}

float calcImpostoRenda(float &sb, float &inss){
	float ircal, ir;
	if(sb<=1903.98){
		return 0;
		
	}else if(sb>=1903.99 && sb<=2826.65){
		ircal = sb-inss;
		ir = (ircal * 7.5/100) - 142.8;
		return ir;
	}else if(sb>=2826.66 && sb<=3751.05){
		ircal = sb-inss;
		ir = (ircal * 15/100)- 354.8;
		return ir;
	}else if(sb>=3751.06 && sb<=4664.68){
		ircal = sb-inss;
		ir = (ircal * 25.5/100)- 636.13;
		return ir;
	}else if(sb>4664.68){
		ircal = sb-inss;
		ir = (ircal * 27.5/100) - 869.36;
		return ir;
	}
	
	return ir;
}



float calcHoraExtra(float &vh, int &he){
	if(he==0){
		return vh*0;
	}else{
		return vh * 50 / 100;
	}
}

float calcVT(float &sb){
	return sb * 6 / 100;
}

float calcTicketAlimentacao(float &sb){
	return sb * 10 / 100;
}

float faltas(float &sb){
	return sb / 30 ;
}








