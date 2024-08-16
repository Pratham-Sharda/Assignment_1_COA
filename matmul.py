import time

def create_matrix(N, value):
    return [[value for _ in range(N)] for _ in range(N)]

def multiply_matrix(A, B, N):
    C = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            C[i][j] = 0
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
    return C

def matrix_multiplication(N, value_type):

    total_start_time = time.time()

    A = create_matrix(N, value_type(3))  # Create N x N matrix filled with 1
    B = create_matrix(N, value_type(45))  # Create N x N matrix filled with 1

    # Measure the "meat portion" time (matrix multiplication)
    meat_start_time = time.time()
    C = multiply_matrix(A, B, N)
    meat_end_time = time.time()


    total_end_time = time.time()


    total_time = total_end_time - total_start_time
    meat_time = meat_end_time - meat_start_time

    
    print(f"Time taken for N={N} with {value_type.__name__}:")
    print(f"Total program execution time: {total_time:.5f} seconds")
    print(f"Meat portion (matrix multiplication) time: {meat_time:.5f} seconds")
    print(f"Meat portion as a proportion of total time: {meat_time / total_time:.2%}\n")

if __name__ == "__main__":

    print("Matrix Multiplication with Integer Type:")
    matrix_multiplication(64, int)
    # matrix_multiplication(128, int)
    # matrix_multiplication(256, int)
    # matrix_multiplication(512, int)
    # matrix_multiplication(1024, int)

    print("\nMatrix Multiplication with Double Type:")
    matrix_multiplication(64, float)
    # matrix_multiplication(128, float)
    # matrix_multiplication(256, float)
    # matrix_multiplication(512, float)
    # matrix_multiplication(1024, float)



