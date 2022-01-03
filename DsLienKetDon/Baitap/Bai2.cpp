#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * Next;
};
typedef Node *DS;
Node *TaoNode(int x){
	Node *p;
	p=new Node;
	p->data=x;
	p->Next=NULL;
	return p;
}
void ChenDau(DS &pHead,int x){
	Node *p;
	p=TaoNode(x);
	p->Next=pHead;
	pHead=p;
}
void TaoDS(DS &pHead){
	int a;
	do{
		cout<<"nhap a: ";cin>>a;
		if(a!=0) ChenDau(pHead,a);
	}while(a!=0);
}
void Tong_Chan(DS pHead){
	int sum=0;
	Node *p;
	for(p=pHead;p!=NULL;p=p->Next)
		if(p->data%2==0) sum+=p->data;
	cout<<"\nTong chan: "<<sum;
}
int main(){
	DS pHead;
	pHead = NULL;
	TaoDS(pHead);
	Tong_Chan(pHead);
	return 0;
}
