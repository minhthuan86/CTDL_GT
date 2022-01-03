#include<iostream>
#include<math.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
typedef Node*DS;
Node *TaoNode(int x){
	Node *p;
	p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
}
Node ChenDau(DS &pHead,int x){
	Node *p;
	p=TaoNode(x);
	p->next=pHead;
	pHead=p;
}
Node ChenCuoi(DS &pHead,int x){
	Node *p,*q;
	p=TaoNode(x);
	if(pHead==NULL) pHead=p;
	else{
		for(q=pHead;q->next!=NULL;q=q->next);
		q->next=p;
	}
}
int CheckNT(int x){
	if(x<2) return 0;
	if(x==2||x==3) return 1;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
void TaoDS(DS &pHead){
	int a;
	do{
		cout<<"Nhap a: ";cin>>a;
		if(a!=0)
			if(CheckNT(a)) ChenDau(pHead,a);
			else ChenCuoi(pHead,a);
	}while (a!=0);
}
void InDS(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->next)
		cout<<p->data<<"\t";
}
int main(){
	DS pHead;
	pHead=NULL;
	TaoDS(pHead);
	InDS(pHead);
	return 0;
}
