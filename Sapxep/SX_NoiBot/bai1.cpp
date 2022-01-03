#include<iostream>
using namespace std;
void xuat(int A[],int n){
	for(int i=0;i<n;i++) cout<<"\t"<<A[i];
}
void noibot(int a[],int n){
	int t;
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if(a[j]<a[j-1]){
				t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;	
			}
	
}
void chontructiep(int a[],int n){
	int min,t=0;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++) 
			if(a[j]<a[min]) min=j;
		swap (a[min],a[i]);
		t++;
		cout<<t<<"\n";
		xuat(a,n);
	}
}
void sapxepchen(int a[],int n){
	int t;
	for (int i=1;i<n;i++){
		t=a[i];
		int j=i-1;
	
		while (j>=0 && a[j]>t){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=t;
	}	
}

int main(){
	int A[]={6, 1 ,3 ,0, 5, 7, 9, 2, 8 ,4},n=10;
	xuat(A,n);
	//noibot(A,n);
	chontructiep(A,n);
	//sapxepchen(A,n);
	cout<<"\nMang sau sap xep: ";
	xuat(A,n);
}
