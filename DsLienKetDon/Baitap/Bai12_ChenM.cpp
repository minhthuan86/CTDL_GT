#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef Node * DS;
Node *TaoNode(int x){
    Node *p=new Node;
    p->data=x;
    p->next=NULL;
    return p;
}
void ChenDau(DS &pHead,int x){
	Node *p;
	p=TaoNode(x);
	p->next=pHead;
	pHead=p;
}
void ChenCuoi(DS &pHead, int x){
    DS p,q;
    p=TaoNode(x);
    if(pHead==NULL) pHead=p;
    else{
        for(q=pHead;q->next!=NULL;q=q->next);
        q->next=p;
    }
}
void TaoDS(DS &pHead){
    int a;
    do{
        cout<<"Nhap a: ";cin>>a;
        if(a!=0) ChenCuoi(pHead,a);
    }while(a!=0);
}
void InDS(DS pHead){
    DS p;
    for(p=pHead;p!=NULL;p=p->next) cout<<p->data<<"\t";
}
Node *find_ViTri(Node *pHead, int M){
    Node *p;
	for(p=pHead;p!=NULL;p=p->next)
	if(p->data>=M) return p;
	return NULL;
}
void chen(DS &pHead, int M){
    if (pHead == NULL) {
        ChenDau(pHead, M);
        return;
    }
    Node *q = find_ViTri(pHead, M);
    if (q == NULL){
        if(pHead->data >= M)
            ChenDau(pHead, M);
        else ChenCuoi(pHead, M);
    }
    else{
        Node *newNode = TaoNode(M);
        newNode->next = q->next;
        q->next = newNode;
    }
}

int main()
{
	int M;
	DS pHead=NULL;
	TaoDS(pHead);
	cout<<"\nDanh sach truoc khi chen :\n";
	InDS(pHead);
	cout<<"\nNhap gia tri M can chen : ";
	cin>>M;
	cout<<"\nDanh sach sau khi chen :\n";
	chen(pHead,M);
	InDS(pHead);
 return 0;
}