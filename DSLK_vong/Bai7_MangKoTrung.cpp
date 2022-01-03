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
int CheckTonTai(DS pHead,int a){
    DS p=pHead;
	if(pHead==NULL) return 1;
	do{
		if(p->Data==a) return 0;
		p=p->Next;
	}while(p!=pHead);
    return 1;	
}
void Tao_DS(DS &pHead,int A[],int n)
{
   for(int i=0;i<n;i++) {
       if(CheckTonTai(pHead,A[i])==1) {
            if(A[i]%2==0) Chen_Dau_Vong(pHead,A[i]);
            else Chen_Cuoi_Vong(pHead,A[i]);
       }
   }
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
int main(){
    int A[]={1,2,3,4,3,5,6,7,7};
    DS pHead;
	pHead=NULL;
	Tao_DS(pHead,A,9);
	In_DS(pHead);
}
