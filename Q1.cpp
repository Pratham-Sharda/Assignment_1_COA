

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Recursive Fibonacci
long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Loop Fibonacci
long long fib_loop(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Recursive Fibonacci with Memoization
vector<long long> memo(50, -1);

long long fib_memo(int n) {
    if (memo[n] != -1) return memo[n];
    if (n <= 1) return memo[n] = n;
    return memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
}

// Loop Fibonacci with Memoization
vector<long long> fib_table(50, -1);

long long fib_loop_memo(int n) {
    fib_table[0] = 0;
    fib_table[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib_table[i] = fib_table[i - 1] + fib_table[i - 2];
    }
    return fib_table[n];
}

int main() {
    
    double recursive_time, loop_time, memoized_recursive_time, memoized_loop_time;

    
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 50; i++) {
        cout << fib_recursive(i) << " ";
    }
    cout << endl;
    clock_gettime(CLOCK_MONOTONIC, &end);
    recursive_time = (end.tv_sec - start.tv_sec) * 1e9;
    recursive_time = (recursive_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << "Time taken by Recursive Fibonacci: " << recursive_time << " seconds" << endl;

    
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 50; i++) {
        cout << fib_loop(i) << " ";
    }
    cout << endl;
    clock_gettime(CLOCK_MONOTONIC, &end);
    loop_time = (end.tv_sec - start.tv_sec) * 1e9;
    loop_time = (loop_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << "Time taken by Loop Fibonacci: " << loop_time << " seconds" << endl;

    
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 50; i++) {
        cout << fib_memo(i) << " ";
    }
    cout << endl;
    clock_gettime(CLOCK_MONOTONIC, &end);
    memoized_recursive_time = (end.tv_sec - start.tv_sec) * 1e9;
    memoized_recursive_time = (memoized_recursive_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << "Time taken by Memoized Recursive Fibonacci: " << memoized_recursive_time << " seconds" << endl;


    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i = 0; i < 50; i++) {
        cout << fib_loop_memo(i) << " ";
    }
    cout << endl;
    clock_gettime(CLOCK_MONOTONIC, &end);
    memoized_loop_time = (end.tv_sec - start.tv_sec) * 1e9;
    memoized_loop_time = (memoized_loop_time + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << "Time taken by Memoized Loop Fibonacci: " << memoized_loop_time << " seconds" << endl;

    cout << "Speedup of Loop Fibonacci: " << recursive_time / loop_time << "x" << endl;
    cout << "Speedup of Memoized Recursive Fibonacci: " << recursive_time / memoized_recursive_time << "x" << endl;
    cout << "Speedup of Memoized Loop Fibonacci: " << recursive_time / memoized_loop_time << "x" << endl;

    return 0;
}
