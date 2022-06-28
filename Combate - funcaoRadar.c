
// FUNCAO RADAR


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 15




int main()
{
    
    char matriz[TAM][TAM];
    
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            matriz[i][j] = '.';}
    }
    
    printf("   ");
    for (int i = 0; i < TAM; i++){
        printf("%2d|", i);
    }
    printf("\n   ");    
    for (int i = 0; i < TAM; i++){
        printf(" __");
    }

    for (int i = 0; i < TAM; i++){
        printf("\n%2d |", i);
        for (int j = 0; j < TAM; j++){
            printf(" %c ", matriz[i][j]);    
        }
    
    }
    printf("\n\n\n");
    srand(time(NULL));
    
    int x, y;
    
    x = rand() % TAM;
    y = rand() % TAM;
    
    matriz[x][y] = 'P';
    
    int z, w;
    
    z = rand() % TAM;
    w = rand() % TAM;
    
    matriz[z][w] = 'M';
    
    printf("   ");
    for (int i = 0; i < TAM; i++){
        printf("%2d|", i);
    }
    printf("\n   ");    
    for (int i = 0; i < TAM; i++){
        printf(" __");
    }
    
    for (int i = 0; i < TAM; i++){
        printf("\n%2d |", i);
        for (int j = 0; j < TAM; j++){
            printf(" %c ", matriz[i][j]);    
        }
    }
    /*
    char temp1;
    
    scanf("%c", &temp1);
    
    
    if (temp1 == 'd'){
        matriz[x][y] = 
        
    }*/

    return 0;
}