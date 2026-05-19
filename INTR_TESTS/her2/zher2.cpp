#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const int n = 2;
    
    double alpha[2] = {1.0, 0.0};
    double x[4] = {1.0, 0.0, 0.0, 1.0};
    double y[4] = {0.0, 1.0, 1.0, 0.0};
    double a[8] = {0.0};
    
    int lda = n;

    printf("Запуск zher2 (complex double Hermitian rank-2)... ");
    cblas_zher2(order, uplo, n, alpha, x, 1, y, 1, a, lda);
    printf("Успешно!\n");

    return 0;
}