# Prime-Number-Checker
# Overview
This C program generates an array of 50 random integers, writes them to a file named "fileex02", and then checks whether each number is prime using multi-threading. It utilizes pthread library for parallel execution.
# Code Structure
remplir(): Fills an array with 50 random integers and writes them to a file named "fileex02".
is_prime(int num): Checks if a given number is prime.
test(): Prints whether each number in the array is prime or not using multi-threading.
main(): Creates three threads - one for filling the array, and two for testing and printing prime numbers.
