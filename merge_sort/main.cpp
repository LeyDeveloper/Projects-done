#include <iostream>
#include <math.h>
#include <malloc.h>
using namespace std;
int merge(int *v, int inicio, int meio, int fim);
int main(int argc, char** argv) {
	
	return 0;
}

int mergeSort(int *v, int inicio, int fim){
	int meio;
	if(inicio < fim){
		meio = floor((fim+inicio) / 2);
		mergeSort(v, inicio, meio);
		mergeSort(v, meio+1, fim);
		merge(v, inicio, meio, fim);
	}
	
}

int merge(int *v, int inicio, int meio, int fim){
	int *temp, p1, p2, tamanho, i, j ,k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim-inicio+1;
	p1 = inicio;
	p2 = meio+1;
	temp = (int*)malloc(tamanho*sizeof(int));
	if(temp != NULL){
		for(i=0;i<tamanho;i++){
			if(!fim1 && !fim2){
				if(v[p1] < v[p2]){
					temp[i] = v[p1++];
				}else{
					temp[i] = v[p2++];
				}
				
				if(p1 > meio){
					fim1 = 1;
				}
				
				if(p2 > fim){
					fim2 = 1;
				}
			}else{
				
				if(!fim1){
					temp[i] = v[p1++];
				}
				
				if(!fim2){
					temp[i] = v[p2++];
				}
			}
		}
		
		for(j=0, k=inicio ; j<tamanho ; j++, k++){
			v[k] = temp[j];
		}
	}
	
	free(temp);
}

