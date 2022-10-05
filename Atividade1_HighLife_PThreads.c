// Brendo Yuki Katagi - RA 120.682
// Luan Olimpio Claro da Costa - RA 120.855
// Matheus Anido Pereira Coimbra - RA 104.112

// Atividade 1 - Programacao Concorrente e Distribuida
// Jogo da Vida - OpenMP

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

# define GERACOES 2000
# define NUM_THREADS 8
# define DIMENSOES 2048
# define POSITION(x) (x+DIMENSOES)%DIMENSOES
# define LINHAS_POR_THREAD DIMENSOES/NUM_THREADS;
# define RESTO DIMENSOES%NUM_THREADS;

int ** grid, **newGrid;
struct Thread_data {
    int inicio, fim, g;
};


void inicializa_tabuleiro1(int ** grid) {
    //GLIDER
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

int varredura(int i, int j, int ** grid) {
  int k, l, count = 0;
  for (k = i-1; k <= i+1; k++) {
    for(l = j-1; l <= j+1; l++) {
      if(k != i || l != j)
        count += grid[POSITION(k)][POSITION(l)];
    }
  }
  return count;
}

void jogo_da_vida(void* t_data) {
    int i, j, count = 0;

    for(i=t_data->inicio ; i<t_data->inicio; i++){
      for(j=0; j<DIMENSOES; j++) {
        count = varredura(i, j, grid);
        if((count == 2 || count == 3) && grid[i][j] == 1) {
          newGrid[i][j] = 1;
        } else if((count == 3 || count == 6) && grid[i][j] == 0) {
          newGrid[i][j] = 1;
        } else {
          newGrid[i][j] = 0;
        }
      }
    }
    if(t_data->g == 0)
      printf("N Threads: %d\n", NUM_THREADS);

}

int ** inicia_grid() {
  int i;
  int ** grid = (int **) calloc(sizeof(int *), DIMENSOES);
  for(i = 0; i < DIMENSOES; i++) {
    grid[i] = (int *) calloc(sizeof(int), DIMENSOES);
  }
  return grid;
}

void libera_grid(int ** grid) {
  int i;
  for(i = 0; i < DIMENSOES; i++)
    free(grid[i]);
  free(grid);
}

int main() {
  int i, j, count = 0, thread_num;
  int inicio = 0; fim = LINHAS_POR_THREAD + RESTO; //primeira thread executa linhas a mais
  int **aux;
  pthread_barrier_t barreira; // Cria barreira
  pthread_barrier_init(&barreira, NULL, NUM_THREADS); //inicializa barreira
  struct timeval i_time, f_time, exec_time;
  pthread_t threads[NUM_THREADS];

  grid = inicia_grid();
  newGrid = inicia_grid();

  inicializa_tabuleiro1(grid);
  //omp_set_num_threads(NUM_THREADS);

  printf("MATRIZES INICIADAS\n");

  //itime = omp_get_wtime();
  gettimeofday(i_time, NULL);
  for(i=0; i < GERACOES; i++) {
    for(thread_num = 0; thread_num < NUM_THREADS; thread_num++){

        Thread_data t_data = {inicio, fim, i};

        pthread_create(&threads[thread_num], NULL, jogo_da_vida, &t_data);

        inicio += fim;
        fim += LINHAS_POR_THREAD;
    }

    pthread_barrier_wait(&barreira); // Aguarda a execução de todas as threads
    aux = grid;
    grid = newGrid;
    newGrid = aux;

  }
  pthread_exit(NULL);
  gettimeofday(f_time, NULL);
  timersub(&f_time, &i_time, &exec_time);


  for(i = 0; i < DIMENSOES; i++) {
    for(j = 0; j < DIMENSOES; j++) {
        count += grid[i][j];
    }
  }
  printf("%d\n", count);
  printf("Tempo de execucao: %f\n", exec_time);
  libera_grid(grid);
  libera_grid(newGrid);
  aux = NULL;
  return 0;
}
