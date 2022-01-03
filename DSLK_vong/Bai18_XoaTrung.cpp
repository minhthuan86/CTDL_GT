
#include<iostream>
#include<conio.h>
using namespace std;

struct Node{
	int Data;
	Node *Next;
};

typedef Node* DS;

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
		for(q=pHead;q->Next!=pHead;q=q->Next);
		q->Next=p;
		p->Next=pHead;
	}
}

void Tao_DS_Mang(DS &pHead, int A[], int n){
	for(int i = 0; i < n; i++)
		 Chen_Cuoi_Vong(pHead,A[i]);
}
void XoaDau(DS &pHead){
        DS p=pHead,q=pHead;
        for(;p->Next!=pHead;p=p->Next);
        p->Next=pHead->Next;
        pHead=pHead->Next;
        delete q;
}
void XoaConTro(DS pHead,DS &p) {
        DS q=pHead;
        do{
            q=q->Next;
        }while(q->Next!=p);
        q->Next=p->Next;
        delete p;
}
void XoaTatCaM(DS &pHead,int m){
   while(pHead->Data==m){
       XoaDau(pHead);
   }
   DS p=pHead;
   do{
       if(p->Data==m){
        DS k=p;
        p=p->Next;
        XoaConTro(pHead,k);
       }
       else p=p->Next;
   }while(p->Next!=pHead);
}
void XoaTrung(DS &pHead){
	DS k=pHead;
	do{
		XoaTatCaM(k->Next,k->Data);
		k=k->Next;
	}while(k!=pHead);
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
int main()
{
	int n;
	DS pHead = NULL,p;
	int A[]={1,1,2,1,3,1,4,2,5,6,4,1,6,3,5};
	Tao_DS_Mang(pHead, A, 15);
	cout << "Danh sach: ";
	In_DS_dowhile(pHead);
    XoaTrung(pHead);
    cout<<"\nDS sau khi xoa: ";
    In_DS_dowhile(pHead);
	return 0;
}
