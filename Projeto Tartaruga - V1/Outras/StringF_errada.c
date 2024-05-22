#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

#define MAX_LEN 1000

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

void multiplyStrings(char *result, const char *num1, int num2) {
    int len1 = strlen(num1);
    int carry = 0;
    int prod;

    char *tempResult = (char *)malloc(len1 + 11);  // Aloca espaço suficiente para o produto
    int k = len1;

    for (int i = len1 - 1; i >= 0; i--) {
        prod = (num1[i] - '0') * num2 + carry;
        carry = prod / 10;
        tempResult[k--] = (prod % 10) + '0';
    }

    while (carry) {
        tempResult[k--] = (carry % 10) + '0';
        carry /= 10;
    }

    strcpy(result, tempResult + k + 1);

    free(tempResult);
}

void divideStrings(char *result, const char *num, int divisor) {
    int len = strlen(num);
    int carry = 0;
    int digit;
    int i, j = 0;
    char *tempResult = (char *)malloc(len + 11);  // Aloca espaço suficiente para o resultado

    for (i = 0; i < len; i++) {
        carry = carry * 10 + (num[i] - '0');
        digit = carry / divisor;
        if (digit > 0 || j > 0) {
            tempResult[j++] = digit + '0';
        }
        carry %= divisor;
    }

    if (j == 0) {
        tempResult[j++] = '0';
    }

    tempResult[j] = '\0';
    strcpy(result, tempResult);

    free(tempResult);
}

void sumInverseFactorials(char *result, int N) {
  char sum[MAX_LEN] = "0";

  #pragma omp parallel
  {
      char factorial[MAX_LEN];
      char term[MAX_LEN];
      int i, thread_id, num_threads;

      thread_id = omp_get_thread_num();
      num_threads = omp_get_num_threads();

      for (i = thread_id; i <= N; i += num_threads) {
          // Calcula o fatorial de i
          strcpy(factorial, "1");
          for (int j = 2; j <= i; j++) {
              char temp[MAX_LEN];
              strcpy(temp, factorial);
              multiplyStrings(factorial, temp, j);
          }

          // Divide 1 pelo fatorial de i
          divideStrings(term, "1", i);

          #pragma omp critical
          {
              char tempSum[MAX_LEN];
              strcpy(tempSum, sum);
              sumStrings(sum, tempSum, term);
          }
      }
  }

  strcpy(result, sum);
}

int main() {
  int N = 20;
  char result[MAX_LEN];

  sumInverseFactorials(result, N);

  printf("Soma da série até 1/%d!: %s\n", N, result);

  return 0;
}
