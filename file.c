#include <stdio.h>
#include "file.h"

// Save all contacts from AddressBook into a file
void saveContactsToFile(AddressBook *addressBook)
{
    // Declare a file pointer
    FILE *fp;

    // Open contacts.txt in write mode
    fp = fopen("contacts.txt", "w");

    // Check whether the file opened successfully
    if (fp == NULL)
    {
        printf("File opening failed\n");

        // Exit the function if file opening fails
        return;
    }

    // Store the total number of contacts in the file
    fprintf(fp, "%d\n", addressBook->contactCount);

    // Loop through all contacts
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // Store the contact name in the file
        fprintf(fp, "%s\n", addressBook->contacts[i].name);

        // Store the contact phone number in the file
        fprintf(fp, "%s\n", addressBook->contacts[i].phone);

        // Store the contact email in the file
        fprintf(fp, "%s\n", addressBook->contacts[i].email);
    }

    // Close the file after saving all contacts
    fclose(fp);
}


// Load contacts from file into AddressBook
void loadContactsFromFile(AddressBook *addressBook)
{
    // Declare a file pointer
    FILE *fp;

    // Open contacts.txt in read mode
    fp = fopen("contacts.txt", "r");

    // Check whether the file exists or opened successfully
    if (fp == NULL)
    {
        // Set contact count to zero if file is not available
        addressBook->contactCount = 0;

        // Exit the function
        return;
    }

    // Read the total number of contacts from the file
    fscanf(fp, "%d\n", &addressBook->contactCount);

    // Loop through all contacts stored in the file
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        // Read the contact name from the file
        fscanf(fp, "%[^\n]\n", addressBook->contacts[i].name);

        // Read the contact phone number from the file
        fscanf(fp, "%[^\n]\n", addressBook->contacts[i].phone);

        // Read the contact email from the file
        fscanf(fp, "%[^\n]\n", addressBook->contacts[i].email);
    }

    // Close the file after loading all contacts
    fclose(fp);
}