
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

void clearInputBuffer(void);
void readText(const char *prompt, char *text, int size);
void addSuppliers(Supplier suppliers[], int count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);

int main(void)
{
    Supplier suppliers[MAX_SUPPLIERS];
    int choice;

    printf("====================================\n");
    printf("     SUPPLIER MANAGEMENT SYSTEM\n");
    printf("====================================\n");

    do {
        printf("\n1. Add Supplier Details\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier by Name\n");
        printf("4. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        clearInputBuffer();

        switch (choice) {
            case 1:
                addSuppliers(suppliers, MAX_SUPPLIERS);
                break;

            case 2:
                displaySuppliers(suppliers, MAX_SUPPLIERS);
                break;

            case 3:
                searchSupplier(suppliers, MAX_SUPPLIERS);
                break;

            case 4:
                printf("Exiting Supplier Management System.\n");
                break;

            default:
                printf("Invalid choice. Choose 1 to 4.\n");
        }

    } while (choice != 4);

    return 0;
}

void clearInputBuffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        /* Discard remaining input */
    }
}

void readText(const char *prompt, char *text, int size)
{
    printf("%s", prompt);

    if (fgets(text, size, stdin) != NULL) {
        size_t length = strlen(text);

        if (length > 0 && text[length - 1] == '\n') {
            text[length - 1] = '\0';
        } else {
            clearInputBuffer();
        }
    } else {
        text[0] = '\0';
    }
}

void addSuppliers(Supplier suppliers[], int count)
{
    int i;

    printf("\n--- Enter Supplier Details ---\n");

    for (i = 0; i < count; i++) {
        printf("\nSupplier %d\n", i + 1);

        readText("Name: ", suppliers[i].name, NAME_LENGTH);
        readText("Email: ", suppliers[i].email, EMAIL_LENGTH);
        readText("Phone: ", suppliers[i].phone, PHONE_LENGTH);
        readText("Town: ", suppliers[i].town, TOWN_LENGTH);
    }

    printf("\nAll %d suppliers have been recorded.\n", count);
}

void displaySuppliers(const Supplier suppliers[], int count)
{
    int i;

    printf("\n--- Registered Suppliers ---\n");

    for (i = 0; i < count; i++) {
        if (suppliers[i].name[0] == '\0') {
            continue;
        }

        printf("\nSupplier %d\n", i + 1);
        printf("Name:  %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Phone: %s\n", suppliers[i].phone);
        printf("Town:  %s\n", suppliers[i].town);
    }
}

void searchSupplier(const Supplier suppliers[], int count)
{
    char searchName[NAME_LENGTH];
    int i;
    int found = 0;

    readText("\nEnter supplier name to search for: ",
             searchName, NAME_LENGTH);

    for (i = 0; i < count; i++) {
        if (suppliers[i].name[0] != '\0' &&
            strcmp(suppliers[i].name, searchName) == 0) {

            printf("\nSupplier found!\n");
            printf("Name:  %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Phone: %s\n", suppliers[i].phone);
            printf("Town:  %s\n", suppliers[i].town);

            found = 1;
        }
    }

    if (!found) {
        printf("Supplier '%s' was not found.\n", searchName);
    }
}
