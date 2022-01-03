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
void TaoDSTuMang(DS &pHead,DS &pTail,int A[],int n){
    for(int i=0;i<n;i++){
        ChenCuoi(pHead,pTail,A[i]);
    }
}
void InDS(DS pHead,DS pTail){
    cout<<"In thuan:";
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data<<" ";
    cout<<"\nIn nguoc: ";
    for(;pTail!=NULL;pTail=pTail->prev) cout<<pTail->data<<" ";
}
void XoaDau(DS &pHead,DS &pTail){
    DS p=pHead;
    if(pHead==NULL) return;
    if(pHead==pTail) {
        pHead=NULL;
        pTail=NULL;
        delete p;
        return;
    }
    pHead=pHead->next;
    pHead->prev=NULL;
    delete p;
}
void XoaCuoi(DS &pHead,DS &pTail){
    DS p=pTail;
    if(pHead==NULL) return;
    if(pHead==pTail) {
        pHead=NULL;
        pTail=NULL;
        delete p;
        return;
    }
    pTail=pTail->prev;
    pTail->next=NULL;
    delete p;
}
Node *TimK(DS pHead,int K) {
    for(;pHead!=NULL;pHead=pHead->next)
    if(pHead->data==K) return pHead;
    return NULL;
}
void ChenM(DS &pHead,DS &pTail,int M,int K) {
    DS p=TimK(pHead,K);
    if(p==NULL) {ChenCuoi(pHead,pTail,M); return;}
    DS q=TaoNode(M);
    q->next=p->next;
    p->next->prev=q;
    q->prev=p;
    p->next=q;
}
void XoaK(DS &pHead,DS &pTail,int K) {
    DS p=TimK(pHead,K);
    if (p==NULL) return;
    if (p==pHead) {
        XoaDau(pHead,pTail);
        return;
    }
    if (p==pTail) {
        XoaCuoi(pHead,pTail);
        return;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
}
int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10};
    DS pTail,pHead;
    pHead=pTail=NULL;
    TaoDSTuMang(pHead,pTail,A,10);
    //TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    // XoaCuoi(pHead,pTail);
    cout<<"\nSau khi chen: ";
    ChenM(pHead,pTail,10,5);
    InDS(pHead,pTail);
}