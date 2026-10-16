
#include <stdio.h>

int main(void)
{
    int numberOfEmployees;
    int i;
    double salary;
    double totalSalary = 0.0;
    double highestSalary;
    double lowestSalary;
    double averageSalary;

    printf("MUNICIPAL EMPLOYEE SALARY ANALYSIS\n");
    printf("----------------------------------\n");

    printf("Enter number of employees (1-50): ");

    if (scanf("%d", &numberOfEmployees) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (numberOfEmployees < 1 || numberOfEmployees > 50)
    {
        printf("Please enter a number from 1 to 50.\n");
        return 1;
    }

    for (i = 1; i <= numberOfEmployees; i++)
    {
        printf("Enter salary for employee %d: ", i);

        if (scanf("%lf", &salary) != 1)
        {
            printf("Invalid salary input.\n");
            return 1;
        }

        if (salary < 0)
        {
            printf("Salary cannot be negative.\n");
            return 1;
        }

        if (i == 1)
        {
            highestSalary = salary;
            lowestSalary = salary;
        }
        else
        {
            if (salary > highestSalary)
            {
                highestSalary = salary;
            }

            if (salary < lowestSalary)
            {
                lowestSalary = salary;
            }
        }

        totalSalary += salary;
    }

    averageSalary = totalSalary / numberOfEmployees;

    printf("\n--- Salary Analysis Results ---\n");
    printf("Number of Employees: %d\n", numberOfEmployees);
    printf("Total Salary: NAD %.2f\n", totalSalary);
    printf("Average Salary: NAD %.2f\n", averageSalary);
    printf("Highest Salary: NAD %.2f\n", highestSalary);
    printf("Lowest Salary: NAD %.2f\n", lowestSalary);

    return 0;
}
