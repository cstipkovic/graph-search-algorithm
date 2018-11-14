#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define NONE  -1
#define BRANCO 0
#define CINZA  1
#define PRETO  2

#include<conio.h>
#include<process.h>

struct q_point
{
  int ele;
  struct q_point* n;
};
 
struct q_point *f_ptr = NULL;
int e_que(void);
void ENQUEUE(int);
int DEQUEUE(void);
void show_ele();



typedef struct aresta{
	int nome;
	struct aresta *prox;
}Aresta;

typedef struct vert{
	int nome, cor, d;
	Aresta *prim;
}Vertice;


void imprimeGrafo(Vertice G[], int ordem);
void criaGrafo(Vertice **G, int ordem);
int  acrescentaAresta(Vertice G[], int ordem, int v1, int v2, int orientado);
int  calculaTamanho(Vertice G[], int ordem);
int isConexo(Vertice G[], int ordem);

void criaGrafo(Vertice **G, int ordem){
	int i;
	*G= (Vertice*) malloc(sizeof(Vertice)*ordem);
	
	for(i=0; i<ordem; i++){
		(*G)[i].nome= i;
		(*G)[i].prim= NULL;
		(*G)[i].cor = NONE;
	}
}

int acrescentaAresta(Vertice G[], int ordem, int v1, int v2, int orientado){
	if (v1<0 || v1 >= ordem)
	   return 0;
	if (v2<0 || v2 >= ordem)
	   return 0;
	
	Aresta *A1= (Aresta *) malloc(sizeof(Aresta));
	A1->nome= v2;
	A1->prox= G[v1].prim;
	G[v1].prim= A1;
   if (orientado == 0) {
   	Aresta *A2= (Aresta *) malloc(sizeof(Aresta));
	A2->nome= v1;
	A2->prox= G[v2].prim;
	G[v2].prim= A2;
   }
	
}


int  calculaTamanho(Vertice G[], int ordem){
	int i;
	int totalArestas=0;
	
	for (i=0; i<ordem; i++){
		int j;
		Aresta *aux= G[i].prim;
		for(j=0; aux != NULL; aux= aux->prox, j++);
		totalArestas += j;	
	}
	return totalArestas/2 + ordem;
}

void imprimeGrafo(Vertice G[], int ordem){
	int i;

	printf("\nOrdem:   %d",ordem);
	printf("\nTamanho: %d",calculaTamanho(G, ordem));
	printf("\nLista de Adjacencia:\n");

	for (i=0; i<ordem; i++){
		printf("\n    V%d: ", i);
		Aresta *aux= G[i].prim;
		for( ; aux != NULL; aux= aux->prox)
			printf("%3d", aux->nome);
	}
	printf("\n\n");
}

void isArvore(Vertice G[], int ordem) {
	if (isConexo(G, ordem)) {
		if ((calculaTamanho(G, ordem) - ordem) == (ordem - 1)) {
			printf("Grafo eh uma arvore!\n");
		} else {
			printf("Esse Grafo nao eh uma arvore!\n");
		}
	} else {
		printf("Esse Grafo nao eh uma arvore!\n");
	}
}

int isConexo(Vertice G[], int ordem) {
	int i;

	for (i = 0; i < ordem; i++) {
		Aresta *aux = G[i].prim;
		if (aux == NULL) {
			return 0;
		}
	}

	return 1;
}

void BFS(Vertice G[], int ordem, int vertice_inicio){
	int i;
	Vertice *H;
	criaGrafo(&H, ordem);
	for (i=0; i<ordem; i++){
		G[i].cor = BRANCO;
		//printf("\n    V%d: ", i);
		Aresta *aux= G[i].prim;
		for( ; aux != NULL; aux= aux->prox)
		;//	printf("%3d", aux->nome);
	}
	i = 0;
	H[i].cor = CINZA;
	H[i].d = 0;
	ENQUEUE(H[i].nome);
	while (e_que()!=1)
	   G[i].nome = 
	  
}

/* Function to check if the queue is empty*/
int e_que(void)
{
  if(f_ptr==NULL)
     return 1;
     
  return 0;
}
/* Function to add an element to the queue*/
void ENQUEUE(int ele)
{
  struct q_point *queue = (struct q_point*)malloc(sizeof(struct q_point));
  queue->ele = ele;
  queue->n = NULL;
  if(f_ptr==NULL)
    f_ptr = queue;
  else
  {
    struct q_point* ptr;
    ptr = f_ptr;
    for(ptr=f_ptr ;ptr->n!=NULL; ptr=ptr->n);
      ptr->n = queue;
  }
}
 
/* Function to remove an element from the queue*/
int DEQUEUE()
{
  struct q_point* queue=NULL;
  if(e_que()==false)
  {
    int j = f_ptr->ele;
    queue=f_ptr;
    f_ptr = f_ptr->n;
    free (queue);
    return j;
  }
  else
  {
    printf("\n\tQueue is empty.");
    return -9999;
  }
}
/* Function to display the queue*/
void show_ele()
{
  struct q_point *ptr=NULL;
  ptr=f_ptr;
  if(e_que())
  {
    printf("\n\tQUEUE is Empty.");
    return;
  }
  else
  {
    printf("\n\tElements present in Queue are:\n\t");
    while(ptr!=NULL)
    {
      printf("%d\t",ptr->ele);
      ptr=ptr->n;
    }
  }
}




int main(int argc, char *argv[]) {
	Vertice *G;
	int ordemG = 6, i, v1, v2, orientado;
    char escolha;
		
	criaGrafo(&G, ordemG);
	acrescentaAresta(G,ordemG,1,2,0);
	acrescentaAresta(G,ordemG,2,3,0);
	acrescentaAresta(G,ordemG,3,4,0);
	acrescentaAresta(G,ordemG,4,5,0);
	acrescentaAresta(G,ordemG,5,1,0);
	acrescentaAresta(G,ordemG,2,5,0);
	acrescentaAresta(G,ordemG,2,4,0);
	imprimeGrafo(G, ordemG);
	
	ordemG = 7;
	criaGrafo(&G, ordemG);
	acrescentaAresta(G,ordemG,1,2,1);
	acrescentaAresta(G,ordemG,1,4,1);
	acrescentaAresta(G,ordemG,2,5,1);
	acrescentaAresta(G,ordemG,3,5,1);
	acrescentaAresta(G,ordemG,3,6,1);
	acrescentaAresta(G,ordemG,4,2,1);
	acrescentaAresta(G,ordemG,5,4,1);
	acrescentaAresta(G,ordemG,6,6,1);
	imprimeGrafo(G, ordemG);
	
	
	
		do {
	    printf("\n\nEntre com o numero de vertices do grafo: ");
	    scanf("%d",&ordemG);
	    criaGrafo(&G, ordemG);
	    for (i=0;i<ordemG;i++) {
		  do {
		     printf("\nEntre com o 1o. vertice da %da. aresta: ",(i+1));	
		     scanf ("%d",&v1);
		     printf("\nEntre com o 2o. vertice da %da. aresta: ",(i+1));	
		     scanf ("%d",&v2);	
			 printf ("\nVertice eh orientado? (1 para SIM ou 0 para NAO)");
			 scanf ("%d",&orientado);	   	
		  } while(v1<0 || v2<0 || v1>ordemG || v2>ordemG);
	      acrescentaAresta(G, ordemG, v1, v2, orientado);
	    }  
	   imprimeGrafo(G, ordemG);
	   isArvore(G, ordemG);    
		
	   printf("\nTecle zero para sair ou qualquer tecla para continuar: ");
	   fflush(stdin);
	   scanf("%c",&escolha);	
	} while (escolha!='0');

	imprimeGrafo(G, ordemG);
    system("PAUSE");
	return 0;
}

