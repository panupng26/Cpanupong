#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node{
	int num;
	struct node *next;
	struct node *prev;
}ptr;

void reverse(ptr **head,ptr **last)
{
	ptr *current,*temp;
	
	current = *head;
	while(current != NULL)
	{
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		current = temp;
	}
	
	temp = (*head);
	(*head) = (*last);
	(*last) = temp;
	
	printf("List reversed successfully\n");
}


void delbegin(ptr **head)
{
	ptr *temp;
	
	if(*head != NULL)
	{
		temp = (*head);
		(*head) = (*head)->next;
		temp->next = NULL;
		(*head)->prev = NULL;
		free(temp);
		printf("SUCCESSFULLY DELETED NODE FROM POSITION.\n");
	}else{
		printf("empty\n");
	}
}

void delend(ptr **last)
{
	ptr *temp;
	
	if(*last != NULL)
	{
		temp = (*last);
		(*last) = (*last)->prev;
		(*last)->next = NULL;
		temp->prev = NULL;
		free(temp);
		printf("SUCCESSFULLY DELETED NODE FROM POSITION.\n");
	}else{
		printf("empty\n");
	}
}
void deln(ptr **head,ptr **last)
{
	ptr *temp;
	int i,p;

	if(*head != NULL)
	{
		temp = (*head) ;
	printf("Enter the position which you want to delete : ");
	scanf("%d",&p);
		for(i=1;i<p;i++)
		{
			temp = temp->next ;
		}
		if(p==1)
		{
			delbegin(&*head);
		}else if(temp == (*last))
		{
			delend(&*last);
		}else if(temp!=NULL)
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			
			free(temp);
			printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", p);
		}
		
		
	}else{
		printf("empty\n");
	}
}

void displayListFromFirst(ptr *head)
{
	ptr *temp;
	temp = head;
	int i = 1;
	while (temp != NULL)
	{
		printf("Data of %d node = %d\n",i,temp->num);
		temp = temp->next;
		i++;
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
			delbegin(&*head);
		}else if (menu == 3 )
			{
				delend(&*last);
			}else if (menu == 4)
				{
					deln(&*head,&*last);
				}else if (menu == 5)
					{
						displayListFromFirst(*head);
					}else if (menu == 6)
						{
							reverse(&*head,&*last);
						}
}

void menulist()
{
	int menu;
	printf("============================================\n");
	printf("DOUBLY LINKED LIST PROGRAM\n");
	printf("============================================\n");
	printf("1. Create List\n");
	printf("2. Delete node - at beginning\n");
	printf("3. Delete node - at end\n");
	printf("4. Delete node - at N\n");
	printf("5. Display list - at the front\n");
	printf("6. revers\n");
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
