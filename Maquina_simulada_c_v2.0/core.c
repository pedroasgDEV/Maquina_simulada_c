//Modulos
#include "core.h"

//Gera uma nova maquina
TMach NewMachine(){
    TMach aux;
    aux.custo = 0;
    aux.ciclos = 0;

    aux.missC1 = 0;
    aux.missC2 = 0;
    aux.missC3 = 0;

    aux.hitC1 = 0;
    aux.hitC2 = 0;
    aux.hitC3 = 0;

    return aux;
}

//Guarda as instruções do arquivo txt no vetor
void read_inst(TInst *inst, int qnt_instr){
    FILE *arq = fopen("instructions.txt", "r");

    if(arq == NULL){printf("arq não encontrado"); exit(0);}

    

    for(int i = 0; i < qnt_instr; i++){
        fscanf(arq, "%d %d %d %d %d %d %d", &(inst[i].opcode), &(inst[i].end1.end_block), &(inst[i].end1.end_word),
        &(inst[i].end2.end_block), &(inst[i].end2.end_word), &(inst[i].end3.end_block), &(inst[i].end3.end_word));
    }

    fclose(arq);
} 

//Aloca e preenche a memoria ram com lixo
void montar_ram(TMemBlock *ram, int tam_ram, int qnt_wrds){
    //Preenchendo com lixo
    for(long int i = 0; i < tam_ram; i++){
        ram[i].end_bloco = i; //Add endereço
        for(int j = 0; j < qnt_wrds; j++) ram[i].words[j] = rand() % 1000000; //Add palavras
    }
}

//Maquina que vai long interpretar a instrução
void interprets_machine(TInst instr, TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3, TMach *mach){
    //Pega os blocos na memoria
    TCell *cell1 = MemorySearch(instr.end1.end_block, ram, cache1, cache2, cache3);
    TCell *cell2 = MemorySearch(instr.end2.end_block, ram, cache1, cache2, cache3);
    TCell *cell3 = MemorySearch(instr.end3.end_block, ram, cache1, cache2, cache3);
    
    //Adicionar custos
    mach->custo += cell1->block.custo;
    mach->custo += cell2->block.custo;
    mach->custo += cell3->block.custo;

    //Hit e miss da celula 1
    switch (cell1->block.cacheHit){
        //Caso tenha encontrado na cache 1
        case 1:
            mach->hitC1++;
            break;
        
        //Caso tenha encontrado na cache 2
        case 2:
            mach->missC1++;
            mach->hitC2++;
            break;
        
        //Caso tenha encontrado na cache 3
        case 3:
            mach->missC1++;
            mach->missC2++;
            mach->hitC3++;
            break;
        
        //Caso tenha encontrado na ram
        case 4:
            mach->missC1++;
            mach->missC2++;
            mach->missC3++;
            break;
    }

    //Hit e miss da celula 2
    switch (cell2->block.cacheHit){
        //Caso tenha encontrado na cache 1
        case 1:
            mach->hitC1++;
            break;
        
        //Caso tenha encontrado na cache 2
        case 2:
            mach->missC1++;
            mach->hitC2++;
            break;
        
        //Caso tenha encontrado na cache 3
        case 3:
            mach->missC1++;
            mach->missC2++;
            mach->hitC3++;
            break;
        
        //Caso tenha encontrado na ram
        case 4:
            mach->missC1++;
            mach->missC2++;
            mach->missC3++;
            break;
    }

     //Hit e miss da celula 3
    switch (cell3->block.cacheHit){
        //Caso tenha encontrado na cache 1
        case 1:
            mach->hitC1++;
            break;
        
        //Caso tenha encontrado na cache 2
        case 2:
            mach->missC1++;
            mach->hitC2++;
            break;
        
        //Caso tenha encontrado na cache 3
        case 3:
            mach->missC1++;
            mach->missC2++;
            mach->hitC3++;
            break;
        
        //Caso tenha encontrado na ram
        case 4:
            mach->missC1++;
            mach->missC2++;
            mach->missC3++;
            break;
    }

    //Pega os dois primeiros valores
    int x = cell1->block.words[instr.end1.end_word];
    int y = cell2->block.words[instr.end2.end_word];
    int result;

    switch(instr.opcode){
        //Fazer nada
        case 0:
            printf("Não há de se levar nada a memoria\n");
            break;

        //Soma
        case 1:
            result = x + y;
            cell3->block.words[instr.end3.end_word] = result; //Guarda o resultado
            printf("%d + %d = %d\n", x, y, result);
            break;

        //Subtração
        case 2:
            result = x - y;
            cell3->block.words[instr.end3.end_word] = result; //Guarda o resultado
            printf("%d - %d = %d\n", x, y, result);
            break;
    }

    //Atualiza a ram
    ram[cell1->block.end_bloco] = cell1->block;
    ram[cell2->block.end_bloco] = cell2->block;
    ram[cell3->block.end_bloco] = cell3->block;
}

//Roda a maquina
void machine(TMemBlock *ram, TRow *cache1, TRow *cache2, TRow *cache3, TInst *instr){
    //Cria uma nova maquina
    TMach mach = NewMachine();

    //Compila as instruções
    for(long int pc = 0; instr[pc].opcode != -1; pc++){
        TInst instrucao = instr[pc];

        interprets_machine(instrucao, ram, cache1, cache2, cache3, &mach);

        //Iprime as informações de uso da maquina em cada ciclo de processamento
        printf("Custo: %ld\n", mach.custo);
        printf("C1 hit: %ld | C1 miss: %ld | C2 hit: %ld| C2 miss: %ld | C3 hit: %ld| C3 miss: %ld\n", mach.hitC1, mach.missC1, mach.hitC2, mach.missC2, mach.hitC3, mach.missC3); 

        mach.ciclos++;
    }

    //Porcentagem de blocos encontrados em cada cache e na ram
    float perC1 = (((float) mach.hitC1) / ((float) mach.hitC1 + mach.missC1)) * 100;
    float perC2 = (((float) mach.hitC2) / ((float) mach.hitC2 + mach.missC2)) * 100;
    float perC3 = (((float) mach.hitC3) / ((float) mach.hitC3 + mach.missC3)) * 100;
    float perRAM  = (((float) mach.missC3) / ((float) mach.ciclos * 3)) * 100;

    //Iprime as informações de uso da maquina
    printf("\nCusto: %ld | ", mach.custo);
    printf("C1: %.2f | C2: %.2f | C3: %.2f | RAM: %.2f | ", perC1, perC2, perC3, perRAM);
}