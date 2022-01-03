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

bool KiemTra(DS &pHead){
		if((pHead==NULL) || (pHead->Next==NULL)) return true;
		else{
			DS q=pHead, p=pHead->Next;
		while(p != NULL){
		if(q->Data > p->Data) return false;
			q=p;
			p=p->Next;
		}
		return true;
	}
}

int main()
{
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	if(KiemTra(pHead)==true) cout<<"\nTang"<<endl;
    else cout<<"\nkhong tang"<<endl;
 return 0;
}

