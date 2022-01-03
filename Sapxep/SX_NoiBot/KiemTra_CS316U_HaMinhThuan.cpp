#include<iostream>
using namespace std;
int a[50][50],m,n;
void nhap(int a[50][50], int &m, int &n)
{
	do{
	
   cout<<"nhap so hang m: ";cin>>m;
   cout<<"nhap so cot n: ";cin>>n;
   }while(m>50||n>50||m<1||n<1);
   for(int i = 0; i < m; i++)
      for(int j = 0; j < n; j++)
      {
         cout<<"A["<<i<<"]["<<j<<"]= ";cin>>a[i][j];
      }
}
void xuat(int a[50][50],int m,int n){
	for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++)
         cout<<a[i][j]<<" ";
      cout<<"\n";
   }
}
void chuyenvi(int a[50][50],int m,int n){
	cout<<"ma tran chuyen vi: "<<"\n";
	for(int j = 0; j < n; j++){
      for(int i = 0; i < m; i++)
         cout<<a[i][j]<<" ";
      cout<<"\n";
   }
}
void chontructiep(int a[50][50],int n,int t){
	int min=0;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++) 
			if(a[j][t]<a[min][t]) min=j;
		swap (a[min][t],a[i][t]);
	}
}
void sapxep(int a[50][50],int m,int n){
	cout<<"ma tra sau khi sap xep: "<<"\n";
	for(int i=0;i<n;i++){
		chontructiep(a,m,i);
	}
	xuat(a,m,n);
}
int max(int a[50][50],int n,int t){
	int max=a[0][t];
	for(int i=0;i<n;i++){
		if(max<a[i][t]) max = a[i][t];
	}
	return max;
}
void phantuMax(int a[50][50],int m,int n){
	cout<<"lon nhat moi cot: ";
	for(int i=0;i<n;i++){
		cout<<"\nmax cot "<<i<<"= "<<max(a,m,i);
	}
	cout<<"\n";
}
void chen(int A[50][50], int n){
	for(int i=1;i<n;i++){
		int m=A[i][i];
		int j=i;
		while(j>0 && A[j-1][j-1]<m){
			A[j][j]=A[j-1][j-1];
			j--;
		}
		A[j][j]=m;
	}
}
void xep_hangcheo(int a[50][50],int m,int n){
	if(m!=n) cout<<"Luu y!!!! : m khac n, moi nhap lai\n";
	else{
		chen(a,m);
		xuat(a,m,n);
	}
}
int main(){
	int select;
	cout<<"********** WELLCOME **********\n";
	do{		
		cout<<"1. Nhap ma tran \n";
		cout<<"2. In ma tran \n";
		cout<<"3. In ra ma tran chuyen vi cua A \n";
		cout<<"4. Sap xep ma tran theo thu tu tang dan tren moi cot \n";
		cout<<"5. In ra phan tu lon nhat tren moi cot \n";
		cout<<"6. Sap xep cac phan tu tren duong cheo chinh theo thu tu giam dan \n";
		cout<<"7. Ket thuc\n";
		cout<<"Ban chon cong viec thuc hien: ";
		cin>>select;
		switch(select)
		{
			case 1 : nhap(a,m,n); break;
			case 2 : xuat(a,m,n);break;
			case 3 : chuyenvi(a,m,n);break;
			case 4 : sapxep(a,m,n);break;	
			case 5 : phantuMax(a,m,n);break;
			case 6 : xep_hangcheo(a,m,n);break;
			case 7 : { cout<<"!!! Cam on da su dung !!!";
						return 0;	}		
		}
	}while(select!=0);
}
