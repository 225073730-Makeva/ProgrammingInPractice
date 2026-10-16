
#include <stdio.h>
#include "employees.h"

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

void calculateEmployeeSalary(void)
{
    float basic, housing, transport, total;

    printf("\n--- Employee Salary ---\n");

    printf("Enter basic salary: ");
    if (scanf("%f", &basic) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter housing allowance: ");
    if (scanf("%f", &housing) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    printf("Enter transport allowance: ");
    if (scanf("%f", &transport) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    while (getchar() != '\n');

    if (basic < 0 || housing < 0 || transport < 0) {
        printf("Amounts cannot be negative.\n");
        return;
    }

    total = calculateSalary(basic, housing, transport);

    printf("Total salary: NAD %.2f\n", total);
}
