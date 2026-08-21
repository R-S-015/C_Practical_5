#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    // Variables with clear, meaningful names to track the order state
    int menuChoice;
    int totalItemsOrdered = 0;
    int totalBillAmount = 0;
    
    // Array to remember the sequence of ordered items for the final bill format
    int orderHistory[100]; 

    // Display the menu repeatedly until the cashier chooses Exit (Option 5)
    do {
        // Print the menu options
        printf("1. Pizza Rs.250\n");
        printf("2. Burger Rs.150\n");
        printf("3. Sandwich Rs.120\n");
        printf("4. Coffee Rs.80\n");
        printf("5. Exit\n");
        
        // Accept the user's choice
        printf("Choice: ");
        scanf("%d", &menuChoice);

        // Process the selected item using a switch statement
        switch (menuChoice) {
            case 1:
                totalBillAmount += 250; // Add price to total bill
                orderHistory[totalItemsOrdered] = 1; // Record item for the final bill
                totalItemsOrdered++; // Increase the count of items ordered
                break;
            case 2:
                totalBillAmount += 150;
                orderHistory[totalItemsOrdered] = 2;
                totalItemsOrdered++;
                break;
            case 3:
                totalBillAmount += 120;
                orderHistory[totalItemsOrdered] = 3;
                totalItemsOrdered++;
                break;
            case 4:
                totalBillAmount += 80;
                orderHistory[totalItemsOrdered] = 4;
                totalItemsOrdered++;
                break;
            case 5:
                // Exit option selected. The loop condition will catch this and terminate.
                break;
            default:
                // Handle invalid inputs
                printf("Invalid choice. Please enter a number between 1 and 5.\n\n");
        }
    } while (menuChoice != 5); // Exit only when the user selects 5

    // Display the final bill before terminating the program
    printf("\nRestaurant Bill\n");
    
    // Loop through the recorded history to print the itemized list matching the sample output
    for (int i = 0; i < totalItemsOrdered; i++) {
        if (orderHistory[i] == 1) {
            printf("Pizza Rs.250\n");
        } else if (orderHistory[i] == 2) {
            printf("Burger Rs.150\n");
        } else if (orderHistory[i] == 3) {
            printf("Sandwich Rs.120\n");
        } else if (orderHistory[i] == 4) {
            printf("Coffee Rs.80\n");
        }
    }

    // Print final summaries and closing message
    printf("Items Ordered: %d\n", totalItemsOrdered);
    printf("Total Amount Rs.%d\n", totalBillAmount);
    printf("Thank You! Visit Again.\n");

    return 0;
}