// struct do item que será armazenado na tabela Hash
typedef struct{
  int codigo;
}Item;

typedef struct{
  Item *vetor;
  int M; // onde M é o tamanho do vetor
}Hash;

void inicializa(Hash* hash, int M);

void rehash(Hash* hash, int h1, int M, int codigo);

void insere(Hash* hash, int codigo);

void printaDadosInseridos(Hash* hash);

void pesquisa(Hash* hash, int codigo);


