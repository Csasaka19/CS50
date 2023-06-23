#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
//  Program must accept a single command-line argument
// If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error message of your choice and return from main a value of 1
if (argc != 2)
{
    printf("Usage: ./caesar key\n");
    return 1;
}
// If any of the characters of the command-line argument is not a decimal digit, your program should print the message Usage: ./caesar key and return from main a value of 1.
bool result = only_digits(argv[1]);
if (result == false)
{
    printf("Usage: ./caesar key\n");
    return 1;
}
// Convert string to integer
int key = atoi(argv[1]);
// printf("%i", key);

string plain = get_string("plaintext: \n");

for (int k = 0, length = strlen(plain); k < length; k++)
{
    // replace letters on the plain text
    plain[k] = rotate(plain[k], key);
}
printf("ciphertext: %s", plain);
return 0;
}

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == false)
        {
             return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    int cipher;
    if (isalpha(c) == true)
    {
        if (isupper(c) == true)
        {
            // Covert to a range of 0 - 25..0 = A, 1 = B .....
            int upper = c - 65;
            // Apply the formula c = (p + k) % 26 where c = ciphertext p = plain text and k = key
            // Wrap around Z to A
            cipher = (upper + n) % 26;
            cipher += 65;
            return (char) c;

        }
        else
        {
            // Covert to a range of 0 - 25...0 = a, 1 = b .....
            int lower = c - 97;
            // Apply the formula c = (p + k) % 26 where c = ciphertext p = plain text and k = key
            // Wrap around from z to a
            cipher = (lower + n) % 26;
            cipher += 97;
            return (char) c;
        }
    }
        return c;

}