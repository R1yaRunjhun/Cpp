#include<iostream>
using namespace std;
//this function work is to find a sub-array to work on(divide untill it is left with only one element)....
int partition(int X[],int low,int up)
{
	int pivot=X[low];		//selection of pivot element of the given array or subarray which is the lowest member of that sub array as a reference to compare with..
	int i=low,j=up+1;		
	do{
		do{
			i++;			//start the comparision from left  side of the array and move forwrad untill the condition in while holds true
		}while(X[i]<pivot&&i<j);
		do{
			j--;			//start the comparision from right  side of the array and move backwrad untill the condition in while holds true
		}while(X[j]>pivot);
		if(i<j)
		{
		int temp=X[i];		// if the value of left side greater than pivot and right side is smaller than pivot element.......swap the both element
		X[i]=X[j];
		X[j]=temp;
		}
	}while (i<j);
	int temp=X[j];		
		X[j]=X[low];
		X[low]=temp;
		return j;			//return the position  where i=j which will be the the dividing criteria of the quick sort 
	
}
//quick sort 
void QuickSortArray(int X[],int low,int up)
{
	if(low<up)
	{
		int w=partition(X,low,up);
		QuickSortArray(X,low,w-1);
		QuickSortArray(X,w+1,up);
		
	}	
}
//printing array
void printarray(int n,int X[])
{
	for(int i=0;i<n;i++)
	{
		cout<<X[i]<<" ";
	}
}
//Binary seach recursive approach
int BinarySearch(int X[],int low,int up,int n)
{

	if(low<=up)
	{
	int mid=low+(up-low)/2;	
	if(X[mid]==n)
		return mid;
	if(n<X[mid])
		return BinarySearch(X,low,mid-1,n);
	else
		return BinarySearch(X,mid+1,up,n);		
	}
	return -1;
}
//merge sort merging approach 
void merge(int X[],int low,int mid,int up)
{
	int l1=low,up1=mid,l2=mid+1,up2=up;
	int Y[up-low+1];			
	int j=0;					
	while(l1<=up1&&l2<=up2)	
	{
		if(X[l1]<=X[l2])
		{
			Y[j]=X[l1];
			l1++;		
		}
		else
		{
		    Y[j]=X[l2];
			l2++;
		}
		j++;
	}
	while(l1<=up1)
	{
		Y[j]=X[l1];
		j++;
		l1++;
	}
	while(l2<=up2)
	{
		Y[j]=X[l2];
		j++;
		l2++;
	}
	int k,r;
	for(k=low,r=0;k<up,r<j;k++,r++)
	{
		X[k]=Y[r];
	}
}
//Merge sort 
void MergeSortArray(int X[],int low,int up)
{
	if(low<up)
	{
		int mid=low+(up-low)/2;	
		MergeSortArray(X,low,mid);
		MergeSortArray(X,mid+1,up);
		merge(X,low,mid,up);
	}	
}

int main()
{
	int n,number;
	cout<<"Enter the size of array";
	cin>>n;
	int SampleArray[n];
	cout<<"Enter every element of array\n";
	for(int i=0;i<n;i++)
	{
		cin>>SampleArray[i];
	}
	cout<<"select the sorting technique\n1.merge sort\n2.quick sort";
	int choice;
	cin>>choice;
	switch(choice)
	{
	case 1:	MergeSortArray(SampleArray,0,n-1);
			cout<<"array after merge sort\n";
			printarray(n,SampleArray);
			break;
	case 2: QuickSortArray(SampleArray,0,n-1);
			cout<<"array after quick sort\n ";
			printarray(n,SampleArray);
			break;
	default: break;
	}
	cout<<"\nthe second smallest number is  "<<SampleArray[1]<<" and second largest is "<<SampleArray[n-2];
	cout<<"\nenter the element to be searched in the array\n";
	cin>>number;
	int s=BinarySearch(SampleArray,0,n-1,number);
	(s==-1)?cout<<"\nthe given number is not present in the array\n":cout<<"the given number is present at  "<<s<<"th index in the array\n";
    return 0; 
	
}
