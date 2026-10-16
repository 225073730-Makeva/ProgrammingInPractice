
#include <stdio.h>

int main(void)
{
    float basicSalary;
    float housing;
    float transport;
    float tax;
    float grossSalary;
    float netSalary;

    printf("EMPLOYEE SALARY CALCULATOR\n");
    printf("--------------------------\n");

    printf("Enter basic salary: ");
    if (scanf("%f", &basicSalary) != 1)
    {
        printf("Invalid salary input.\n");
        return 1;
    }

    printf("Enter housing allowance: ");
    if (scanf("%f", &housing) != 1)
    {
        printf("Invalid housing allowance.\n");
        return 1;
    }

    printf("Enter transport allowance: ");
    if (scanf("%f", &transport) != 1)
    {
        printf("Invalid transport allowance.\n");
        return 1;
    }

    printf("Enter tax: ");
    if (scanf("%f", &tax) != 1)
    {
        printf("Invalid tax input.\n");
        return 1;
    }

    grossSalary = basicSalary + housing + transport;
    netSalary = grossSalary - tax;

    printf("\n--- Salary Results ---\n");
    printf("Basic Salary: %.2f\n", basicSalary);
    printf("Housing Allowance: %.2f\n", housing);
    printf("Transport Allowance: %.2f\n", transport);
    printf("Tax: %.2f\n", tax);
    printf("Gross Salary: %.2f\n", grossSalary);
    printf("Net Salary: %.2f\n", netSalary);

    if (netSalary >= 20000)
    {
        printf("Income Category: High Income\n");
    }
    else
    {
        printf("Income Category: Standard Income\n");
    }

    return 0;
}
