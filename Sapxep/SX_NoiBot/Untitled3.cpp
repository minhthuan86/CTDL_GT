#include<iostream>
#include<stdio.h>
using namespace std;
int a[100][100];
int b[100][100];
void in (int a[100][100],int &dong, int &cot){
	do{
		printf("Nhap so dong: ");
		scanf("%d",&dong);
		printf("Nhap so cot: ");
		scanf("%d",&cot);
	}while(dong>100||cot>100&&cot<0||dong<0);
	for(int i=0;i<dong;i++){
		for(int j=0;j<cot;j++){
			printf("Nhap array[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void out(int a[100][100],int dong, int cot){
	printf ("Ma tran vua nhap la: \n");
	for(int i=0;i<dong;i++){
		printf ("\n");
		for(int j=0;j<cot;j++){
			printf("%d\t ",a[i][j]);
		}
	}
}
int chuyenvi(int a[100][100], int &dong, int &cot,int b[100][100]){
	
	
	for(int i= 0; i < cot;i++){
		for(int j = 0; j < dong; j++){
			b[i][j]= a[j][i];
		}
	}
	
}
void sapxepchen(int a[][100],int n,int m){
	for(int i=1;i<n;i++){
		int m=a[i][i];
		int j=i;
		while(j>0&&a[j-1][j-1]<m){
			a[j][j] = a[j-1][j-1];
			j--;
		}
		a[j][j] =m;
	}
	}
	
int main (){
	int dong,cot, a[100][100],b[100][100];
	in(a,dong,cot);
	out(a,dong,cot);
	/*chuyenvi(a,dong,cot,b);
	cout <<"\nmang sau chuyen vi la: \n";
	out(b,cot,dong);*/
	sapxepchen(a,dong,cot);
	out(a,dong,cot);
	return 0;
}

