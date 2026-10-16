
#include <stdio.h>

int main(void)
{
    float budget = 100000.00f;

    char supplierA[] = "Supplier A";
    char supplierB[] = "Supplier B";
    char supplierC[] = "Supplier C";
    char supplierD[] = "Supplier D";

    float priceA = 95000.00f;
    float priceB = 88000.00f;
    float priceC = 82000.00f;
    float priceD = 91000.00f;

    int registeredA = 1, documentsA = 1;
    int registeredB = 1, documentsB = 1;
    int registeredC = 0, documentsC = 1;
    int registeredD = 1, documentsD = 0;

    int qualifiedA = registeredA == 1 &&
                     documentsA == 1 && priceA <= budget;

    int qualifiedB = registeredB == 1 &&
                     documentsB == 1 && priceB <= budget;

    int qualifiedC = registeredC == 1 &&
                     documentsC == 1 && priceC <= budget;

    int qualifiedD = registeredD == 1 &&
                     documentsD == 1 && priceD <= budget;

    float lowestPrice = budget + 1;

    if (qualifiedA && priceA < lowestPrice)
    {
        lowestPrice = priceA;
    }

    if (qualifiedB && priceB < lowestPrice)
    {
        lowestPrice = priceB;
    }

    if (qualifiedC && priceC < lowestPrice)
    {
        lowestPrice = priceC;
    }

    if (qualifiedD && priceD < lowestPrice)
    {
        lowestPrice = priceD;
    }

    printf("TENDER EVALUATION REPORT\n");
    printf("------------------------\n");
    printf("Available budget: NAD %.2f\n\n", budget);

    if (!qualifiedA)
    {
        printf("%s: Disqualified\n", supplierA);
    }
    else if (priceA == lowestPrice)
    {
        printf("%s: Preferred Supplier\n", supplierA);
    }
    else
    {
        printf("%s: Qualified\n", supplierA);
    }

    if (!qualifiedB)
    {
        printf("%s: Disqualified\n", supplierB);
    }
    else if (priceB == lowestPrice)
    {
        printf("%s: Preferred Supplier\n", supplierB);
    }
    else
    {
        printf("%s: Qualified\n", supplierB);
    }

    if (!qualifiedC)
    {
        printf("%s: Disqualified\n", supplierC);
    }
    else if (priceC == lowestPrice)
    {
        printf("%s: Preferred Supplier\n", supplierC);
    }
    else
    {
        printf("%s: Qualified\n", supplierC);
    }

    if (!qualifiedD)
    {
        printf("%s: Disqualified\n", supplierD);
    }
    else if (priceD == lowestPrice)
    {
        printf("%s: Preferred Supplier\n", supplierD);
    }
    else
    {
        printf("%s: Qualified\n", supplierD);
    }

    return 0;
}
