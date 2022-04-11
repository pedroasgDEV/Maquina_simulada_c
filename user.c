// Modulos
#include "operations.h"
#include "user.h"

// Bibliotecas
#include <stdio.h>
#include <string.h>

//Funções
//Interpreta os comandos do usuario
void user_process(char command[], long int a, long int b, long int c ,long int** memoria_instrucoes, long int* memoria_dados){
    //TODO fazer as chamadas das operações conforme os comandos do usuario
}

//Faz a comunicação com o usuario
void user_comunication(long int** memoria_instrucoes, long int* memoria_dados){
    int numb; //Numero de comandos do usuario
    char command[20]; //Comando do usuario
    long int a, b, c; //Valores de entrada

    scanf("%d", &numb);

    for(int i = 0; i < numb; i++){
        scanf("%s %ld %ld %ld", command, &a, &b, &c); //Le o comando do usuario
        user_process(command, a, b, c, memoria_instrucoes, memoria_dados); //Interpreta o comando
    }
}

