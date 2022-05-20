#ifndef MMU_H
#define MMU_H

//Modulos
#include "core.h"

//Funções
TCell *MemorySearch(int end_block, TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3); //Procura o bloco na memoria
void ToCache1(TCell *cell, TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3); //Leva celula para o topo da cache 1
void ToCache2(TCell *cell, TMemBlock *ram, TRow *cache2, TRow *cache3); //Leva celula para o topo da cache 2
void ToCache3(TCell *cell, TMemBlock *ram, TRow *cache3); //Leva celula para o topo da cache 3

#endif