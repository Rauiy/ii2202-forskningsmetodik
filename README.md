# ii2202-forskningsmetodik

Compile any of the programs with, gcc -O -fopenmp -o "output name" "inputfile.c"

fibonacci.c has an input N and computes the sequence of N

fibonacci-multi.c has two inputs N and T It computes the sequence of N with T threads

fibonacci-multi2.c has two inputs N and T. It computes <threads> sequences of <number> in each thread.

MatrixSum.c has two inputs T and Ti. It calculates the sum of a random 1000x1000 matrix Ti times with T threads. 

examples:
gcc -O -fopenmp -o fib fibonacci.c
fib 17

gcc -O -fopenmp -o fibm fibonaccim.c
fib 17 4

gcc -O -fopenmp -o fibm2 fibonaccim2.c
fib 17 4

gcc -O -fopenmp -o mat MatrixSum.c
mat 4 17
