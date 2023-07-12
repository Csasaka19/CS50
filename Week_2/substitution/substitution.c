#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // When there is more or less than one command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    // Checking if it is alphabetical
    string key = argv[1];
    int len = strlen(key);
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            printf("Non alphabetical characters forbidden!\n");
            return 1;
        }
    }
    // If argument count is less or more than 26 characters
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }



    //Prompt user for text
    // string plain = get_string("plaintext: ");



}