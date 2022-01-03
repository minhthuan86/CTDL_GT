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
int main(){
	int a[]={1,4,6,2,3,5,7},m=9;
	DS pHead=NULL;
	TaoDS(pHead,a,7);
	InDS(pHead);
	if(TimM(pHead,m)!=NULL) cout<<"co "<<TimM(pHead,m)->data<<" trong DS";
	else cout<<"ko tim thay m";
	return 0;
}
