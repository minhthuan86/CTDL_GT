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
void XoaConTro(DS &pHead,DS &pTail,DS p) {
    if(p==NULL||pHead==NULL) return;
    if(p==pHead) {XoaDau(pHead,pTail);return;}
    if(p==pTail) {XoaCuoi(pHead,pTail);return;}
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
}
void XoaM(DS &pHead,DS &pTail) {
    int M;
    cout<<"\nNhap GT can xoa: ";cin>>M;
    DS p=TimK(pHead,M);
    XoaConTro(pHead,pTail,p);
    cout<<"Sau khi xoa:\n";
    InDS(pHead,pTail);
}
int main(){
    DS pHead=NULL,pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    XoaM(pHead,pTail);
}