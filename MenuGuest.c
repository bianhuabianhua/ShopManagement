#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void MenuGuest()
{
	char choice = '\0';
	
	/* Menu items for guest */
	printf("Welcome to shop management system. \n");
    printf("Now login as: Guest.\n");
    printf("********************\n");
    printf("1. View informations\n");
    printf("2. Price billboard\n");
    printf("\n");
    printf("L: Login as root\n");
    printf("A: About this programme\n");
    printf("X: Exit\n");
    printf("********************\n");
    printf("Choice: ");
    
    fflush(stdin);
	scanf("%c", &choice);
    
	switch (choice)
    {
    	case '1': ViewInfo(); break;
    	case '2': Billboard(); break;
    	case 'l':
    	case 'L': UserLogin(); break;
    	case 'a':
    	case 'A': About(0); break;
    	case 'x':
    	case 'X':exit (0); break;
    	default: printf("Invalid choice. Try again, please.\n");
				 printf("Choice: ");
				 fflush(stdin);
				 scanf("%c", &choice);
				 break;
    }
}