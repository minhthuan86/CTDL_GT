#include<stdio.h>
int Search(int A[],int X,int n)
{
	for(int i=n-1;i>=0;i--)
	 if(A[i]==X) return i;
	 return -1;
}
int Search1(int A[],int X,int n)
{
	if(n==0) return -1;
	if(A[n-1]==X) return n-1;
	Search1(A,X,n-1);
}
int Search2(int A[],int X,int n,int i=0)
{
	if(i==n) return -1;
	if(A[i]==X) return i;
	Search2(A,X,n,i+1);
}
int main()
{
	int A[]={2,3,3,4,1},n=5,X=1;
	int kq=Search(A,X,n);
	if(kq==-1) printf("Khong tim thay X trong mang");
	else printf("Vi tri xuat hien dau tien cua x trong mang la: %d", kq+1);
	
}

