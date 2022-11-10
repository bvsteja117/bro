#include<stdio.h>
#include<stdlib.h>
typedef struct snglst
{
  int data;
  struct snglst *lnk;
}snglst;
snglst *strt,*nxt,*tmp;
int n,i,elm,pos;



main()
{
  int ch;
  void creation();
  void display();
  void revdisplay(snglst*);
  void insertion();
  void deletion();
  void search();
  while(1)
  {

  printf("1.Creation \n");
  printf("2.Display \n");
  printf("3.Display in Reverse \n");
  printf("4.Insertion \n");
  printf("5.Deletion \n");
  printf("6.Search \n");
  printf("7.Exit \n");
  printf("Select ur choice \n");
  scanf("%d",&ch);

  switch(ch)
  {
	case 1:
		creation();
		break;
	case 2:
		display();
		break;
	case 3:
		printf("List is ");
		revdisplay(strt);
		break;
	case 4:
		insertion();
		break;
	case 5:
		deletion();
		break;
	case 6:
		search();
		break;
	case 7:
		free(strt);
		exit(0);
	default:
		printf("Invalid choice \n");
  }  }}
void creation()
{
	strt=NULL;
	printf("Enter the range");
	scanf("%d",&n);

	printf("Enter %d elements \n",n);
	for(i=1;i<=n;i++)
	{
	   tmp=(snglst*)malloc(sizeof(snglst));
	   printf("Enter the element %d: ",i);
	   scanf("%d",&tmp->data);
	   tmp->lnk=NULL;
	   if(strt==NULL)
	   {
	     strt=tmp;
	     nxt=tmp;
	   }
	   else
	   {
	     nxt->lnk=tmp;
	     nxt=tmp;
	   }
	}
	printf("List was created Successfully \n ");
}
void insertion()
{
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
   printf("Enter the pos to insert \n");
   scanf("%d",&pos);
   if(pos<1 || pos>n+1)
    printf("%d is out of range",pos);
   else
   {
    printf("Enter the elem to insert\n");
    scanf("%d",&elm);
    tmp=(snglst*)malloc(sizeof(snglst));
    tmp->data=elm;
    nxt=strt;

    if(pos==1)
    {
      tmp->lnk=strt;
      strt=tmp;
    }
    else
    {
      for(i=1;i<pos-1;i++)
       nxt=nxt->lnk;

     tmp->lnk=nxt->lnk;
     nxt->lnk=tmp;
     }
    n++;
    printf("%d is inserted successfully \n",elm);
   }
}
void deletion()
{
   snglst *del;
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
  printf("Enter the elm to delete \n");
  scanf("%d",&elm);
  if(strt->data==elm)
    {
      tmp=strt;
      strt=tmp->lnk;
      free(tmp);
    }
   else
    {
      del=strt;
      while(del!=NULL)
      {
	 if(del->lnk->data==elm)
	 {
	    tmp=del->lnk;
	    del->lnk=tmp->lnk;
	    free(tmp);
	    break;
	 }
	 del=del->lnk;
      }
    }
    if(del==NULL)
     printf("%d not found",elm);
    else
    {
     printf("%d delted successfully",elm);
     n--;
    }}
void display()
{
   snglst *dsp;
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
   dsp=strt;
   printf("List is \n");
   while(dsp!=NULL)
    {
      printf("%d\t",dsp->data);
      dsp=dsp->lnk;
    }
}
void revdisplay(snglst *dsp)
{
   if(strt==NULL)
   {
     printf(" empty");
     return;
   }
   if(dsp==NULL)
     return;
   revdisplay(dsp->lnk);
   printf("%d\t",dsp->data);
}
void search()
{
   snglst *srch;
   if(strt==NULL)
   {
     printf("List is empty");
     return;
   }
   srch=strt;
   printf("Enter the elm to search \n");
   scanf("%d",&elm);
   i=1;
   while(srch!=NULL)
    {
      if(srch->data==elm)
       {
	  printf("%d found at position %d",elm,i);
	  break;
       }
    i++;
    srch=srch->lnk;
    }
    if(srch==NULL)
      printf("%d not found in the list ",elm);
}
