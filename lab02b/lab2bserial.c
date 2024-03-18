#include <stdio.h>
#include <stdlib.h>

#define N 100

int matriz[N][N];
int vetor[N];
int resultado[N];

void mult() {
  for (int i = 0; i < N; i++) {
    resultado[i] = 0;
    for (int j = 0; j < N; j++) {
      resultado[i] += matriz[i][j] * vetor[j];
    }
  }
}

void imprimir(int colunas, int linhas, int v[linhas][colunas]) {
  for (int i = 0; i < linhas; i++) {
    for (int y = 0; y < colunas; y++) {
      printf("%d ", v[i][y]);
    }
    printf("\n");
  }
}

void preencher(int colunas, int linhas, int v[linhas][colunas]) {
  for (int i = 0; i < linhas; i++) {
    for (int y = 0; y < colunas; y++) {
      v[i][y] = rand() % 10;
    }
  }
}

int main(void) {
  preencher(N, N, matriz);

  printf("Matriz:\n");
  imprimir(N, N, matriz);

  for (int i = 0; i < N; i++) {
    vetor[i] = rand() % 10;
  }
  
  printf("Vetor:\n");
  for (int i = 0; i < N; i++) {
    printf("%d\n", vetor[i]);
  }

  mult();

  printf("Resultado:\n");
  for (int k = 0; k < N; k++) {
    printf("%d\n", resultado[k]);
  }

  return 0;
}

