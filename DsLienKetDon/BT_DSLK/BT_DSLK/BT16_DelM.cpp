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

bool DelX(DS &pHead,int x){
	DS q,p;
	int Found=0;
		q=pHead;
		while(q!=NULL && !Found)
			if(q->Data!=x)
			{
				p=q;
				q=q->Next;
			}
			else Found=1;
			if(Found)
			{
				if(q==pHead)
					pHead=q->Next;
				else
					p->Next=q->Next;
				delete(q);
			}
}

int main(){
	int M;
	DS pHead;
	Node*p;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nNhap M = ";cin>>M;
	if(DelX(pHead,M)){
		cout<<"\nSau khi xoa x :\n";	
		Out_DS(pHead);
	}else{
		cout<<"\nkhong co "<<M<<" o trong danh sach !!!\n";
		Out_DS(pHead);
	}
 return 0;
}

