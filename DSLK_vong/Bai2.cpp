#include<iostream>
using namespace std;
struct Node
{
	int Data;
	Node *Next;
};
typedef Node * DS;
Node * Tao_Nut(int a)
{
	Node * p;
	p=new Node;
	p->Data=a;
	p->Next=p;
	return p;
}
void Chen_Dau_Vong(DS &pHead,int a)
{
	DS p=Tao_Nut(a),q;
	if(pHead==NULL) pHead=p;
	else
	{
		//tim phan tu cuoi ds lv vong;
		for(q=pHead;q->Next!=pHead;q=q->Next);
		//Noi nut moi vao ds
		q->Next=p;
		p->Next=pHead;
		pHead=p;
	}
}

void Tao_DS(DS &pHead,int A[],int n)
{
	for(int i=0;i<n;i++) Chen_Dau_Vong(pHead,A[i]);
}
void In_DS(DS pHead)
{
	DS p=pHead;
	if(pHead==NULL) return;
	do{
		cout<<p->Data<<"\t";
		p=p->Next;
	}while(p!=pHead);
	
}
int tong(DS pHead){
	int tong=0;
	DS p=pHead;
	do{
		if(p->Data%2==0) tong+=p->Data;
		p=p->Next;
	}while(p!=pHead);
	return tong;
}

int main(){
    int A[]={1,2,3,4,5,6,7,8};
    DS pHead;
	pHead=NULL;
	Tao_DS(pHead,A,8);
	//Tao_Vong(pHead);
	In_DS(pHead);
	cout<<"\ntong chan: "<<tong(pHead);
}