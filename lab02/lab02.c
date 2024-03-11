#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int matriz[3][3] = {{1,2,3},{3,2,1},{2,2,2}};
int vetor[3] = {3,2,1};
int resultado[3];

void* mult(void* num){
  long nume = (long) num;;
  resultado[nume]=0;
  for(int i=0;i<3;i++)
    resultado[nume]+= matriz[nume][i]*vetor[i];
  return NULL;
}

void imprimir(int colunas, int linhas, int v[linhas][colunas]){
  for(int i = 0; i < linhas; i++){
    for(int y = 0; y < colunas; y++){
      printf("%d ", v[i][y]);
    }
   printf("\n");
 }

}

int main(void) {
  int linhas = sizeof(matriz)/sizeof(matriz[0]);
  int colunas = sizeof(matriz[0])/sizeof(int);
  pthread_t* thread_rope=malloc(linhas * sizeof(pthread_t));

 printf("Matriz:\n");
 imprimir(colunas, linhas, matriz);

 printf("Vetor:\n");
 for(int i = 0; i<colunas; i++){
  printf("%d\n", vetor[i]);
 }

  for(long linha = 0; linha<linhas; linha++){
    pthread_create(&thread_rope[linha], NULL, mult, (void*) linha);
  }

  for(int i=0; i<linhas; i++){
    pthread_join(thread_rope[i], NULL);
  }

  printf("Resultado:\n");
  for(int k = 0; k < linhas; k++) {
    printf("%d\n", resultado[k]);
  }
  printf("\n");
  free(thread_rope); 
  return 0;
}
