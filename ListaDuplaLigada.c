#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct no {
    int dados;
    char nome [30];
    struct no *anterior;
    struct no *proximo;
}noptr;

//=====================================================================

void insere_ordenado(noptr **inifunc, noptr *novo, int valor)
{
    noptr *p, *ant;


    novo->dados=valor;
    printf("\n Digite um nome a ser pesquisado: ");
    setbuf(stdin, NULL);
    fgets(novo->nome,29,stdin);
    novo->anterior=NULL;

    if(*inifunc==NULL){
       novo->proximo = NULL;
       *inifunc=novo;
       return;
    }

    p=*inifunc;

    while(p != NULL && p->dados <= valor){
       ant = p;
       p=p->proximo;
    }

    if (p == *inifunc)
    {
      novo->proximo=*inifunc;
      (*inifunc)->anterior=novo;
      *inifunc=novo;
    }
    else{
    ant->proximo = novo;
    novo->anterior = ant;
    novo->proximo = p;
    if (p)
      p->anterior = novo;
    }

}
//====================================================================

void remove_inicio(noptr **inifunc)
{
    noptr *p;

    if(*inifunc==NULL)
    {
       printf("\nLista Vazia!!!");
       return;
    }
    else
    {
       p=*inifunc;
       printf("\nValor Removido: %d",p->dados);
       *inifunc=p->proximo;
       (*inifunc)->anterior=NULL;
       free(p);
    }
}
//====================================================================

void lista_todos(noptr *inifunc)
{
  if(inifunc==NULL)
  {
     printf("\nLista Vazia!!!");
     return;
  }
  noptr *p;
  p = inifunc;
  while(p)
  {
      printf("\nSaida: %d", p->dados);
      p = p->proximo;
  }
  printf("\n");
}

//==================================================================
void busca_altera(noptr **inifunc,char aux [])
{

  if(*inifunc==NULL)
  {
     printf("\nLista Vazia!!!");
     return;
  }
  noptr *p;
  p = *inifunc;

  while(strcmp(p->nome,aux) != 0)
  {
      p = p->proximo;
  }

  printf("\n Digite o novo valor: "); scanf("%d",&p->dados);
  //p->dados = aux;

}
//====================================================================

void main()
{
  int recebe=1;
  char aux [30];

  noptr *inicio;
  inicio=NULL;
  noptr *info;

  while(recebe!=0){
    info=(struct no *) malloc(sizeof(noptr));
     if(!info){
       printf("\nSem Memoria!!!");
       return;
     }
     printf("Digite um valor: ");
     scanf("%d",&recebe);
     if(recebe!=0)
       insere_ordenado(&inicio,info,recebe);
  }
  lista_todos(inicio);
  printf("\n Digite um nome a ser pesquisado: ");
  //scanf("%d",&aux);
  setbuf(stdin, NULL);
  fgets(aux,29,stdin);
  busca_altera(&inicio,aux);
  //remove_lista(&inicio);
  lista_todos(inicio);
}
//====================================================================
