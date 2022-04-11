// Modulos
#include "operations.h"
#include "core.h"

// Funções
// Soma
long int soma(long int a, long int b, long int **memoria_instrucoes, long int *memoria_dados){
    long int ram_position = 0; // Posição da memoria

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

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[3][2];
}

// Subtração
long int sub(long int a, long int b, long int **memoria_instrucoes, long int *memoria_dados){
    long int ram_position = 0; // Posição da memoria

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

    // Faz a subtração dos numeros
    memoria_instrucoes[2][0] = 1;
    memoria_instrucoes[2][1] = ram_position - 2;
    memoria_instrucoes[2][2] = ram_position - 1;
    memoria_instrucoes[2][3] = ram_position;

    // Traz o valor da subtração
    memoria_instrucoes[3][0] = 3;
    memoria_instrucoes[3][1] = ram_position;

    // Encerra a execução
    memoria_instrucoes[4][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[3][2];
}

// Multiplicação
long int multi(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){
    long int c;

    if(b < 0){c = -b;} //Se o multiplicador for negativo
    else{c = b;} //Se o multiplicador for positivo

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = 0;
    memoria_instrucoes[0][2] = 0;

    for(long int i = 0; i < c; i++){
        memoria_instrucoes[0][1] = soma(memoria_instrucoes[0][1], a, memoria_instrucoes, memoria_dados);
    } 

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    if(b < 0){return -memoria_instrucoes[1][2];} //Se o multiplicador for negativo
    else{return memoria_instrucoes[1][2];} //Se o multiplicador for positivo
}

//Divisão
long int divi(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){
    long int c, d, i = 0;

    if(b < 0){c = -b;} //Se o divisor for negativo
    else{c = b;} //Se o divisor for positivo

    if(a < 0){d = -a;} //Se o dividendo for negativo
    else{d = a;} //Se o dividendo for positivo

    for(i = 0; (d > 0) && (c > 0); i++)
        d = sub(d, c, memoria_instrucoes, memoria_dados);
    
    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = i;
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[2][0] = 3;
    memoria_instrucoes[2][1] = 0;

    //Encerra a execução
    memoria_instrucoes[3][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    //? To usando a multiplicação do c só para facilitar a comparação
    if(b * a < 0){return -memoria_instrucoes[2][2];} //Se o multiplicador for negativo
    else{return memoria_instrucoes[2][2];} //Se o multiplicador for positivo
}

//Potencia
long int pot(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){
    long int c = a;

    for(long int i = 1; i < b; i++)
        a = multi(a, c, memoria_instrucoes, memoria_dados);

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    if(b == 0){memoria_instrucoes[0][1] = 1;} //Se b for 0
    else{memoria_instrucoes[0][1] = a;} //Se b não for 0
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}

//Raiz
long int raiz(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){
    long int i, c = -1234;

    for(i = 0; c != a; i++)
        c = pot(i, b, memoria_instrucoes, memoria_dados);

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = i - 1;
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
    
}

//Fatorial
long int fato(long int a, long int** memoria_instrucoes, long int* memoria_dados){
    long int result = a, b;

    if(a < 0){b = -a;}
    else{b = a;}

    b = sub(b, 1, memoria_instrucoes, memoria_dados);
    
    while(b > 1){
        result = multi(result, b, memoria_instrucoes, memoria_dados);
        b = sub(b, 1, memoria_instrucoes, memoria_dados);      
    }
    
    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    if(a == 0) {memoria_instrucoes[0][1] = 1;} //Caso a entrada for 0
    else{memoria_instrucoes[0][1] = result;}
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
    
}

//Logaritmo
long int loga(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){
    //"a" é a base
    //"b" é o logaritmando

    long int result = -1234, i;
    
    for(i = 0; result != b; i++)
        result = pot(a, i, memoria_instrucoes, memoria_dados);

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = i - 1;
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}

//Encontra o A termo da sequencia Fibonaci
long int fibonaci(long int a, long int** memoria_instrucoes, long int* memoria_dados){
    //"a" é a posição do termo a ser encontrado na sequencia Fibonaci

    long int b = 0, c = 1, d;

    for(int i = 1; i < a; i++){
        d = c;
        c = soma(c, b, memoria_instrucoes, memoria_dados) ;
        b = d;
    }

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = c;
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
} 

//Ponto medio de dois termos de uma PA
long int ponto_medio_pa(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = divi(soma(a, b, memoria_instrucoes, memoria_dados), 2, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
} 

//Ponto medio de dois termos de uma PG
long int ponto_medio_pg(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = raiz(multi(a, b, memoria_instrucoes, memoria_dados), 2, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
} 

//Encontra o N termo de uma PA
long int termo_pa(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados){
    //"a" é o termo inicial
    //"b" é o razão
    //"n" é a posição do termo a ser encontrado na pa

    long int mult;

    mult = multi(sub(n, 1, memoria_instrucoes, memoria_dados), b, memoria_instrucoes, memoria_dados);

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = soma(a, mult, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}

//Encontra o N termo de uma PG
long int termo_pg(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados){
    //"a" é o termo inicial
    //"b" é a razão
    //"n" é a posição do termo a ser encontrado na pg

    long int pote;

    pote = pot(b, sub(n, 1, memoria_instrucoes, memoria_dados), memoria_instrucoes, memoria_dados);

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = multi(a, pote, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}

//Faz a soma de N termos de uma PA
long int soma_pa(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados){
    //"a" é o termo inicial
    //"b" é a razão
    //"n" é o numero de termos a serem somados de uma PA

    long int som;

    som = soma(a, termo_pa(a, b, n, memoria_instrucoes, memoria_dados), memoria_instrucoes, memoria_dados);
    
    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = divi(multi(som, n, memoria_instrucoes, memoria_dados), 2, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}

//Faz a soma de N termos de uma PG
long int soma_pg(long int a, long int b, long int n, long int** memoria_instrucoes, long int* memoria_dados){
    //"a" é o termo inicial
    //"b" é a razão
    //"n" é o numero de termos a serem somados de uma PG

    long int subt, mult;

    subt = sub(pot(b, n, memoria_instrucoes, memoria_dados), 1, memoria_instrucoes, memoria_dados);
    mult = multi(a, subt, memoria_instrucoes, memoria_dados);
    
    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = divi(mult, sub(b, 1, memoria_instrucoes, memoria_dados), memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}

//Faz a conversão de Celsius para Kelvin
long int kelvin(long int a, long int** memoria_instrucoes, long int* memoria_dados){
    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = soma(a, 273, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}

//Faz a conversão de Celsius para Fahrenheit
long int fahrenheit(long int a, long int** memoria_instrucoes, long int* memoria_dados){
    long int som;
    
    som = soma(multi(a, 9, memoria_instrucoes, memoria_dados), 160, memoria_instrucoes, memoria_dados);

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = divi(som, 5, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];

}

//Calcula a hipotenusa de um triangulo
long int hipotenusa(long int a, long int b, long int** memoria_instrucoes, long int* memoria_dados){
    long int som;
    
    som = soma(pot(a, 2, memoria_instrucoes, memoria_dados), pot(b, 2, memoria_instrucoes, memoria_dados), memoria_instrucoes, memoria_dados);

    //Leva o resultado para a memoria
    memoria_instrucoes[0][0] = 2;
    memoria_instrucoes[0][1] = raiz(som, 2, memoria_instrucoes, memoria_dados);
    memoria_instrucoes[0][2] = 0;

    //Traz o valor final da memoria
    memoria_instrucoes[1][0] = 3;
    memoria_instrucoes[1][1] = 0;

    //Encerra a execução
    memoria_instrucoes[2][0] = -1;

    //Executa a maquina
    machine(&memoria_instrucoes, &memoria_dados);

    return memoria_instrucoes[1][2];
}