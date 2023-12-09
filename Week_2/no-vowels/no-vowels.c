#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string a);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    string word = argv[1];
    string replaced = replace(word);
    printf("%s\n", replaced);
}

string replace(string a)
{
    for (int i = 0; i < strlen(a); i++)
    {
        switch (a[i])
        {
            case 'a':
                a[i] = '6';
                break;

            case 'e':
                a[i] = '3';
                break;

            case 'i':
                a[i] = '1';
                break;

            case 'o':
                a[i] = '0';
                break;

            case 'u':
                a[i] = 'u';
                break;
        }
    }
    return a;
}
