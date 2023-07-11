#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // If argument is less than 0
    if (argc < 0)
    {
        printf("Substitution key is required ./substitution key\n");
        return 1;
    }
    // When argument is more than 1
    else if (argc > 1)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    // Count
    int count = 0;
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        // Look for non alphabetical characters
        if (!isalpha(argv[i]))
        {
            printf("The key should not have a digit or any special character");
            return 1;
        }
        count ++;
    }
    // If argument count is less than 26 characters
    else if (count < 26 || count > 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    // Number error when letters is not typed




}