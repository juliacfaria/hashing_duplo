#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void inicializa(Hash* hash, int M){
  (*hash).vetor = (Item*)malloc(M*sizeof(Item));
  (*hash).M = M;


  // inicialização com valores pré-definidos é necessária
  int i;
  for(i=0;i<M;i++){
   (*hash).vetor[i].codigo = -1;
  }
}

void rehash(Hash* hash, int h1, int M, int codigo){
  printf("h1: %d\n", h1);

  int h2 = 1 + (codigo%(M-1));
  printf("h2: %d\n", h2);

  int qtd = 0;
  int re_hash;

  while(qtd<M){
    re_hash = (h1+((qtd+1)*h2))%M;
    printf("RH: %d\n", re_hash);

    if((*hash).vetor[re_hash].codigo == -1){
      (*hash).vetor[re_hash].codigo = codigo;
      printf("re_hash: %d Codigo: %d\n", re_hash, (*hash).vetor[re_hash].codigo);     
      return;
    }
    qtd++;
  }

  printf("Tabela cheia!\n");
}


void insere(Hash* hash, int codigo){
  int M = (*hash).M;
  int h1 = codigo % M;

  if((*hash).vetor[h1].codigo == -1){
    (*hash).vetor[h1].codigo = codigo;
    printf("Indice que inseriu: %d\n", h1);
  }else{
    rehash(hash, h1, M, codigo);
  }
}

void printaDadosInseridos(Hash* hash){
  int i, tamanho =(*hash).M;
  printf("\n\nDados\n");
  for(i=0;i<tamanho;i++){
    printf("Cod: %d\n", hash->vetor[i].codigo);
  }
}

void pesquisa(Hash* hash, int codigo){
  int M = (*hash).M;

  int h1 = codigo % M;

  if((*hash).vetor[h1].codigo == codigo){
    printf("%d encontrado no indice %d\n\n", codigo, h1);
    return;
  }

  printf("h1: %d\n", h1);

  int h2 = 1 + (codigo%(M-1));
  printf("h2: %d\n", h2);

  int qtd = 0;
  int re_hash;

  while(qtd<M){
    re_hash = (h1+((qtd+1)*h2))%M;
    printf("RH: %d\n", re_hash);

    if((*hash).vetor[re_hash].codigo == codigo){
      printf("%d encontrado no indice %d\n\n", codigo, re_hash);     
      return;
    }
    qtd++;
  }

  printf("%d não encontrado!\n\n", codigo);
}
