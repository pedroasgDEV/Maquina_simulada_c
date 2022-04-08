//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Modulos

//Define
#define ram 1000
#define n_instr 100

//Funçôes
int* montar_ram();
int** montar_instrucoes();

int* montar_ram(){
    //Alocando dinamicamente
    int* dados = (int*) malloc(ram * sizeof(int));

    //Preenchendo com lixo
    for(int i = 0; i < ram; i++)
        dados[i] = rand() % n_instr;

    return dados;
}

int** montar_instrucoes(){
    //Alocando dinamicamente
    int** instr = (int**) malloc(n_instr * sizeof(int*));

    //Preenchendo com lixo
    for(int i = 0; i < n_instr; i++){
        instr[i] = (int*) malloc(4 * sizeof(int));

        //Halt
        if(i == (n_instr - 1)){
            instr[i][0] = -1;
            instr[i][1] = -1;
            instr[i][2] = -1;
            instr[i][3] = -1;
            continue;
        }

        instr[i][0] = rand() % 3;
        instr[i][1] = rand() % ram;
        instr[i][2] = rand() % ram;
        instr[i][3] = rand() % ram;
    }

    return instr;

}

int main(int argc, char *argv[]){
    //Semente
    srand(time(NULL));

    //Variaveis
    int** memoria_instrucoes;
    int* memoria_dados;

    memoria_dados = montar_ram();
    memoria_instrucoes = montar_instrucoes();

    for(int i = 0; i < n_instr; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", memoria_instrucoes[i][j]);
        }
        printf("\n");
    }

    //for(int i = 0; i < ram; i++)
    //    printf("%d\n", memoria_dados[i]);

    
    //Libera a memoria alocada
    for(int i = 0; i < n_instr; i++){
        free(memoria_instrucoes[i]);
    }
    free(memoria_instrucoes);
    free(memoria_dados);
    return 0;
}