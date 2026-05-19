#define OPENBLAS_USE_OPENMP
#include <omp.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <../OpenBLAS-0.3.31/cblas.h>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// 1. Оптимизированная реализация с Cache Blocking и SIMD
template <typename T>
void my_trmm(int M, int N, T alpha, const T* __restrict__ A, T* __restrict__ B) {
    const int BLOCK = 64; 

    #pragma omp parallel for collapse(2) schedule(static)
    for (int j_b = 0; j_b < N; j_b += BLOCK) {
        for (int k_b = 0; k_b < M; k_b += BLOCK) {
            
            int j_end = std::min(j_b + BLOCK, N);
            int k_end = std::min(k_b + BLOCK, M);

            for (int j = j_b; j < j_end; ++j) {
                for (int k = k_b; k < k_end; ++k) {
                    const T valB = alpha * B[k + j * M];
                    
                    // Самый важный цикл. i <= k гарантирует треугольность матрицы A.
                    #pragma omp simd
                    for (int i = 0; i <= k; ++i) {
                        B[i + j * M] += A[i + k * M] * valB;
                    }
                }
            }
        }
    }
}

// Обертки для OpenBLAS
void openblas_trmm(int M, int N, float alpha, float* A, float* B) {
    cblas_strmm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, M, N, alpha, A, M, B, M);
}

void openblas_trmm(int M, int N, double alpha, double* A, double* B) {
    cblas_dtrmm(CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, M, N, alpha, A, M, B, M);
}

template <typename T>
void run_benchmark(int size) {
    T alpha = 1.0;
    vector<T> A(size * size, 1.1);
    vector<T> B(size * size, 2.2);
    vector<T> B_backup = B;

    double prod_my = 1.0;
    double prod_blas = 1.0;

    cout << "\n--- Testing size " << size << " ---" << endl;

    for (int i = 0; i < 10; ++i) {
        // Сброс данных перед каждым тестом
        vector<T> B_test = B_backup;

        // Тест твоей функции
        auto s1 = high_resolution_clock::now();
        my_trmm(size, size, alpha, A.data(), B_test.data());
        auto e1 = high_resolution_clock::now();
        double t_my = duration<double>(e1 - s1).count();
        prod_my *= t_my;

        // Тест OpenBLAS
        B_test = B_backup; 
        auto s2 = high_resolution_clock::now();
        openblas_trmm(size, size, alpha, A.data(), B_test.data());
        auto e2 = high_resolution_clock::now();
        double t_blas = duration<double>(e2 - s2).count();
        prod_blas *= t_blas;
        
        cout << "Iter " << i+1 << ": My=" << t_my << "s, BLAS=" << t_blas << "s" << endl;
    }

    double gmean_my = pow(prod_my, 0.1);
    double gmean_blas = pow(prod_blas, 0.1);

    // Расчет процента производительности
    // P = (T_blas / T_my) * 100
    double perf_ratio = (gmean_blas / gmean_my) * 100.0;

    cout << "------------------------------------" << endl;
    cout << "Geometric Mean (My):   " << gmean_my << "s" << endl;
    cout << "Geometric Mean (BLAS): " << gmean_blas << "s" << endl;
    cout << "Relative Performance:  " << perf_ratio << "%" << endl;
    

}

int main() {
    int test_size = 1000; 
    run_benchmark<double>(test_size);
    return 0;
}