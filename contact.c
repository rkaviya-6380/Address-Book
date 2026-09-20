#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include "color.h"

void listContacts(AddressBook *addressBook) 
{
    int i;  // Declare a variable for loop

    // Check whether the contact list is empty
    if(addressBook->contactCount == 0)
    {
        printf(RED_COLOR"No contacts available\n"RESET_COLOR);
        return;
    }

    printf(BLUE_COLOR"\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║                CONTACT LIST                  ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf(RESET_COLOR);

    // Loop through all the contacts
    for(i = 0; i < addressBook->contactCount; i++)
    {
        printf(YELLOW_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║                 CONTACT %-2d                 ║\n", i + 1);
        printf("╠══════════════════════════════════════════════╣\n");
        printf(RESET_COLOR);

        printf(GREEN_COLOR"║  Name  : "RESET_COLOR"%-32s ║\n",
               addressBook->contacts[i].name);

        printf(GREEN_COLOR"║  Phone : "RESET_COLOR"%-32s ║\n",
               addressBook->contacts[i].phone);

        printf(GREEN_COLOR"║  Email : "RESET_COLOR"%-32s ║\n",
               addressBook->contacts[i].email);

        printf(YELLOW_COLOR"╚══════════════════════════════════════════════╝\n"
               RESET_COLOR);
    }

    // Sort contacts based on the chosen criteria
    // Sort contacts based on the chosen criteria
}

void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    
    printf(BLUE_COLOR"\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║           INITIALIZING ADDRESS BOOK          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf(RESET_COLOR);
    populateAddressBook(addressBook);
    // Load contacts from file during initialization (After files)
    //loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) 
{
    printf(BLUE_COLOR"\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║              SAVING CONTACTS                 ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf(RESET_COLOR);
    saveContactsToFile(addressBook); // Save contacts to file

    exit(EXIT_SUCCESS); // Exit the program
}


void createContact(AddressBook *addressBook)
{
    /* Define the logic to create a Contacts */

    // Declare temporary strings to store name, phone and email
    char str1[100], str2[100], str3[100];

    // Declare variables for validation and loop
    int res, i, count;

    printf(BLUE_COLOR"\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║              ADD NEW CONTACT                 ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf(RESET_COLOR);

    // Repeat until a valid name is entered
    while(1)
    {
        printf(CYAN_COLOR"Enter the name : "RESET_COLOR);
        scanf(" %[^\n]", str1);

        // Assume the name is valid and initialize character count
        res = 1, count = 0;

        // Check each character of the name
        for(i = 0; str1[i] != '\0'; i++)
        {
            count++;

            // Allow only alphabets and spaces
            if(!((str1[i] >= 'A' && str1[i] <= 'Z') ||
                 (str1[i] >= 'a' && str1[i] <= 'z') ||
                 str1[i] == ' '))
            {
                res = 0;
            }
        }

        // Check minimum length of the name
        if(count<3)
        {
            printf(RED_COLOR"Name must contain at least 3 characters\n"
                   RESET_COLOR);
        }

        // Check whether invalid characters are present
        else if(res == 0)
        {
            printf(RED_COLOR"Name should contain only alphabets and spaces\n"
                   RESET_COLOR);
        }

        // Exit the loop if the name is valid
        else
        {
            break;
        }
    }

    // Repeat until a valid phone number is entered
    while(1)
    {
        printf(CYAN_COLOR"Enter the phone number : "RESET_COLOR);

        // Read the phone number
        scanf("%s", str2);

        // Assume the phone number is valid and initialize count
        res = 1, count = 0;

        // Check each character of the phone number
        for(i = 0; str2[i] != '\0'; i++)
        {
            count++;

            // Allow only digits from 0 to 9
            if(!(str2[i] >= '0' && str2[i] <= '9'))
            {
                res = 0;
            }
        }

        // Check whether the first digit is between 6 and 9
        if(!(str2[0] >= '6' && str2[0] <= '9'))
        {
            printf(RED_COLOR"First digit must be between 6 and 9\n"
                   RESET_COLOR);
        }

        // Check whether any non-digit character is present
        else if(res == 0)
        {
            printf(RED_COLOR"Other than Digits any other Character not allowed in phone number\n"
                   RESET_COLOR);
        }

        // Check whether phone number contains exactly 10 digits
        else if(count != 10)
        {
            printf(RED_COLOR"Phone number must contain exactly 10 digits\n"
                   RESET_COLOR);
        }

        // Exit the loop if the phone number is valid
        else
        {
            break;
        }
    }

    // Repeat until a valid email is entered
    while(1)
    {
        printf(CYAN_COLOR"Enter the email id : "RESET_COLOR);

        // Read the email ID
        scanf("%s", str3);

        // Assume the email is valid
        res = 1;

        // Store the position of @ and dot
        int at = -1, dot = -1;

        // Count the number of @ and dot symbols
        int at_count = 0, dot_count = 0;

        // Check each character of the email
        for(i = 0; str3[i] != '\0'; i++)
        {
            /* Check validation parts */

            // Allow only lowercase alphabets, digits, @ and dot
            if(!((str3[i] >= '0' && str3[i] <= '9') ||
                 (str3[i] >= 'a' && str3[i] <= 'z') ||
                 str3[i] == '@' || str3[i] == '.'))
            {
                res = 0;
            }

            // Store @ position and count @ symbols
            if(str3[i] == '@')
            {
                at = i;
                at_count++;
            }

            // Store dot position and count dot symbols
            if(str3[i] == '.')
            {
                dot = i;
                dot_count++;
            }
        }

        // Check whether @ is missing
        if(at_count == 0)
        {
            printf(RED_COLOR"Missing @\n"RESET_COLOR);
        }

        // Check whether multiple @ symbols are present
        else if(at_count > 1)
        {
            printf(RED_COLOR"Multiple @ symbols are not allowed\n"
                   RESET_COLOR);
        }

        // Check whether dot is missing
        else if(dot_count == 0)
        {
            printf(RED_COLOR"Missing dot\n"RESET_COLOR);
        }

        // Check whether multiple dots are present
        else if(dot_count > 1)
        {
            printf(RED_COLOR"Multiple dots are not allowed\n"
                   RESET_COLOR);
        }

        // Check whether invalid characters are present
        else if(res == 0)
        {
            printf(RED_COLOR"Invalid symbol\n"RESET_COLOR);
        }

        // Check whether dot comes after @
        else if(dot < at)
        {
            printf(RED_COLOR"Dot must appear after @\n"RESET_COLOR);
        }

        // Check whether at least one character exists between @ and dot
        else if(dot == at + 1)
        {
            printf(RED_COLOR"At least one character must be present between @ and dot\n"
                   RESET_COLOR);
        }

        // Check whether the email ends with .com
        else if(!(str3[dot+1] == 'c' &&
                  str3[dot+2] == 'o' &&
                  str3[dot+3] == 'm' &&
                  str3[dot+4] == '\0'))
        {
            printf(RED_COLOR"Extra characters after the domain\n"
                   RESET_COLOR);
        }

        // Exit the loop if email is valid
        else
        {
            break;
        }
    }

    // Copy the validated name into the current contact
    strcpy(addressBook->contacts[addressBook->contactCount].name, str1);

    // Copy the validated phone number into the current contact
    strcpy(addressBook->contacts[addressBook->contactCount].phone, str2);

    // Copy the validated email into the current contact
    strcpy(addressBook->contacts[addressBook->contactCount].email, str3);

    // Increase the contact count after creating the contact
    addressBook->contactCount++;

    // Display successful contact creation message
    printf(GREEN_COLOR"\n");
    printf("╔══════════════════════════════════════════════╗\n");
    printf("║       CONTACT CREATED SUCCESSFULLY!          ║\n");
    printf("╚══════════════════════════════════════════════╝\n");
    printf(RESET_COLOR);
}
void searchContact(AddressBook *addressBook)
{
    /* Define the logic for search */

    // Declare variables for choice, loop, and search status
    int choice, i, found;

    // Declare a string to store the search value
    char search[100];

    // Initialize flag to keep the search menu running
    int flag = 1;

    // Repeat the search menu until user chooses Exit
    while(flag)
    {
        // Reset found status for every new search
        found = 0;

        // Display search options
        printf(BLUE_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║               SEARCH CONTACT                 ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║  1. Search by Name                           ║\n");
        printf("║  2. Search by Phone Number                   ║\n");
        printf("║  3. Search by Email ID                       ║\n");
        printf(YELLOW_COLOR"║  4. Exit                                     ║\n"BLUE_COLOR);
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);

        // Read the user's choice
        printf(CYAN_COLOR"Enter the choice : "RESET_COLOR);
        scanf("%d", &choice);

        // Search contact by name
        if(choice == 1)
        {
            // Get the name to search
            printf(CYAN_COLOR"Enter name to search : "RESET_COLOR);
            scanf(" %[^\n]", search);

            // Check the entered name with all stored contacts
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Compare the entered name with current contact name
                if(strcmp(addressBook->contacts[i].name, search) == 0)
                {
                    // Display the matching contact details
                    printf(GREEN_COLOR"\n");
                    printf("╔══════════════════════════════════════════════╗\n");
                    printf("║                CONTACT FOUND                 ║\n");
                    printf("╠══════════════════════════════════════════════╣\n");
                    printf("║  Name  : %-34s║\n",
                           addressBook->contacts[i].name);
                    printf("║  Phone : %-34s║\n",
                           addressBook->contacts[i].phone);
                    printf("║  Email : %-34s║\n",
                           addressBook->contacts[i].email);
                    printf("╚══════════════════════════════════════════════╝\n");
                    printf(RESET_COLOR);

                    // Set found to 1 when a matching contact is found
                    found = 1;
                }
            }
        }

        // Search contact by phone number
        else if(choice == 2)
        {
            // Get the phone number to search
            printf(CYAN_COLOR"Enter phone number to search : "RESET_COLOR);
            scanf("%s", search);

            // Check the entered phone number with all stored contacts
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Compare the entered phone number with current contact phone
                if(strcmp(addressBook->contacts[i].phone, search) == 0)
                {
                    // Display the matching contact details
                    printf(GREEN_COLOR"\n");
                    printf("╔══════════════════════════════════════════════╗\n");
                    printf("║                CONTACT FOUND                 ║\n");
                    printf("╠══════════════════════════════════════════════╣\n");
                    printf("║  Name  : %-34s║\n",
                           addressBook->contacts[i].name);
                    printf("║  Phone : %-34s║\n",
                           addressBook->contacts[i].phone);
                    printf("║  Email : %-34s║\n",
                           addressBook->contacts[i].email);
                    printf("╚══════════════════════════════════════════════╝\n");
                    printf(RESET_COLOR);

                    // Set found to 1 when a matching contact is found
                    found = 1;
                }
            }
        }

        // Search contact by email ID
        else if(choice == 3)
        {
            // Get the email ID to search
            printf(CYAN_COLOR"Enter email ID to search : "RESET_COLOR);
            scanf("%s", search);

            // Check the entered email with all stored contacts
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Compare the entered email with current contact email
                if(strcmp(addressBook->contacts[i].email, search) == 0)
                {
                    // Display the matching contact details
                    printf(GREEN_COLOR"\n");
                    printf("╔══════════════════════════════════════════════╗\n");
                    printf("║                CONTACT FOUND                 ║\n");
                    printf("╠══════════════════════════════════════════════╣\n");
                    printf("║  Name  : %-34s║\n",
                           addressBook->contacts[i].name);
                    printf("║  Phone : %-34s║\n",
                           addressBook->contacts[i].phone);
                    printf("║  Email : %-34s║\n",
                           addressBook->contacts[i].email);
                    printf("╚══════════════════════════════════════════════╝\n");
                    printf(RESET_COLOR);

                    // Set found to 1 when a matching contact is found
                    found = 1;
                }
            }
        }

        // Exit the search menu
        else if(choice == 4)
        {
            // Set flag to 0 to stop the while loop
            flag = 0;
        }

        // Handle invalid menu choice
        else
        {
            printf(RED_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║               INVALID CHOICE!                ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
        }

        // Display message if no matching contact is found
        if(choice != 4 && found == 0 && choice >= 1 && choice <= 3)
        {
            printf(RED_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║          NO MATCHING RECORD FOUND            ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
        }
    }
}
void editContact(AddressBook *addressBook)
{
    // Declare variables to store search value and new contact details
    char search[100];
    char newName[50], newPhone[20], newEmail[50];

    // Declare variables for menu choice, loop and selection
    int choice, i, j;
    int foundCount, selected;

    // Repeat edit operation until user chooses Exit
    while(1)
    {
        // Reset the matching contact count for every search
        foundCount = 0;

        // Display edit options
        printf(BLUE_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║                 EDIT CONTACT                 ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║  1. Edit by Name                             ║\n");
        printf("║  2. Edit by Phone                            ║\n");
        printf("║  3. Edit by Email                            ║\n");
        printf(YELLOW_COLOR"║  4. Exit                         ║\n"RESET_COLOR);
        printf(BLUE_COLOR"╚══════════════════════════════════════════════╝\n"
               RESET_COLOR);

        // Read the user's choice
        printf(CYAN_COLOR"Enter your choice : "RESET_COLOR);
        scanf("%d", &choice);

        // Exit the edit function
        if(choice == 4)
        {
            break;
        }

        // Check whether the entered choice is valid
        if(choice < 1 || choice > 4)
        {
            printf(RED_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║               INVALID CHOICE!                ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
            continue;
        }

        // Get the value based on the selected search option
        if(choice == 1)
        {
            // Get the name to search
            printf(CYAN_COLOR"Enter name to edit : "RESET_COLOR);
            scanf(" %[^\n]", search);
        }
        else if(choice == 2)
        {
            // Get the phone number to search
            printf(CYAN_COLOR"Enter phone number to edit : "
                   RESET_COLOR);
            scanf("%s", search);
        }
        else if(choice == 3)
        {
            // Get the email ID to search
            printf(CYAN_COLOR"Enter email ID to edit : "
                   RESET_COLOR);
            scanf("%s", search);
        }

        // Find the number of contacts matching the search value
        for(i = 0; i < addressBook->contactCount; i++)
        {
            // Compare name, phone or email based on the user's choice
            if((choice == 1 &&
                strcmp(addressBook->contacts[i].name, search) == 0) ||
               (choice == 2 &&
                strcmp(addressBook->contacts[i].phone, search) == 0) ||
               (choice == 3 &&
                strcmp(addressBook->contacts[i].email, search) == 0))
            {
                // Increase the count when a matching contact is found
                foundCount++;
            }
        }

        // If no contact matches the search value
        if(foundCount == 0)
        {
            printf(RED_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║          NO MATCHING RECORD FOUND            ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
            continue;
        }

        // If more than one contact matches the search value
        if(foundCount > 1)
        {
            printf(YELLOW_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║           MULTIPLE CONTACTS FOUND            ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);

            // Initialize display number for matching contacts
            j = 1;

            // Display all matching contacts
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Check whether the current contact matches the search value
                if((choice == 1 &&
                    strcmp(addressBook->contacts[i].name, search) == 0) ||
                   (choice == 2 &&
                    strcmp(addressBook->contacts[i].phone, search) == 0) ||
                   (choice == 3 &&
                    strcmp(addressBook->contacts[i].email, search) == 0))
                {
                    // Display the matching contact details
                    printf(GREEN_COLOR"\n");
                    printf("╔══════════════════════════════════════════════╗\n");
                    printf("║                 CONTACT %d                   ║\n", j);
                    printf("╠══════════════════════════════════════════════╣\n");
                    printf("║  Name  : %-34s ║\n",
                           addressBook->contacts[i].name);
                    printf("║  Phone : %-34s ║\n",
                           addressBook->contacts[i].phone);
                    printf("║  Email : %-34s ║\n",
                           addressBook->contacts[i].email);
                    printf("╚══════════════════════════════════════════════╝\n");
                    printf(RESET_COLOR);

                    // Increase the display number
                    j++;
                }
            }

            // Ask the user to select which contact to edit
            printf(CYAN_COLOR"\nSelect contact number to edit : "
                   RESET_COLOR);
            scanf("%d", &selected);

            // Check whether the selected contact number is valid
            if(selected < 1 || selected > foundCount)
            {
                printf(RED_COLOR"\n");
                printf("╔══════════════════════════════════════════════╗\n");
                printf("║              INVALID SELECTION!              ║\n");
                printf("╚══════════════════════════════════════════════╝\n");
                printf(RESET_COLOR);
                continue;
            }

            // Find the actual array index of the selected contact
            j = 0;

            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Check for matching contacts
                if((choice == 1 &&
                    strcmp(addressBook->contacts[i].name, search) == 0) ||
                   (choice == 2 &&
                    strcmp(addressBook->contacts[i].phone, search) == 0) ||
                   (choice == 3 &&
                    strcmp(addressBook->contacts[i].email, search) == 0))
                {
                    // Count the matching contact
                    j++;

                    // Stop when the selected contact is reached
                    if(j == selected)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            // Only one contact matches, so find that contact directly
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Check whether the current contact matches the search value
                if((choice == 1 &&
                    strcmp(addressBook->contacts[i].name, search) == 0) ||
                   (choice == 2 &&
                    strcmp(addressBook->contacts[i].phone, search) == 0) ||
                   (choice == 3 &&
                    strcmp(addressBook->contacts[i].email, search) == 0))
                {
                    // Stop at the matching contact
                    break;
                }
            }
        }

        // ================= NEW NAME =================

// Get and validate the new name
while(1)
{
    int valid = 1;
    int count = 0;

    // Read the new name
    printf(CYAN_COLOR"Enter new name : "RESET_COLOR);
    scanf(" %[^\n]", newName);

    // Check every character of the new name
    for(j = 0; newName[j] != '\0'; j++)
    {
        // Count the number of characters
        count++;

        // Allow only alphabets and spaces
        if(!((newName[j] >= 'A' && newName[j] <= 'Z') ||
             (newName[j] >= 'a' && newName[j] <= 'z') ||
             newName[j] == ' '))
        {
            valid = 0;
        }
    }

    // Check minimum name length
    if(count < 3)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║        NAME MUST HAVE 3 CHARACTERS           ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
        continue;
    }

    // Check for invalid characters
    if(valid == 0)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║     NAME SHOULD CONTAIN ONLY ALPHABETS       ║\n");
        printf("║                AND SPACES                    ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
        continue;
    }

    // Exit the validation loop when name is valid
    break;
}

        // ================= NEW PHONE =================

// Get and validate the new phone number
while(1)
{
    int valid = 1;
    int count = 0;

    // Read the new phone number
    printf(CYAN_COLOR"Enter new phone number : "RESET_COLOR);
    scanf("%s", newPhone);

    // Check every character of the phone number
    for(j = 0; newPhone[j] != '\0'; j++)
    {
        // Count the number of digits
        count++;

        // Allow only digits
        if(!(newPhone[j] >= '0' && newPhone[j] <= '9'))
        {
            valid = 0;
        }
    }

    // Check whether first digit is between 6 and 9
    if(!(newPhone[0] >= '6' && newPhone[0] <= '9'))
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║     FIRST DIGIT MUST BE BETWEEN 6 AND 9      ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
        continue;
    }

    // Check for non-digit characters
    if(valid == 0)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║       ONLY DIGITS ARE ALLOWED IN PHONE       ║\n");
        printf("║                 NUMBER                       ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
        continue;
    }

    // Check whether phone number contains exactly 10 digits
    if(count != 10)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║       PHONE NUMBER MUST CONTAIN 10           ║\n");
        printf("║                 DIGITS                       ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
        continue;
    }

    // Exit the validation loop when phone number is valid
    break;
}
// ================= NEW EMAIL =================

// Get and validate the new email ID
while(1)
{
    int valid = 1;
    int at = -1;
    int dot = -1;
    int at_count = 0;
    int dot_count = 0;

    // Read the new email ID
    printf(CYAN_COLOR"Enter new email ID : "RESET_COLOR);
    scanf("%s", newEmail);

    // Check every character of the email
    for(j = 0; newEmail[j] != '\0'; j++)
    {
        // Allow lowercase alphabets, digits, @ and dot
        if(!((newEmail[j] >= '0' && newEmail[j] <= '9') ||
             (newEmail[j] >= 'a' && newEmail[j] <= 'z') ||
             newEmail[j] == '@' || newEmail[j] == '.'))
        {
            valid = 0;
        }

        // Store @ position and count @ symbols
        if(newEmail[j] == '@')
        {
            at = j;
            at_count++;
        }

        // Store dot position and count dot symbols
        if(newEmail[j] == '.')
        {
            dot = j;
            dot_count++;
        }
    }

    // Check whether @ is missing
    if(at_count == 0)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║                 MISSING @                    ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Check whether multiple @ symbols are present
    else if(at_count > 1)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║       MULTIPLE @ SYMBOLS NOT ALLOWED         ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Check whether dot is missing
    else if(dot_count == 0)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║                  MISSING DOT                 ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Check whether multiple dots are present
    else if(dot_count > 1)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║        MULTIPLE DOTS NOT ALLOWED             ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Check for invalid characters
    else if(valid == 0)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║              INVALID SYMBOL                  ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Check whether dot comes after @
    else if(dot < at)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║          DOT MUST APPEAR AFTER @             ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Check whether at least one character is present between @ and dot
    else if(dot == at + 1)
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║       CHARACTER REQUIRED BETWEEN @ & DOT     ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Check whether email ends with .com
    else if(!(newEmail[dot + 1] == 'c' &&
              newEmail[dot + 2] == 'o' &&
              newEmail[dot + 3] == 'm' &&
              newEmail[dot + 4] == '\0'))
    {
        printf(RED_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║       EMAIL MUST END WITH .COM               ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(RESET_COLOR);
    }

    // Exit the validation loop when email is valid
    else
    {
        break;
    }
}

        // ================= UPDATE CONTACT =================

// Replace the old name with the new name
strcpy(addressBook->contacts[i].name, newName);

// Replace the old phone number with the new phone number
strcpy(addressBook->contacts[i].phone, newPhone);

// Replace the old email with the new email
strcpy(addressBook->contacts[i].email, newEmail);

// Display successful update message
printf(GREEN_COLOR"\n");
printf("╔══════════════════════════════════════════════╗\n");
printf("║            CONTACT UPDATED SUCCESSFULLY      ║\n");
printf("╚══════════════════════════════════════════════╝\n");
printf(RESET_COLOR);
    }
}

void deleteContact(AddressBook *addressBook)
{
    // Declare variables for search value, confirmation, loop and selection
    char search[100];
    char confirm;
    int choice, i, j;
    int foundCount, selected;

    // Repeat delete operation until user chooses Exit
    while(1)
    {
        // Reset the matching contact count
        foundCount = 0;

        // Display delete options
        printf(BLUE_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║                DELETE CONTACT                ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║  1. Delete by Name                           ║\n");
        printf("║  2. Delete by Phone                          ║\n");
        printf("║  3. Delete by Email                          ║\n");
        printf(YELLOW_COLOR"║  4. Exit                         ║\n"RESET_COLOR);
        printf(BLUE_COLOR"╚══════════════════════════════════════════════╝\n"
               RESET_COLOR);

        // Read the user's choice
        printf(CYAN_COLOR"Enter your choice : "RESET_COLOR);
        scanf("%d", &choice);

        // Exit the delete function
        if(choice == 4)
        {
            break;
        }

        // Check whether the entered choice is valid
        if(choice < 1 || choice > 4)
        {
            printf(RED_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║               INVALID CHOICE!                ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
            continue;
        }

        /* Get search value */

        // Get the name to search
        if(choice == 1)
        {
            printf(CYAN_COLOR"Enter name to delete : "RESET_COLOR);
            scanf(" %[^\n]", search);
        }

        // Get the phone number to search
        else if(choice == 2)
        {
            printf(CYAN_COLOR"Enter phone number to delete : "
                   RESET_COLOR);
            scanf("%s", search);
        }

        // Get the email ID to search
        else if(choice == 3)
        {
            printf(CYAN_COLOR"Enter email ID to delete : "
                   RESET_COLOR);
            scanf("%s", search);
        }

        /* Count matching records */

        // Search through all stored contacts
        for(i = 0; i < addressBook->contactCount; i++)
        {
            // Compare the selected field with the search value
            if((choice == 1 &&
                strcmp(addressBook->contacts[i].name, search) == 0) ||
               (choice == 2 &&
                strcmp(addressBook->contacts[i].phone, search) == 0) ||
               (choice == 3 &&
                strcmp(addressBook->contacts[i].email, search) == 0))
            {
                // Increase count when a matching contact is found
                foundCount++;
            }
        }

        /* No record found */

        // Display message if no matching contact is found
        if(foundCount == 0)
        {
            printf(RED_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║          NO MATCHING RECORD FOUND            ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
            continue;
        }

        /* Multiple records found */

        // Handle the case when multiple contacts match
        if(foundCount > 1)
        {
            printf(YELLOW_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║           MULTIPLE CONTACTS FOUND            ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);

            // Initialize display number
            j = 1;

            // Display all matching contacts
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Check whether the current contact matches the search value
                if((choice == 1 &&
                    strcmp(addressBook->contacts[i].name, search) == 0) ||
                   (choice == 2 &&
                    strcmp(addressBook->contacts[i].phone, search) == 0) ||
                   (choice == 3 &&
                    strcmp(addressBook->contacts[i].email, search) == 0))
                {
                    // Display the matching contact details
                    printf(GREEN_COLOR"\n");
                    printf("╔══════════════════════════════════════════════╗\n");
                    printf("║                 CONTACT %d                   ║\n", j);
                    printf("╠══════════════════════════════════════════════╣\n");
                    printf("║  Name  : %-34s ║\n",
                           addressBook->contacts[i].name);
                    printf("║  Phone : %-34s ║\n",
                           addressBook->contacts[i].phone);
                    printf("║  Email : %-34s ║\n",
                           addressBook->contacts[i].email);
                    printf("╚══════════════════════════════════════════════╝\n");
                    printf(RESET_COLOR);

                    // Increase display number
                    j++;
                }
            }

            // Ask the user to select the contact to delete
            printf(CYAN_COLOR"\nSelect contact number to delete : "
                   RESET_COLOR);
            scanf("%d", &selected);

            // Check whether the selected number is valid
            if(selected < 1 || selected > foundCount)
            {
                printf(RED_COLOR"\n");
                printf("╔══════════════════════════════════════════════╗\n");
                printf("║              INVALID SELECTION!              ║\n");
                printf("╚══════════════════════════════════════════════╝\n");
                printf(RESET_COLOR);
                continue;
            }

            /* Find selected contact */

            // Reset matching contact counter
            j = 0;

            // Find the actual array index of selected contact
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Check whether the current contact matches
                if((choice == 1 &&
                    strcmp(addressBook->contacts[i].name, search) == 0) ||
                   (choice == 2 &&
                    strcmp(addressBook->contacts[i].phone, search) == 0) ||
                   (choice == 3 &&
                    strcmp(addressBook->contacts[i].email, search) == 0))
                {
                    // Count the matching contact
                    j++;

                    // Stop when the selected contact is reached
                    if(j == selected)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            /* Only one matching record */

            // Find the only matching contact
            for(i = 0; i < addressBook->contactCount; i++)
            {
                // Compare the selected field with the search value
                if((choice == 1 &&
                    strcmp(addressBook->contacts[i].name, search) == 0) ||
                   (choice == 2 &&
                    strcmp(addressBook->contacts[i].phone, search) == 0) ||
                   (choice == 3 &&
                    strcmp(addressBook->contacts[i].email, search) == 0))
                {
                    // Stop at the matching contact
                    break;
                }
            }
        }

        /* Confirmation */

        // Ask the user for confirmation before deleting
        printf(YELLOW_COLOR"\n");
        printf("╔══════════════════════════════════════════════╗\n");
        printf("║              DELETE CONFIRMATION             ║\n");
        printf("╠══════════════════════════════════════════════╣\n");
        printf("║  Are you sure you want to delete this        ║\n");
        printf("║  contact?                                    ║\n");
        printf("╚══════════════════════════════════════════════╝\n");
        printf(CYAN_COLOR"Enter (y/n) : "RESET_COLOR);
        scanf(" %c", &confirm);

        // Delete the contact if user confirms
        if(confirm == 'y' || confirm == 'Y')
        {
            /* Shift contacts */

            // Shift all contacts after the deleted contact one position left
            for(j = i; j < addressBook->contactCount - 1; j++)
            {
                addressBook->contacts[j] =
                    addressBook->contacts[j + 1];
            }

            // Decrease contact count after deletion
            addressBook->contactCount--;

            // Display successful deletion message
            printf(GREEN_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║           CONTACT DELETED SUCCESSFULLY       ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
        }
        else
        {
            // Display cancellation message
            printf(YELLOW_COLOR"\n");
            printf("╔══════════════════════════════════════════════╗\n");
            printf("║              DELETE CANCELLED                ║\n");
            printf("╚══════════════════════════════════════════════╝\n");
            printf(RESET_COLOR);
        }
    }
}