#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./cat <filename>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        printf("%c", c);
    }
    
    return 0;
}