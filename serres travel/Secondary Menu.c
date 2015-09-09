#include <stdio.h>
#include <stdlib.h>

#include "Customer.h"
#include "Lang.h"

int Menu_Management(Customer *List, int *en, int people, int tpeople, int dayz, int margin)
{
	int opt, html=0, fixed=0, space=2, seats=51, lrow=5, exit=0;
	FILE *fp;
	
	while (!exit)
	{
		
		Print_Options(*en);
		scanf("%d", &opt);
		printf("\n");
		switch (opt)
		{
			case 1:
				printf("Not available at the moment\n\n");
				break;
				printf("Doste ton arithmo ton atomon pou thelete na metakinountai mazi 2,4,8 klp\n");
				scanf("%d", &space);
				while (space%2!=0)
				{
					printf("Den dothike sostos arithmos, parakalo ksanaprospathiste\n");
					scanf("%d", &space);
				}
				margin/=space;
				if (margin==0) margin=1;
				margin*=space;
				Set_Seat(List, margin, people, tpeople, dayz, fixed);
				break;
			case 2:
				printf("poses 2ades na meinoun statheres?\n");
				scanf ("%d", &fixed);
				fixed*=2;
				Set_Seat(List, margin, people, tpeople, dayz, 2);
				
				fp=fopen("./Seats per day.txt", "w");
				Print_SitRep_Doubles(List, fp, people, dayz, html);
				fclose (fp);
	
				fp=fopen("./Seats per person.txt", "w");
				Print_SitRep_Personal(List, fp, people, dayz, html);
				fclose (fp);
				break;
			case 3:
				Change_Lang(en);
				break;
			case 4:
				return;
			case 7:
				Print_Layout(seats, lrow);
				break;
			}
	}
}			
