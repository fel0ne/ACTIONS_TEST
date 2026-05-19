#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper;
    const int n = 2;
    const float alpha = 1.0f;
    
    float x[4] = {1.0f, 1.0f, 1.0f, -1.0f};
    float a[8] = {0.0f};
    
    int lda = n;

    printf("Запуск cher (complex float Hermitian)... ");
    cblas_cher(order, uplo, n, alpha, x, 1, a, lda);
    printf("Успешно!\n");

    return 0;
}