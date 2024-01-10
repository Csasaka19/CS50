#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    if (*input == '\0'){
       // printf("The string input is empty");
        return 0;
    }
    int lastdig = *input - '0';

    input++;

    int partialresult = convert(input);

     printf("Adding digit %i to partial result %i\n", lastdig, partialresult);

    return lastdig + partialresult * 10;
}