#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./initials <name>\n");
    }
    // Given a name, print the initials of the first and last name
    printf("%c.%c\n", toupper(argv[1][0]), toupper(argv[2][0]));
}