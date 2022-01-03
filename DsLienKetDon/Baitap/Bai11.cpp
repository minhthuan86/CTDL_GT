#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};
typedef Node *DS;
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
Node ChenCuoi(DS &pHead,int x){
	Node *p,*q;
	p=TaoNode(x);
	if(pHead==NULL) pHead=p;
	else{
		for(q=pHead;q->next!=NULL;q=q->next);
		q->next=p;
	}
}
void TaoDS(DS &pHead,int A[],int n){
	for(int i=0;i<n;i++) ChenDau(pHead,A[i]);//in nguoc danh sach
}
void InDS(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->next)
		cout<<p->data<<"\t";
	cout<<"\n";
}
Node *TimM(DS pHead,int m){
	Node *p;
	for(p=pHead;p!=NULL;p=p->next)
	if(p->data==m) return p;
	return NULL;
}
void ChenSauK(DS &pHead,int k,int m){
	Node *p,*q;
	p=TimM(pHead,k);
	if(p==NULL) ChenCuoi(pHead,m);
	else {
		q=TaoNode(m);
		q->next=p->next;
		p->next=q;
	}
}
int main(){
	int a[]={1,4,6,2,3,5,7},m=9,k=2;
	DS pHead=NULL;
	TaoDS(pHead,a,7);
	InDS(pHead);
	ChenSauK(pHead,k,m);
	InDS(pHead);
	return 0;
}
