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

int timkiem(DS &pHead,int m){
	for(Node *p=pHead;p!=NULL;p=p->Next)
	if(p->Data==m) return 1;
	return 0;
}

int main(){
	int m;
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nNhap m = ";
	cin>>m;
	if(timkiem(pHead,m)==1)
        cout<<"\nCo gia tri "<<m<<" trong danh sach. ";
    else
	    cout<<"\nkhong co gia tri "<<m<<" trong danh sach !";
 return 0;
}

