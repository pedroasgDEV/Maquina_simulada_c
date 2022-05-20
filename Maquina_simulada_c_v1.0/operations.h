#ifndef OPERATIONS_H
#define OPERATIONS_H

//TODO fazer a fatoração com processamento paralelo e função de recursividade
//TODO depois, usando python, multiplicar as saidas das maquinas paralelas
//TODO em c chama o arquivo pyhton usando o comando system
//TODO ler o aquivo gerado em pyhton e printar aqui

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
long int parouimpar(long int a, long int** memoria_instrucoes, long int* memoria_dados); //Verifica se um numero é par ou impar
long int primo(long int a, long int** memoria_instrucoes, long int* memoria_dados); //Verifica se um numero é primo
long int bhaskara_sub(long int a, long int b, long int c, long int** memoria_instrucoes, long int* memoria_dados); //Calcula a subtração da bhaskara
long int bhaskara_soma(long int a, long int b, long int c, long int** memoria_instrucoes, long int* memoria_dados); //Calcula a soma da bhaskara
long int qnt_alg(long int a, long int** memoria_instrucoes, long int* memoria_dados); //Quntidade de algarismos de um numero
long int qnt_alg_prod(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados); //Calcula a quantidade de algarismos de um produto 


#endif 