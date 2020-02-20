#include<stdio.h>
#include<string.h>

void leftrecursion(char production[])
{
	int i=4,j=0,k=0;
	char alpha[10],beta[10];
	if(production[0]!=production[3])
	{
		printf("This production is not left recursive");
	}	
	else
	{
		printf("This production is left recursive");
		printf("\nAfter elemination of left recursion\n");
		while(production[i]!='/')
		{
			alpha[j]=production[i];
			j++;i++;
		}
	
		i=i+1;
		while(production[i]!='\0')
		{
			beta[k]=production[i];
			k++,i++;
		}
		printf("%c->",production[0]);
		printf("%s",beta);
		printf("%c'",production[0]);
		printf("\n%c'->",production[0]);
		printf("%s",alpha);
		printf("%c'/lambda",production[0]);
		
		
	}
}

int main()
{
	char production[10];
	printf("Enter the production rule\n");
	scanf("%s",production);
	leftrecursion(production);
}
