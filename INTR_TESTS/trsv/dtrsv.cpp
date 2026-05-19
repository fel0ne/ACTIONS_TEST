#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const enum CBLAS_TRANSPOSE trans = CblasNoTrans;
    const enum CBLAS_DIAG diag = CblasNonUnit;
    const int n = 2;
    
    double a[4] = {2.0, 1.0, 0.0, 2.0};
    double x[2] = {1.0, 1.0};
    
    printf("Запуск dtrsv (double)... ");
    cblas_dtrsv(order, uplo, trans, diag, n, a, n, x, 1);
    printf("Успешно!\n");

    return 0;
}