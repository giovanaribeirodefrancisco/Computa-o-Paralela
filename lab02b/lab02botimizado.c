#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100000
#define C 100

int matriz[N][C];
int vetor[C];
int resultado[N];
int contador_thread;

void *mult(void *rank) {
    long meurank = (long) rank;
    int local = N / contador_thread;
    int primeira = meurank * local;
    int ultima = (meurank + 1) * local - 1;
    for (int i = primeira; i <= ultima; i++) {
        resultado[i] = 0;
        for (int j = 0; j < C; j++)
            resultado[i] += matriz[i][j] * vetor[j];
    }
    return NULL;
}

void preencher(int colunas, int linhas, int v[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int y = 0; y < colunas; y++) {
            v[i][y] = rand() % 10;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <numero_de_threads>\n", argv[0]);
        return 1;
    }
    int linhas = N;
    contador_thread = strtol(argv[1], NULL, 10);

    pthread_t *thread_rope = malloc(contador_thread * sizeof(pthread_t));

    preencher(C, linhas, matriz);

    for (int a = 0; a < COLUNAS; a++) {
        vetor[a] = rand() % 10;
    }

    for (long thread = 0; thread < contador_thread; thread++) {
        pthread_create(&thread_rope[thread], NULL, mult, (void*) thread);
    }

    for (long i = 0; i < contador_thread; i++) {
        pthread_join(thread_rope[i], NULL);
    }

    free(thread_rope);
    return 0;
}
