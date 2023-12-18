#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int collatz(int n);

int main(int argc, char *argv[]){
    if (argc != 2)
    {
        printf("Usage ./collatz number\n");
        return 1;
    }
     
    int term = atoi(argv[1]);
    if (term > 0)
    {
        printf("%d :step(s) required to obtain 1\n", collatz(term));
    }
    else
    {
        printf("Use a positive number as a command line argument\n");
        return 1;
    }

}

int collatz(int n){
    // printf("%d", n);
    // Base case
    if (n == 1)
        return 0;
    else if ((n % 2) == 0)
        return 1 + collatz(n / 2);
    else
        return 1 + collatz(3 * n + 1);
}