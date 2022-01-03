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
void Chen_Dau(DS &pHead,int a)
{
	DS p=Tao_Nut(a);
	p->Next=pHead;
	pHead=p;
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
int daonguoc(int n,int r=0){
	if(n==0) return r;
	return daonguoc(n/10,r*10+n%10);
}
void IN_DX(DS pHead){
    DS p=pHead;
	if(pHead==NULL) return;
	do{
		if(p->Data==daonguoc(p->Data)) cout<<p->Data<<"\t";
		p=p->Next;
	}while(p!=pHead);
}
int main(){
    int A[]={11,22,31,141,505,61,57,8};
    DS pHead;
	pHead=NULL;
	Tao_DS(pHead,A,8);
	//Tao_Vong(pHead);
	In_DS(pHead);
    cout<<"\n so doi xung la: ";
    IN_DX(pHead);
}