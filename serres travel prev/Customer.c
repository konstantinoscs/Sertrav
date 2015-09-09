#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Customer.h"

int Read_Customer(Customer *List, int ind, int days, FILE *in)
{
	List[ind].Seats=malloc(days*sizeof(int));
/******Name******/
	char ch;
	int size=10, position=0;
	List[ind].Name=malloc(10*sizeof(char));
	ch=fgetc(in);
	do
	{
		List[ind].Name[position++]=ch;
		/*printf("put %c\n", ch);*/
		if(position+1==size)
		{
			List[ind].Name=realloc(List[ind].Name, ++size);
			if(List[ind].Name==NULL)
				return 0;
		}
		ch=fgetc(in);
	}while(!(ch==' '));
	List[ind].Name[position]='\0';
	/*printf("%s", List[ind].Name);*/
	
/*****Last Name*******/
	size=10;
	position=0;
	List[ind].LName=malloc(10*sizeof(char));
	ch=fgetc(in);
	do
	{
		List[ind].LName[position++]=ch;
		/*printf("put %c\n", ch);*/
		if(position+1==size)
		{
			List[ind].LName=realloc(List[ind].LName, ++size);
			if(List[ind].LName==NULL)
				return 0;
		}
		ch=fgetc(in);
	}while(!(ch=='\n') && !(ch==EOF));
	List[ind].LName[position]='\0';
	if (ch==EOF)
		ungetc(ch, in);
	/*printf("%s\n", List[ind].LName);*/
}

int Set_Seat(Customer *List, int margin, int people, int tpeople, int days, int stath)
{
	int i, j, res;
	for(i=0; i<people; i++)
	{
		List[i].Seats[0]=i+1;
	}
	for (j=1; j<days; j++)
	{		
		for (i=0+stath; i<people; i++)
		{
			res=List[i].Seats[j-1]+margin;
			if(res<=tpeople)
			List[i].Seats[j]=res;
			else
			List[i].Seats[j]=(res%tpeople)+stath;	
		}
		for (i=0; i<stath; i++)
			List[i].Seats[j]=List[i].Seats[j-1];
	}
}

int Print_SitRep_Doubles(Customer *List, FILE *out, int people, int days, int html, int stath)
{
	int i, j;
	if (html)
		html_opening (out);
	fprintf(out, "Πρόγραμμα Εκδρομής\n");
	if (html)
		fprintf(out, "</h1>");
	fprintf(out, "\n");
	for(j=0; j<days; j++)
	{
		if (html)
			fprintf(out, "<h3>\n");
		fprintf(out, "%dη Μέρα:\n", j+1);
		if (html)
			fprintf(out, "</h3>\n");
		for (i=0; i<people; i+=2)
		{
			if (html)
				fprintf(out, "<p>\n");
			fprintf(out, "%s %.3s.", List[i].LName, List[i].Name);
			if (i+2<=people)
			fprintf(out, " - %s %.3s.:", List[i+1].LName, List[i+1].Name);
			fprintf(out, " %d", List[i].Seats[j]);
			if (i+2<=people)
			fprintf(out, "-%d" ,  List[i+1].Seats[j]);
			fprintf(out, "\n");
			if (html)
				fprintf (out, "</p>\n");
		}
		fprintf(out, "\n");
	}
	if (html)
	fprintf(out, "</body>\n</html>\n");
}

int Free_List (Customer *List, int people)
{
	int i;
	for(i=0; i<people; i++)
	{
		free(List[i].LName);
		free(List[i].Name);
		free(List[i].Seats);
	}
}

int Print_SitRep_Personal(Customer *List, FILE *out, int people, int days, int html, int stath)
{
	int i, j;
	for (i=0; i<people; i++)
	{
		fprintf(out, "%s %s\n", List[i].LName, List[i].Name);
		for(j=0; j<days; j++)
		{
			fprintf(out, "%dη Μέρα: %d\n", j+1, List[i].Seats[j]);
		}
		fprintf(out, "\n");
	}
}

int html_opening (FILE *out)
{
	fprintf(out, "<!DOCTYPE html>");
	fprintf(out, "<html>\n");
	fprintf(out, "<head>\n");
	fprintf(out, "\t<title>Sertrav</title>\n");
	fprintf(out, "</head>\n");
	fprintf(out, "<body>\n");
	fprintf(out, "<h1>\n");
}

int Print_Layout(int seats, int lrow)
{
	int i, lastrow;
	lastrow=seats-lrow;
	for (i=0; i<seats; i++)
	{
		printf("%d ", i+1);
		if (i+1<10 && (i+1)%2==1)
		{
			printf(" ");
			if ((i+1)!=9)
				printf(" ");
		}
		if ((i+1)<lastrow)
		{
			if((i+1)%4==0)
			{
				printf("\n");
			}
			else if ((i+1)%2==0)
			{
				printf("\t");
			}
		}
		if(i+1==lastrow)
			printf("\n");
	}
	printf("\n");
}

int Print_Screen_Day (Customer *List, int people, int day, FILE *out)
{
	int i;
	day--;
	fprintf(out, "%dη Μέρα:\n", day+1);
	for(i=0; i<people; i++)
	{
		fprintf(out, "%s, %s %d\n", List[i].LName, List[i].Name, List[i].Seats[day]);
	}
}
