#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void AddInfo()
{
	FILE *fp;
	char choice;
	
	/* Open data file for appending. If not exist, create one. */
	if ((fp = fopen("goodinfo.data", "ab")) == NULL)
	{
		fp = fopen("goodinfo.data", "wb");
	}
	
	while (1)
	{
		/* Get informations */
		printf("\n");
		printf("ID: ");
		scanf("%d", &goods.id);
		printf("Name: (16 characters max)\n");
		fflush(stdin);
		gets(goods.name);
		printf("Price: ");
		fflush(stdin);
		scanf("%f", &goods.price);
		printf("Percent off for VIPs: ");
		fflush(stdin);
		scanf("%d", &goods.off);
		goods.vip_price = goods.price * (1 - (goods.off / 100.0)) * 1.0;
		
		/* Write informations to file */
		fprintf(fp, "%d", goods.id);
		fputc('\t', fp);
		fprintf(fp, "%s", goods.name);
		if (strlen(goods.name) < 8)
		{
    		fputc('\t', fp);
    		fputc('\t', fp);
		}
		else
		{
			fputc('\t', fp);
		}
		fprintf(fp, "%.2f", goods.price);
		fputc('\t', fp);
		fprintf(fp, "%d", goods.off);
		fputc('\t', fp);
		fprintf(fp, "%.2f", goods.vip_price);
		fputc('\n', fp);
		
		printf("Add another one? (y/n)\n");
		fflush(stdin);
		scanf("%c", &choice);
		
		if (choice == 'y' || choice == 'Y')
		{
			;
		}
		if (choice == 'n' || choice == 'N')
		{
			break;
		}
	}
		
	fclose (fp);
	
	system("cls");
	MenuAdmin();
}

