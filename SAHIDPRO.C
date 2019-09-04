 #include<stdio.h>
 #include<conio.h>
 #include<graphics.h>
 #include<string.h>
 #include<stdlib.h>
	  void Rectangle();
	   void Swindows();
	   void Clear_Window();
	   void Print_Heading();
	   void add();
	   void deletes();
	   void display();
	   void search();
	   struct student
	   {
	   int id[10];
	   char name[30];
	   char fn[30];
	   char branch[30];
	   unsigned int roll;
	   unsigned int mn;
	   char dist[10];
	   }su;

void Rectangle()
{
	int i,j;
	gotoxy(5,5);
	printf("%c",201);
	   for(i=1;i<70;i++)
	   {
	     gotoxy(i,j);
	     printf("%c",205);
	   }
	   gotoxy(80,j);
	   printf("%c",187);
	   for(j=6;j<25;j++)
	   {
	     gotoxy(75,j);
	     if(j==10)
	     printf("%c",185);
	   else
	    printf("%c",186);
	   }
	   gotoxy(75,25);
	   printf("%c",188);
	   for(i=74;i>5;i--)
	   {
	   gotoxy(i,25);
	   if(i==30)
	   printf("%c",202);
	   else
	   printf("%c",205);
	   }
	   gotoxy(5,25);
	   printf("%c",200);
	   for(j=24;j>5;j--)
	   {
	   gotoxy(5,j);
	   if(j==10)
	   printf("%c",204);
	   else
	   printf("%c",186);
	   }
	   for(i=6;i<75;i++)
	   {
		gotoxy(i,10);
			if(i==30)
				printf("%c",203);
			else
				printf("%c",205);
	   }
	   for(j=11;j<25;j++)
	   {
		gotoxy(30,j);
		printf("%c",186);
	   }
	   getch();
	}
  void Clear_Window()
  {
     int i=31,j=11;
       for(i=31;i<74;i++)
       {
	 for(j=11;j<25;j++)
	 {
	  gotoxy(i,j);
	  printf("");
	 }
       }
  }
  void Swindows()
  {
	Rectangle();
	setcolor(32);
	gotoxy(20,7);
	printf("     Student Management System       ");
	gotoxy(18,8);
	printf("    Ramgarh Engineering College  ");
	gotoxy(15,9);
	printf("   Department of Computer Science");
  }
void add()
{
void Clear_Window();
FILE *fp;
int print=30;
fp=fopen("record.txt","rb+");
if(fp=='\0')
{
  printf("Error in opening File");
}
else
{
  fflush(stdin);
  gotoxy(print,14);
  printf("Id:");
  scanf("%d",&su.id);
  gotoxy(print,15);
  printf("Student Name:");
  gets(su.name);
  gotoxy(print,16);
  printf("Father Name:");
  gets(su.fn);
  gotoxy(print,17);
  printf("Branch:");
  gets(su.branch);
  gotoxy(print,18);
  printf("Roll No:");
  scanf("%d",&su.roll);
  gotoxy(print,19);
  printf("Mobile No:");
  scanf("%d",&su.mn);
  gotoxy(print,20);
  printf("Dist:");
  scanf("%c",&su.dist);
  fwrite(&su,sizeof(su),1,fp);
  gotoxy(40,22);
  printf("The Record is Sucessfully added");
}
 fclose(fp);
}
void search()
{
FILE *fp;
 char id[15];
 int isFound=0;
Clear_Window();
gotoxy(35,14);
printf("Enter id to search:");
fflush(stdin);
gets(id);

fp=fopen("record.txt","r");
while(fread(&su,sizeof(su),1,fp)==1)
{
   if(strcmp(id,su.id)=='\0')
   {
	isFound=1;
	break;
   }
}
if(isFound==1)
{
gotoxy(35,15);
printf("The Record is Found");
gotoxy(35,17);
printf("ID:%s",su.id);
gotoxy(35,18);
printf("Name:%s",su.name);
gotoxy(35,19);
printf("Father Name:",su.fn);
gotoxy(35,20);
printf("Branch:",su.branch);
gotoxy(35,21);
printf("Roll No:",su.roll);
gotoxy(35,22);
printf("Mobile No:",su.mn);
}
else
{
gotoxy(35,24);
printf("Sorry No Record Found in the Database");
}
fclose(fp);
}
void deletes()
{
FILE *fp,*temp;
int print=35;
char s_id[15];
Clear_Window();
gotoxy(35,14);
printf("Enter Id to delete:");
fflush(stdin);
gets(s_id);
fp=fopen("record.txt","rb");
temp=fopen("temp.txt","wb");
while(fread(&su,sizeof(su),1,fp)==1)
{
if(strcmp(s_id,su.id)=='\0')
{
fwrite(&su,sizeof(su),1,temp);
}
}
fclose(fp);
fclose(temp);
remove("record.txt");
rename("temp.txt","record.txt");
gotoxy(35,24);
printf("The Record is Successfully deleted");
}
 void Main()
 {
	int choice;
	int x=6;
	setcolor(10);
	while(1)
	{
	gotoxy(x,12);
	printf("1.Add Student:");
	gotoxy(x,14);
	printf("2.Search Student by Id:");
	gotoxy(x,16);
	printf("3.Delete Student:");
	gotoxy(x,18);
	printf("4.Exit:");
	gotoxy(x,20);
	printf("Choose Your Choice:");
	scanf("%d",&choice);
	switch(choice)
	 {
		case 1:
		add();
		break;
		case 2:
		search();
		break;
		case 3:
		deletes();
		break;
		case 4:
		exit(1);
		break;
		default:
		printf("Choose valid choice");
	 }
     }
}
void Print_Heading()
{
}



 int main()
  {           FILE *fp;
	   int gd=DETECT,gm;
	   initgraph(&gd,&gm,"C:\\TC\\BGI");
	   clrscr();
	   Swindows();
	   Main();
	   Swindows();
	   Print_Heading();
	   closegraph();
	   getch();
	   return 0;
 }