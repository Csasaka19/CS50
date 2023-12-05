// #include <cs50.h>
#include <stdio.h>

int main(void) 
{
    int height;
    do
    {
        printf("Height: ");
        scanf("%d", &height);
    } while (height < 1 || height > 8);
    // If the user fails provide required input, you should re-prompt for the same

    for (int i = 0; i < height; i++)
    {
        //print spaces according to the current row
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    
}