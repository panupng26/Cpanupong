#include <stdio.h>
#include <string.h>

int cartAt()
{
	char card[4] = {"C","D","H","S"};
	int check,c;
	int lengthc,lengthn;
	char number[13] = {"2","3","4","5","6","7","8","9","0","J","Q","K","A"};
	lengthc = strlen(card);
	lengthn = strlen(number);
	for(i=0;i<lengthc;i++)
	{
		for(j=0;j<lengthn;j++)
		{
			printf(" %c %c",card[i],number[j]);
		}
	}
	printf("Enter n : ");
	scanf("%d",&check);
	return ;
}
int main()
{
	
}
