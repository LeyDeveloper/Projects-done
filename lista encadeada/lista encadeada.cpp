#include <stdio.h>
#include <stdlib.h>
	

	//Estrutura base do nó.
	struct no
	{
	    int chave;
	    struct no *pont;
	};
	 
	 
	//Função pra printar o nó na tela.
	void mostralista(struct no *p)
	{
	    printf("Mostrando a lista encadeada:\n"); 
	    if(p)
	    {
	        do
	        {
	            printf(" %d", p->chave);
	            p=p->pont;
	        }
	        while(p);
	    }
	    else
	        printf("Lista vazia.");
	        
	    printf("\n\n");
        system("pause");    
	}
	 
	 
	 
	int main(void)
	{
	    struct no *pNo1 = NULL;
	    struct no *pNo2 = NULL;
	    struct no *pNo3 = NULL;
	     
	    //Criando os nos e associando os dados.
	    pNo1 = (struct no*) malloc(sizeof(struct no*));
	    pNo1->chave = 10;
	     
	    pNo2 = (struct no*) malloc(sizeof(struct no*));
	    pNo2->chave = 20;
	     
	    pNo3 = (struct no*) malloc(sizeof(struct no*));
	    pNo3->chave = 30;
	     
	    //Conectando os nós
	    pNo1->pont = pNo2;
	    pNo2->pont = pNo3;  
	    pNo3->pont = NULL;
	     
	    //Mostrando a lista.
	    if(pNo1)  
	        mostralista(pNo1);
	  
	  return 0;
	}
