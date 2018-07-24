#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void add(void);
void display(void);
void search(void);
void del(void);
void modify(void);
void gotoxy(int,int);
struct CAR{
        	int carID;
        	float carPrice;
        	char company[50];
          };  

int main()
{ 
    system("color 2e");
   	
	int choice;
   
    while(1)
    {
	
//	int choice;
    gotoxy(24,3);
	printf("******please Enter your choice*******\n\n");
	gotoxy(28,8);
	printf("<1> Make A New Account");
	gotoxy(28,10);
	printf("<2> List of Existing Accounts");
	gotoxy(28,12);
	printf("<3> Search An Account");
	gotoxy(28,14);
	printf("<4> Delete Account");
	gotoxy(28,16);
	printf("<5> Modify An Account");
	gotoxy(28,18);
	printf("<6> Quit");
	gotoxy(24,21);
	printf("Choice =  ");
//	printf("1.Add data\n2.display data\n3.Search data\n4.Delete data\n5.Modify data\n5.Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			del();
			break;
		case 5:
			modify();
			break;
		case 6:
			exit(0);
		default:
			printf("Opps...sorry...Please give valid input\n");
			break;
	}
	
   system("cls");	
	}

	return 0;
}
void add()
{ 
 char a = 'y';
 FILE *fp	;
 struct CAR  c;
 fp = fopen("record.txt","ab+");
 if(fp==NULL)
 {
 	printf("something went wrong\n");
 	exit(0);
 }
 
 while(a == 'y')
 {
 
  printf("Enter car ID\n");
 scanf("%d",&c.carID);
 printf("Enter car price\n");
 scanf("%f",&c.carPrice);
 fflush(stdin);
 printf("Enter car company\n");
 gets(c.company);
  fwrite(&c,sizeof(c),1,fp);
  printf("\t\t*****Made Account Successfully******\n\n");
  printf("Add another ac\n");
  fflush(stdin);
  scanf("%c",&a);
  printf("\n"); 
 }
 fclose(fp);
}
void display(void)
{ 
 int j ;
struct CAR c1 ;
 FILE *fp1;
 fp1 = fopen("record.txt","rb");
 while(fread(&c1,sizeof(c1),1,fp1))
 {
 	if(c1.carID == 0)
 	{
 		printf("Only %d Accounts are exiting\n\n ",j);
 		printf("press any key go to main manu\n\n");
 		getch();
 		break;
	}
 printf("Car id is = %d\n\n",c1.carID);
 printf("Car's price is =%.1f\n\n",c1.carPrice);
 printf("Car's company is = %s\n\n",c1.company);
 printf("\n\n\n\n");
 getch();
 j++;
  }
 fclose(fp1);	
}
void search(void)
{   char a1 = 'y'; 
   struct CAR c2;

	FILE *fp2;
	int id , t = 1;
	fp2 = fopen("record.txt","rb");
  while(a1 == 'y')
  {
	printf("Enter car id\n");
	scanf("%d",&id);
  while(fread(&c2,sizeof(c2),1,fp2))
  {
  
    if(c2.carID ==id)
    {
    	printf("car id is = %d\n",c2.carID);
    	printf("car price is = %.1f\n",c2.carPrice);
    	printf("car company is = %s\n",c2.company);
    	printf("\n\n\n\n");
    	t++;
   //	getch();
	}
  }
  if(t == 1)
  {
  	printf("******account not found******\n\n\n");
  }
  printf("Search Anothor Account y/n\n\n");
  fflush(stdin);
  scanf("%c",&a1);

}

  
	fclose(fp2);
} 
void del(void)  //delete function defination
{ 
 char ch = 'y' ;
int carid ;
 struct CAR c3 ;
 FILE *fp3 , *ft ;
 while(ch == 'y' )
 {
 	
 	 printf("Enter car id\n");
     scanf("%d",&carid);
   	 fp3 = fopen("record.txt","rb+");
     ft = fopen("temp.txt","wb+");
 	 rewind(fp3);
 	while(fread(&c3,sizeof(c3),1,fp3))
 	{
 	if(c3.carID!=carid)
	 {
	 	fwrite(&c3,sizeof(c3),1,ft);
		 }	
	}
	fclose(fp3);
	fclose(ft);
	remove("record.txt");
	rename("temp.txt","record.txt");
	printf("\t\t****Account delete successfully******\n\n\n\n");
	printf("Delete another ac\n");
	fflush(stdin);
	scanf("%c",&ch);
	printf("\n");
}
}

void modify(void)
{   
    int car_id ,cd ;
    struct CAR c4 ;
	char b = 'y',co[30];
	float cp;
	FILE *fp4;
	fp4 = fopen("record.txt","rb+");
	while(b == 'y')
	{   printf("Enter car id\n");
	    scanf("%d",&car_id);
		while(fread(&c4,sizeof(c4),1,fp4))
		{
			if(c4.carID==car_id)
			{   printf("Car id is = %d\n",c4.carID);
			    printf("Price is = %.1f\n",c4.carPrice);
			    printf("Company name is = %s\n\n\n",c4.company);
				printf("Enter New car Id\n");
				scanf("%d",&cd);
				printf("Enter New price\n");
				scanf("%f",&cp);
				fflush(stdin);
				printf("Enter New Compnay name\n");
				gets(co);
				fseek(fp4,-sizeof(c4),1);
				fwrite(&c4,sizeof(c4),1,fp4);
			}
		}
		printf("\t\t******Account Modified Successfully******\n\n\n");
		printf("Modify another ac\n");
		fflush(stdin);
		scanf("%c",&b);
		printf("\n");
		
	}
	fclose(fp4);
	
}
void gotoxy(int x , int y)
{
	COORD q ;
	q.X = x ;
	q.Y = y ;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),q);
}

