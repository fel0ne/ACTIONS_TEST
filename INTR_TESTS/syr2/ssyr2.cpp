#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const int n = 2;
    const float alpha = 1.0f;
    
    float x[2] = {1.0f, 0.0f};
    float y[2] = {0.0f, 1.0f};
    float a[4] = {0.0f, 0.0f, 0.0f, 0.0f}; 
    
    int lda = n;
    int incx = 1;
    int incy = 1;

    printf("Запуск ssyr2 (float)... ");
    cblas_ssyr2(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    printf("Успешно!\n");

    return 0;
}