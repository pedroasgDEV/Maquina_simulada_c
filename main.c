//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Modulos
#include "core.h"

//TODO criar modulo das operações matematicas e fazer as operações de soma e subrtação

int main(int argc, char *argv[]){
    //Semente
    srand(time(NULL));

    //Variaveis
    int** memoria_instrucoes;
    int* memoria_dados;

    memoria_dados = montar_ram();
    memoria_instrucoes = montar_instrucoes();

    machine(memoria_instrucoes, &memoria_dados);

    //Libera a memoria alocada
    for(int i = 0; i < n_instr; i++)
        free(memoria_instrucoes[i]);
    free(memoria_instrucoes);
    free(memoria_dados);
    return 0;
}