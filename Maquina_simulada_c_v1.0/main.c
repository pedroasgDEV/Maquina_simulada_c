//Bibliotecas
#include <time.h>
#include <stdlib.h>

//Modulos
#include "core.h"
#include "user.h"

int main(int argc, char *argv[]){
    //Semente
    srand(time(NULL));

    //Variaveis
    long int** memoria_instrucoes;
    long int* memoria_dados;

    memoria_dados = montar_ram();
    memoria_instrucoes = montar_instrucoes();


    user_comunication(memoria_instrucoes, memoria_dados);

    //Libera a memoria alocada
    for(int i = 0; i < n_instr; i++)
        free(memoria_instrucoes[i]);
    free(memoria_instrucoes);
    free(memoria_dados);
    return 0;
}