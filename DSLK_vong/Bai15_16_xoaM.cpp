
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
Node *Tim(DS pHead,int m){
    	DS p=pHead;
	do{
		if(p->Data==m) return p;
		p=p->Next;
	}while(p!=pHead);
    return NULL;
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
void XoaM(DS &pHead,int m){
    DS p=Tim(pHead,m),q;
    if(p==NULL) cout<<"Ko co M";
    else if(p==pHead)  XoaDau(pHead);
    else XoaConTro(pHead,p);    
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
	int A[10]={1,5,7,2,6,8,9,3,4,10};
	Tao_DS_Mang(pHead, A, 10);
	cout << "Danh sach: ";
	In_DS_dowhile(pHead);
    XoaM(pHead,6);
    cout<<"\nDS sau khi xoa: ";
    In_DS_dowhile(pHead);
	return 0;
}
