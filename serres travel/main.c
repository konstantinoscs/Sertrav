#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "Customer.h"
#include "Lang.h"
#include "Secondary Menu.h"
#define test 0
	
int main(void) 
{
	int people=0, opt, dayz, i, margin, exit=0, space=2, tpeople, day, fixed=0, en=-1, times;
	int html=0;
	char ch;
	Customer	*List=NULL;
	FILE *fp;
	
	/*printf("List must be in a text file with the name List.txt in the same folder as the programm ");
	printf("for it to work\n");*/
	printf("Sertrav v2.0: Konstantinos Stefanidis-Vozikis\n");
	printf("Revision Date: 31/8/2015\n\n");
		
	
	Opening (&en, &dayz);
	
	List=malloc(sizeof(Customer));
	if (List==NULL)
	{
		printf("Error stin malloc, to programma termatizetai\n");
		sleep(5);
		return -1;
	}
	fp=fopen("./List.txt", "r+");
	ch=fgetc(fp);
	/*printf("ok");*/
	while (ch!=EOF)
	{
		/*printf("loop is %d\n", people+1);*/
		ungetc(ch, fp);
		Read_Customer(List, people, dayz, fp);	
		people++;
		ch=fgetc(fp);
		if(ch!=EOF)
		{
			List=realloc(List, ((people+1)*sizeof(Customer)));
			if (List==NULL)
			{
				printf("Lathos stin realloc, to programma termatizetai\n");
				sleep(5);
				return -1;
			}
		}
	}
	fclose(fp);

	tpeople=people;
	if (tpeople%2==1) tpeople++;
	margin=people/dayz;
	margin/=space;
	if (margin==0) 
		margin=1;
	margin*=space;
	if (margin%2==1) margin++;
	
	Set_Seat(List, margin, people, tpeople, dayz, fixed);
	
	fp=fopen("./Seats per day.txt", "w");
	Print_SitRep_Doubles(List, fp, people, dayz, html);
	fclose (fp);
	
	fp=fopen("./Seats per person.txt", "w");
	Print_SitRep_Personal(List, fp, people, dayz, html);
	fclose (fp);
		
	while (!exit)
	{
		Primary_Menu(en);
		scanf("%d", &opt);
		printf("\n");
		switch (opt)
		{
			case 1:
				Menu_Management(List, &en, people, tpeople, dayz, margin); 
				printf("\n");
				break;
			case 2:
				Change_Lang(&en);
				break;
			case 3:
				Free_List (List, people);
				free(List);
				exit=1;
				break;
		}
	}
			
			#if test
			case 5:
				printf("Gia poia mera na ginei ektuposi theseon?\n");
				scanf("%d", &day);
				Print_Screen_Day (List, people, day, stdout);
				printf("\n");
				break;
			case 7:
				fp=fopen("./Seats per day.html", "w");
				Print_SitRep(List, fp, people, dayz, 1);
				fclose (fp);
				break;
			#endif
		printf("\n");
	printf("Programm executed succesfully\n");
	sleep (1);
	return 0;
}
