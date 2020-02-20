#include<stdio.h>
#include<string.h>
int main()
{
	char production[10];
	int prolenX,prolenY,i,count=0;
	printf("enter the production rule\n");
	scanf("%s",production);
	for(i=0;i<strlen(production);i++)
	{
		if(production[i]=='-')
		{
			prolenX= i;
			prolenY=(strlen(production)-i)-2;
			break;
		}
	}
	
	if(prolenX==1)
	{
		for(i=4;i<(strlen(production)-1);i++)
		{
			if(production[i]>=65&&production[i]<=90)
			{
				count++;	
			}
		}
		if(production[0]>=65&&production[0]<=90)
		{
			if(count==0 && production[3]>=65&&production[3]<=90 || production[strlen(production)]>=65&&production[strlen(production)]<=90)
			{
				printf("\nIt is a regular grammer");	
			}
			else 
			{
				printf("\nIt is context free grammer");
			}
		}  
	}
	else if(prolenX<=prolenY)
	{
		printf("\nIt is a context sensitive grammer");
	}
	else if(prolenX>=1)
	{
		printf("\nIt is a recursively enumerable grammar");
	}
}
