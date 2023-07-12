#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool unique_alphabets(string a);

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

    if (unique_alphabets(key) == true)
    {
        //Prompt user for text
         string plain = get_string("plaintext: ");
    }



}

bool unique_alphabets(string a)
{
    // Checks if the key contains unique alphabets
    for(int i = 0; i < strlen(a); i++)
    {
        for(int j = i + 1; j < strlen(a); j++)
        {
            // The string may have different cases
            if (tolower(a[i]) == tolower(a[j]))
            {
                printf("Redundant alphabetical characters used \n");
                return false;
            }
        }
    }
    return true;
}