//Bibliotecas
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//Modulos
#include "core.h"
#include "instructions.h"
#include "memoryblock.h"
#include "address.h"
#include "blockrow.h"

//Constantes
#define tam_ram 1000 //Tamanho da ram
#define tam_cache1 8 //Tamanho da cache 1
#define tam_cache2 16 //Tamanho da cache 2
#define tam_cache3 32 //Tamanho da cache 3
#define qnt_wrds 4 //Quantidade de palavras
#define qnt_instr 10001 //Quantidade de instruções

int main(){
    //Semente
    srand(time(NULL));

    //Pega o tempo inicial
    clock_t begin = clock();

    //Cria e aloca os vetores
    TMemBlock *ram = NewMemBlock(tam_ram, qnt_wrds);
    TRow cache1 = NewRow(tam_cache1);
    TRow cache2 = NewRow(tam_cache2);
    TRow cache3 = NewRow(tam_cache3);
    TInst *inst = NewInstructions(qnt_instr);


    //Monta a ram
    montar_ram(ram, tam_ram, qnt_wrds);

    //Montar instruções
    read_inst(inst, qnt_instr);

    //Roda a maquina
    machine(ram, &cache1, &cache2, &cache3, inst);
    
    //Libera os vetores
    FreeMemBLock(&ram, tam_ram);
    FreeRow(&cache1);
    FreeRow(&cache2);
    FreeRow(&cache3);
    FreeInstructions(&inst);

    //Pega o tempo final
    clock_t end = clock();

    //Calcula o tempo de exec
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time: %.2lf\n", time_spent);

    return 0;
}