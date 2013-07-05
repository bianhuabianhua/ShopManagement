#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void EditInfo()
{
	FILE *fp;
	char IdToEdit;
	int CurrentId;
	int CurrentPos, diag;
	char tmp;
	char choice;
	
	if ((fp = fopen("goodinfo.data", "r+w")) == NULL)
	{
		printf("Data file does not exist. Please create one first.\n");
		system("pause");
		system("cls");
		MenuAdmin();
	}
	
	LabelEdit:
	printf("ID: ");
	fflush(stdin);
	scanf("%c", &IdToEdit);
	
	fseek(fp, 0L, SEEK_SET);    /* Begin from the head of the file */
	
	/* Read once a line. If ID mismatch, go to next line. */
	while(1)
	{
        CurrentId = fgetc(fp);
	    if (CurrentId == IdToEdit)
	    {
	    	CurrentPos = (ftell(fp) + sizeof('\t'));
			break;
	    }
	    else
	    {
			do
	    	{
	    		tmp = fgetc(fp);
	    	}
	    	while (tmp != '\n');
	    }
	}
	
	/* Edit information */
	printf("Name: (50 characters max)\n");
	fflush(stdin);
	gets(goods.name);
	printf("Price: ");
    fflush(stdin);
	scanf("%f", &goods.price);
	printf("Percent off: ");
    fflush(stdin);
	scanf("%d", &goods.off);
	goods.vip_price = goods.price * (1 - (goods.off / 100.0)) * 1.0;
	
	/* Put the position label before goods.name in that line*/
	fseek(fp, (long)CurrentPos, 0);
	
	/* Write to file */
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

    printf("Edit another one? (y/n)\n");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
    	goto LabelEdit;
    }
    if (choice == 'N' || choice == 'n')
    {
    	fclose(fp);
		system("cls");
    	MenuAdmin();
    }
}

