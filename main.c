#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "TAD/Hash.h"

#define M 8 // tamanho do meu vetor

int main(){
  Hash hash;
  
  inicializa(&hash, M);

  insere(&hash, 24);
  insere(&hash, 19);
  insere(&hash, 27);
  insere(&hash, 103);
  insere(&hash, 173);
  insere(&hash, 174);
  printaDadosInseridos(&hash);
  
  printf("\n\nPESQUISA:\n\n");

  pesquisa(&hash, 23);
  pesquisa(&hash, 27);
  pesquisa(&hash, 174);
  pesquisa(&hash, 175);

  return 0;
}