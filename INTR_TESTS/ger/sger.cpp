#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const int m = 2;
    const int n = 3;
    const float alpha = 1.0f;
    
    float x[2] = {1.0f, 2.0f};
    float y[3] = {1.0f, 1.0f, 1.0f};
    float a[6] = {0.0f};
    
    int lda = n;
    int incx = 1;
    int incy = 1;

    printf("Запуск sger (float)... ");
    cblas_sger(order, m, n, alpha, x, incx, y, incy, a, lda);
    printf("Успешно!\n");

    return 0;
}