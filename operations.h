#ifndef OPERATIONS_H
#define OPERATIONS_H

//Funçôes
long int soma(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Soma
long int sub(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Subtração
long int multi(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Multiplicação
long int divi(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Divisão
long int pot(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Potencia]
long int raiz(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Raiz
long int fato(long int a, long int** memoria_instrucoes, long int* memoria_dados); //Fatorial
long int loga(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Logaritmo
long int fibonaci(long int a, long int** memoria_instrucoes, long int* memoria_dados); //Encontra o A termo da sequencia Fibonaci
long int ponto_medio_pa(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Ponto medio de dois termos de uma PA
long int ponto_medio_pg(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Ponto medio de dois termos de uma PG
long int termo_pa(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados); //Encontra o N termo de uma PA
long int termo_pg(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados); //Encontra o N termo de uma PG
long int soma_pa(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados); //Faz a soma de N termos de uma PA
long int soma_pg(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados); //Faz a soma de N termos de uma PG
long int kelvin(long int a, long int** memoria_instrucoes, long int* memoria_dados); //Faz a conversão de Celsius para Kelvin
long int fahrenheit(long int a, long int** memoria_instrucoes, long int* memoria_dados); //Faz a conversão de Celsius para Fahrenheit
long int hipotenusa(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Calcula a hipotenusa de um triangulo




#endif 