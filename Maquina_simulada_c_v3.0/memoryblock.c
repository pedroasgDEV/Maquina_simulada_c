//Modulos
#include "memoryblock.h"

//Cria um vetor de blocos de memoria
TMemBlock *NewMemBlock(int n_blocks, int qtd_wrds){
    TMemBlock *aux = (TMemBlock*) malloc(n_blocks * sizeof(TMemBlock)); //Aloca o vetor de TADS
    
    //Preenche a TAD
    for(int i = 0; i < n_blocks; i++){
        aux[i].words = (int*) malloc(qtd_wrds * sizeof(int));
        aux[i].end_bloco = -1;
        aux[i].custo = 0;
        aux[i].cacheHit = 0;
    }

    return aux;
}

//Libera um vetor de blocos de memoria
void FreeMemBLock(TMemBlock **blocks, int tam_vet){
    for(int i = 0; i < tam_vet; i++){ free((*blocks)[i].words); (*blocks)[i].words = NULL;}
    free(*blocks);
    *blocks = NULL;
}