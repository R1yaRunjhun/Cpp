#include<stdio.h>
#include<conio.h>
#include<ctype.h>
int main()
{    int i;
char a[100];
	scanf("%s",a);
	while(a[i]=='\0')
	{
		if(islower(a[i])) 
		a[i] = toupper(a[i]);
        else
        a[i]= tolower(a[i]);
        printf("%s",a[i]);
	}
	
	return 0;
}
