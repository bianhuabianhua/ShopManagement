#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    char choice;
	
	printf("Welcome to shop management system. \n");
    printf("********************\n");
    printf("1. User Login\n");
    printf("2. Information management\n");
    printf("\n");
    printf("X. Exit\n");
    printf("********************\n");
    printf("Choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    
    while (1)
    {
    	switch (choice)
    	{
    		case '1': UserLogin(); break;
    		case '2': system("cls"); MenuGuest(); break;
    		case 'x':
    		case 'X': exit (0); break;
    		default: printf("Invalid choice. Try again, please.\n");
    		         printf("Choice: ");
    		         fflush(stdin);
    		         scanf("%c", &choice);
    	}
    }
    return 0;
}

