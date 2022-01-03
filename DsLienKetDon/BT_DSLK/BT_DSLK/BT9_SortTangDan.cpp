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

void Sort(DS &pHead){
	DS P,Q;
	int Temp;
	for(P=pHead;P->Next!=NULL;P=P->Next)
	 	for(Q=P->Next;Q!=NULL;Q=Q->Next)
			if(P->Data>Q->Data){
				Temp = P->Data;
				P->Data=Q->Data;
				Q->Data=Temp;
			}
}

int main()
{
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	cout<<"\nDSLK khi chua xep :\n";
	Out_DS(pHead);
	cout<<"\nDSLK khi da xep :\n";
	Sort(pHead);
	Out_DS(pHead);
 return 0;
}

