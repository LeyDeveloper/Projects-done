#include "iostream"
using namespace std;
const int MAX=10;

struct pilha{
 	int topo;
 	int memo[MAX];
};

void push(pilha &P, int x);
int pop(pilha &P);
void transformaBi(pilha &P, int num, int &resto);

int main() {  						
 	pilha P;
 	int num,resto;
 	P.topo=-1;
 	
 	
 	cout<<"Entre com o numero = "; 	
 	cin>>num;
 		if(num==0){
 		 do{
   			cout<<"\nEntre com outro numero = ";
   			cin>>num;
  		}while(num==0);
  		
 		 transformaBi(P,num,resto);
 		}
 		else{
  			transformaBi(P,num,resto);
 			cout<<"\n"<<endl;
 	
 			system ("pause");
				 return 0;
		}

}

void push(pilha &P, int x){
	 P.topo++;
	 P.memo[P.topo]=x;
}


int pop(pilha &P){
	 int aux=P.memo[P.topo];
 	P.topo--;
 	return aux;
}


void transformaBi(pilha &P, int num, int &resto){
	while(num!=0){				
 		resto=num%2; 			
  		push(P,resto);			
  		num=num/2;				
 	}
 	
	 cout<<"\n";		
	 
	 
 	while(P.topo!=-1){
  		num=pop(P);
  		cout<<num;
 }
}
