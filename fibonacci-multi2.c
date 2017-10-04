#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXWORKERS 4		/* Maximum number of workers */

double start_time, end_time;/* Start and end time variables */
int Worker(int);
void Init(int, int);

int main(int argc, char *argv[])
{
	int n, t = 1;
	if(argc > 1)
		sscanf(argv[1], "%d", &n);
	if(argc == 3)
		sscanf(argv[2], "%d", &t);
	if(t > 4)
		t = 4;
	
	omp_set_num_threads(t);
	
	Init(n, t);
}

void Init(int n, int t){
	/* Start of the test */
	start_time = omp_get_wtime();
	int res;
#pragma omp parallel /* Define parallel part */
#pragma omp single /* Define that only thread should do this */
	res = Worker(n); /* Do the actual work */

	end_time = omp_get_wtime();
	printf("Fibonacci: %d = %ld\n", n, res);
	printf("Time: %g seconds\n", end_time - start_time);
	printf("Threads: %d", t);
}

int Worker(int n)
{
	if(n < 2)
		return n;
	
	int a, b;
	
#pragma omp task shared(a) if(n > 10)
	a = Worker(n-1);
	
	b = Worker(n-2);
	/* Barrier */
#pragma omp taskwait
	return a + b;
}
