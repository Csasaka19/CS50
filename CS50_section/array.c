#include <stdio.h>

int main(void)
{
    // Ask user for size of array dynamically
    int number;
    do
    {
       printf("Enter a positive number: ");
       scanf("%i", &number);
    } while (number < 0);

    // Declare an array of size number

    int twice[number];
    for (int i = 0; i < number; i++)
    {
        // Assign value to each element
        // Each element is twice the previous element
        twice[i] = i * 2;
        // Print each element
        printf("twice[%i] = %i\n", i, twice[i]);
    }
    
    return 0;
    
}