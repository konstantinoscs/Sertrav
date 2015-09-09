
typedef struct Customer
{
	char *Name;
	char *LName;
	int *Seats;
}Customer;

int Read_Customer (Customer *List, int ind, int days, FILE *in);
int Set_Seat(Customer *List, int margin, int people, int tpeople, int days, int fixed);
int Print_SitRep_Doubles(Customer *List, FILE *out, int people, int days, int html);
int Free_List (Customer *List, int people);
int Print_SitRep_Personal(Customer *List, FILE *out, int people, int days, int html);
int Print_Layout (int seats, int lrow);
int Print_Screen_Day (Customer *List, int people, int day, FILE *out);
