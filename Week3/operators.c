
#include <stdio.h>

int main(void)
{
    float revenue;
    float expenses;
    float balance;

    printf("MUNICIPAL BUDGET CALCULATOR\n");

    printf("Enter total revenue: ");
    scanf("%f", &revenue);

    printf("Enter total expenses: ");
    scanf("%f", &expenses);

    balance = revenue - expenses;

    printf("\n--- Budget Results ---\n");
    printf("Revenue: %.2f\n", revenue);
    printf("Expenses: %.2f\n", expenses);
    printf("Balance: %.2f\n", balance);

    return 0;
}
