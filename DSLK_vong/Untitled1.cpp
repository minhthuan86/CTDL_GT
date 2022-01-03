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

void Tao_Vong(DS &pHead)
{
	DS p;
	if(pHead==NULL||pHead->Next==pHead) return;
	for(p=pHead;p->Next!=NULL;p=p->Next);
	p->Next=pHead;
	
}
void In_DS(DS pHead)
{
	DS p;
	for(p=pHead;p->Next!=pHead;p=p->Next)
	 cout<<p->Data<<"\t";
	 cout<<p->Data<<"\t";
}
void In_DS_dowhile(DS pHead)
{
	DS p=pHead;
	if(pHead==NULL) return;
	do{
		cout<<p->Data<<"\t";
		p=p->Next;
	}while(p!=pHead);
	
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
		//pHead=p;
	}
}

void Tao_DS(DS &pHead)
{
	int a;
	do{
		cout<<"Nhap a=";cin>>a;
		if(a!=0)
		Chen_Cuoi_Vong(pHead,a);
	}while(a!=0);
}
void xoadau_vong(DS &pHead){
	DS q,p;
	if(pHead==NULL) return;
	if(pHead->Next==pHead) {
	p=pHead;pHead=NULL;
	delete(p);
	return;
	}
	for(q=pHead;q->Next!=pHead;q=q->Next);
	q->Next=pHead->Next;
	p=pHead;
	pHead=pHead->Next;
	delete(p);
}
void xoacuoi_vong(DS &pHead){
	if(pHead==NULL) return;
	if(pHead->Next==pHead) {pHead=NULL;return;}
	DS q,p;
	for(q=pHead;q->Next!=pHead;q=q->Next) p=q;
	//for(p=pHead;p->Next!=q;p=p->Next);
	p->Next=pHead;
	delete(q);
}
int main(){
	DS pHead;
	pHead=NULL;
	Tao_DS(pHead);
	//Tao_Vong(pHead);
	In_DS_dowhile(pHead);
	xoacuoi_vong(pHead);
	cout<<"\n";
	In_DS_dowhile(pHead);
	
}

