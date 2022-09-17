// Luan Olimpio Claro da Costa - RA 120.855

// Atividade 1 - Programacao Concorrente e Distribuida
// Arquivo Jogo da Vida - PThreads

#include <stdio.h>
#include <stdlib.h>

# define geracoes 2000
# define num_threads 1
# define dimensoes 2048

void inicializa_tabuleiro1(int ** grid)
{
    //GLIDER

    int i, j;

    for(i=0; i<dimensoes; i++)
    {
        for(j=0; j<dimensoes; j++)
        {
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

int varredura(int i, int j, int ** grid)
{
    int k, l, count = 0;
    for (k = i-1; k < i+1; k++)
    {
        for(l = j-1; l < j+1; l++)
        {
            count += grid[(k+dimensoes)%dimensoes][(l+dimensoes)%dimensoes];
        }
    }
    return count;
}



void jogo_da_vida(int ** grid, int ** newGrid)
{
    int i, j, count, **aux;

    for(i=0; i<dimensoes; i++)
    {
        for(j=0; j<dimensoes; j++)
        {
            count = varredura(i, j, grid);
            if((count < 2 || count >= 4) && grid[i][j] == 1)
            {
                newGrid[i][j] = 0;
            }
            else if((count == 2 || count == 3) && grid[i][j] == 1)
            {
                newGrid[i][j] = 1;
            }
            else if(count == 3)
            {
                newGrid[i][j] = 1;
            }
        }
    }
    aux = grid;
    grid = newGrid;
    newGrid = aux;
}

int ** inicia_matriz()
{
    int i;
    int ** matriz = (int **) calloc(sizeof(int *), dimensoes);
    for(i = 0; i < dimensoes; i++)
    {
        matriz[i] = (int *)calloc(sizeof(int), dimensoes);
    }
    return matriz;
}

int main()
{
    int i, j, count = 0;
    int ** matriz, **matriz2;

    matriz = inicia_matriz();
    inicializa_tabuleiro1(matriz);
    matriz2 = inicia_matriz();
    printf("MATRIZES INICIADAS\n");

    for(i=0; i<geracoes; i++)
    {
        jogo_da_vida(matriz, matriz2);
    }
    for(i = 0; i < dimensoes; i++)
    {
        for(j=0; j < dimensoes; j++)
        {
            count += matriz[i][j];
        }
    }
    printf("%d\n", count);
    return 0;
}

