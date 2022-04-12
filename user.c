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
    //Soma
    if(strcmp(command, "+") == 0)
        printf("%ld + %ld = %ld\n", a, b, soma(a, b, memoria_instrucoes, memoria_dados));
    

    //Subtração
    if(strcmp(command, "-") == 0)
        printf("%ld - %ld = %ld\n", a, b, sub(a, b, memoria_instrucoes, memoria_dados));
    

    //Multiplicação
    if(strcmp(command, "x") == 0)
        printf("%ld x %ld = %ld\n", a, b, multi(a, b, memoria_instrucoes, memoria_dados));
    

    //Divisão
    if(strcmp(command, "/") == 0)
        printf("%ld / %ld = %ld\n", a, b, divi(a, b, memoria_instrucoes, memoria_dados));
    

    //Potencia
    if(strcmp(command, "^") == 0)
        printf("%ld ^ %ld = %ld\n", a, b, pot(a, b, memoria_instrucoes, memoria_dados));

    
    //Raiz
    if(strcmp(command, "raiz") == 0)
        printf("raiz %ld de %ld = %ld\n", a, b, raiz(b, a, memoria_instrucoes, memoria_dados));

    //Fatorial
    if(strcmp(command, "!") == 0)
        printf("%ld! = %ld\n", a, fato(a,memoria_instrucoes, memoria_dados));

    //Logaritmo
    if(strcmp(command, "log") == 0)
        printf("log de %ld na base %ld = %ld\n", b, a, loga(a, b, memoria_instrucoes, memoria_dados));

    //Fibonaci
    if(strcmp(command, "fib") == 0)
        printf("O %ld° termo da sequencia Fibonaci é %ld\n", a, fibonaci(a, memoria_instrucoes, memoria_dados));

    //Ponto medio de dois termos de uma PA
    if(strcmp(command, "pa/") == 0)
        printf("O ponto medio da PA entre %ld e %ld é %ld\n", a, b, ponto_medio_pa(a, b, memoria_instrucoes, memoria_dados));

    //Ponto medio de dois termos de uma PG
    if(strcmp(command, "pg/") == 0)
        printf("O ponto medio da PG entre %ld e %ld é %ld\n", a, b, ponto_medio_pg(a, b, memoria_instrucoes, memoria_dados));

    //Encontra o N termo de uma PA
    if(strcmp(command, "pa") == 0)
        printf("o %ld° termo da PA de %ld com razão %ld é %ld\n", c, a, b, termo_pa(a, b, c, memoria_instrucoes, memoria_dados));

    //Encontra o N termo de uma PG
    if(strcmp(command, "pg") == 0)
        printf("o %ld° termo da PG de %ld com razão %ld é %ld\n", c, a, b, termo_pg(a, b, c, memoria_instrucoes, memoria_dados));

    //Soma os N termos de uma PA
    if(strcmp(command, "pa+") == 0)
        printf("A soma dos %ld termos da PA de %ld com razão %ld é %ld\n", c, a, b, soma_pa(a, b, c, memoria_instrucoes, memoria_dados));

    //Soma os N termo de uma PG
    if(strcmp(command, "pg+") == 0)
        printf("A soma dos %ld termos da PG de %ld com razão %ld é %ld\n", c, a, b, soma_pg(a, b, c, memoria_instrucoes, memoria_dados));
    
    //Kelvin
    if(strcmp(command, "kelvin") == 0)
        printf("%ld°C são %ld°K\n", a, kelvin(a, memoria_instrucoes, memoria_dados));

    //Fahrenheit
    if(strcmp(command, "fahrenheit") == 0)
        printf("%ld°C são %ld°F\n", a, fahrenheit(a, memoria_instrucoes, memoria_dados));
    
    //Hipotenusa
    if(strcmp(command, "hipo") == 0)
        printf("Hipotenusa %ld² + %ld² = %ld²\n", a, b, hipotenusa(a, b, memoria_instrucoes, memoria_dados));
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

    printf("#END");
}

