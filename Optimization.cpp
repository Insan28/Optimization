#include <iostream>

#define SIZE 2048	
#define BLOCK_SIZE 16

int A[SIZE * SIZE];
int B[SIZE * SIZE];
int C[SIZE * SIZE];

int main(int argc, char* argv[]) {
	for (int i = 0; i < SIZE * SIZE; ++i)
		A[i] = B[i] = C[i] = i;

	int input = atoi(argv[1]);
	int i, j, k, ii, jj, kk;

	if (input == 1)
		for (i = 0; i < SIZE; i++)
			for (j = 0; j < SIZE; j++)
				for (k = 0; k < SIZE; k++)
					C[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];
	else
		for (ii = 0; ii < SIZE; ii += BLOCK_SIZE)
			for (kk = 0; kk < SIZE; kk += BLOCK_SIZE)
				for (jj = 0; jj < SIZE; jj += BLOCK_SIZE)
					for (i = ii; i < ii + BLOCK_SIZE && i < SIZE; i++)
						for (k = kk; k < kk + BLOCK_SIZE && k < SIZE; k++)
							for (j = jj; j < jj + BLOCK_SIZE && j < SIZE; j++)
								C[i * SIZE + j] += A[i * SIZE + k] * B[k * SIZE + j];

	return 0;
}

