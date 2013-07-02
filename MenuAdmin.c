#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void MenuAdmin()
{
	char choice = 'N';
	
	/* Menu items for root */
	printf("Welcome to shop management system. \n");
    printf("Now login as: root.\n");
    printf("********************\n");
    printf("1. Create item information\n");
    printf("2. View informations\n");
    printf("3. Delete information\n");
    printf("4. Edit information\n");
    printf("5. Price billboard\n");
    printf("6. Save into file\n");
    printf("\n");
    printf("G: Login as guest\n");
    printf("A: About this programme\n");
    printf("X: Exit\n");
    printf("********************\n");
    printf("Choice: ");
    
    fflush(stdin);
	scanf("%c", &choice);
    
    switch (choice)
    {
		case '1': AddInfo(); break;
    	case '2': ViewInfo(); break;
    	case '3': RemoveInfo(); break;
    	case '4': EditInfo(); break;
    	case '5': Billboard(); break;
    	case '6': FileOperation(); break; 
    	case 'g':
    	case 'G': system("cls"); MenuGuest(); break;
    	case 'a':
    	case 'A': About(1); break;
    	case 'x':
    	case 'X':exit (0); break;
    	default: printf("Invalid choice. Try again, please.\n");
    	         printf("Choice: ");
				 fflush(stdin);
				 scanf("%c", &choice);
				 break;
    }
}
