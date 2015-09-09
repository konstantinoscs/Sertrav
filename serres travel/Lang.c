#include <stdio.h>

void Change_Lang(int *en)
{
	(*en)*=-1;
}

void Print_Options(int en)
{
	if (en==1)
	{
		printf("1. Change margin\n");
		printf("2. Fixed seats\n");
		printf("3. Allagi glossas\n");
		printf("4. Return back\n");
		printf("Select option 1-6\n");
	}
	else
	{
	printf("1. Allagi eurous\n");
	printf("2. Statheres theseis\n");
	printf("3. Change language\n");
	printf("4. Epistrofi piso\n");
	printf("Doste epilogi 1-6\n");
	}
	printf("\n");
}

void Opening (int *en, int *dayz)
{
	int lang;
	printf("1. Ellinika\n");
	printf("2. English\n");
	printf("\n");
	scanf ("%d", &lang);
	if (lang==2)
	*en=1;
	if (lang==1)
		printf("Doste arithmo imeron\n");
	else
		printf("Insert number of days\n");
	scanf("%d", dayz);
}

void Primary_Menu(int en)
{
	if (en==1)
	{
		printf("1. More options\n");
		printf("2. Allagi glossas\n");
		printf("3. Exit\n");
		printf("Select option 1-3\n");
	}
	else
	{
		printf("1. Perissoteres epiloges\n");
		printf("2. Change language\n");
		printf("3. Exit\n");
		printf("Doste epilogi 1-3\n");
	}
}
