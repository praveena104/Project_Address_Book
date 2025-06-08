#include <stdio.h>
#include "contact.h"
#include <string.h>
#include "populate.h"
#include <stdlib.h>
int main() 
{

	//structure variable
	AddressBook book;
	book.contacts=NULL;
	book.contactCount=0;

	//Function call
	//initialize(&book);
	
book.fptr=fopen("addressbook.csv","r+");
if(book.fptr==NULL)
{
	printf("Error:File doesn't exist\n");
	return 0;
}

loadContactsFromFile(&book);

int choice,Yes;
  do{

        printf("\nAddress Book Menu:\n");
        printf("1. Create Contact\n");
        printf("2. Search Contact\n");
        printf("3. Edit Contact\n");
        printf("4. Delete Contact\n");
        printf("5. List Contacts\n");
        printf("6. Exit\n");
        printf("Enter your choice: \n");

    scanf("%d",&choice);
    //printf("--------------------------------------------------------\n");
switch(choice)
{
    case 1:
        //  printf("contact create function\n");
            createContact(&book);
    break;
    case 2:
    //      printf("Selected search contact\n");
	  searchContact(&book);
    break;
    case 3:
  //         printf("Selected edit contact\n");
	   editContact(&book);
    break;
    case 4:
        //   printf("delete contact function\n");
	    deleteContact(&book);
    break;
    case 5:
//    	   printf("Selected list contact\n");
	   listContacts(&book);
    break;
    case 6:
           printf("Do you want to store data to file(Yes/No):\n");
	   char response[4];
	   scanf("%s",response);
	   if (strcmp(response, "Yes") == 0)
	   {
		saveContactsToFile(&book);
	   }
	   else
	   {
		   printf("Exit\n");
	   }
	   break;
	   
    default:
         printf("Select menu between 1-5\n");
	 break;
}
}
while(choice!=6);
fclose(book.fptr);
free(book.contacts);
    return 0;
}


