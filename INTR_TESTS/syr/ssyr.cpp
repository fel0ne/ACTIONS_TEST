#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const int n = 2;
    const float alpha = 1.0f;
    
    float x[2] = {1.0f, 2.0f};
    float a[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    
    int lda = n;
    int incx = 1;

    printf("Запуск ssyr (float)... ");
    cblas_ssyr(order, uplo, n, alpha, x, incx, a, lda);
    printf("Успешно!\n");

    return 0;
}