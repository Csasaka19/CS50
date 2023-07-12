#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
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

    int position = 0;
    // Check for redundant alphabet in key
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = i + 1; j < strlen(key); j++)
        {
            // The string may have different cases
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Redundant alphabetical characters used \n");
                return 1;
            }
        }
    }
    // Prompt user for text
    string plain = get_string("plaintext: ");

    // For uniformity change the whole key to uppercase
    for (int k = 0; k < strlen(key); k++)
    {
        if (islower(key[k]))
        {
            // In ASCII lower letters are 32 digits more
            key[k] -= 32;
        }
    }
    printf("ciphertext: ");
    // Cipher the text
    for (int l = 0; l < strlen(plain); l++)
    {
        if (isupper(plain[l]))
        {
            position = plain[l] - 65;
            printf("%c", key[position]);
        }
        else if (islower(plain[l]))
        {
            position = plain[l] - 97;
            // Convert back to lower case
            printf("%c", key[position] + 32);
        }
        else
        {
            printf("%c", plain[l]);
        }
    }
    printf("\n");

    return 0;
}
