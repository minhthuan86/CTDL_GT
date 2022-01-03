#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<cmath>
#include<conio.h>
using namespace std;
struct Node{
	int Data;
	Node * Next;
};
typedef Node * DS;
Node * Create_Node(int data){
	Node * p;
	p=new Node;
	p->Data=data;
	p->Next=p;
	return p;
}
void AddHead(DS &pHead,int a){
	Node *p=new Node();
	Node *q=pHead;
	p->Data = a;
	p->Next = pHead;
	if (pHead != NULL){  
        while (q->Next != pHead)  
            q = q->Next;  
        q->Next = p;  
    }  
    else
        p->Next = p;
    pHead = p;
}
void AddTail(DS &pHead,int a){
	DS p=Create_Node(a),q;
	if(pHead==NULL) pHead=p;
	else
	{
		//tim phan tu cuoi ds lv vong;
		for(q=pHead;q->Next!=pHead;q=q->Next);
		q->Next=p;
		p->Next=pHead;
	}
}
void In_DS_dowhile(DS pHead){
	DS p=pHead;
	if(pHead==NULL) return;
	do{
		cout<<p->Data<<"\t";
		p=p->Next;
	}while(p!=pHead);
	
}
void Tao_DS(DS &pHead){
	int a;
	char key;
	do{
		cout<<"Nhap a=";cin>>a;
		key = getch();
		if(a!=0)
		if(a%2!=0)
			AddHead(pHead,a);
		else 
			AddTail(pHead,a);
	}while(key!=27);
}
int main(){	
	DS pHead=NULL;
	Tao_DS(pHead);
	cout<<"\nDanh sach : \n";
	In_DS_dowhile(pHead);
 	return 0;
}