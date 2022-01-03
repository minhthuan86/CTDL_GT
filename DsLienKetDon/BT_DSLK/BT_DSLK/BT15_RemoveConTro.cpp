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

Node *search_K(DS pHead, int k){
    for(Node *p = pHead; p != NULL; p = p->Next)
        if(p->Data == k)
            return p;
    return NULL;
}

void xoaConTro(DS &pHead, Node *p, int M){
    p = search_K(pHead, M);
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

int main(){
	int M;
	DS pHead;
	Node*p;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nNhap con tro can xoa M = ";
	cin>>M;
	cout<<"\nSau khi xoa con tro : \n";
	xoaConTro(pHead,p,M);
	Out_DS(pHead);
 return 0;
}

