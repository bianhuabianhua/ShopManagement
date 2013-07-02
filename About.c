#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void About(int flag)
{
	system("cls");
	printf("About. \n");
	printf("********************\n");
	printf("A simple shop management system.\n");
	printf("Written by b0R1s @ SiT.\n");
	printf("Not distributed yet. Under GPL license agreement.\n");
	printf("Copyleft 2013 b0R1s. None right reserved.\n");
	printf("********************\n");
	printf("Thanks for using.\n");
	system("pause");
	system("cls");
	
	if (flag == 1)
	{
		MenuAdmin();
	}
	if (flag == 0)
	{
		MenuGuest();
	}
}

