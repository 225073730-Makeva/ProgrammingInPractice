
#include <stdio.h>

int main(void)
{
    int budgets[10];
    int numberOfDepartments;
    int i;
    int j;
    int searchBudget;
    int found = 0;
    int temp;

    printf("MUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
    printf("---------------------------------------\n");

    printf("Enter number of departments (1-10): ");

    if (scanf("%d", &numberOfDepartments) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (numberOfDepartments < 1 || numberOfDepartments > 10)
    {
        printf("Enter a number from 1 to 10.\n");
        return 1;
    }

    /* Capture the department budgets */
    for (i = 0; i < numberOfDepartments; i++)
    {
        printf("Enter budget for department %d (NAD): ", i + 1);

        if (scanf("%d", &budgets[i]) != 1 || budgets[i] < 0)
        {
            printf("Invalid budget. Enter a non-negative whole number.\n");
            return 1;
        }
    }

    /* Display the original budgets */
    printf("\n--- Department Budgets ---\n");

    for (i = 0; i < numberOfDepartments; i++)
    {
        printf("Department %d: NAD %d\n", i + 1, budgets[i]);
    }

    /* Search for a budget */
    printf("\nEnter a budget to search for: ");

    if (scanf("%d", &searchBudget) != 1)
    {
        printf("Invalid search input.\n");
        return 1;
    }

    for (i = 0; i < numberOfDepartments; i++)
    {
        if (budgets[i] == searchBudget)
        {
            printf("Budget found at position %d (Department %d).\n",
                   i + 1, i + 1);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Budget not found.\n");
    }

    /* Sort budgets in ascending order */
    for (i = 0; i < numberOfDepartments - 1; i++)
    {
        for (j = 0; j < numberOfDepartments - 1 - i; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    /* Display the sorted budgets */
    printf("\n--- Budgets Sorted (Lowest to Highest) ---\n");

    for (i = 0; i < numberOfDepartments; i++)
    {
        printf("NAD %d\n", budgets[i]);
    }

    return 0;
}
