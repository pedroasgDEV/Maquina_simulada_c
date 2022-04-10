// Modulos
#include "operations.h"
#include "core.h"

// Bibliotecas
#include <stdio.h>

// Funções]
// Soma
int soma(int a, int b, int **memoria_instrucoes, int *memoria_dados){
    int ram_position = 0; // Posição da memoria

    // Leva o primeiro numero para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = a;
    memoria_instrucoes[0][2] = ram_position;
    ram_position++;

    // Leva o segundo numero para a memoria
    memoria_instrucoes[1][0] = 2;
    memoria_instrucoes[1][1] = b;
    memoria_instrucoes[1][2] = ram_position;
    ram_position++;

    // Faz a soma dos numeros
    memoria_instrucoes[2][0] = 0;
    memoria_instrucoes[2][1] = ram_position - 2;
    memoria_instrucoes[2][2] = ram_position - 1;
    memoria_instrucoes[2][3] = ram_position;

    // Traz o valor da soma
    memoria_instrucoes[3][0] = 3;
    memoria_instrucoes[3][1] = ram_position;

    // Encerra a execução
    memoria_instrucoes[4][0] = -1;

    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[3][2];
}

// Subtração
int sub(int a, int b, int **memoria_instrucoes, int *memoria_dados){
    int ram_position = 0; // Posição da memoria

    // Leva o primeiro numero para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = a;
    memoria_instrucoes[0][2] = ram_position;
    ram_position++;

    // Leva o segundo numero para a memoria
    memoria_instrucoes[1][0] = 2;
    memoria_instrucoes[1][1] = b;
    memoria_instrucoes[1][2] = ram_position;
    ram_position++;

    // Faz a soma dos numeros
    memoria_instrucoes[2][0] = 1;
    memoria_instrucoes[2][1] = ram_position - 2;
    memoria_instrucoes[2][2] = ram_position - 1;
    memoria_instrucoes[2][3] = ram_position;

    // Traz o valor da soma
    memoria_instrucoes[3][0] = 3;
    memoria_instrucoes[3][1] = ram_position;

    // Encerra a execução
    memoria_instrucoes[4][0] = -1;

    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[3][2];
}

// Multiplicação
int multi(int a, int b, int** memoria_instrucoes, int* memoria_dados){
    int c;

    if(b < 0){c = -b;} //Se o multiplicador for negativo
    else{c = b;} //Se o multiplicador for positivo

    //Leva o primeiro numero para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = 0;
    memoria_instrucoes[0][2] = 0;

    for(int i = 0; i < c; i++){
        memoria_instrucoes[0][1] = soma(memoria_instrucoes[0][1], a, memoria_instrucoes, memoria_dados);
    } 

    //Traz o valor final da
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    machine(&memoria_instrucoes, &memoria_dados);

    if(b < 0){return -memoria_instrucoes[1][2];} //Se o multiplicador for negativo
    else{return memoria_instrucoes[1][2];} //Se o multiplicador for positivo
}


//! - Precisa concertar o erro dessa função
//Divisão
int divi(int a, int b, int** memoria_instrucoes, int* memoria_dados){
    int c;

    if(b == 0){return 0;}

    if(b < 0){c = -b;} //Se o multiplicador for negativo
    else{c = b;} //Se o multiplicador for positivo

    //Leva o primeiro numero para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = a;
    memoria_instrucoes[0][2] = 0;

    for(int i = 0; memoria_instrucoes[0][1] >= 0; i++){
        memoria_instrucoes[0][1] -= sub(memoria_instrucoes[0][1], c, memoria_instrucoes, memoria_dados);
    } 

    //Traz o valor final da
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    machine(&memoria_instrucoes, &memoria_dados);

    if(b < 0){return -memoria_instrucoes[1][2];} //Se o multiplicador for negativo
    else{return memoria_instrucoes[1][2];} //Se o multiplicador for positivo
}