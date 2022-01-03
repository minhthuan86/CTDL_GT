#include<iostream>
using namespace std;
int xuat(int a[],int n){
	cout<<"xuat mang: ";
	for(int i=0;i<n;i++) cout<<a[i]<<"\t";
	cout<<"\n";
}
void chen(int a[],int &n,int x,int k){
	n++;
	for(int i=n-1;i>=k-1;i--) a[i]=a[i-1];
	a[k-1]=x;
}
void xoa(int a[],int &n,int k)
{
    for(int i=k;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    --n;
}
void xoaX(int a[],int &n,int x)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        {
            xoa(a,n,i);
            i--;
        }
    }
}
void chensauX(int a[],int &n,int x,int m){
	int i,j,t=0;
	for(i=0;i<n;i++){
		if(a[i]==x){
			for(j=n;j>i;j--) a[j]=a[j-1];
			a[j+1]=m;
			t++;
			n++;
		}
	}
	if(t==0) {
		n++;
		a[n-1]=x;
	} 
}
int main(){
	int a[]={1,2,4,7,4},n=5,x=4,m=5;
	xuat(a,n);
	//chen(a,n,x,k);
	//xoaX(a,n,2);
	chensauX(a,n,x,m);
	cout<<"sau khi chen:"<<"\n";
	xuat(a,n);
}
