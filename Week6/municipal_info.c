
#include <stdio.h>
#include <string.h>

int main(void)
{
    float salaries[50];
    float budgets[10];
    char registrations[20][20];

    float total, average, highest, lowest, temp;
    float searchSalary;
    int found, i, j;

    char searchRegistration[20];

    /* A. EMPLOYEE SALARIES */
    printf("========================================\n");
    printf("     MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("========================================\n");
    printf("\n--- A. Employee Salary Management ---\n");

    total = 0.0f;

    for (i = 0; i < 50; i++)
    {
        printf("Enter salary for employee %d (NAD): ", i + 1);

        if (scanf("%f", &salaries[i]) != 1 ||
            salaries[i] < 0.0f)
        {
            printf("Invalid salary. Enter a non-negative number.\n");
            return 1;
        }

        total += salaries[i];
    }

    highest = salaries[0];
    lowest = salaries[0];

    printf("\n--- All Employee Salaries ---\n");

    for (i = 0; i < 50; i++)
    {
        printf("Employee %d: NAD %.2f\n", i + 1, salaries[i]);

        if (salaries[i] > highest)
            highest = salaries[i];

        if (salaries[i] < lowest)
            lowest = salaries[i];
    }

    average = total / 50.0f;

    printf("\nTotal salary expenditure: NAD %.2f\n", total);
    printf("Average salary: NAD %.2f\n", average);
    printf("Highest salary: NAD %.2f\n", highest);
    printf("Lowest salary: NAD %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");

    if (scanf("%f", &searchSalary) != 1)
    {
        printf("Invalid search input.\n");
        return 1;
    }

    found = 0;

    for (i = 0; i < 50; i++)
    {
        if (salaries[i] == searchSalary)
        {
            printf("Salary found for Employee %d.\n", i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("Salary not found.\n");

    /* Sort salaries from lowest to highest */
    for (i = 0; i < 49; i++)
    {
        for (j = 0; j < 49 - i; j++)
        {
            if (salaries[j] > salaries[j + 1])
            {
                temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    printf("\n--- Salaries Sorted (Lowest to Highest) ---\n");

    for (i = 0; i < 50; i++)
        printf("NAD %.2f\n", salaries[i]);

    /* B. DEPARTMENT BUDGETS */
    printf("\n--- B. Department Budget Management ---\n");

    total = 0.0f;

    for (i = 0; i < 10; i++)
    {
        printf("Enter budget for department %d (NAD): ", i + 1);

        if (scanf("%f", &budgets[i]) != 1 ||
            budgets[i] < 0.0f)
        {
            printf("Invalid budget. Enter a non-negative number.\n");
            return 1;
        }

        total += budgets[i];
    }

    printf("\n--- Original Department Budgets ---\n");

    for (i = 0; i < 10; i++)
        printf("Department %d: NAD %.2f\n", i + 1, budgets[i]);

    average = total / 10.0f;

    printf("Total department budget: NAD %.2f\n", total);
    printf("Average department budget: NAD %.2f\n", average);

    /* Sort budgets from lowest to highest */
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9 - i; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");

    for (i = 0; i < 10; i++)
        printf("NAD %.2f\n", budgets[i]);

    /* C. VEHICLE REGISTRATIONS */
    printf("\n--- C. Vehicle Registration Management ---\n");

    for (i = 0; i < 20; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);

        if (scanf("%19s", registrations[i]) != 1)
        {
            printf("Invalid registration input.\n");
            return 1;
        }
    }

    printf("\n--- Registered Vehicles ---\n");

    for (i = 0; i < 20; i++)
        printf("Vehicle %d: %s\n", i + 1, registrations[i]);

    printf("\nEnter a registration number to search for: ");

    if (scanf("%19s", searchRegistration) != 1)
    {
        printf("Invalid search input.\n");
        return 1;
    }

    found = 0;

    for (i = 0; i < 20; i++)
    {
        if (strcmp(registrations[i], searchRegistration) == 0)
        {
            printf("Registration found at position %d.\n", i + 1);
            found = 1;
        }
    }

    if (!found)
        printf("Registration number not found.\n");

    printf("\nAll Week 6 tasks completed.\n");

    return 0;
}
