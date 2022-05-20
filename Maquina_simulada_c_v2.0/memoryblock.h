#ifndef MEMORYBLOCK_H
#define MEMORYBLOCK_H

//Bibliotecas
#include <stdlib.h>

//TAD de dados de um bloco de memoria
typedef struct memoryblock{
    int *words; //Quantidade de palavras no bloco
    int end_bloco; //Endereço do bloco
    int custo; //Preço de uso do bloco
    int cacheHit; //Quantas vezes foi encontrado
}TMemBlock;

//Funçôes da TAD
TMemBlock *NewMemBlock(int n_blocks, int qtd_wrds); //Cria um vetor de blocos de memoria
void FreeMemBLock(TMemBlock **blocks, int tam_vet); //Libera um vetor de blocos de memoria

#endif