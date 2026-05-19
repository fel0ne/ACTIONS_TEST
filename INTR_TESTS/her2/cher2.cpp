#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const int n = 2;
    
    float alpha[2] = {1.0f, 0.0f};
    float x[4] = {1.0f, 0.0f, 0.0f, 1.0f}; 
    float y[4] = {0.0f, 1.0f, 1.0f, 0.0f}; 
    float a[8] = {0.0f}; 
    
    int lda = n;

    printf("Запуск cher2 (complex float Hermitian rank-2)... ");
    cblas_cher2(order, uplo, n, alpha, x, 1, y, 1, a, lda);
    printf("Успешно!\n");

    return 0;
}