//Modulos
#include "instructions.h"

//Aloca um vetor de instruções
TInst *NewInstructions(int n_inst){
    TInst *aux = (TInst*) malloc(n_inst * sizeof(TInst));
    return aux; 
}

//Libera um vetor de instruções
void FreeInstructions(TInst **inst){
    free(*inst);
    *inst = NULL;
}