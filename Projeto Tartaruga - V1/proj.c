#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <mpfr.h>

void fatorial(int n, mpfr_t* vet) {
	mpfr_init2(vet[0], 5000); // Inicializa com precisão de 5000 bits
	mpfr_set_d(vet[0], 1.0, MPFR_RNDU);

	mpfr_init2(vet[1], 5000); // Inicializa com precisão de 5000 bits
	mpfr_set_d(vet[1], 1.0, MPFR_RNDU);

	for (int i = 2; i < n; ++i) {
		mpfr_init2(vet[i], 5000); // Inicializa com precisão de 5000 bits
		mpfr_mul_si(vet[i], vet[i - 1], i, MPFR_RNDU);
	}
}

void soma(int n, mpfr_t* vet, mpfr_t* globalP) {
	int posicao = omp_get_thread_num();
		int threads = omp_get_num_threads();

		int parte = n/threads;
		int inicio = parte * posicao;
		int fim = inicio + parte - 1;

	mpfr_t parcial;
	mpfr_init2(parcial, 5000); //Inicializa com precisão 5000
	mpfr_set_d(partial, 0.0, MPFR_RNDU);

	for (int i = inicio; i <= fim; i++){
		mpfr_div(vet[i], vet[0], vet[i], MPFR_RNDU);
		mofr_add(partial, partial, vet[i], MPFR_RNDU);
	}
# pragma omp critical
	mpfr_add(*globalP, *globalP, parcial, MPFR_RNDU);

	mpfr_clear(parcial);
}

double calcular_e_paralelo(int n_termos, int Threads) {

	mpfr_t* vet = (mpfr_t*)malloc(n_termos * sizeof(mpfr_t));
	fatorial(n_termos, vet);

	mpfr_t global;
	mpfr_init2(global, 5000); // Inicializa com precisão de 5000 bits
	mpfr_set_d(global, 0.0, MPFR_RNDU);
# 		pragma omp parallel num_threads(Threads)
	soma(n_termos, vet, &global);

	printf("Resultado da aproximação de Euler: ");
	mpfr_out_str(stdout, 10, 0, global, MPFR_RNDU);
	printf("\n");

	
	mpfr_clear(global);
	for (int i = 0; i < n_termos; i++) {
		mpfr_clear(vet[i]);
	}
	free(vet);

	return resultado;
}


int main(int argc, char* argv[]) {
	if(argc != 2) {
		printf("\nEntre o argumento de threads\n");
		return 1;
	}

	int nThreads = strtol(argv[1], NULL, 10);

	int n_termos = 10000000;
	calcular_e_paralelo(n_termos,nThreads);

	printf("Valor de e (paralelo): %.100f\n", e_paralelo);

	return 0;
}
