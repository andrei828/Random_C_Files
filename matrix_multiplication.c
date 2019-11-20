#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct matrix_args {
	int array_size;
	int matrix_row;
	int matrix_col;
	int * matrix_cell;
	int *** matrix1;
	int *** matrix2;
};

void read_data(FILE * in, int * n, int * m, int * p, int *** a, int *** b) {
	fscanf(in, "%d", n);
	fscanf(in, "%d", m);

	*a = malloc(*n * sizeof(int *));

	for (int i = 0; i < *n; i++)
		a[0][i] = malloc(*m * sizeof(int));

	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *m; j++)
			fscanf(in, "%d", &a[0][i][j]);

	fscanf(in, "%d", m);
	fscanf(in, "%d", p);

	*b = malloc(*m * sizeof(int *));

	for (int i = 0; i < *m; i++)
		b[0][i] = malloc(*p * sizeof(int));

	for (int i = 0; i < *m; i++)
		for (int j = 0; j < *p; j++)
			fscanf(in, "%d", &b[0][i][j]);
}

void * calculate_cell(void * v) {
	
	struct matrix_args *args = v;
	*args->matrix_cell = 0;

	for (int i = 0; i < args->array_size; i++) 
		*args->matrix_cell += (*args->matrix1)[args->matrix_col][i] * 
							  (*args->matrix2)[i][args->matrix_row];  
	
	// free(v);
	return NULL;
}

int main() {
	
	FILE * in = fopen("input_matrix.txt", "r");
	if (!in) {
		printf("Could not find file\n");
		return -1;
	}

	int n, m, p, **a, **b, counter = 0;
	
	read_data(in, &n, &m, &p, &a, &b);

	pthread_t * threads = malloc(n * p * sizeof(pthread_t));

	int ** c = malloc(n * sizeof(int *));
	if (!c) {
		printf("Could not allocate memory\n");
		return -1;
	}
	for (int i = 0; i < n; i++) {
		c[i] = malloc(p * sizeof(int));
		if (!c[i]) {
			printf("Could not allocate memory\n");
			return -1;
		}
	}

	struct matrix_args * args;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < p; j++) {	

			args = malloc(sizeof(struct matrix_args));
			if (!args) {
				printf("Could not allocate memory\n");
				return -1;
			}	
			
			args->matrix1 = &a;
			args->matrix2 = &b;
			args->array_size = m;
			args->matrix_row = j;
			args->matrix_col = i;
			args->matrix_cell = &c[i][j];
			
			pthread_create(&threads[counter++], NULL, calculate_cell, args);
		}

	free(args);
	void * res;
	for (int i = 0; i < counter; i++)
		if (pthread_join(threads[i], res)) {
			printf("Could not join threads\n");
		} 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
}

/*
4 4
1 2 3 4
3 4 2 1
3 4 5 2
2 1 3 4
4 3
1 2 3
3 2 1
4 3 1
5 4 2
*/


/*
39 31 16 
28 24 17 
45 37 22 
37 31 18 
*/