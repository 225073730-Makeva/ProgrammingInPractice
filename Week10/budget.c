
#include <stdio.h>
#include "budget.h"

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

void calculateDepartmentBudget(void)
{
    float revenue, expenses, balance;

    printf("\n--- Department Budget ---\n");

    printf("Enter revenue: ");
    if (scanf("%f", &revenue) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter expenses: ");
    if (scanf("%f", &expenses) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    while (getchar() != '\n');

    if (revenue < 0 || expenses < 0) {
        printf("Amounts cannot be negative.\n");
        return;
    }

    balance = calculateBudget(revenue, expenses);

    printf("Remaining budget: NAD %.2f\n", balance);
}
