#include <stdio.h>
#include <stdlib.h>
#include "../../OpenBLAS-0.3.31/cblas.h"

int main() {
    const enum CBLAS_ORDER order = CblasRowMajor;
    const int m = 2; 
    const int n = 2;
    float alpha[2] = {1.0f, 0.0f};
    
    float x[4] = {1.0f, 0.0f, 1.0f, 0.0f};
    float y[4] = {1.0f, 0.0f, 1.0f, 0.0f};
    float a[8] = {0.0f};
    
    int lda = n;

    printf("Запуск cgeru (complex float)... ");
    cblas_cgeru(order, m, n, alpha, x, 1, y, 1, a, lda);
    printf("Успешно!\n");

    return 0;
}