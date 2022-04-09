#ifndef CORE_H
#define CORE_H

//Define
#define n_ram 1024
#define n_instr 100

//Funçôes
int* montar_ram(); //Aloca e preenche a memoria ram com lixo
int** montar_instrucoes(); //Aloca e preenche a memoria de instruções com lixo
int** compilar(int** memoria_instrucoes); //Compila o codigo
void machine(int** memoria_instrucoes, int** memoria_dados); //Roda a maquina
void interprets_machine(int** memoria_dados, int** instrucao); //Maquina que vai interpretar a instrução

#endif



