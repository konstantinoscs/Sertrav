#include <stdio.h>

void Print_Options(int en)
{
	if (en==1)
	{
		printf("1. Print seats per day\n");
		printf("2. Print seats per person\n");
		printf("3. Change margin\n");
		printf("4. Fixed seats\n");
		printf("5. Allagi glossas\n");
		printf("6. Exit\n");
		printf("Select option 1-6\n");
	}
	else
	{
	printf("1. Ektuposi theseon ana imera\n");
	printf("2. Ekutposi theseon ana atomo\n");
	printf("3. Allagi eurous\n");
	printf("4. Statheres theseis\n");
	printf("5. Change language\n");
	printf("6. Exit\n");
	printf("Doste epilogi 1-6\n");
	}
	printf("\n");
}

void Opening (int *en, int *dayz)
{
	int lang;
	printf("1. Ellinika\n");
	printf("2.English\n");
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
	
