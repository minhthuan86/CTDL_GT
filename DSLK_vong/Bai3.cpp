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
void Chen_Cuoi_Vong(DS &pHead,int a)
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
	}
}

void Tao_DS(DS &pHead,int A[],int n)
{
	for(int i=0;i<n;i++) Chen_Cuoi_Vong(pHead,A[i]);
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
int KTSNT(int n){
	if(n<2) return 0;
	if(n==2 || n==3) return 1;
	for(int i=2;i<=n/2;i++)
		if(n%i==0) return 0;
	return 1;
}
void TaoDS_NT(DS pHead,DS &pHead_NT){
	DS p=pHead;
	do{
		if(KTSNT(p->Data)==1) 
			Chen_Cuoi_Vong(pHead_NT,p->Data);
		p=p->Next;
	}while(p!=pHead);
	
}

int main(){
    int A[]={1,2,3,4,5,6,7,8};
    DS pHead,pHead_NT;
	pHead=NULL,pHead_NT=NULL;
	Tao_DS(pHead,A,8);
	//Tao_Vong(pHead);
	In_DS(pHead);
    TaoDS_NT(pHead,pHead_NT);
	cout<<"\nDSNT: ";
    In_DS(pHead_NT);
}
