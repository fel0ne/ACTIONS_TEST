#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const int n = 2;

    double alpha[2] = {1.0, 0.0};
    double beta[2] = {0.0, 0.0};
    
    double a[8] = {0};
    double x[4] = {0};
    double y[4] = {0};

    int lda = n;
    int incx = 1;
    int incy = 1;

    cblas_zhemv(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    printf("Тип Z (Complex Double): Успешно!\n");

    return 0;
}