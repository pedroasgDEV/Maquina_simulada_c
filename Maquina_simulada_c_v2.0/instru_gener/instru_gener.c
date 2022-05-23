//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define qtd_inst 10001 //Quantidade de instruções
#define qtd_for 5 //Numero de intruções que vão se repetir
#define qtd_wrds 4 //Quantidade de palavras
#define tam_ram 1000 //Tamanho da ram
#define prob 90 //Probabilidade de repetição em %

int main(){
    srand(time(NULL));

    //Abre o arquivo
    FILE *arquivo = fopen("instructions.txt", "w");

    //Variaveis
    int inst[qtd_inst][7];
    int rep[qtd_for][7];
    int aux;
    
    //Gera as instruções que vão se repetir
    for(int i = 0; i < qtd_for; i++){
        rep[i][0] = rand() % 3;
        for(int j = 1; j < 7; j++){
            rep[i][j] = rand() % tam_ram;
            rep[i][++j] = rand() % qtd_wrds;
        }
    }

    for(int i = 0; i < qtd_inst;){
        aux = (rand() % 100) + 1;
        if(aux <= prob && i + qtd_for < qtd_inst){
            for(int j = 0; j < qtd_for; j++){
                for(int k = 0; k < 7; k++)
                    inst[i + j][k] = rep[j][k];
            }
            i += qtd_for;
        }
        else{
            inst[i][0] = rand() % 3;
            for(int j = 1; j < 7; j++){
                inst[i][j] = rand() % tam_ram;
                inst[i][++j] = rand() % qtd_wrds;
            }
            i++;
        } 
    }

    inst[qtd_inst - 1][0] = -1; 

    for(int i = 0; i < qtd_inst; i++){
        for(int j = 0; j < 6; j++)
            fprintf(arquivo, "%d ", inst[i][j]);
        fprintf(arquivo, "%d\n", inst[i][6]);
    }


    fclose(arquivo);

    return 0;
}