#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void ViewInfo(int flag)
{
	FILE *fp;
	
	if((fp = fopen("goodinfo.data", "r")) == NULL)
	{
		if (flag == 0)
		{
			printf("Data file does not exist. Please contact the administrator. \n");
			system("pause");
			system("cls");
			MenuGuest();
		}
		if (flag = 1)
		{
			printf("Data file does not exist. Please create one first.\n");
			system("pause");
			system("cls");
			MenuAdmin();
		}
	}
	
	system("cls");
	printf("Goods information\n");
	printf("********************\n");
	printf("ID\tName\t\tPrice\tOff\tVIP Price\n");
	
	while(!feof(fp))
	{
		putchar(getc(fp));
	}
	
	printf("\n");
	printf("********************\n");
	printf("End of list.\n");
	system("pause");
	system("cls");
	
	fclose(fp);
	
	if (flag == 0)
	{
		MenuGuest();
	}
	if (flag == 1)
	{
		MenuAdmin();
	}
}

