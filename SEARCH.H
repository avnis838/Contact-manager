void search_sno()
{
  FILE *fp;
  int n,found=0;
  textcolor(WHITE);
  clrscr();
  printf("Enter the serial no : ");
  scanf("%d",&n);
  fp=fopen("info.dat","r");
  while(fread(&cont,sizeof(cont),1,fp)!=NULL)
  {
    if(cont.sno==n)
    {
      printf("\nCategory      : %s",cont.category);
      printf("\nNAME          : %s",cont.name);
      printf("\nGender        : %c",cont.gender);
      printf("\nAge           : %d",cont.age);
      printf("\nAddress       : %s",cont.address);
      printf("\nPhone no      : %s",cont.phone);
      found=1;
    }
  }
  if(found==0)
  {
    printf("\nNot found,press any key.....");
    fclose(fp);
    getch();
    return;
  }
  fclose(fp);
  getch();
}
void search_category()
{
  window(1,1,80,25);
  textbackground(BLUE);
  textcolor(GREEN);
  clrscr();
  char category[30];
  cprintf("\nEnter category to be searched : ");
  gets(category);
  gotoxy(35,3);
  cprintf("List of contacts");
  cprintf("\n");
  gotoxy(1,4);
  for(int i=1;i<=80;i++)
  cprintf("-");
  gotoxy(1,5);
  cprintf("SNO");
  gotoxy(8,5);
  cprintf("CATEGORY");
  gotoxy(20,5);
  cprintf("NAME");
  gotoxy(36,5);
  cprintf("GENDER");
  gotoxy(46,5);
  cprintf("AGE");
  gotoxy(55,5);
  cprintf("ADDRESS");
  gotoxy(70,5);
  cprintf("PHONE");
  printf("\n");
  for(int j=1;j<=80;j++)
  printf("-");
  FILE *fp=fopen("info.dat","rb");
  i=7;
  while(fread(&cont,sizeof(cont),1,fp)!=NULL)
  { if(strcmp(cont.category,category)==0){
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

  }
  fclose(fp);
  textcolor(YELLOW+BLINK);
  printf("\n");
  cprintf("Successfully displayed ,press any key..");
  getch();
}

void search_name()
{
  window(1,1,80,25);
  textbackground(BLUE);
  textcolor(GREEN);
  clrscr();
  char name[30];
  printf("\nEnter name to be searched : ");
  gets(name);
  gotoxy(35,3);
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
  { if(strcmp(cont.name,name)==0){
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

  }
  fclose(fp);
  textcolor(YELLOW+BLINK);
  printf("\n");
  cprintf("Successfully displayed ,press any key..");
  getch();
}
void search_phone()
{
  FILE *fp;
  int found=0;
  char phone[30];
  textcolor(YELLOW);
  clrscr();
  cprintf("\nEnter phone no : ");
  scanf("%s",&phone);
  fp=fopen("info.dat","rb");
  while(fread(&cont,sizeof(cont),1,fp)!=NULL)
  {
    if(strcmp(phone,cont.phone)==0)
    {
      printf("\nCategory      : %s",cont.category);
      printf("\nNAME          : %s",cont.name);
      printf("\nGender        : %c",cont.gender);
      printf("\nAge           : %d",cont.age);
      printf("\nAddress       : %s",cont.address);
      printf("\nPhone no      : %s",cont.phone);
      found=1;
    }
  }
  if(found==0)
  {
    printf("\nNot found, press any key....");
  }
  fclose(fp);
  getch();
}

