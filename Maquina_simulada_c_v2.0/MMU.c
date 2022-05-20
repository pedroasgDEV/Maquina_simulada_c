//Modulos
#include "MMU.h"

//Procura o bloco na memoria
TCell *MemorySearch(int end_block, TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3){

    //Olha primeiro na cache 1
    TCell *aux = cache1->top;
    int custo = 10;
    
    //Procura na cache 1
    while (aux != NULL){
        if(aux->block.end_bloco == end_block){break;}
        aux = aux->after;
    }

    //Se tiver encontrado na cache 1
    if(aux != NULL){

        //Tirar a celula da cache 1
        GetCell(cache1, aux);

        aux->block.custo += custo;
        aux->block.cacheHit = 1;

        //leva para o começo da cache1
        ToCache1(aux, ram, cache1, cache2, cache3);

        return aux;
    }

    else{

        //Olha na cache 2
        aux = cache2->top;
        custo += 110;

        //Procura na cache 2
        while (aux != NULL){
            if(aux->block.end_bloco == end_block){break;}
            aux = aux->after;
        }

        //Se tiver encontrado na cache 2
        if(aux != NULL){

            //Tirar a celula da cache 2
            GetCell(cache2, aux);

            aux->block.custo += custo;
            aux->block.cacheHit = 2;

            //leva para o começo da cache 1
            ToCache1(aux, ram, cache1, cache2, cache3);

            return aux;
        }

        else{
            //Olha na cache 3
            aux = cache3->top;
            custo += 1110;

            //Procura na cache 3
            while (aux != NULL){
                if(aux->block.end_bloco == end_block){break;}
                aux = aux->after;
            }

            //Se tiver encontrado na cache 3
            if(aux != NULL){

                //Tirar a celula da cache 3
                GetCell(cache3, aux);

                aux->block.custo += custo;
                aux->block.cacheHit = 3;

                //leva para o começo da cache 2
                ToCache2(aux, ram, cache2, cache3);

                 //Tirar a celula da cache 2
                GetCell(cache2, aux);

                //leva para o começo da cache 1
                ToCache1(aux, ram, cache1, cache2, cache3);

                return aux;
            }

            else{
                custo += 11110; 

                //Pega o endereço da memoria
                aux = NewCell(ram[end_block]);

                aux->block.custo += custo;
                aux->block.cacheHit = 4; 
                
                //leva para o começo da cache 3
                ToCache3(aux, ram, cache3);

                //Tirar a celula da cache 3
                GetCell(cache3, aux);

                //leva para o começo da cache 2
                ToCache2(aux, ram, cache2, cache3);

                //Tirar a celula da cache 2
                GetCell(cache2, aux);

                //leva para o começo da cache 1
                ToCache1(aux, ram, cache1, cache2, cache3);

                return aux;
            }

        }

    }
    
}


//Leva celula para o topo da cache 3
void ToCache3(TCell *cell, TMemBlock *ram, TRow *cache3){

    //Se conseguir levar a celula para o topo da cache 3
    if(PushRow(cache3, cell));

    //Se a cache 3 estive cheia
    else{
        TMemBlock lixo;
        TCell *aux = NewCell(lixo);
        aux->block = cell->block;
        
        //Tira a ultima celula da cache 3
        PopRow(cache3, aux);
        
        //Libera a celula
        FreeCell(&aux);

        //Leva a celula para o topo da cache 3
        PushRow(cache3, cell);
    }
}

//Leva celula para o topo da cache 2
void ToCache2(TCell *cell, TMemBlock *ram, TRow *cache2, TRow *cache3){
    //Se conseguir levar a celula para o topo da cache 2
    if(PushRow(cache2, cell));

    //Se a cache 2 estive cheia
    else{
        TMemBlock lixo;
        TCell *aux = NewCell(lixo);
        aux->block = cell->block;
        
        //Tira a ultima celula da cache 2
        PopRow(cache2, aux);

        //Leva para o topo da cache 3
        ToCache3(aux, ram, cache3);

        //Leva a celula para o topo da cache 2
        PushRow(cache2, cell);
    }
}

//Leva celula para o topo da cache 1
void ToCache1(TCell *cell, TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3){

    //Se conseguir levar a celula para o topo da cache 1
    if(PushRow(cache1, cell));

    //Se a cache 1 estive cheia
    else{
        TMemBlock lixo;
        TCell *aux = NewCell(lixo);
        aux->block = cell->block;
        
        //Tira a ultima celula da cache 1
        PopRow(cache1, aux);
        
        //Leva para o topo da cache 2
        ToCache2(aux, ram, cache2, cache3);

        //Leva a celula para o topo da cache 1
        PushRow(cache1, cell);
    }
}


