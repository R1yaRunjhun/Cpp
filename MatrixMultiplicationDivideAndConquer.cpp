#include<iostream>
using namespace std;
void MatrixMultiplication(int n,int m, int *arr1)
{
	if(x!=1&&y!=1)
	{
		int n=n/2;
		MatrixMultiplication(n/2,n/(int*)arr1);
}
void printarray(int n,int *X)
{
	for(int j=0;j<n;j++)
		{
			for(int k=0;k<m;k++)
			{
			  	cout<<*((X+j*m)+k)<<"\t";	
			}
			cout<<endl;
		}
}
int main()
{
	int size;
	cout<<"Enter the size of square matrix"<<endl;
	cin>>size;
	int i;
	for(i=size;i>=1;i/=2)
	{
		
		int z =i%2;
		if(z&&i)
		break;
	}	
	if( i!=1)
	{
		cout<<"enter the right size i.e. in the form of exponential of 2";
		main();
	}
	else
	{
		int arr[size][size],arr1[size][size];
		cout<<"Enter the elements of array"<<endl;
		for(int j=0;j<size;j++)
		{
			for(int k=0;k<size;k++)
			{
			  	cin>>arr[j][k];	
			}
	
		}
		for(int j=0;j<size;j++)
		{
			for(int k=0;k<size;k++)
			{
			  	cin>>arr1[j][k];	
			}
	
		}
		cout<<"\nfirst matrix\n";
		printarray(size,(int*)arr);
		cout<<"\nsecond matrix\n";
		printarray(size,(int*)arr1);
		MatrixMultiplication(size,(int*)arr1);
		
	}
	return 0;
}
