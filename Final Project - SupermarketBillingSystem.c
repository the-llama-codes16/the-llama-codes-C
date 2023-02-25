/* Project: Supermarket Billing System
Started: Aug 21, 2022
Finished: Sep 25, 2022
Note: I have work and I do this on my free time, so duration might be longer

By: Iam Rasendi M. Saldua
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define FLUSH while(getchar() != '\n')

//info for each product
typedef struct displayProduct {
    char itemCode[10];
    char name[30];
    char price[10];
} displayProduct;

void Header (void);
void BillingHeader (void);
void ProductHeader (void);
int MainPage (void);
int ProductPage (void);
void BillingPagePrep (void);
void BillingPageMain (void);
void AddProductInfo (void);
void GetSearchKey(char* searchKey, int* searchMethod);
int ExecuteProductSearch (char* searchKey, int* searchMethod, displayProduct* searchedProducts);
void DisplaySearchedProducts (displayProduct* searchedProducts, int searchResultCount);
void EditProductInfoIntro (void);
int GetProductToEdit (int searchResultCount);
void EditProductInfo (displayProduct* searchedProducts, int productToEdit);
void ExitGracefully (void);

int main (void) {
    //Main Page Data
    int mainPageNav;

    //Product Page Data
    int productPageNav;

    //SearchProductInfo data
    displayProduct* searchedProducts = (displayProduct*)calloc(10, sizeof(displayProduct));
    char* searchKey = (char*)calloc(30, sizeof(char));
    int* searchMethod = (int*)calloc(1, sizeof(int));
    int searchResultCount;

    //EditProductInfo data
    int productToEdit;

    //starting page
    Header();
    mainPageNav = MainPage();

    switch (mainPageNav) {
    case 1: //Billing Page
        BillingHeader();
        BillingPagePrep();
        BillingPageMain();
        break;
    case 2: //Product Page
        ProductHeader();
        productPageNav = ProductPage();
        switch (productPageNav) {
        case 1: //Add New Product
            ProductHeader();
            AddProductInfo();
            break;
        case 2: //Search Product Info
            ProductHeader();
            GetSearchKey(searchKey, searchMethod);
            searchResultCount = ExecuteProductSearch (searchKey, searchMethod, searchedProducts);
            DisplaySearchedProducts (searchedProducts, searchResultCount);
            break;
        case 3: //Edit Product Info
            ProductHeader();
            EditProductInfoIntro();
            GetSearchKey(searchKey, searchMethod);
            searchResultCount = ExecuteProductSearch (searchKey, searchMethod, searchedProducts);
            DisplaySearchedProducts (searchedProducts, searchResultCount);
            productToEdit = GetProductToEdit(searchResultCount);
            EditProductInfo (searchedProducts, productToEdit);
            break;
        case 4: //Exit
            ExitGracefully();
        }
        break;
    case 3: //Exit
        ExitGracefully();
        break;
    default:
        printf("Error input. Will exit now.\n");
        ExitGracefully();
    }

    //freeing dynamically allocated data
    free(searchedProducts);
    free(searchKey);
    free(searchMethod);

    return 0;
}

void Header (void) {
    printf("\n\n");
    printf("=====================================================\n");
    printf("              SUPERMARKET BILLING SYSTEM\n");
    printf("=====================================================\n");

    return;
}//Header


int MainPage (void) {
    int option;

    printf("1. Billing\n");
    printf("   (Enter products purchased and get a sales invoice)\n");
    printf("2. Product\n");
    printf("   (Add, Search, or Edit Product information)\n");
    printf("3. Exit\n");
    printf("\nEnter option: ");
    scanf("%d", &option);

    return option;
}//MainPage


void BillingHeader (void) {
    printf("\n\n");
    printf("=====================================================\n");
    printf("              SUPERMARKET BILLING SYSTEM\n");
    printf("                    - Billing Page -\n");
    printf("=====================================================\n");

    return;
}


void BillingPagePrep (void) {
    //check if there is already a record of products
    FILE* fhand = fopen("ProductList.txt", "r");
    if (fhand == NULL) {
        printf("\nA record of available products does not exist yet. Please add a new product using the Product Page to create a record.\n\n");
        exit(0);
    }
    else {
        printf("\nAccessing ProductList.txt...\n");

        //removing any existing Sales Invoice file
        remove("SalesInvoice.txt");

        fclose(fhand);
    }

    return;
}//BillingPagePrep


void BillingPageMain (void) {
    printf("Enter the item code of products purchased.");
    printf("\nRefer to ProductList.txt for the item codes.\n");

    //creating SalesInvoice header
    char* salesInvoiceHeader = (char*)calloc(200, sizeof(char));
    strcpy(salesInvoiceHeader, "-------------------------SALES INVOICE-------------------------\n\n");
    strcat(salesInvoiceHeader, "\n         Product Name        | Quantity | Unit Price |  Total  \n");
    FILE* fhand2 = fopen("SalesInvoice.txt", "w");
    fputs(salesInvoiceHeader, fhand2);
    fclose(fhand2);
    free(salesInvoiceHeader);

    //initializing variables for loop
    char addMore = 'Y';
    int itemCount = 1;
    FILE* fhand = NULL;
    int found = 0;
    char confirmProd = 'N';
    int grandTotal = 0;
    int stopper = 0;
    char* toWriteToSalesInvoice = (char*)calloc(500, sizeof(char));


    //while loop to add purchased products
    do {
        char* itemCodeInput = (char*)calloc(10, sizeof(char));
        char* itemCode = (char*)calloc(10, sizeof(char));
        char* productName = (char*)calloc(40, sizeof(char));
        char* unitPrice = (char*)calloc(10, sizeof(char));
        int* unitPriceInt = (int*)calloc(10, sizeof(int));
        int* quantity = (int*)calloc(10, sizeof(int));
        int* totalItemPrice = (int*)calloc(15, sizeof(int));
        char* scratchPaper = (char*)calloc(70, sizeof(char));

        //get the item code
        FLUSH;
        printf("\n[%d]", itemCount);
        printf("\nItem Code: ");
        scanf("%[^\n]", itemCodeInput);
        FLUSH;

        fhand = fopen("ProductList.txt", "r");

        //scan the record for the product
        while(stopper == 0 && found == 0) {
            char* rawString = (char*)calloc(80, sizeof(char));

            if (fgets(rawString, 80, fhand) == NULL) {
                stopper = 1;
                free(rawString);
                continue;
            }

            sscanf(rawString, "%9[01234567890]%*c%39[^_]%*c%9s", itemCode, productName, unitPrice);
            sscanf(rawString, "%*[^_] %*c %*[^_] %*c %d", unitPriceInt);

            if(strcmp(itemCode, itemCodeInput) == 0) {
                found = 1;
            }

            free(rawString);
        }
        fclose(fhand);

        if (found == 1) {
            printf("\nProduct Name: %s", productName);
            printf("\nUnit Price: %s", unitPrice);
            printf("\nIs this the product (Y/N)? ");
            scanf(" %c", &confirmProd);
            confirmProd = toupper(confirmProd);

            //if product is correct
            if (confirmProd == 'Y') {
                //get the quantity
                printf("\nQuantity: ");
                scanf("%d", quantity);
                FLUSH;

                //calculate the total price
                (*totalItemPrice) = (*quantity) * (*unitPriceInt);
                grandTotal += (*totalItemPrice);

                //display the running total and prepare the purchased product details for writing
                printf("Overall Total: %d\n", grandTotal);
                sprintf(scratchPaper, "%29s-%10d-%12s-%9d\n", productName, *quantity, unitPrice, *totalItemPrice);
                strcat(toWriteToSalesInvoice, scratchPaper);

                //ask if user wants to add more
                printf("\nWould you like to add more (Y/N)? ");
                scanf(" %c", &addMore);
                addMore = toupper(addMore);

                //if user wants to add more
                if (addMore == 'Y') {
                    //prepare for next iteration
                    itemCount++;
                    found = 0;
                }
            }
            //if result is not the correct product
            else {
                //prepare for next iteration
                found = 0;
            }
        }
        //if product is not found
        else {
            printf("\nProduct does not exist. Please double check your input.\n");
            stopper = 0;
        }

        //free everything
        free(itemCodeInput);
        free(itemCode);
        free(productName);
        free(unitPrice);
        free(unitPriceInt);
        free(quantity);
        free(totalItemPrice);
        free(scratchPaper);
    } while (addMore == 'Y');

    //Writing everything to SalesInvoice.txt
    fhand2 = fopen("SalesInvoice.txt", "a");
    fputs(toWriteToSalesInvoice, fhand2);
    fclose(fhand2);
    free(toWriteToSalesInvoice);

    //adding itemCount and Grand Total
    printf("\nTotal number of item types: %d", itemCount);
    printf("\nGrand Total: %d\n", grandTotal);
    char* toWriteToFile2 = (char*)calloc(200, sizeof(char));
    sprintf(toWriteToFile2, "\nTotal number of Item Types: %d\nGrand Total   ----------------------------------------%9d", itemCount, grandTotal);
    fhand2 = fopen("SalesInvoice.txt", "a");
    fputs(toWriteToFile2, fhand2);
    fclose(fhand2);
    free(toWriteToFile2);

    //displaying Sales Invoice to screen
    fhand2 = fopen("SalesInvoice.txt", "r");
    stopper = 0;
    while (stopper == 0) {
        char* rawString2 = (char*)calloc(70, sizeof(char));
        if (fgets(rawString2, 69, fhand2) == NULL) {
            stopper = 1;
        }
        else {
            printf("%s", rawString2);
        }
        free(rawString2);
    }
    fclose(fhand2);
    printf("\n\nDetailed Sales Invoice is also saved in file: \"SalesInvoice.txt\"\n\n");

    return;
}//BillingPageMain


void ProductHeader(void) {
    printf("\n\n");
    printf("=====================================================\n");
    printf("              SUPERMARKET BILLING SYSTEM\n");
    printf("                    - Product Page -\n");
    printf("=====================================================\n");

    return;
}//ProductHeader


int ProductPage (void) {
    int option;

    printf("1. Add product information\n");
    printf("   (For new products)\n");
    printf("2. Search product information\n");
    printf("   (Search the records for a product)\n");
    printf("3. Edit product information\n");
    printf("   (Change price, product name, or item code)\n");
    printf("4. Exit\n");
    printf("\nEnter option: ");
    scanf("%d", &option);

    return option;
}//ProductPage


void AddProductInfo (void) {
    char* delimiter = (char*)calloc(2, sizeof(char));
    char* newLine = (char*)calloc(2, sizeof(char));
    char addMore = 'Y';

    strcpy(delimiter, "_");
    strcpy(newLine, "\n");

    do {
        //allocate memory for each data
        FILE* fhand;
        char* itemCode = (char*)calloc(10, sizeof(char));
        char* name = (char*)calloc(30, sizeof(char));
        char* unitPrice = (char*)calloc(10, sizeof(char));
        char* productDetails = (char*)calloc(100, sizeof(char));

        //instruction, clean the input stream
        printf("Add a new product.\n");
        FLUSH;

        //open the ProductList file to append new product/s
        fhand = fopen("ProductList.txt", "a");

        //get info
        printf("Item Code: ");
        scanf("%9[^\n]", itemCode);
        FLUSH;
        strcat(productDetails, itemCode);
        strcat(productDetails, delimiter);

        printf("Name: ");
        scanf("%29[^\n]", name);
        FLUSH;
        strcat(productDetails, name);
        strcat(productDetails, delimiter);

        printf("Unit Price: ");
        scanf("%9[^\n]", unitPrice);
        FLUSH;
        strcat(productDetails, unitPrice);
        strcat(productDetails, newLine);

        //write itemCode_name_unitPrice to file
        fputs(productDetails, fhand);

        //deallocate memories
        free(itemCode);
        free(name);
        free(unitPrice);
        free(productDetails);
        fclose(fhand);

        //ask to continue
        printf("\nWould you like to add another product?(Y/N) ");
        scanf(" %c", &addMore);
        addMore = toupper(addMore);
    } while(addMore == 'Y');

    free(delimiter);
    free(newLine);

    printf("\nProducts have been added.\n\n");

    return;
}//AddProductInfo


void GetSearchKey(char* searchKey, int* searchMethod) {
    //opening ProductList.txt
    FILE* fhand = fopen("ProductList.txt", "r");
    if (fhand == NULL) {
        printf("\nFile ProductList.txt does not exist yet. Please add a new product to your inventory to create the file.\n");

        exit(0);
    }

    //if ProductList.txt is successfully opened, ask for Search Method
    printf("\nSearch for a product using:");
    printf("\n1. Item Code\n2. Product Name\n");
    printf("\nEnter Option: ");
    scanf("%d", searchMethod);
    FLUSH;
    //Note: if user enters a number not in the choices, it will default to 2

    //getting search keyword
    if ((*searchMethod) == 1) {
        printf("\nSearch for a product using an Item Code.");
        printf("\nPlease enter the item code: ");
        scanf("%29[^\n]", searchKey);
        FLUSH;
    }
    else {
        printf("\nSearch for a product using a Product Name.");
        printf("\nPlease enter the product name: ");
        scanf("%29[^\n]", searchKey);
        FLUSH;
    }

    fclose(fhand);
    return;
}//GetSearchKey


int ExecuteProductSearch (char* searchKey, int* searchMethod, displayProduct* searchedProducts) {
    char* itemCode = (char*)calloc(10, sizeof(char));
    char* productName = (char*)calloc(30, sizeof(char));
    char* lowCaseProductName = (char*)calloc(30, sizeof(char));
    char* unitPrice = (char*)calloc(10, sizeof(char));
    char* rawString = (char*)calloc(400, sizeof(char));
    int found = 0;
    int itemCount = 0;

    FILE* fhand = fopen("ProductList.txt", "r");

    //parsing the file to look for the product, stop when found
    //if using Item Code
    if ((*searchMethod) == 1) {
        itemCount = 0;
        while (fgets(rawString, 400, fhand) != NULL) {
            itemCode = strtok(rawString, "_");
            productName = strtok(NULL, "_");
            unitPrice = strtok(NULL, "\0");

            if (strcmp(itemCode, searchKey) == 0) {
                found = 1;
            }

            if (found == 1) {
                strcpy(searchedProducts[itemCount].itemCode, itemCode);
                strcpy(searchedProducts[itemCount].name, productName);
                strcpy(searchedProducts[itemCount].price, unitPrice);
                found = 0;
                itemCount++;
            }
        }
    }
    //if using Product Name
    else {
        //turn userInput to lowercase
        int i = 0;
        while (searchKey[i]) {
            searchKey[i] = tolower(searchKey[i]);
            i++;
        }

        //parse the file
        itemCount = 0;
        while (fgets(rawString, 400, fhand) != NULL) {
            itemCode = strtok(rawString, "_");
            productName = strtok(NULL, "_");
            unitPrice = strtok(NULL, "\0");

            //to remove case sensitivity, a lowercase version of productName is used
            strcpy(lowCaseProductName, productName);
            i = 0;
            while (lowCaseProductName[i]) {
                lowCaseProductName[i] = tolower(lowCaseProductName[i]);
                i++;
            }

            //compare with search keyword
            if (strstr(lowCaseProductName, searchKey) != NULL) {
                found = 1;
            }

            //store matched product
            if (found == 1) {
                strcpy(searchedProducts[itemCount].itemCode, itemCode);
                strcpy(searchedProducts[itemCount].name, productName);
                strcpy(searchedProducts[itemCount].price, unitPrice);
                found = 0;
                itemCount++;
            }
        }
    }

    free(itemCode);
    free(productName);
    free(lowCaseProductName);
    free(unitPrice);
    free(rawString);
    fclose(fhand);

    return itemCount;
}//ExecuteProductSearch


void DisplaySearchedProducts (displayProduct* searchedProducts, int searchResultCount) {
    printf("\n================= Search Results ====================");

    if (searchResultCount == 0) {
        printf("\nProduct does not exist. Please use another search key.\n\n");

        exit(0);
    }
    else {
        printf("\nTop results:\n");
        for (int step = 0; step < searchResultCount; step++) {
            printf("[%d]\n", (step + 1));
            printf("Item Code:    %s\n", searchedProducts[step].itemCode);
            printf("Product Name: %s\n", searchedProducts[step].name);
            printf("Unit Price:   %s\n", searchedProducts[step].price);
        }
    }

    return;
}//DisplaySearchedProducts


void EditProductInfoIntro (void) {
    printf("\nEdit a product's information.");
    printf("\n\nProduct to edit:");

    return;
}//EditProductInfo


int GetProductToEdit (int searchResultCount) {
    int productToEdit;

    printf("\nEnter the number of the product to edit.");
    printf("\nNOTE: An invalid entry will default to 1.\n");
    printf("Product Number: ");
    scanf("%d", &productToEdit);
    FLUSH;

    //default an invalid entry to 1
    if (productToEdit < 1 || productToEdit > searchResultCount) {
        productToEdit = 1;
    }

    return productToEdit;
}//SelectProductToEdit


void EditProductInfo (displayProduct* searchedProducts, int productToEdit) {
    int infoToEdit;
    int editExecuted = 0;
    char* newInfo = (char*)calloc(30, sizeof(char));
    char* itemCodeIdentifier = (char*)calloc(10, sizeof(char));
    char* scratchPaper = (char*)calloc(5000, sizeof(char));

    //section header
    printf("\n\n================ Edit Product Info ==================");

    //confirming product to be edited
    printf("\nProduct to be edited:");
    printf("\nItem Code:    %s", searchedProducts[productToEdit - 1].itemCode);
    printf("\nProduct Name: %s", searchedProducts[productToEdit - 1].name);
    printf("\nUnit Price:   %s", searchedProducts[productToEdit - 1].price);

    //getting the info type to edit
    printf("\nWhat information do you want to edit?");
    printf("\n1. Item Code");
    printf("\n2. Product Name");
    printf("\n3. Unit Price");
    printf("\nNOTE: An invalid entry will default to 3. Unit Price.");
    printf("\nEnter option: ");
    scanf("%d", &infoToEdit);
    FLUSH;

    //getting the replacement info
    if (infoToEdit == 1) {
        printf("\nEnter new Item Code: ");
        scanf("%9[^\n]", newInfo);
        FLUSH;
    }
    else if (infoToEdit == 2) {
        printf("\nEnter new Product Name: ");
        scanf("%29[^\n]", newInfo);
        FLUSH;
    }
    else {
        printf("\nEnter new Unit Price: ");
        scanf("%9[^\n]", newInfo);
        FLUSH;
    }

    //saving the item code to use in search
    strcpy(itemCodeIdentifier, searchedProducts[productToEdit - 1].itemCode);

    //opening the file
    FILE* fhand = fopen("ProductList.txt", "r");
    if (fhand == NULL) {
        printf("Product List file cannot be opened or does not exist. Please add a new product to create the file.\n");
        exit(0);
    }

    int stopper = 0;
    //scanning the file
    while (stopper == 0) {
        char* toAddToScratchEdited = (char*)calloc(100, sizeof(char));
        char* toAddToScratch = (char*)calloc(100, sizeof(char));
        char* rawString = (char*)calloc(100, sizeof(char));
        char* itemCode = (char*)calloc(10, sizeof(char));
        char* productName = (char*)calloc(30, sizeof(char));
        char* unitPrice = (char*)calloc(10, sizeof(char));

        if (fgets(rawString, 100, fhand) == NULL) {
            stopper = 1;
        }
        else {
            strcpy(toAddToScratch, rawString);
            sscanf(rawString, "%9[^_]%*c%29[^_]%*c%9s", itemCode, productName, unitPrice);

            //perform edit if scanned line is the target product
            if (strcmp(itemCode, itemCodeIdentifier) == 0 && editExecuted == 0) {
                if (infoToEdit == 1) {
                    strcpy(itemCode, "");
                    strcpy(itemCode, newInfo);
                    printf("\nCopied!\n");
                }
                else if (infoToEdit == 2) {
                    strcpy(productName, "");
                    strcpy(productName, newInfo);
                    printf("\nCopied!\n");
                }
                else {
                    strcpy(unitPrice, "");
                    strcpy(unitPrice, newInfo);
                    printf("\nCopied!\n");
                }

                //combine all info to one string of format itemCode_productName_unitPrice
                strcat(toAddToScratchEdited, itemCode);
                strcat(toAddToScratchEdited, "_");
                strcat(toAddToScratchEdited, productName);
                strcat(toAddToScratchEdited, "_");
                strcat(toAddToScratchEdited, unitPrice);
                strcat(toAddToScratchEdited, "\n");

                //add to scratch
                strcat(scratchPaper, toAddToScratchEdited);

                //ensure that edit is only made once
                editExecuted = 1;
            }

            //move to scratch if not the target product
            else {
                strcat(scratchPaper, toAddToScratch);
            }
        }

        free(toAddToScratchEdited);
        free(toAddToScratch);
        free(rawString);
        free(itemCode);
        free(productName);
        free(unitPrice);
    }

    //close and delete old product list file
    fclose(fhand);
    remove("ProductList.txt");

    //create new file
    fhand = fopen("ProductList.txt", "w");
    fputs(scratchPaper, fhand);

    printf("\nProduct information has been edited.\n");

    free(newInfo);
    free(itemCodeIdentifier);
    free(scratchPaper);

    return;
}//EditProductInfo


void ExitGracefully (void) {
    printf("Exiting...\n\n");

    return;
}
