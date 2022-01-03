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

double TBC(DS &pHead){
   	int count=0,sum=0;
	while(pHead != NULL){
		sum+=pHead->Data;
		count++;
		pHead=pHead->Next;
	}
	if(count != 0)return double(sum)/count;
	else return 0.0;
}

int main()
{
	DS pHead;
	pHead=NULL;
	In_DS(pHead);
	Out_DS(pHead);
	cout<<"\nTrung binh cong trong DS : \n"<<TBC(pHead);
 return 0;
}

