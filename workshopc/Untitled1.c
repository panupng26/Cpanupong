#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node{
	int num;
	struct node *next;
	struct node *prev;
}ptr;
void insertnodeN(ptr **head,ptr **last)
{
	ptr *newnode,*temp;
	int p,i,n;
	printf("Enter the position where you want to insert new node : ");
	scanf("%d",&p);
	if(*head == NULL)
	{
		printf("Enter data of %d node : ",p);
		scanf("%d",&n);
		
		temp = *head;
		for(i=1;i<p-1;i++)
		{
			if(temp == NULL)
			{
				break;
			}
			temp = temp->next ;
		}
		
		if(p == 1)
		{
			insertnodebegining(&*head);
		}
	}
		
}	
	
void insertnodeend(ptr **last)
{
	ptr *newnode;
	newnode = (ptr*)malloc(sizeof(ptr));
	printf("Enter data of end node : ");
	scanf("%d",&newnode->num);
	if(*last != NULL)
	{
		(*last)->next = newnode;
		newnode->next = NULL;
		newnode->prev = (*last) ;
		(*last) = newnode;
		printf("sucess\n");
		
	}else{
		printf("Empty \n");
	}
}

void insertnodebegining(ptr **head)
{
	ptr *newnode ;
	newnode = (ptr*)malloc(sizeof(ptr));
	printf("Enter data of first node : ");
	scanf("%d",&newnode->num);
	
	if(*head != NULL)
	{
		(*head)->prev = newnode;
		newnode->next = (*head);
		newnode->prev = NULL;
		(*head) = newnode;
		printf("sucess\n");
	}else
	{
			printf("Empty \n");
	}
}
void displayListFromEnd(ptr *last)
{
	ptr *temp;
	temp = last;
	while (temp != NULL)
	{
		printf("Data of %d \n",temp->num);
		temp = temp->prev ;
	}
}
void displayListFromFirst(ptr *head)
{
	ptr *temp;
	temp = head;
	while (temp != NULL)
	{
		printf("Data of %d \n",temp->num);
		temp = temp->next;
	}
}
void createnode(ptr **head,ptr **last)
{
	ptr *newnode;
	int i,n;
	printf("Enter the total number of node in list : ");
	scanf("%d",&n);
	if(n>=1)
	{
		(*head) = (ptr*)malloc(sizeof(ptr));
		
		if(head != NULL)
		{
				printf("Enter data of 1 node : ");
				scanf("%d",&(*head)->num);
				(*head)->next = NULL;
				(*head)->prev = NULL;
				(*last) = (*head);
				
				if(newnode != NULL)
				{
					for(i=2; i<=n;i++)
					{
						newnode= (ptr*)malloc(sizeof(ptr));
						printf("Enter data of %d node : ",i);
						scanf("%d",&newnode->num);
						newnode->next = NULL;
						newnode->prev = (*last);
						(*last)->next = newnode;
						*last = newnode;
					}
					printf("\nDoubly linked list create successfully\n");
				}
				
				
				
		}
	
	}else{
		printf("Sorry unlocate\n");
	}
}

void program(int menu,ptr **head,ptr **last)
{
	int n;
	
	if(menu == 1)
	{
	
    createnode(&*head,&*last);
	}else if (menu == 2)
		{
			insertnodebegin(&*head);
		}else if (menu == 3 )
			{
				insertnodeend(&*last);
			}else if (menu == 4)
				{
					insertnodeN(&*head,&*last);
				}else if (menu == 5)
					{
						displayListFromFirst(*head);
					}else if (menu == 6)
						{
							displayListFromEnd(*last);
						}
}

void menulist()
{
	int menu;
	printf("============================================\n");
	printf("DOUBLY LINKED LIST PROGRAM\n");
	printf("============================================\n");
	printf("1. Create List\n");
	printf("2. Insert node - at beginning\n");
	printf("3. Insert node - at end\n");
	printf("4. Insert node - at N\n");
	printf("5. Display list - at the front\n");
	printf("6. Display list - at the end\n");
	printf("0. Exit\n");
	printf("--------------------------------------------\n");

}
int main()
{
	ptr *head,*last;
	int menu ;
	int n;
	menulist();
	printf("Enter you choice : ");
	scanf("%d",&menu);

while(menu != 0)
{
	program(menu,&head,&last);
	menulist();
	printf("Enter you choice : ");
	scanf("%d",&menu);
	
}
	return 0;
}
