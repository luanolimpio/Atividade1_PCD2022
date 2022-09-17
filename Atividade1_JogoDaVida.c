// Luan Olimpio Claro da Costa - RA 120.855

// Atividade 1 - Programacao Concorrente e Distribuida
// Arquivo Jogo da Vida - PThreads

#include <stdio.h>

# define geracoes 2000
# define num_threads 1
# define dimensoes 40

int grid[dimensoes][dimensoes];
// alocacao dinamica

void inicializa_tabuleiro1(){
    //GLIDER

    int i, j;

    for(i=0; i<dimensoes; i++){
        for(j=0; j<dimensoes; j++){
            grid[i][j]=0;
        }
    }

    grid[1][2]=1;
    grid[2][3]=1;
    grid[3][1]=1;
    grid[3][2]=1;
    grid[3][3]=1;

    grid[10][31]=1;
    grid[10][32]=1;
    grid[11][30]=1;
    grid[11][31]=1;
    grid[12][31]=1;
}



void jogo_da_vida(){

}

void main(){
    int i;

}

