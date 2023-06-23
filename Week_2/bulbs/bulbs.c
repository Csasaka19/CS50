#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message: ");
    int length = strlen(message);

    for (int i = 0; i < length; i++)
    {
        // Convert to ASCII
        int to_ascii = message[i];
        // Divide by two and its modulo to get the binary number
        int j = 0;
        int bin_no[] = {0, 0, 0, 0, 0, 0, 0, 0};
        while (to_ascii > 0)
        {
            bin_no[j] = to_ascii % 2;
            to_ascii /= 2;
            j++;
        }
        // print out the result
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(bin_no[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
