#include <stdio.h>
#include<string.h>
#include "contact.h"
#include "color.h"
#include "file.h"
#include "populate.h"

int main() {
    int choice;
    AddressBook addressBook;
    addressBook.contactCount = 0;
    populateAddressBook(&addressBook);

    do {
        printf(BLUE_COLOR"\nAddress Book Menu:\n"RESET_COLOR);
        printf(CYAN_COLOR"1. Create contact\n"RESET_COLOR);
        printf(CYAN_COLOR"2. Search contact\n"RESET_COLOR);
        printf(CYAN_COLOR"3. Edit contact\n"RESET_COLOR);
        printf(CYAN_COLOR"4. Delete contact\n"RESET_COLOR);
        printf(CYAN_COLOR"5. List all contacts\n"RESET_COLOR);
        printf(YELLOW_COLOR"6. Exit\n"RESET_COLOR);
        printf(BLUE_COLOR"Enter your choice: "RESET_COLOR);
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:
                
                listContacts(&addressBook);
                break;
            case 6:
                printf(GREEN_COLOR"Saving and Exiting...\n"RESET_COLOR);
                //saveContactsToFile(&addressBook);
                break;
            default:
                printf(RED_COLOR"Invalid choice. Please try again.\n"RESET_COLOR);
        }
    } while (choice != 6);
    
       return 0;
}