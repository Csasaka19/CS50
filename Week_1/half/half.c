// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

// #include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount , tax_percent, tip_percent;
    printf("Bill before tax and tip: ");
    scanf("%f", &bill_amount);
    printf("Sale Tax Percent: ");
    scanf("%f", &tax_percent);
    printf("Tip percent: ");
    scanf("%f", &tip_percent);

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float tax_amount, final, bill_after, tip_final;
    tax_amount = bill * (tax / 100);
    bill_after = bill + tax_amount;
    tip_final = bill_after * ((float) tip / 100);
    final = tip_final + bill_after;

    return (final / 2);
}
