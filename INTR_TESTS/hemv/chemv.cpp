#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_UPLO uplo = CblasUpper; 
    const int n = 2; 
    
    float alpha[2] = {1.0f, 0.0f}; 
    float beta[2] = {0.0f, 0.0f};
    

    float a[8] = {0}; 
    float x[4] = {0};
    float y[4] = {0};
    
    int lda = n;
    int incx = 1;
    int incy = 1;

    cblas_chemv(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    printf("Тип C (Complex Float): Успешно!\n");

    return 0;
}