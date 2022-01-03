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

int KTSNT(int n){
	if(n<2) return 0;
	if(n==2 || n==3) return 1;
	for(int i=2;i<=n/2;i++)
		if(n%i==0) return 0;
	return 1;
}

void InSNT(DS &pHead){
	DS p=pHead;
	if(p==NULL) return;
	while(p!=NULL){
		if(KTSNT(p->Data))
			cout<<p->Data<<" ";
		p=p->Next;
	}
}

int main()
{
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nSo nguyen to trong DS : \n";
	InSNT(pHead);
 return 0;
}

