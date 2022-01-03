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
    cout<<"\n";
}
void XoaDau(DS &pHead){
    DS p;
	p=pHead;
	pHead=pHead->next;
	delete(p);
}
Node *search_K(DS pHead, int k){
    for(Node *p = pHead; p != NULL; p = p->next)
        if(p->data == k)
            return p;
    return NULL;
}

void xoaConTro(DS &pHead, Node *p, int M){
    p = search_K(pHead, M);
    if(p == NULL) return;
    if(p == pHead)
        XoaDau(pHead);
    else{
        Node *q;
        for(q = pHead; q ->next != p; q = q->next);
        q->next = p->next;
        delete(p);
    }
}
int main(){
    int M;
    DS pHead=NULL;
    TaoDS(pHead);
    InDS(pHead);
    cout<<"\nNhap gia tri can xoa M = ";
	cin>>M;
	cout<<"\nSau khi xoa con tro : \n";
	xoaConTro(pHead,pHead,M);
    InDS(pHead);
}