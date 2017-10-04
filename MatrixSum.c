#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000  /* maximum matrix size */
#define MAXWORKERS 8   /* maximum number of workers */
#define RAND 999999
double start_time, end_time;
int numWorkers;
int size;
double matrix[MAXSIZE][MAXSIZE];
omp_lock_t lck;
int start();

/* read command line, initialize, and create threads */
int main(int argc, char *argv[]) {
	int i, j, total = 0, max = -1, min = RAND; /* Partial coordinate and shared coordinate variables*/
	int times = 100;
	/* read command line args if any */
	size = MAXSIZE;
	numWorkers = 1;

	if(argc > 1) sscanf(argv[1], "%d", &numWorkers);
	if(argc > 2) sscanf(argv[2], "%d", &times);
	
	if (size < 100) size = 100;
	if (numWorkers > MAXWORKERS) numWorkers = MAXWORKERS;
	else if (numWorkers <= 0)numWorkers = 1;

	omp_set_num_threads(numWorkers);
	/* initialize the matrix */
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			matrix[i][j] = (rand() % RAND);
		}
	}

	start_time = omp_get_wtime();
	for(i = 0; i< times; i++){
		total = start();
	}
	// implicit barrier
	end_time = omp_get_wtime();
	
	printf("it took %g seconds, magnified %dx times\n", end_time - start_time, times);
}

int start(){
int i, j, total;
#pragma omp parallel private(j)
	{
#pragma omp for reduction (+:total)
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				total += matrix[i][j];
			}
		}
	}
	return total;
}

