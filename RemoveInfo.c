#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void RemoveInfo()
{
	FILE *fp;
	char IdToRemove;
	int CurrentPos, CurrentId;
	char ToBeDeleted[sizeof(struct GoodInfo)];
	char ReadNextChar;
	int i;
	char tmp, choice;

    if ((fp = fopen("goodinfo.data", "r+w")) == NULL)
	{
		printf("Data file does not exist.\n");
		system("pause");
		system("cls");
		MenuAdmin();
	}
	
	LabelDelete:
	printf("ID: ");
    fflush(stdin);
    scanf("%c", &IdToRemove);
	
	/* Read data file. Once read a line. If not a match, go to next line. */
	while(1)
	{
		CurrentId = fgetc(fp);
		if (CurrentId == IdToRemove)
		{
			CurrentPos = (ftell(fp) - sizeof(int)); 
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
	
	/* Go to the beginning of this line */
	fseek(fp, (long)CurrentPos, SEEK_SET);
	
	/* Write "" into this line*/
	for (i = 0; i < sizeof(struct GoodInfo); i++)
	{
		fputc('\0', fp);
	}
	
	printf("Delete another one? (y/n) ");
	fflush(stdin);
	scanf("%c", &choice);
	if (choice == 'y' || choice == 'Y')
	{
		goto LabelDelete;
	}
	if (choice == 'n' || choice == 'N')
	{
		fclose(fp);
		system("cls");
		MenuAdmin();
	}
}

