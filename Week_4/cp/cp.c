#include <stdio.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
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
    FILE *file2 = fopen(argv[2], "w");
    if(file2 == NULL)
    {
        printf("File not found\n");
        return 1;
    }
    
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        // Copies the contents of file to file2
        fputc(c, file2);
    }
    
    return 0;
}