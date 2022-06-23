#ifndef BLOCKROW_H
#define BLOCKROW_H

//Modulos
#include "memoryblock.h"

//Bibliotecas
#include <stdlib.h>

typedef struct cell{
    struct cell *after, *before; //Celula seguinte e Celula anterior
    TMemBlock block; //Bloco da celula
}TCell;


//TAD de dados de uma instrução
typedef struct row{
    int tam; //Tamanho atual da fila
    int tam_full; //Tamanho maximo da fila
    TCell *top, *bottom; //Topo e fundo da fila
}TRow;

//Funções da celula
TCell *NewCell(TMemBlock block); //Cria uma celula
void FreeCell(TCell **cell); //Libera uma celula

//Funçôes da fila
TRow NewRow(int tam); //Inicia uma fila de blocos
int EmptyRow(TRow *row); //Verifica se a fila esta vazia
int PushRow(TRow *row, TCell *cell); //Adiciona uma celula no começo da fila
int PopRow(TRow *row, TCell *cell); //Remove uma celula do fim fila
void FreeRow(TRow *row); //Esvazia uma fila
void GetCell(TRow *row, TCell *cell); //Tira uma celula da fila

#endif