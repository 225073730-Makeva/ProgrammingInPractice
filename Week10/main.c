
#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"
#include "storage.h"

int main(void)
{
    int choice;

    do {
        displayWelcome();
        displayReportMenu();

        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Enter a number.\n");

            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        while (getchar() != '\n');

       
switch (choice) {
    case 1:
        calculateEmployeeSalary();
        break;

    case 2:
        calculateVATAmount();
        break;

    case 3:
        calculateDepartmentBudget();
        break;

    case 4:
        manageData();
        break;

    case 5:
        printf("Program closed.\n");
        break;

    default:
        printf("Invalid option. Try again.\n");
}


    } while (choice != 5);

    return 0;
}
