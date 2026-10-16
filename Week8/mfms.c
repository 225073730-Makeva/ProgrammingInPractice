
#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 10
#define NAME_LENGTH 100
#define EMAIL_LENGTH 100
#define PHONE_LENGTH 25
#define TOWN_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    char phone[PHONE_LENGTH];
    char town[TOWN_LENGTH];
} Supplier;

/* Function prototypes */
void clearInputBuffer(void);
int readNumber(const char *prompt, int *number);
int readDouble(const char *prompt, double *value);
void readText(const char *prompt, char *text, int size);

void displayMenu(void);
double calculateSalary(double basic, double housing, double transport);
double calculateVAT(double amount);
double calculateBudget(double revenue, double expenses);

void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);

Supplier suppliers[MAX_SUPPLIERS];
int supplierCount = 0;

int main(void)
{
    int choice;

    do {
        displayMenu();

        if (!readNumber("Choose an option: ", &choice)) {
            printf("Invalid input. Enter a menu number.\n");
            continue;
        }

        switch (choice) {
            case 1: {
                double basic, housing, transport;

                if (!readDouble("Basic salary (NAD): ", &basic) ||
                    !readDouble("Housing allowance (NAD): ", &housing) ||
                    !readDouble("Transport allowance (NAD): ", &transport)) {
                    printf("Invalid amount. Please enter valid numbers.\n");
                    break;
                }

                if (basic < 0 || housing < 0 || transport < 0) {
                    printf("Amounts cannot be negative.\n");
                    break;
                }

                printf("Total salary: NAD %.2f\n",
                       calculateSalary(basic, housing, transport));
                break;
            }

            case 2: {
                double amount;

                if (!readDouble("Enter amount before VAT (NAD): ", &amount)) {
                    printf("Invalid amount.\n");
                    break;
                }

                if (amount < 0) {
                    printf("Amount cannot be negative.\n");
                    break;
                }

                printf("VAT at 15%%: NAD %.2f\n", calculateVAT(amount));
                printf("Amount including VAT: NAD %.2f\n",
                       amount + calculateVAT(amount));
                break;
            }

            case 3: {
                double revenue, expenses;

                if (!readDouble("Enter revenue (NAD): ", &revenue) ||
                    !readDouble("Enter expenses (NAD): ", &expenses)) {
                    printf("Invalid amount.\n");
                    break;
                }

                if (revenue < 0 || expenses < 0) {
                    printf("Amounts cannot be negative.\n");
                    break;
                }

                printf("Remaining budget: NAD %.2f\n",
                       calculateBudget(revenue, expenses));
                break;
            }

            case 4:
                addSupplier();
                break;

            case 5:
                displaySuppliers();
                break;

            case 6:
                searchSupplier();
                break;

            case 7:
                printf("Exiting MFMS. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Select 1 to 7.\n");
        }

        printf("\n");

    } while (choice != 7);

    return 0;
}

void displayMenu(void)
{
    printf("========================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Calculate Employee Salary\n");
    printf("2. Calculate VAT\n");
    printf("3. Calculate Budget\n");
    printf("4. Add Supplier\n");
    printf("5. Display Suppliers\n");
    printf("6. Search Supplier\n");
    printf("7. Exit\n");
}

int readNumber(const char *prompt, int *number)
{
    int result;

    printf("%s", prompt);
    result = scanf("%d", number);
    clearInputBuffer();

    return result == 1;
}

int readDouble(const char *prompt, double *value)
{
    int result;

    printf("%s", prompt);
    result = scanf("%lf", value);
    clearInputBuffer();

    return result == 1;
}

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* Discard remaining characters */
    }
}

void readText(const char *prompt, char *text, int size)
{
    size_t length;

    printf("%s", prompt);

    if (fgets(text, size, stdin) == NULL) {
        text[0] = '\0';
        return;
    }

    length = strlen(text);

    if (length > 0 && text[length - 1] == '\n') {
        text[length - 1] = '\0';
    } else {
        clearInputBuffer();
    }
}

double calculateSalary(double basic, double housing, double transport)
{
    return basic + housing + transport;
}

double calculateVAT(double amount)
{
    return amount * 0.15;
}

double calculateBudget(double revenue, double expenses)
{
    return revenue - expenses;
}

void addSupplier(void)
{
    Supplier *supplier;

    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }

    supplier = &suppliers[supplierCount];

    printf("\n--- Add Supplier ---\n");
    readText("Name: ", supplier->name, NAME_LENGTH);
    readText("Email: ", supplier->email, EMAIL_LENGTH);
    readText("Phone: ", supplier->phone, PHONE_LENGTH);
    readText("Town: ", supplier->town, TOWN_LENGTH);

    if (supplier->name[0] == '\0') {
        printf("Supplier name cannot be empty. Record not saved.\n");
        return;
    }

    supplierCount++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers(void)
{
    int i;

    if (supplierCount == 0) {
        printf("No suppliers have been added yet.\n");
        return;
    }

    printf("\n--- Supplier List ---\n");

    for (i = 0; i < supplierCount; i++) {
        printf("\nSupplier %d\n", i + 1);
        printf("Name:  %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Phone: %s\n", suppliers[i].phone);
        printf("Town:  %s\n", suppliers[i].town);
    }
}

void searchSupplier(void)
{
    char searchName[NAME_LENGTH];
    int i;
    int found = 0;

    if (supplierCount == 0) {
        printf("No suppliers are available to search.\n");
        return;
    }

    readText("Enter supplier name: ", searchName, NAME_LENGTH);

    for (i = 0; i < supplierCount; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("\nSupplier found!\n");
            printf("Name:  %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Phone: %s\n", suppliers[i].phone);
            printf("Town:  %s\n", suppliers[i].town);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Supplier '%s' was not found.\n", searchName);
    }
}
