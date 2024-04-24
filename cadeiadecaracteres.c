/*
* Descrição: Projeto que manipula vetores a fim de concatenar os vetores nome e sobrenome dentro do vetor nomecompleto, manipular o formato e conteúdo do vetor,
* o convertendo para letras maiúsculas e minúsculas, além de adcionar um sistema de busca dentro do vetor final.
*
* Autor: Thiago Martins
*/

#include <stdio.h>

int main(){
    char nome[31], sobrenome[31], nomecompleto[61];
    
    nome[0] = 'T';
    nome[1] = 'h';
    nome[2] = 'i';
    nome[3] = 'a';
    nome[4] = 'g';
    nome[5] = 'o';
    nome[6] = '\0';
    
    printf("\nNome: %s!", nome);
    
    sobrenome[0] = 77;
    sobrenome[1] = 97;
    sobrenome[2] = 114;
    sobrenome[3] = 116;
    sobrenome[4] = 105;
    sobrenome[5] = 110;
    sobrenome[6] = 115;
    sobrenome[7] = '\0';
    
    printf("\nSobrenome: %s!\n", sobrenome);
    
    //Colocar o nome no vetor nomecompleto
    int i = 0;
    
    while(nome[i] != '\0'){
        nomecompleto[i] = nome[i];
        i++;
    }
    
    //Colocar o espaço entre nome e sobrenome, além de salvar onde começa o sobrenome
    nomecompleto[i] = ' ';
    i++;
    
    int k = i;
    
    //Colocar sobrenome no vetor nomecompleto
    int j = 0;
    
    while(sobrenome[j] != '\0'){
        nomecompleto[i] = sobrenome[j];
        i++;
        j++;
    }
    
    printf("\nNome Completo: %s!\n", nomecompleto);
    
    nomecompleto[i] = '\0';
    
    //Colocar tudo em Maiúsculo
    i = 0;
    
    while(nomecompleto[i] != '\0'){
        if( nomecompleto[i] >= 'a' &&  nomecompleto[i] <= 'z' && i != 0 && i != k){
            nomecompleto[i] -= 32;
        }
        
        i++;
    }
    
    
    printf("\nNome completo em Maiúsculo: %s!\n", nomecompleto);
    
    //Nome completo em minúsculo, exceção das iniciais
    i= 0;
    
    while(nomecompleto [i] != '\0'){
        if(nomecompleto[i] >= 'A' && nomecompleto[i] <= 'Z' && i != 0 && i != k){
            nomecompleto[i] += 32;
        }
        
        i++;
    }
    
    printf("\nNome completo em minúsculo (exceção das iniciais): %s!\n", nomecompleto);
    
    //Nome completo junto sem espaços
    int espacos = 0;
    i = 0;
    
    //Eliminamos os espaços quandro atribuimos a posição nomecompleto[i - espacos] o valor de nomecompleto[i]
    while(nomecompleto[i] != '\0'){
        if(nomecompleto[i] == ' '){
            espacos++;
        }else{
            nomecompleto[i - espacos] = nomecompleto[i];
        }
        i++;
    }
    
    //Finalizando o vetor
    nomecompleto[i - espacos] = '\0';
    
    printf("\nNome completo sem espaços: %s!\n", nomecompleto);
    
    //Busca por nome dentro de nomecompleto
    int resultado = 0;
    i = 0;
    
    printf("\nInsira o nome que você deseja buscar dentro do vetor nomecompleto: ");
    scanf("%s", nome);
    
    while (nomecompleto[i] != '\0') {
        if (nomecompleto[i] == nome[0]){
            int j = 1;
            while (nome[j] != '\0' && nomecompleto[i + j] == nome[j]) {
                j++;
            }
            if (nome[j] == '\0') { 
                resultado = 1; 
                break; 
            }
        }
        i++;
    }
    
    // Retorna se o nome buscado está ou não presente no vetor
    if (resultado == 1) {
        printf("\nO nome buscado está presente no vetor!");
    } else {
        printf("\nO nome buscado não está presente no vetor");
    }
    
    return 0;
}
