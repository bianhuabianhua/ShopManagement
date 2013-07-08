#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <malloc.h>

FILE *fp;
int LineCount = 0;

int GetLineCount(int User)
{
	char c;
	
	if ((fp = fopen("goodinfo.data", "r")) == NULL)
	{
		printf("Data file does not exist.\n");
		system("pause");
		system("cls");
		if (User == 1)
		{
			MenuAdmin();
		}
		if (User == 0)
		{
			MenuGuest();
		}
	}
	
	fseek(fp, 0L, SEEK_SET);
	while (!feof(fp))
	{
		LabelCountBegin:
		c = fgetc(fp);
		if (c == '\n')
		{
			LineCount++;
//			goto LabelCountBegin;
		}
	}
	
	return LineCount;
}


void Billboard(int User)
{
	int i = 0;
	int a = 0, b = 0;
	char useless;
	struct GoodInfo temp;
	/* Create array PriceList[LineCount] */
	struct GoodInfo *PriceList = (struct GoodInfo *)malloc(GetLineCount(User) * sizeof(struct GoodInfo));
	
	fseek(fp, 0L, SEEK_SET);
	while (!feof(fp))
	{
		/* Get ID */
		PriceList[i].id = fgetc(fp);
		/* Skip spaces */
		do
		{
			useless = fgetc(fp);
		}
		while (fgetc(fp) == ' ');
		/* Get name */
		fscanf(fp, "%s", PriceList[i].name);
		/* Skip spaces */
		do
		{
			useless = fgetc(fp);
		}
		while (fgetc(fp) == ' ');
		/* Get price */
		fscanf(fp, "%f", &PriceList[i].price);
		i++;
		/* Go to the beginning of the next line */
		do
		{
			useless = fgetc(fp);
		}
		while (fgetc(fp) != '\n');
	}
	
	/* Sort. Price from high to low */
	for (a = 0; a < LineCount; a++)
	{
		for (b = 0; b < (LineCount - a); b++)
		{
			if (PriceList[b].price < PriceList[b+1].price)
			{
				temp.id = PriceList[b].id;
				strcpy(temp.name, PriceList[b].name);
				temp.price = PriceList[b].price;
				PriceList[b].id = PriceList[b+1].id;
				strcpy(PriceList[b].name, PriceList[b+1].name);
				PriceList[b].price = PriceList[b+1].price;
				PriceList[b+1].id = temp.id;
				strcpy(PriceList[b+1].name, temp.name);
				PriceList[b+1].price = temp.price;
			}
		}
	}
	
	system("cls");
	printf("Price billboard\n");
	printf("********************\n");
	printf("ID\tName\t\tPrice\n");
	for (i = 0; i < LineCount; i++)
	{
		if (strlen(PriceList[i].name) < 8)
		{
			printf("%d\t%s\t\t%.2f\n", PriceList[i].id, PriceList[i].name, PriceList[i].price);
		}
		else
		{
			printf("%d\t%s\t%.2f\n", PriceList[i].id, PriceList[i].name, PriceList[i].price);
		}
	}
	printf("********************\n");
	printf("End of billboard.\n");

	system("pause");
	fclose(fp);
	if (User == 0)
	{
		system("cls");
		MenuGuest();
	}
	if (User == 1)
	{
		system("cls");
		MenuAdmin();
	}
}

