#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define MAX_LEN 1000

// Função para remover zeros à esquerda de uma string
void removeLeadingZeros(char *str) {
    int len = strlen(str);
    int i = 0;
    while (str[i] == '0' && i < len - 1) {
        i++;
    }
    if (i > 0) {
        memmove(str, str + i, len - i + 1);
    }
}

// Função para somar duas strings que representam números
void sumStrings(char *result, const char *num1, const char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = len1 > len2 ? len1 : len2;
    int carry = 0;
    int sum;

    char *tempResult = (char *)malloc(maxLen + 2);
    tempResult[maxLen + 1] = '\0';

    int i = len1 - 1, j = len2 - 1, k = maxLen;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = i >= 0 ? num1[i--] - '0' : 0;
        int digit2 = j >= 0 ? num2[j--] - '0' : 0;

        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        tempResult[k--] = (sum % 10) + '0';
    }

    if (carry) {
        tempResult[k--] = carry + '0';
    }

    strcpy(result, tempResult + k + 1);

    free(tempResult);
}

// Função para calcular o fatorial de um número
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Função para somar os inversos dos fatoriais
void sumInverseFactorials(char *result, int N) {
    double sum = 0.0;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i <= N; i++) {
        sum += 1.0 / factorial(i);
    }

    snprintf(result, MAX_LEN, "%.20f", sum);
}

int main() {
    int N = 20;
    char result[MAX_LEN];

    sumInverseFactorials(result, N);

    printf("Soma da série até 1/%d!: %s\n", N, result);

    return 0;
}
