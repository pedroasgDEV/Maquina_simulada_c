//Modulos
#include "core.h"

//Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Aloca e preenche a memoria ram com lixo
int* montar_ram(){
    //Alocando dinamicamente
    int* dados = (int*) malloc(n_ram * sizeof(int));

    //Preenchendo com lixo
    for(int i = 0; i < n_ram; i++)
        dados[i] = rand() % (n_instr + 1);

    return dados;
}

//Aloca e preenche a memoria de instruções com lixo
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

        instr[i][0] = rand() % 2;
        instr[i][1] = rand() % (n_ram + 1);
        instr[i][2] = rand() % (n_ram + 1);
        instr[i][3] = rand() % (n_ram + 1);
    }

    return instr;

}

//Maquina que vai interpretar a instrução
void interprets_machine(int** memoria_dados, int** instrucao){
    switch((*instrucao)[0]){
        //Soma
        case 0:
            (*memoria_dados)[(*instrucao)[3]] = (*memoria_dados)[(*instrucao)[1]] + (*memoria_dados)[(*instrucao)[2]];
            break;

        //Subtração
        case 1:
            (*memoria_dados)[(*instrucao)[3]] = (*memoria_dados)[(*instrucao)[1]] - (*memoria_dados)[(*instrucao)[2]];
            break;

        //Gravar na memoria ram
        case 2:
            (*memoria_dados)[(*instrucao)[2]] = (*instrucao)[1];
            break;

        //Pegar da memoria ram
        case 3:
            (*instrucao)[2] = (*memoria_dados)[(*instrucao)[1]];
            break;
    }
}

//Roda a maquina
void machine(int*** memoria_instrucoes, int** memoria_dados){
    //Aloca as instruções dinamicamente
    int* instrucao = (int*) malloc(4 * sizeof(int));

    //Compila as instruções
    for(int i = 0; (*memoria_instrucoes)[i][0] != -1; i++){
        instrucao = (*memoria_instrucoes)[i];
        interprets_machine(memoria_dados, &instrucao);
        (*memoria_instrucoes)[i] = instrucao;
    }
}