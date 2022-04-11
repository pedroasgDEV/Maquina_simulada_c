#ifndef USER_H
#define USER_H
//Funções
void user_comunication(long int** memoria_instrucoes, long int* memoria_dados); //Faz a comunicação com o usuario
void user_process(char command[], long int a, long int b, long int c ,long int** memoria_instrucoes, long int* memoria_dados); //Interpreta os comandos do usuario

#endif