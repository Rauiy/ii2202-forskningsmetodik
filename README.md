# ii2202-forskningsmetodik

Compile any of the programs with, gcc -O -fopenmp -o <output name> <inputfile.c>

fibonacci.c has an input <number> and computes the sequence of <number>

fibonaccim.c has two inputs <number> and <threads>. It computes the sequence of <number> with <threads> threads

fibonaccim2.c has two inputs <number> and <threads>. It computes <threads> sequences of <number> in each thread.

MatrixSum.c has two inputs <threads> and <times>. It calculates the sum of a random 1000x1000 matrix <times> times with <threads> threads. 

examples:
gcc -O -fopenmp -o fib fibonacci.c
fib 17

gcc -O -fopenmp -o fibm fibonaccim.c
fib 17 4

gcc -O -fopenmp -o fibm2 fibonaccim2.c
fib 17 4

gcc -O -fopenmp -o mat MatrixSum.c
mat 4 17
