// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    do
    {
        printf("Card Number: ");
        scanf("%li", &number);
    }
    while (number < 0);

    // Case 1: Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    int num_1, num_2, num_3, num_4, num_5, num_6, num_7, num_8;
    int num_9, num_10, num_11, num_12, num_13, num_14, num_15, num_16;
    int sum1, sum2, sum3;
    num_1 = ((number % 100)/ 10) * 2;
    num_2 = ((number % 10000)/ 1000 * 2);
    num_3 = ((number % 1000000)/ 100000 * 2);
    num_4 = ((number % 100000000)/ 10000000 * 2);
    num_5 = ((number % 10000000000)/ 1000000000 * 2);
    num_6 = ((number % 1000000000000)/ 100000000000 * 2);
    num_7 = ((number % 100000000000000)/ 10000000000000 * 2);
    num_8 = ((number % 10000000000000000)/ 1000000000000000 * 2);

    // Since we only want digits 0-9 eliminate none digits 10- 18
    num_1 = (num_1 % 100 / 10) + (num_1 % 10);
    num_2 = (num_2 % 100 / 10) + (num_2 % 10);
    num_3 = (num_3 % 100 / 10) + (num_3 % 10);
    num_4 = (num_4 % 100 / 10) + (num_4 % 10);
    num_5 = (num_5 % 100 / 10) + (num_5 % 10);
    num_6 = (num_6 % 100 / 10) + (num_6 % 10);
    num_7 = (num_7 % 100 / 10) + (num_7 % 10);
    num_8 = (num_8 % 100 / 10) + (num_8 % 10);

    sum1 = num_1 + num_2 + num_3 + num_4 + num_5 + num_6 + num_7 + num_8;

    // Case 2: The numbers that were no multiplied by 2
    num_9 = (number % 10);
    num_10 = ((number % 1000) / 100);
    num_11 = ((number % 100000) / 10000);
    num_12 = ((number % 10000000) / 1000000);
    num_13 = ((number % 1000000000) / 100000000);
    num_14 = ((number % 100000000000) / 10000000000);
    num_15 = ((number % 10000000000000) / 1000000000000);
    num_16 = ((number % 1000000000000000) / 100000000000000);

    sum2 = num_9 + num_10 + num_11 + num_12 + num_13 + num_14 + num_15 + num_16;

    sum3 = sum1 + sum2;


        int length = 0;
        long Visa, Amex, Master;
        Visa = number;
        Amex = number;
        Master = number;

    if ((sum3 % 10) != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    // Length of the card

        while (number > 0)
        {
            number = number / 10;
            length++;
        }

        // Check VISA
        while (Visa >= 10)
        {
            Visa /= 10;
        }
        if (Visa == 4 && (length == 13 || length == 16))
        {
            printf("VISA\n");
            return 0;
        }

        // Check AMEX
        while (Amex >= 10000000000000)
        {
            Amex /= 10000000000000;
        }
        if (length == 15 && (Amex == 34 || Amex == 37))
        {
            printf("AMEX\n");
            return 0;
        }

        // Check MASTERCARD
        while (Master >= 100000000000000)
        {
            Master /= 100000000000000;
        }
        if (length == 16 && (Master == 51 || Master == 52 || Master == 53 || Master == 54 || Master == 55))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
        }
    }