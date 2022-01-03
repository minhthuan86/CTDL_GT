#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int c=a;a=b;b=c;
}
int Bubble_sort(int A[],int n)
{
	for(int i=0; i<n-1;i++)
	  for(int j=n-1;j>i;j--)
	    if(A[j]<A[j-1])swap(A[j],A[j-1]);
}
int SelectionSort(int a[],int n){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++)
			if(a[min]>a[j]) min=j;
		swap(a[min],a[i]);
	}
}
void Print(int A[],int n)
{
	for(int i=0;i<n;i++)
	 cout<<A[i]<<"\t";
}
int main()
{
	int A[]={1, 5 ,2, 6 ,8,2 ,9},n=7;
	Print(A,n);
	//Bubble_sort(A,n);
	SelectionSort(A,n);
	cout<<"Mang da sap xep\n";
	Print(A,n);
}

