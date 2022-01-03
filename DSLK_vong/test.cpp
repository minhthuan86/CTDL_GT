#include<iostream>
#include<conio.h>
#define Max 10
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

 void chen_dau(DS &pHead, int data) {
     if (pHead == NULL) {
         pHead = Tao_Nut(data);
       pHead->Next = pHead;
    } else {
       DS q = pHead->Next;
        while (q->Next != pHead)
           q = q->Next;
         DS newNode = Tao_Nut(data);
       newNode->Next = pHead;
        pHead = newNode;
       q->Next = pHead;
     }
 }
// void chen_dau(DS &pHead,int a)
// {
// 	DS p=Tao_Nut(a),q;
// 	if(pHead==NULL) pHead=p;
// 	else
// 	{
// 		for(q=pHead;q->Next!=pHead;q=q->Next);
// 		q->Next=p;
// 		p->Next=pHead;
//         pHead=p;
// 	}
// }

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
	for(int i = 0; i < n; i++){
		cout<<"A["<<i+1<<"] = ";cin>>A[i];
		 Chen_Cuoi_Vong(pHead,A[i]);
	}	
}

DS Tim_K(DS pHead, int M) {
    if (pHead != NULL) {
        DS p = pHead;
        do {
            if (p->Data > M) return p;
            p = p->Next;
        } while (p != pHead);
    }
    return NULL;
}

void ChenM(DS &pHead,int M){
	if(pHead==NULL) {
		DS p=Tao_Nut(M);
		pHead=p;
		return;
	}
   DS p=Tim_K(pHead,M);
   if(p==NULL) Chen_Cuoi_Vong(pHead,M);
   else if(p==pHead) chen_dau(pHead,M);
	   else{
	       DS q=pHead;
	       do {
	           if(q->Next==p){
	               DS NewNode = Tao_Nut(M);
	               q->Next=NewNode;
	               NewNode->Next=p;
	               return;
	           }
	           q=q->Next;
	       }while(q!=pHead);
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
	int n,M;
	DS pHead = NULL;
	int A[10];
	cout <<" Nhap n: ";cin>>n;
	Tao_DS_Mang(pHead, A, n);
	cout << " Danh sach: ";
	In_DS_dowhile(pHead);
	cout << "\n Nhap gia tri can chen: ";cin >> M;
    ChenM(pHead, M);
    cout << " Danh sach sau khi chen: ";
	In_DS_dowhile(pHead);
	return 0;
}