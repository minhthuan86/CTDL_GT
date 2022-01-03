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
	else
	{
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

Node *find_ViTri(Node *pHead, int M){
    Node *q = NULL;
    for (Node *p = pHead; p != NULL; p = p->Next)
        if (p->Data >= M)
            return q;
        else q = p;
    return NULL;
}

void chen(DS &pHead, int M){
    Node *q = find_ViTri(pHead, M);
    if (q == NULL){
        if(pHead->Data >= M)
            InsertHead(pHead, M);
        else InsertTail(pHead, M);
    }
    else{
        Node *newNode = Create_Node(M);
        newNode->Next = q->Next;
        q->Next = newNode;
    }
}

int main()
{
	int M;
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	cout<<"\nDanh sach truoc khi chen :\n";
	Out_DS(pHead);
	cout<<"\nNhap gia tri M can chen : ";
	cin>>M;
	cout<<"\nDanh sach sau khi chen :\n";
	chen(pHead,M);
	Sort(pHead);
	Out_DS(pHead);
 return 0;
}

