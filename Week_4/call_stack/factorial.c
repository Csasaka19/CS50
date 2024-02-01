#include <stdio.h>
#include <stdlib.h>

int factorial(int n);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./factorial <number>\n");
        return 1;
    }

    int n = atoi(argv[1]);

    printf("Factorial of %d is %d\n", n, factorial(n));

    return 0;
}

int factorial(int n){
    // Base case
    if (n == 1)
    {
        return 1;
    }

    // Recursive case
    return n * factorial(n - 1);
}

