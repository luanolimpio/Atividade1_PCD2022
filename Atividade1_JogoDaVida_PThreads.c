// Luan Olimpio Claro da Costa - RA 120.855

// Atividade 1 - Programacao Concorrente e Distribuida
// Arquivo Jogo da Vida - PThreads

#include <stdio.h>
#include <pthread.h>

# define geracoes 2000
# define num_threads 1
# define dimensoes 50

int tabuleiro[dimensoes][dimensoes];

void inicializa_tabuleiro1(){
    //GLIDER

    int i, j;

    for(i=0; i<dimensoes; i++){
        for(j=0; j<dimensoes; j++){
            tabuleiro[i][j]=0;
        }
    }

    tabuleiro[1][2]=1;
    tabuleiro[2][3]=1;
    tabuleiro[3][1]=1;
    tabuleiro[3][2]=1;
    tabuleiro[3][3]=1;

    tabuleiro[10][31]=1;
    tabuleiro[10][32]=1;
    tabuleiro[11][30]=1;
    tabuleiro[11][31]=1;
    tabuleiro[12][31]=1;
}



void jogo_da_vida(){

}

void main(){
    int i;
    pthread_t t[num_threads];

    for(i=0; i<num_threads; i++){
        //thread_create(&t[i], NULL, ThreadProcess, (void *) (i+1));
    }
}

/*#include <stdio.h>
#include <pthread.h>

#define   MAX_COUNT   10
#define   MAX_THREADS  2

void  *ThreadProcess(void *th);  /* thread process prototype

int  main(void) {
  pthread_t t[MAX_THREADS];  // duas threads
  int i;

  for(i=0; i<MAX_THREADS; i++)
    pthread_create(&t[i], NULL, ThreadProcess, (void *) (i+1));

  pthread_exit(NULL);
}

void  *ThreadProcess(void *th) {
  int i, thid;

  thid = (int) th;
  for (i=1; i<=MAX_COUNT; i++)
    printf("Line from thread %d,value=%d\n", thid, i);

  pthread_exit(NULL);
  }
}*/










