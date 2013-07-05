/* 
* Use root:admin to login as administrator.
* flag=0: guest, flag=1: root
*/

#include <stdio.h>
#include <stdlib.h>

void UserLogin()
{
	char user[5], pass[6];
	char root[5] = {"root"}, admin[6] = {"admin"};
	char guest[6] = {"guest"};
	int flag = 0;
	int i;
	
	for (i = 3; i > 0; i--)
	{
		printf("Username: ");
		scanf("%s", user);
		printf("Password: ");
		scanf("%s", pass);
		
	    if (strcmp(user, root) == 0 && strcmp(pass, admin) == 0)
		{
			flag = 1;
			break;
		}
		else if (strcmp(user, guest) == 0 && strcmp(pass, guest) == 0)
		{
			flag = 0;
			break;
		}
		else
		{
			printf("%d tries remaining.\n", i);
		}
	}
	
	if (flag == 1)
	{
		system("cls");
	    MenuAdmin();
	}
	else if (flag == 0)
    {
        system("cls");
		MenuGuest();
    }
    else
    {
    	printf("Access denided. Will now exit.\n");
    	exit (0);
    }
}

