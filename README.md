### Executar o programa com OpenMP

```sh
gcc -o jogodavida Atividade1_HighLife_OpenMP.c -fopenmp
time ./jogodavida
```

### Executar o programa com Pthread
```sh
gcc Atividade1_HighLife_PThreads.c -o jogodavida -pthread
time ./jogodavida
```