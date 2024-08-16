#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

template <typename T>
void multiplyMatrix(const vector<vector<T>>& A, const vector<vector<T>>& B, vector<vector<T>>& C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

template <typename T>
void matrixMultiplication(int N) {
    // Start measuring total program time
    clock_t total_start = clock();

    vector<vector<T>> A(N, vector<T>(N, 1));  // Initialize with 1 for simplicity
    vector<vector<T>> B(N, vector<T>(N, 1));  // Initialize with 1 for simplicity
    vector<vector<T>> C(N, vector<T>(N, 0));

    // Measure the "meat portion" time (matrix multiplication)
    clock_t meat_start = clock();
    multiplyMatrix(A, B, C, N);
    clock_t meat_end = clock();

    // End measuring total program time
    clock_t total_end = clock();

    // Calculate times
    double total_time = ((double)(total_end - total_start)) / CLOCKS_PER_SEC;
    double meat_time = ((double)(meat_end - meat_start)) / CLOCKS_PER_SEC;


    cout << "Time taken for N=" << N << " with " << (is_same<T, int>::value ? "int" : "double") << ":" << endl;
    cout << "Total program execution time: " << fixed << setprecision(5) << total_time << " seconds" << endl;
    cout << "Meat portion (matrix multiplication) time: " << fixed << setprecision(5) << meat_time << " seconds" << endl;
    cout << "Meat portion as a proportion of total time: " << fixed << setprecision(2) << (meat_time / total_time) * 100 << "%" << endl << endl;
}

int main() {
    cout << "Matrix Multiplication with Integer Type:" << endl;
    matrixMultiplication<int>(64);
    // matrixMultiplication<int>(128);
    // matrixMultiplication<int>(256);
    // matrixMultiplication<int>(512);
    // matrixMultiplication<int>(1024);

    cout << "\nMatrix Multiplication with Double Type:" << endl;
    matrixMultiplication<double>(64);
    // matrixMultiplication<double>(128);
    // matrixMultiplication<double>(256);
    // matrixMultiplication<double>(512);
    // matrixMultiplication<double>(1024);

    return 0;
}
