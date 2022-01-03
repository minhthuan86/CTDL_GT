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

void RemoveHead(DS &pHead){
	Node *p;
	p=pHead;
	pHead=pHead->Next;
	delete(p);
}

void xoaConTro(DS &pHead, Node *p){
    if(p == NULL) return;
    if(p == pHead)
        RemoveHead(pHead);
    else{
        Node *q;
        for(q = pHead; q ->Next != p; q = q->Next);
        q->Next = p->Next;
        delete(p);
    }
}

void XoaLe(DS &pHead){
	Node *p,*q;
	p=pHead;
	while(p!=NULL){
	if(p->Data%2!=0){
	    q=p;
		p=p->Next;
	 	xoaConTro(pHead,q);
	}else{
		p=p->Next;
	}
	}
}

int main(){
	DS pHead;
	Node*p;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nDS sau khi xoa phan tu le : \n";
	XoaLe(pHead);
	Out_DS(pHead);
 return 0;
}

