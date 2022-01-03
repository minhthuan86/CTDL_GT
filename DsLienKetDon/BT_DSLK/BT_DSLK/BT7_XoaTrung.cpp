#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<cmath>
using namespace std;

struct Node{
	int Data;
	Node * Next;
};

typedef Node * DS;

Node *Create_Node(int data){
	Node *p;
	p=new Node;
	p->Data=data;
	p->Next=NULL;
	return p;
}

void InsertHead(DS &pHead,int x){
	Node *p;
	p=Create_Node(x);
	p->Next=pHead;
	pHead=p;
}

void In_DS(DS &pHead){
	int a;
	do{
		cout<<"Nhap a = ";cin>>a;
	  if(a!=0) InsertHead(pHead,a);
	}while(a!=0);
}

void Out_DS(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->Next)
	 	cout<<p->Data<<"\t";
}

bool Ktra_Lap(DS &pHead, int a){
    for(DS p=pHead;p!=NULL;p=p->Next){
        if(p->Data==a){
            return true;
        }
    }
    return false;
}
void lay(DS &pHead,int A[],int n){
    for(int i=0;i<n;i++){
        if(Ktra_Lap(pHead,A[i])==false)
        InsertHead(pHead,A[i]);
    }
}

int main()
{
	int A[] = {1,2,3,3,5,6,7},n=3;
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nDanh sach da loai phan tu trung la :\n";
	lay(pHead,A,n);
	Out_DS(pHead);
 return 0;
}

