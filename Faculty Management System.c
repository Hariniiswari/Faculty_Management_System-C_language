#include<stdio.h>
#include<stdlib.h>
struct fac
{
	int id;
	char name[20];
	char dept[10];
	char desig[10];
};

int ctr=0;

void addrec(struct fac *fptr);
void display(struct fac *fptr,int ctr);
void sbydept(struct fac *fptr,int ctr);
void sbyid(struct fac *fptr,int ctr);

void main()
{
	int ch,max;
	struct fac *fptr;
	printf("Enter the max size\n");
	scanf("%d",&max);
	fptr=(struct fac*)malloc(max*sizeof(struct fac));
	do
	{
		printf("1.Add records 2.Display records 3.Search by department 4.Search by ID\n");
		printf("Enter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Add records\n");
			        addrec(fptr);
					break;
			case 2: printf("Display records\n");
					display(fptr,ctr);
					break;
			case 3: printf("Search by department\n");
					sbydept(fptr,ctr);
					break;
			case 4: printf("Search by id\n");
					sbyid(fptr,ctr);
					break;
			default: printf("wrong choice\n");
					 break;
		}
	}while(ch!=4);
}
void  addrec(struct fac *fptr)
{
        printf("Faculty id\n");
        scanf("%d",&(fptr+ctr)->id);
        printf("Faculty name\n");
        scanf("%s",(fptr+ctr)->name);
        printf("Department \n");
        scanf("%s",(fptr+ctr)->dept);
        printf("Designation\n");
        scanf("%s",(fptr+ctr)->desig);
        
        ctr++;
}
void display(struct fac *fptr,int ctr)
{

    int i;
    if(ctr==0)
    {
        printf("No records found\n");
    }
    else
    {
        printf("Id   Name  Department  Designation\n");
        for(i=0;i<ctr;i++)
        {
        	printf("%d\t%s\t%s\t%s\n",(fptr+i)->id,(fptr+i)->name,(fptr+i)->dept,(fptr+i)->desig);
    	}
    	printf("\n\n");
    }
}
void sbydept(struct fac *fptr,int ctr)
{

    int i;
    char search[10];
    printf("Enter the department to be searched\n");
	scanf("%s",search);
	printf("Id   Name  Department  Designation\n");
    for(i=0;i<ctr;i++)
    {
        if(strcmp(search,(fptr+i)->dept)==0)
        {
            printf("%d\t%s\t%s\t%s\n",(fptr+i)->id,(fptr+i)->name,(fptr+i)->dept,(fptr+i)->desig);
        }
    }
}
void sbyid(struct fac *fptr,int ctr)
{
	int a;
	int i;
    printf("Enter the ID to be searched\n");
    scanf("%d",&a);
    printf("Id   Name  Department  Designation\n");
    for(i=0;i<ctr;i++)
    {
	    if(a==(fptr+i)->id)
        {
            printf("%d\t%s\t%s\t%s\n",(fptr+i)->id,(fptr+i)->name,(fptr+i)->dept,(fptr+i)->desig);
        }
    }
}