#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int matriz[3][3] = {{1,2,3},{1,2,3},{1,2,3}};
int vetor[3] = {1,2,3};
int resultado[3];

void* mult(void* num){
  long nume = (long) num;
  int i,j;
  resultado[nume]=0;
  for(i=0;i<3;i++)
    resultado[nume]+= matriz[nume][i]*vetor[i];
  
}

int main(void) {
  int linhas = sizeof(matriz)/sizeof(matriz[0]);
  int colunas = sizeof(matriz[0])/sizeof(int);
  pthread_t* thread_rope=malloc(linhas * sizeof(pthread_t));

  for(long linha = 0; linha<linhas; linha++){
    pthread_create(&thread_rope[linha], NULL, mult, (void*) linha);
  }

  for(int i=0; i<linhas; i++){
    pthread_join(thread_rope[i], NULL);
  }
  for(int k = 0; k < linhas; k++) {
    printf("%d ", resultado[k]);
  }
  printf("\n");
  
  return 0;
}
