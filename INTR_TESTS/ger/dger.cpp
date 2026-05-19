#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const int m = 2;
    const int n = 3;
    const double alpha = 1.0;
    
    double x[2] = {1.0, 2.0};
    double y[3] = {1.0, 1.0, 1.0};
    double a[6] = {0.0};
    
    int lda = n;
    int incx = 1;
    int incy = 1;

    printf("Запуск dger (double)... ");
    cblas_dger(order, m, n, alpha, x, incx, y, incy, a, lda);
    printf("Успешно!\n");

    return 0;
}