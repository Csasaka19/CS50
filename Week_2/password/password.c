#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number, and symbol\n");
    }
}

bool valid(string password)
{
    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_symbol = false;

    for (int i = 0; i < strlen(password); i++)
    {
        if (isupper(password[i]))
        {
            has_upper = true;
        }
        else if (islower(password[i]))
        {
            has_lower = true;
        }
        else if (isdigit(password[i]))
        {
            has_digit = true;
        }
        else if (ispunct(password[i]))
        {
            has_symbol = true;
        }
    }

    // Check if all required conditions are met
    return has_upper && has_lower && has_digit && has_symbol;
}
