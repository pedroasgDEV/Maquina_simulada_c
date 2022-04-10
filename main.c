//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Modulos
#include "core.h"
#include "operations.h"

//TODO adicionar arquivo para interpretador

int main(int argc, char *argv[]){
    //Semente
    srand(time(NULL));

    //Variaveis
    int** memoria_instrucoes;
    int* memoria_dados;

    memoria_dados = montar_ram();
    memoria_instrucoes = montar_instrucoes();

    printf("%d * %d = %d\n", 27, 4, divi(12, 3, memoria_instrucoes, memoria_dados));

    //Libera a memoria alocada
    for(int i = 0; i < n_instr; i++)
        free(memoria_instrucoes[i]);
    free(memoria_instrucoes);
    free(memoria_dados);
    return 0;
}