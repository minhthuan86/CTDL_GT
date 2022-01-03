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

Node*find_K(Node*pHead,int K){
	for(Node*p =pHead;p!=NULL;p=p->Next)
	if(p->Data==K)
	return p;
	return NULL;
}

void chen(DS &pHead,int K,int M){
	Node*p=find_K(pHead,K);
	if(p==NULL) InsertTail(pHead,M);
	else{
		Node*newNode = Create_Node(M);
		newNode->Next = p->Next;
		p->Next=newNode;
	}
}

int main(){
	int k,m;
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	cout<<"\nDanh sach truoc khi chen :\n";
	Out_DS(pHead);
	cout<<"\nNhap K = ";
	cin>>k;
	cout<<"\nNhap M = ";
	cin>>m;
	cout<<"\nDanh sach sau khi chen :\n";
	chen(pHead,k,m);
	Out_DS(pHead);
 return 0;
}

