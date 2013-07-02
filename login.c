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
	int flag = 0;
	
	printf("Username: ");
	scanf("%s", user);
	printf("Password: ");
	scanf("%s", pass);
	
    if (strcmp(user, root) == 0 && strcmp(pass, admin) == 0)
	{
		flag = 1;
	}

	if (flag == 1)
	{
		system("cls");
	    MenuAdmin();
	}
	
    if (flag == 0)
    {
        printf("Access Denided.\n");
        
        system("pause");
        system("cls");
		MenuGuest();
    }
}

