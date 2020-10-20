#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string veiculo="carro";
	string *pv;
	
	
	pv = &veiculo;
	
	cout<<*pv<<"\n"<<pv<<"\n"<<&veiculo;
	
	*pv="moto";
	
	cout<<"\n"<<veiculo<<"\n"<< *pv;
	return 0;
}
