#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};
typedef Node *DS;
Node *TaoNode(int  a){
    Node *p=new Node;
    p->data=a;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void ChenDau(DS &pHead,DS &pTail, int a){
    DS p=TaoNode(a);
    if(pHead==NULL){
        pHead=pTail=p;
    }
    else{
        p->next=pHead;
        pHead->prev=p;
        pHead=p;
    }
}
void ChenCuoi(DS &pHead,DS &pTail, int a){
    DS p=TaoNode(a);
    if(pHead==NULL){
        pHead=pTail=p;
    }
    else{
        p->prev=pTail;
        pTail->next=p;
        pTail=p;
    }
}
void TaoDS(DS &pHead,DS &pTail){
    int a;
    do{
        cout<<"nhap a= ";cin>>a;
        if(a!=0) ChenCuoi(pHead,pTail,a);
    }while(a!=0);
}
void InDS(DS pHead,DS pTail){
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data<<" ";
}
Node *TimK(DS pHead,int M) {
    for(;pHead!=NULL;pHead=pHead->next)
    if(pHead->data>M) return pHead;
    return NULL;
}
void ChenM(DS &pHead,DS &pTail) {
    int M;
    cout<<"nhap gt can chen: ";cin>>M;
    DS p=TimK(pHead,M);
    if(p==NULL) {ChenCuoi(pHead,pTail,M); return;}
    if(p==pHead) {ChenDau(pHead,pTail,M); return;}
    DS q=TaoNode(M);
    q->prev=p->prev;
    p->prev->next=q;
    q->next=p;
    p->prev=q;
}
int main(){
    DS pTail,pHead;
    pHead=pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    ChenM(pHead,pTail);
     cout<<"\nSau khi chen: ";
    InDS(pHead,pTail);
}