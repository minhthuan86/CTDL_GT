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
int TongMax(DS pHead){
    int max=0;
	DS p=pHead;
	do{
		if((p->Data+p->Next->Data)>max) max=p->Data+p->Next->Data;
		p=p->Next;
	}while(p->Next!=pHead);
	return max;
}
int main(){
    int A[]={1,2,3,4,5,8,7,7};
    DS pHead;
	pHead=NULL;
	Tao_DS(pHead,A,8);
	In_DS(pHead);
    cout<<"tong max: "<<TongMax(pHead);
}