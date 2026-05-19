#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const int n = 2;
    const double alpha = 1.0;
    
    double x[2] = {1.0, 0.0};
    double y[2] = {0.0, 1.0};
    double a[4] = {0.0, 0.0, 0.0, 0.0};
    
    int lda = n;
    int incx = 1;
    int incy = 1;

    printf("Запуск dsyr2 (double)... ");
    cblas_dsyr2(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    printf("Успешно!\n");

    return 0;
}