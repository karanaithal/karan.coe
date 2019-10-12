/*Write a program to create a singly linked list that maintains a list of integers. Implement the following operations on the list.
a) Insert a new element at front end and delete an element at front end*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
	struct list *next;
};

typedef struct node NODE;


void insert_front();
void del_front();
void display();
NODE* head;
NODE* getnode();
void main()
{
	int item,choice;
    for(;;)
	{
		printf("\n select  operation :\n");
		printf("1:insert at the front\n2:delete at the front\n 3:Display\n4:EXIT\n");
		scanf("%d",&choice);
        switch(choice)
	    {
		case 1: insert_front();
                break;
		case 2: del_front();
		        break;
		case 3: display();
                break;
		case 4: printf("END\n");
		        return;
		        break;
		default: printf("please enter correct choice\n");
	   }

	}
}

//end of main()----------------------------------------------------------------
//getnode()
NODE* getnode()
{
    NODE* n;
    n=(NODE *)malloc(sizeof(NODE));
    if(n==NULL)
    {
        printf("node not allocated\n");
        return;
    }
    else
        return n;
}
void insert_front()
{
	int item;
	NODE *n;
	n=getnode();
	printf("enter the data:\n");
	scanf("%d",&n->info);
	n->next=NULL;
    if(head==NULL)
	head=n;
    else
    {
	n->next=head;
	head=n;
    }

}

//---end of insert()------------------------------------------------//
void del_front()
{
    NODE* temp;
	if(head==NULL)
		printf("empty\n");
    else
    {
        temp=head;
        head=head->next;
        printf("Info of deleted node=%d", temp->info);
        free(temp);
    }

}
//-end of delete()-------------------------------------------------------//

void display()
{
	NODE *temp=head;
	if(head==NULL)
	{
		printf("EMPTY LIST\n");
		return;
	}

	printf("List contents\n");

	while(temp!=NULL)
	{
		printf("%d\t",temp->info);
		temp=temp->next;
	}

	}
