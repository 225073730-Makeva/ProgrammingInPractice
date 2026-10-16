
#include <stdio.h>
#include "storage.h"

#define MAX_RECORDS 50

struct Record {
    int id;
    char name[50];
    float amount;
};

struct Record employees[MAX_RECORDS];
struct Record suppliers[MAX_RECORDS];
struct Record assets[MAX_RECORDS];
struct Record budgets[MAX_RECORDS];

int employeeCount = 0;
int supplierCount = 0;
int assetCount = 0;
int budgetCount = 0;

void saveRecords(char filename[], struct Record records[],
                 int count)
{
    FILE *fp;
    int i;

    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Could not open file for saving: %s\n", filename);
        return;
    }

    for (i = 0; i < count; i++) {
        if (fprintf(fp, "%d|%s|%.2f\n",
                    records[i].id,
                    records[i].name,
                    records[i].amount) < 0) {
            printf("Error saving data.\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);
    printf("Saved data to %s.\n", filename);
}

void loadRecords(char filename[], struct Record records[],
                 int *count)
{
    FILE *fp;
    int id;
    char name[50];
    float amount;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file for loading: %s\n", filename);
        return;
    }

    *count = 0;

    while (*count < MAX_RECORDS &&
           fscanf(fp, "%d|%49[^|]|%f",
                  &id, name, &amount) == 3) {
        records[*count].id = id;
        snprintf(records[*count].name,
                 sizeof records[*count].name, "%s", name);
        records[*count].amount = amount;
        (*count)++;
    }

    if (ferror(fp)) {
        printf("Error reading file: %s\n", filename);
    } else {
        printf("Loaded %d records from %s.\n", *count, filename);
    }

    fclose(fp);
}

void saveEmployeeBinary(void)
{
    FILE *fp;

    fp = fopen("data/employees.dat", "wb");

    if (fp == NULL) {
        printf("Could not open binary file for saving.\n");
        return;
    }

    if (fwrite(employees, sizeof employees[0],
               employeeCount, fp) != (size_t)employeeCount) {
        printf("Error writing binary file.\n");
    } else {
        printf("Employee records saved in binary format.\n");
    }

    fclose(fp);
}

void loadEmployeeBinary(void)
{
    FILE *fp;

    fp = fopen("data/employees.dat", "rb");

    if (fp == NULL) {
        printf("Could not open binary file for loading.\n");
        return;
    }

    employeeCount = 0;

    while (employeeCount < MAX_RECORDS &&
           fread(&employees[employeeCount],
                 sizeof employees[0], 1, fp) == 1) {
        employeeCount++;
    }

    if (ferror(fp)) {
        printf("Error reading binary file.\n");
    } else {
        printf("Loaded %d employee records from binary file.\n",
               employeeCount);
    }

    fclose(fp);
}

void manageData(void)
{
    int choice;

    do {
        printf("\n--- Data Storage ---\n");
        printf("1. Add employee record\n");
        printf("2. Add supplier record\n");
        printf("3. Add asset record\n");
        printf("4. Add budget record\n");
        printf("5. Save all data\n");
        printf("6. Load all data\n");
        printf("7. Save employees as binary\n");
        printf("8. Load employees from binary\n");
        printf("9. Return to main menu\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        while (getchar() != '\n');

        if (choice >= 1 && choice <= 4) {
            struct Record *records;
            int *count;
            char *type;

            if (choice == 1) {
                records = employees;
                count = &employeeCount;
                type = "Employee";
            } else if (choice == 2) {
                records = suppliers;
                count = &supplierCount;
                type = "Supplier";
            } else if (choice == 3) {
                records = assets;
                count = &assetCount;
                type = "Asset";
            } else {
                records = budgets;
                count = &budgetCount;
                type = "Budget";
            }

            if (*count >= MAX_RECORDS) {
                printf("Maximum number of records reached.\n");
                continue;
            }

            printf("Enter %s ID: ", type);

            if (scanf("%d", &records[*count].id) != 1) {
                printf("Invalid ID.\n");
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n');

            printf("Enter %s name (do not use |): ", type);

            if (scanf("%49[^\n]", records[*count].name) != 1) {
                printf("Invalid name.\n");
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n');

            printf("Enter amount: ");

            if (scanf("%f", &records[*count].amount) != 1 ||
                records[*count].amount < 0) {
                printf("Invalid amount.\n");
                while (getchar() != '\n');
                continue;
            }

            while (getchar() != '\n');

            (*count)++;
            printf("%s record added.\n", type);

        } else if (choice == 5) {
            saveRecords("data/employees.txt",
                        employees, employeeCount);
            saveRecords("data/suppliers.txt",
                        suppliers, supplierCount);
            saveRecords("data/assets.txt",
                        assets, assetCount);
            saveRecords("data/budgets.txt",
                        budgets, budgetCount);

        } else if (choice == 6) {
            loadRecords("data/employees.txt",
                        employees, &employeeCount);
            loadRecords("data/suppliers.txt",
                        suppliers, &supplierCount);
            loadRecords("data/assets.txt",
                        assets, &assetCount);
            loadRecords("data/budgets.txt",
                        budgets, &budgetCount);

        } else if (choice == 7) {
            saveEmployeeBinary();

        } else if (choice == 8) {
            loadEmployeeBinary();

        } else if (choice != 9) {
            printf("Invalid option. Try again.\n");
        }

    } while (choice != 9);
}
