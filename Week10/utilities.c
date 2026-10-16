
#include <stdio.h>
#include "utilities.h"

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

void calculateVATAmount(void)
{
    float amount, vat;

    printf("\n--- VAT Calculator ---\n");
    printf("Enter amount before VAT: ");

    if (scanf("%f", &amount) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    while (getchar() != '\n');

    if (amount < 0) {
        printf("Amount cannot be negative.\n");
        return;
    }

    vat = calculateVAT(amount);

    printf("VAT at 15%%: NAD %.2f\n", vat);
    printf("Total including VAT: NAD %.2f\n", amount + vat);
}
