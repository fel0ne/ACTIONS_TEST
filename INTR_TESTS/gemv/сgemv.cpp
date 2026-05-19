#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const enum CBLAS_TRANSPOSE trans = CblasNoTrans;
    const int m = 2;
    const int n = 2;
    float alpha[2] = {1.0f, 0.0f}; 
    float beta[2] = {0.0f, 0.0f};
    unsigned short a[4] = {0, 0, 0, 0};
    unsigned short x[2] = {0, 0};
    unsigned short y[2] = {0, 0};
    int lda = n;
    int incx = 1;
    int incy = 1;
    cblas_cgemv(order, trans, m, n, alpha, a, lda, x, incx, beta, y, incy);
    printf("Успешно! Функция вызвана.\n");

    return 0;
}