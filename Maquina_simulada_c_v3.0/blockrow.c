//Modulos
#include "blockrow.h"

//Cria uma celula
TCell *NewCell(TMemBlock block){
    TCell *aux = (TCell*) malloc(sizeof(TCell));
    aux->after = NULL;
    aux->before = NULL;
    aux->block = block;
    return aux;
}

//Libera uma celula
void FreeCell(TCell **cell){
    (*cell)->after = NULL;
    (*cell)->before = NULL;
    free(*cell);
    *cell = NULL;
}

//Inicia uma fila de blocos
TRow NewRow(int tam){
    TRow aux;
    aux.top = NULL;
    aux.bottom = aux.top;
    aux.tam = 0;
    aux.tam_full = tam;
    return aux;
}

//Verifica se a fila esta vazia
int EmptyRow(TRow *row){
    //1 se estiver vazia
    //0 se não estiver vazia
    if(row->top == NULL) return 1;
    return 0;
}

int PushRow(TRow *row, TCell *cell){
    //1 se conseguiu adicionar a celula
    //0 se não consegiu adicionar a celula
    
    //Se a fila estiver cheia
    if(row->tam == row->tam_full) return 0;

    //Se a fila estiver vazia
    if(EmptyRow(row)){ 
        row->top = cell;
        row->bottom = cell;
        cell->after = NULL;
        cell->before = NULL;
    }

    //Se a fila não estiver vazia
    else{
        TCell *aux = row->top;
        aux->before = cell;
        cell->after = aux;
        row->top = cell;
        cell->before = NULL;
    }

    row->tam++;
    return 1;
}

//Remove uma celula do fim fila
int PopRow(TRow *row, TCell *cell){
    //1 se conseguiu remover a celula
    //0 se não consegiu remover a celula

    //Se a lista estiver vazia
    if(EmptyRow(row)) return 0;

    TCell *aux = row->bottom;

    //Se a fila tiver uma celula
    if(row->tam == 1){
        row->bottom = NULL;
        row->top = NULL;
    }

    //Se a fila tiver mais de uma celula
    else{ 
        row->bottom = aux->before;
        row->bottom->after = NULL;
    }

    cell = aux;

    row->tam--;
    return 1;
}

//Esvazia uma fila
void FreeRow(TRow *row){
    TCell *aux = NULL;
    while (PopRow(row, aux)){
        if(aux != NULL) FreeCell(&aux);
    }
}

 //Tira uma celula da fila
void GetCell(TRow *row, TCell *cell){

    //Se ele estiver no final
    if(cell->after == NULL && cell->before != NULL){
        row->bottom = cell->before;
        cell->before->after = NULL;
        cell->before = NULL;
    }

    //Se ele estiver no começo
    else if(cell->after != NULL && cell->before == NULL){
        row->top = cell->after;
        cell->after->before = NULL;
        cell->after = NULL;
    }

    //Se ele estiver no meio
    else if(cell->after != NULL && cell->before != NULL){
        cell->after->before = cell->before;
        cell->before->after = cell->after;
        cell->before = NULL;
        cell->after = NULL;
    }

    //Se ele estiver vazia
    else if(cell->after == NULL && cell->before == NULL){
        row->top = NULL;
        row->bottom = NULL;
    }
    
    row->tam--;
}