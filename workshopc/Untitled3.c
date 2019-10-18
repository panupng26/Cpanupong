#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node{
	int num;
	struct node *next;
	struct node *prev;
}ptr;

ptr* createnode(ptr *head,int n,ptr **last)
{
	ptr *newnode ;
	int i,data;
	if(n >= 1)
    {
        head = (ptr*)malloc(sizeof(ptr));

        if(head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->num = data;
            head->prev = NULL;
            head->next = NULL;

            (*last) = head;

            /*
             * Create rest of the n-1 nodes
             */
            for(i=2; i<=n; i++)
            {
                newnode = (ptr*)malloc(sizeof(ptr));

                if(newnode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newnode->num = data;
                    newnode->prev = (*last); // Link new node with the previous node
                    newnode->next = NULL;

                    (*last)->next = newnode; // Link previous node with the new node
                    (*last) = newnode;          // Make new node as last/previous node
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
    return head;
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


void program(int menu,ptr **head,ptr **last)
{
	int n;
	
	if(menu == 1)
	{
	printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
    (*head) = createnode(*head,n,&*last);
	}else if (menu == 2)
		{
		//	insertnodebegin(&*head);
		}else if (menu == 3 )
			{
		//		insertnodeend(&*last);
			}else if (menu == 4)
				{
			//		insertnodeN(&*head,&*last);
				}else if (menu == 5)
					{
				//		displayListFromFirst(*head);
					}else if (menu == 6)
						{
						//	displayListFromEnd(*last);
						}
						
						
		
		
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

//	}
	
	/*printf("Enter the number of nodes you want to create: ");
    scanf("%d",&n);
	head = createnode(n);
	*/
	/*
    printf("Select :");
    scanf("%d",&ck);
    if(ck == 1)
    {
    	displayListFromFirst(head);
	}
	*/
    
    
    
    
    
/*	int cnt,lab,i;
	char exit = 'N';
	
	printf("Enter the total number of node in list :");
	scanf("%d",&cnt);
	for(i=0;i<cnt;i++)
	{
		printf("Enter data of %d node: ",lab+1);
		scanf("%d",&root->num);
		lab++;
		
		
	}
		
	
	while(exit!='N')
	{
		if(head!=NULL)
		{
			newnode = (ptr*)malloc(sizeof(ptr));
			newnode->num = root->num;
			head->prev = NULL;
			head->next = NULL;
		
			last->next = newnode;
			last = newnode;
		}
		
		
	}
	
*/
	
}
