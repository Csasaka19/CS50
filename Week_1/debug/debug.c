// Become familiar wih C syntax
// Learn to debug buggy code

// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask for your name and where live
    char name[20];
    char location[20];
    printf("What is your name? ");
    scanf("%s", name);
    printf("Where do you live? "); 
    scanf("%s", location);
    
    // Say hello
    printf("Hello, %s, from %s\n!", name, location);
}
