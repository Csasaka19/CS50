// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    } 
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

//  Return the max value
int max(int array[], int n)
{
    // Initialize max to the first element
    int max = array[0];
    // Iterate through the array
    for(int i = 0; i < n; i++)
    {
        if (array[i] > max)
        {
            // Update max if the current element is greater
            max = array[i];
        }
    }

    return max;
}
