#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <stdbool.h>

void listContacts(AddressBook *addressBook) 
{
	printf("Contacts List:\n");
	printf("-----------------------------------------------------\n");
	printf("Name\t\tPhone\t\tEmail\n");
	printf("-----------------------------------------------------\n");
	for(int i=0;i<addressBook->contactCount; i++)
       	{
        	printf("%s\t %s\t %s\n", addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
        }
}


/*void initialize(AddressBook *addressBook) 
{
	addressBook->contactCount=0;
	populateAddressBook(addressBook);

}
*/
/*
void saveAndExit(AddressBook *addressBook) 
{

}
*/
int isPhoneNumberPresent(Contact contacts[], int contactCount, char *phoneNumber) 
{
    for (int i = 0; i < contactCount; i++)
    {
        if (strcmp(contacts[i].phone, phoneNumber) == 0) 
	{
            return 1; // Phone number is present
        }
    }
    return 0; // Phone number is not present
}

// Function to check if an email address is already present in the contact list
int isEmailPresent(Contact contacts[], int contactCount, char *emaiil)
{
    for (int i = 0; i < contactCount; i++)
    {
        if (strcmp(contacts[i].email, emaiil) == 0)
       	{
            return 1; // Email address is present
        }
    }
     return 0;
}
void createContact(AddressBook *addressBook) 
{

	addressBook->contacts=realloc(addressBook->contacts,addressBook->contactCount+1*(sizeof(Contact)));
    Contact newContact;


    // Read name
    	printf("Enter name: ");
	scanf("%s",newContact.name);
	//read phone
	
	printf("Enter phone number: ");
	scanf("%s",newContact.phone);
	//validation of phone number
if (isPhoneNumberPresent(addressBook->contacts, addressBook->contactCount,newContact.phone))
{
            printf("Error: Phone number already exists. Please enter a new phone number.\n");
            return; // Skip to the next iteration
}
//Read new email id
        printf("Enter email ID: ");
	scanf("%s",newContact.email);

//validation of email
        if (isEmailPresent(addressBook->contacts, addressBook->contactCount,newContact.email))
       	{
            printf("Error: Email address already exists. Please enter a new email address.\n");
            return; // Skip to the next iteration
        }


    // Add the new contact to the address book
    addressBook->contacts[addressBook->contactCount] = newContact;
    addressBook->contactCount++;  // Increment the count of contacts
    printf("Contact added successfully.\n");

}

void searchContact(AddressBook *addressBook) 
{
	char Name[50];
	int found=0;
	printf("Search contact:\n");
	printf("Enter the name to search:\n");
	scanf("%s",Name);
	for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].name, Name) == 0)
        {
            printf("Contact found: %s, %s, %s\n",
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
            found = 1;
            break; // Stop after finding the first match
        }
    }
    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void editContact(AddressBook *addressBook) 
{
	char Name[50];
	int contactIndex = -1;
    printf("Enter name to edit: ");
    scanf("%s", Name);
    printf("Enter new details: \n");
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].name, Name) == 0)
       	{

            contactIndex = i;
            break; // Exit loop if contact found
        }
    }

    if (contactIndex == -1) 
    {
        printf("Contact not found.\n");
        return;
    }
	    printf("Editing contact: %s\n", addressBook->contacts[contactIndex].name);

	    char choice;
	    do 
	    {
        printf("\nChoose what to edit:\n");
        printf("1. Name\n");
        printf("2. Phone\n");
        printf("3. Email\n");
        scanf(" %c", &choice);

        switch (choice)
       	{

		case '1':
            // Use strcpy to copy new name, phone, and email
            printf("New Name: ");
            char Name[50];
            scanf("%s", Name);
            strcpy(addressBook->contacts[contactIndex].name, Name);
	    break;

		case '2':
            printf("New Phone: ");
            char Phone[20];
            scanf("%s", Phone);
            strcpy(addressBook->contacts[contactIndex].phone, Phone);
	    break;
		case '3':
            printf("New Email: ");
            char Email[50];
            scanf("%s", Email);
            strcpy(addressBook->contacts[contactIndex].email, Email);
	    break;

	    default:
                printf("Invalid choice. Please try again.\n");
		return;
        }
	    }
	while(choice!='4');

            printf("Contact edited successfully.\n"); 

}


void deleteContact(AddressBook *addressBook) 
{

	char name_d[50];
    printf("Enter name to delete: ");
    scanf("%s", name_d);
    for (int i = 0; i < addressBook->contactCount; i++)
    {
	    if(strcmp(addressBook->contacts[i].name,name_d)==0)
                {
		for (int j = i; j < addressBook->contactCount - 1; j++)
		   {
                addressBook->contacts[j] = addressBook->contacts[j + 1];
                   }

                addressBook->contactCount--;
/*
	Contact *temp = realloc(addressBook->contacts,addressBook->contactCount * sizeof(Contact));
if (temp != NULL)
{
                addressBook->contacts = temp; // Only assign if realloc was successful
            
}
else
{
                printf("Error: Memory reallocation failed.\n");
                return;
}
*/
                printf("Contact deleted successfully.\n");
                return;
                }
    }

        printf("Contact not found to delete.\n");
}

