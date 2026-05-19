#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const enum CBLAS_TRANSPOSE trans = CblasNoTrans;
    const enum CBLAS_DIAG diag = CblasNonUnit;
    const int n = 2;
    
    float a[4] = {1.0f, 2.0f, 0.0f, 3.0f};
    float x[2] = {1.0f, 1.0f};
    
    int lda = n;
    int incx = 1;

    printf("Запуск strmv (float)... ");
    cblas_strmv(order, uplo, trans, diag, n, a, lda, x, incx);
    printf("Успешно!\n");

    return 0;
}