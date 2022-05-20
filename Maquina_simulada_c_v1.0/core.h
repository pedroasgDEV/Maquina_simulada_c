#ifndef CORE_H
#define CORE_H

//Define
#define n_ram 1024
#define n_instr 100

//Funçôes
long int* montar_ram(); //Aloca e preenche a memoria ram com lixo
long int** montar_instrucoes(); //Aloca e preenche a memoria de instruções com lixo
void machine(long int*** memoria_instrucoes, long int** memoria_dados); //Roda a maquina
void interprets_machine(long int** memoria_dados, long int** instrucao); //Maquina que vai interpretar a instrução

#endif