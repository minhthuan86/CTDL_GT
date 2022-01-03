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

void InsertTail(DS &pHead,int a){
	Node *p,*q;
	p = Create_Node(a);
	if(pHead==NULL) pHead=p;
	else{
		for(q=pHead;q->Next!=NULL;q=q->Next);
		q->Next=p;
	}
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

void RemoveHead(DS &pHead){
	Node *p;
	p=pHead;
	pHead=pHead->Next;
	delete(p);
}

int main(){
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nSau khi xoa dau : \n";
	RemoveHead(pHead);
	Out_DS(pHead);
 return 0;
}

