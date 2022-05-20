//Modulos
#include "core.h"

//Bibliotecas
#include <stdlib.h>

//Aloca e preenche a memoria ram com lixo
long int* montar_ram(){
    //Alocando dinamicamente
    long int* dados = (long int*) malloc(n_ram * sizeof(long int));

    //Preenchendo com lixo
    for(long int i = 0; i < n_ram; i++)
        dados[i] = rand() % (n_instr + 1);

    return dados;
}

//Aloca e preenche a memoria de instruções com lixo
long int** montar_instrucoes(){
    //Alocando dinamicamente
    long int** instr = (long int**) malloc(n_instr * sizeof(long int*));

    //Preenchendo com lixo
    for(long int i = 0; i < n_instr; i++){
        instr[i] = (long int*) malloc(4 * sizeof(long int));

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

//Maquina que vai long interpretar a instrução
void interprets_machine(long int** memoria_dados, long int** instrucao){
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
void machine(long int*** memoria_instrucoes, long int** memoria_dados){
    //Aloca as instruções dinamicamente
    long int* instrucao = (long int*) malloc(4 * sizeof(long int));

    //Compila as instruções
    for(long int i = 0; (*memoria_instrucoes)[i][0] != -1; i++){
        instrucao = (*memoria_instrucoes)[i];
        interprets_machine(memoria_dados, &instrucao);
        (*memoria_instrucoes)[i] = instrucao;
    }
}