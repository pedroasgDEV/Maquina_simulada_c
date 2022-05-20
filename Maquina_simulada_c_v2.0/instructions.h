#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

//Modulos
#include "address.h"

//Bibliotecas
#include <stdlib.h>

//TAD de dados de uma instrução
typedef struct instructions{
    TAddress end1;
    TAddress end2;
    TAddress end3;
    int opcode;
}TInst;

//Funçôes da TAD
TInst *NewInstructions(int n_inst); //Aloca um vetor de instruções
void FreeInstructions(TInst **inst); //Libera um vetor de instruções

#endif