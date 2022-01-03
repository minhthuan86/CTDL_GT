#include<iostream>
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
void ChenDau(DS &pHead,int x){
	Node *p;
	p=TaoNode(x);
	p->next=pHead;
	pHead=p;
}
void ChenCuoi(DS &pHead,int x){
	Node *p,*q;
	p=TaoNode(x);
	if(pHead==NULL) pHead=p;
	else{
		for(q=pHead;q->next!=NULL;q=q->next);
		q->next=p;
	}
}
void TaoDS(DS &pHead){
	int a;
	do{
		cout<<"Nhap a: ";cin>>a;
		if(a!=0)
			if(a%2!=0) ChenDau(pHead,a);
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

