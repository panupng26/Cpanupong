#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int data;
	struct node *next,*prev;
}ptr;
void menushow()
{
	printf("=============================================\n");
	printf("DOUBLY LINKED LIST PROGRAM\n");
	printf("=============================================\n");
	printf("	1.	Create List\n");
	printf("	2.	Delete node - from begining\n");
	printf("	3.	Delete node - from end \n");
	printf("	4.	Delete node - from N\n");
	printf("	5. 	Display list\n");
	printf("	6.	Reverse list\n");
	printf("	0.	Exit\n");
	printf("---------------------------------------------\n");
}

ptr* createlist(ptr **head,int loop)
{
	ptr *newnode;
	ptr *last;
	int i,data;

	if(loop > 1)
	{
		*head = (ptr*)malloc(sizeof(ptr));
		
		
		
	
		if(*head != NULL)
		{
			printf("Enter data of 1 node : ");
			scanf("%d",&(*head)->data);
			(*head)->prev = NULL;
			(*head)->next = NULL;
			last = (*head);
			for(i=2;i<=loop;i++)
			{
				newnode = (ptr*)malloc(sizeof(ptr));
			
				if(newnode!=NULL)
				{
					printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newnode->data = data;
                  	newnode->prev = last ;
					
				}
				
			}
			
		}
		
	}
	return last;
}

void program(ptr **head, ptr **last)
{
	int menu,data;
	
	menushow();
	printf("Enter your choice : ");
	scanf("%d",&menu);
	while(menu != 0)
	{
		if(menu == 1)
		{
			printf("1");
		}else if (menu == 2)
		{
			printf("2");
		}else if (menu == 3)
		{
			printf("3");
		}else if (menu == 4)
		{
			printf("4");
		}else if (menu == 5)
		{
			printf("5");
		}else if (menu == 6)
		{
			printf("6");
		}
		menushow();
		printf("Enter your choice : ");
		scanf("%d",&menu);
	}
}
int main()
{
	ptr *head,*last;
	program(&head,&last);
	return 0;
}
