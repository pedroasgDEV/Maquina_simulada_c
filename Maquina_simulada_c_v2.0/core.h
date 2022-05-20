#ifndef CORE_H
#define CORE_H

//Modulos
#include "instructions.h"
#include "memoryblock.h"
#include "address.h"
#include "blockrow.h"
#include "MMU.h"

//Bibliotecas
#include <stdlib.h>
#include <stdio.h>

//TAD de informações de uso da maquina
typedef struct machine{
    long int custo; //Custo de uso da maquina

    //Informações das caches
    long int missC1; //Qunatidade de miss na cache 1
    long int hitC1;  //Qunatidade de hit na cache 1
    long int missC2; //Qunatidade de miss na cache 2
    long int hitC2;  //Qunatidade de hit na cache 2
    long int missC3; //Qunatidade de miss na cache 3
    long int hitC3; //Qunatidade de hit na cache 3
}TMach;

//Função da TAD
TMach NewMachine(); //Gera uma nova maquina

//Funçôes
void read_inst(TInst *inst, int qnt_instr); //Guarda as instruções do arquivo txt no vetor
void montar_ram(TMemBlock *ram, int tam_ram, int qnt_wrds); //Preenche a memoria ram com lixo
void machine(TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3, TInst *instr); //Roda a maquina
void interprets_machine(TInst instr, TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3, TMach *mach); //Maquina que vai interpretar a instrução

#endif