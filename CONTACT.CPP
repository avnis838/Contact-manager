#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include"data.h"
#include"search.h"
void delay(int milliseconds)
{
  long pause;
  clock_t now,then;
  pause=milliseconds*(CLOCKS_PER_SEC/1000);
  now=then=clock();
  while((now-then)<pause)
  now=clock();
}
void main()
{
  void change_password();
  void add_contact();
  void delete_contact();
  void edit_contact();
  void search_contact();
  void list_contact();
  int choice;
  char pass[30],ch,original[30];
  FILE *fp;
  int i;
  window(1,1,80,25);
  textbackground(YELLOW);
  clrscr();
  window(20,10,60,15);
  textbackground(BLACK);
  clrscr();
  gotoxy(4,3);
  textcolor(YELLOW+BLINK);
  cprintf("ENTER PASSWORD:");
  i=0;
  while(1)
  {
  ch=getch();
  if(ch==13)
  {
  pass[i] ='\0';
  break;
  }
  pass[i++]=ch;
  printf("*");
  }
  fp=fopen("password.dat","r");
  fgets(original,30,fp);
  fclose(fp);
  if(!strcmp(original,pass)==0)
  {
    gotoxy(4,4);
    textcolor(WHITE+BLINK);
    cprintf("INCORRECT,press any key");
    getch();
    exit(0);
  }
  else
  {
    window(1,1,80,25);
    textbackground(11);
    clrscr();
    gotoxy(32,3);
    textcolor(RED);
    cprintf("CONTACT MANAGER");
    gotoxy(31,5);
    textcolor(BLUE);
    cprintf("VERSION 1");
    gotoxy(22,8);
    textcolor(YELLOW);
    cprintf("DEVELOPED BY ");
    textcolor(BLUE);
    cprintf("AVNISH KUMAR");
    textcolor(RED);
    gotoxy(5,15);
    cprintf("Please wait..");
    for(int i=1;i<=25;i++)
    {
      cprintf("%c",220);
      delay(100);
    }
    while(1){
    textbackground(YELLOW);
    clrscr();
    window(18,5,60,22);
    textbackground(BLACK);
    clrscr();
    textcolor(11);
    gotoxy(18,2);
    cprintf("MAIN MENU");
    gotoxy(16,3);
    cprintf("-------------");
    textcolor(WHITE);
    gotoxy(12,5);
    cprintf("1 Add new contact");
    gotoxy(12,6);
    cprintf("2 Delete contact");
    gotoxy(12,7);
    cprintf("3 Editing");
    gotoxy(12,8);
    cprintf("4 Search contact");
    gotoxy(12,9);
    cprintf("5 List of contacts");
    gotoxy(12,10);
    cprintf("6 Change password");
    gotoxy(12,11);
    cprintf("7 Exit");
    gotoxy(5,12);
    cprintf("-----------------------------------");
    gotoxy(12,14);
    textcolor(YELLOW+BLINK);
    cprintf("Enter your choice:");
    choice=getche();
    switch(choice)
    {
      case '1':
      add_contact();
      break;
      case '2':
      delete_contact();
      break;
      case '3':
      edit_contact();
      break;
      case '4':
      search_contact();
      break;
      case '5':
      list_contact();
      break;
      case '6':
      change_password();
      break;
      case '7':
      exit(0);

    }
    }
  }
  getch();
}
void search_contact()
{
  window(1,1,80,25);
  textbackground(BLACK);
  textcolor(11);
  clrscr();
  textcolor(RED);
  printf("SEARCH options");
  printf("\n") ;
  printf("----------------------------------------------");
  printf("\n1 search by serial no ");
  printf("\n2 search by category ");
  printf("\n3 search by name ");
  printf("\n4 search by phone no ");
  printf("\n5 Back to back menu");
  printf("\n--------------------------------------------");
  textcolor(YELLOW+BLINK);
  cprintf("\nEnter your choice ? ");
  int ch=getche();
  switch(ch)
  {
    case '1':
    search_sno();
    break;
    case '2':
    search_category();
    break;
    case '3':
    search_name();
    break;
    case '4':
    search_phone();
    break;
    case '5':
    return;
  }

}
void change_password()
{
  FILE *fp;
  char current[30],original[30],newpass[30],confirm[30];
  window(1,1,80,25);
  textbackground(WHITE);
  textcolor(BLUE);
  clrscr();
  printf("Change password ");
  printf("\n----------------------------------------------");
  printf("\nEnter the current password : ");
  gets(current);

  fp=fopen("password.dat","r");
  fgets(original,30,fp);
  fclose(fp);
  if(strcmp(current,original)!=0)
  {
    printf("\nIncorrect password, press any key...");
    getch();
    return;
  }
  printf("\nEnter new password : ");
  gets(newpass);
  printf("\nRe-Enter password : ");
  gets(confirm);
  if(strcmp(confirm,newpass)!=0)
  {
    printf("\n Not match, press any key......");
    getch();
    return;
  }
  fp=fopen("password.dat","w");
  fprintf(fp,"%s",newpass);
  fclose(fp);
  printf("Successfully updated,press any key....");
  getch();
}
void edit_contact()
{
  FILE *fp;
  int pos,n,found;
  window(1,1,80,25);
  textcolor(YELLOW);
  textbackground(BLACK);
  clrscr();
  printf("EDIT contact\n");
  printf("-------------------------------------------------------------");
  printf("Enter the serial no to be edited : ");
  scanf("%d",&n);
  fp=fopen("info.dat","r+b");
  found=0;
  while(fread(&cont,sizeof(cont),1,fp)!=NULL)
  {
    if(cont.sno==n)
    {
      found=1;
      printf("\nCategory     : %s",cont.category);
      printf("\nName         : %s",cont.name);
      printf("\nGender       : %c",cont.gender);
      printf("\nAddress      : %s",cont.address);
      printf("\nAge          : %d",cont.age);
      printf("\nContact no   : %s",cont.phone);
      printf("\nEmail id     : %s",cont.email);
      break;
    }
  }
  if(found==0)
  {
    printf("\n");
    textcolor(RED+BLINK);
    cprintf("NOT found,press any key..");
    fclose(fp);
    getch();
    return;
  }
  printf("\nEnter new data : ");
  printf("\n");
  pos=ftell(fp);
  fseek(fp,pos-sizeof(cont),SEEK_SET);
  fflush(stdin);
  printf("Enter category (Friend/Pg/Salesman/Customer/Student) : ");
  gets(cont.category);
  fflush(stdin);
  printf("Enter name : ");
  gets(cont.name);
  fflush(stdin);
  printf("Enter gender m/f : ");
  scanf("%c",cont.gender);
  fflush(stdin);
  printf("Enter age : ");
  scanf("%d",cont.age);
  fflush(stdin);
  printf("Enter address : ");
  gets(cont.address);
  fflush(stdin);
  printf("Enter phone no  : ");
  gets(cont.phone);
  fflush(stdin);
  printf("Enter email id : ");
  gets(cont.email);
  fflush(stdin);

  fwrite(&cont,sizeof(cont),1,fp);
  fclose(fp);
  printf("\n");
  textcolor(RED+BLINK);
  cprintf("Successfully Updated, Press any key...");
  getch();
}

void delete_contact()
{
  int n,found=0;
  FILE *fp1,*fp2;
  window(1,1,80,25);
  textbackground(BLACK);
  textcolor(YELLOW);
  clrscr();
  printf("DELETE CONTACT");
  printf("\n-------------------------------------------------");
  printf("\nEnter serial no to be deleted:");
  scanf("%d",&n);
  fp1=fopen("info.dat","rb");
  while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
  {
    if(cont.sno==n)
    {
      printf("\nCAtegory : %s",cont.category);
      printf("\nNAme : %s",cont.name);
      printf("\nGender : %c",cont.gender);
      printf("\nAge : %d",cont.age);
      printf("\nAddress : %s",cont.address);
      printf("\nPhone : %s",cont.phone);
      printf("\nEmail : %s",cont.email);
      printf("\n--------------------------------------------------");
      found=1;
      break;
    }
    }
    textcolor(RED+BLINK);
    printf("\n");
    if(found==0){
    cprintf("NOT found,press any key");
    getch();
    fclose(fp1);
    return;
    }
    printf("\ndelete it y/n : ");
    char choice=getche();
    if(choice=='y' || choice=='Y')
    {
    rewind(fp1);
    fp2=fopen("temp.dat","wb");
    while(fread(&cont,sizeof(cont),1,fp1)!=NULL)
    {
      if(cont.sno!=n)
      {
	fwrite(&cont,sizeof(cont),1,fp2);
      }

    }
    fclose(fp1);
    fclose(fp2);
    remove("info.dat");
    rename("temp.dat","info.dat");
    textcolor(GREEN+BLINK);
    printf("\n");
    cprintf("Successfully deleted, press any key");
    getch();
    }
}

int getsno()
{
  FILE *fp;
  int n;
  fp=fopen("info.dat","rb");
  int size=sizeof(cont);
  fseek(fp,-size,SEEK_END);
  fread(&cont,sizeof(cont),1,fp);
  n=cont.sno;
  fclose(fp);
  n++;
  return n;
}
void add_contact()
{
  FILE *fp;
  window(1,1,80,25);
  textbackground(YELLOW);
  textcolor(BLACK);
  clrscr();
  printf("ADD new contact\n");
  printf("------------------------------------------------------");
  fflush(stdin);
  cont.sno=getsno();
  printf("\nSerial no: %d",cont.sno);

  fflush(stdin);
  printf("\nEnter category (Friend/PG/Salesman/customer/student):");
  gets(cont.category);
  fflush(stdin);
  printf("Enter name :");
  gets(cont.name);
  fflush(stdin);
  printf("Enter gender m/f :");
  scanf("%c",&cont.gender);
  fflush(stdin);
  printf("Enter age :");
  scanf("%d",&cont.age);
  fflush(stdin);
  printf("Enter address:");
  gets(cont.address);
  fflush(stdin);
  printf("Enter email id :");
  gets(cont.email);
  fflush(stdin);
  printf("Enter phone no:");
  gets(cont.phone);
  fflush(stdin);
  fp=fopen("info.dat","ab");
  fwrite(&cont,sizeof(cont),1,fp);
  fclose(fp);
  textcolor(WHITE+BLINK);
  cprintf("\nSuccessfully saved,press any key");


}

void list_contact()
{
  window(1,1,80,25);
  textbackground(WHITE);
  textcolor(BLUE);
  clrscr();
  gotoxy(35,1);
  printf("List of contacts");
  printf("\n");
  for(int i=1;i<=80;i++)
  printf("-");
  gotoxy(1,3);
  printf("SNO");
  gotoxy(8,3);
  printf("CATEGORY");
  gotoxy(20,3);
  printf("NAME");
  gotoxy(36,3);
  printf("GENDER");
  gotoxy(46,3);
  printf("AGE");
  gotoxy(55,3);
  printf("ADDRESS");
  gotoxy(70,3);
  printf("PHONE");
  printf("\n");
  for(int j=1;j<=80;j++)
  printf("-");
  FILE *fp=fopen("info.dat","rb");
  i=5;
  while(fread(&cont,sizeof(cont),1,fp)!=NULL)
  {
    gotoxy(1,i);
    printf("%d",cont.sno);
    gotoxy(8,i);
    printf("%s",cont.category);
    gotoxy(20,i);
    printf("%s",cont.name);
    gotoxy(36,i);
    printf("%c",cont.gender);
    gotoxy(46,i);
    printf("%d",cont.age);
    gotoxy(55,i);
    printf("%s",cont.address);
    gotoxy(70,i);
    printf("%s",cont.phone);
    i++;

  }
  fclose(fp);
  textcolor(RED+BLINK);
  printf("\n");
  cprintf("PRESS ANY KEY....");
  getch();
}