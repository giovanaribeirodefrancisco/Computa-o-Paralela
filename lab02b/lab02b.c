#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10000

int matriz[N][100];
int vetor[100];
int resultado[100];
int contador_thread;

void* mult(void* rank){
  long meurank = (long) rank;
  int local = N/contador_thread;
  int primeira = meurank*local;
  int ultima = (meurank+1)*local-1;
  for(int i = primeira; i <= ultima; i++){
    resultado[i] = 0;
    for(int j=0;j<100;j++)
      resultado[i]+= matriz[i][j]*vetor[j];
  }
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

void preencher(int colunas, int linhas, int v[linhas][colunas]){
  for(int i = 0; i < linhas; i++){
    for(int y = 0; y < colunas; y++){
      v[i][y] = rand() % 10;
    }
  }
}

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("Uso: %s <numero_de_threads>\n", argv[0]);
    return 1;
  }
  int linhas = sizeof(matriz)/sizeof(matriz[0]);
  int colunas = sizeof(matriz[0])/sizeof(int);
  contador_thread = strtol(argv[1], NULL, 10);
  
  pthread_t* thread_rope=(pthread_t *)malloc(contador_thread * sizeof(pthread_t));
preencher(colunas,linhas, matriz);

 /*printf("Matriz:\n");
 imprimir(colunas, linhas, matriz);*/

  for(int a = 0; a < colunas; a++){
    vetor[a] = rand() % 10;
  }
 /*printf("Vetor:\n");
 for(int i = 0; i<colunas; i++){
  printf("%d\n", vetor[i]);
 }*/

  for(long thread = 0; thread<contador_thread; thread++){
    pthread_create(&thread_rope[thread], NULL, mult, (void*) thread);
  }

  for(int i=0; i<contador_thread; i++){
    pthread_join(thread_rope[i], NULL);
  }

  /*printf("Resultado:\n");
  for(int k = 0; k < linhas; k++) {
    printf("%d\n", resultado[k]);
  }*/
  printf("\n");
  free(thread_rope); 
  return 0;
}
