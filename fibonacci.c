#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double start_time, end_time;/* Start and end time variables */
int Fib(int);
void Init(int);

int main(int argc, char *argv[])
{
	int n, t = 1;
	
	if(argc > 1)
		sscanf(argv[1], "%d", &n);
	
	Init(n);
}

void Init(int n){
	/* Start of the test */
	start_time = omp_get_wtime();
	int res;
	
	res = Fib(n); /* Do the actual work */

	end_time = omp_get_wtime();
	printf("Fibonacci: %d = %ld\n", n, res);
	printf("Time: %g seconds\n", end_time - start_time);
}

int Fib(int n)
{
	if(n < 2)
		return n;
	
	int a, b;
	
	a = Fib(n-1);
	b = Fib(n-2);
	
	return a + b;
}
