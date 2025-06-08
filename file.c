#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "file.h"
#include "contact.h"
void saveContactsToFile(AddressBook *addressBook) 
{
	FILE *fptr=fopen("addressBook.csv","w");
	// Writing to the file passed from main
    if (fptr == NULL)
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

	//run loop
fprintf(fptr,"#%d#\n",addressBook->contactCount);
//loop
for(int i=0;i<addressBook->contactCount; i++) 
{
        fprintf(fptr, "%s,%s,%s\n", 
                addressBook->contacts[i].name,
                addressBook->contacts[i].phone,
                addressBook->contacts[i].email);
}
fclose(fptr);
printf("Contacts saved successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook) 
{
	FILE *fptr=fopen("addressbook.csv", "r");
	if (fptr == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }
	char str[100];
	fscanf(fptr,"%s",str);
	int num=atoi(strtok(str+1,"#"));

	addressBook->contactCount=num;

	//Allocate memory
	addressBook->contacts=malloc(num*sizeof(Contact));
	if (addressBook->contacts == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(fptr);
        return;
    }

	//Read second line from csv file
	for(int i=0;i<num;i++)
	{
		//read
	fscanf(fptr, " %[^\n]" ,str);
	char *token = strtok(str, ",");
        if (token != NULL) 
	{
	strcpy(addressBook->contacts[i].name,token);
	}
	token = strtok(NULL, ",");
	if (token != NULL)
	{
	strcpy(addressBook->contacts[i].phone,token);
	}
	token = strtok(NULL, ",");
        if (token != NULL) 
	{
	strcpy(addressBook->contacts[i].email,token);
	}
	}
	fclose(fptr);

}
