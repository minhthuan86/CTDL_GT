
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
void ChenTruocK(DS pHead,int K,int M){
   DS p=Tim(pHead,K);
    if(p == NULL) Chen_Cuoi_Vong(pHead,M);
    else{
        DS q=Tao_Nut(M);
        q->Next=p->Next;
        p->Next=q;
    }
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
	DS pHead = NULL;
	int A[10]={1,5,7,2,6,8,9,3,4,10};
	Tao_DS_Mang(pHead, A, 10);
	cout << " Danh sach: ";
	In_DS_dowhile(pHead);
	ChenTruocK(pHead,2,8);
	cout <<"\n Danh sach sau khi chen: ";
	In_DS_dowhile(pHead);
	return 0;
}
