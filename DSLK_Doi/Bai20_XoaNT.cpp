#include<iostream>
#include<math.h>
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
	DS p=pHead;
    cout<<"In thuan:";
    for(p=pHead;p!=NULL;p=p->next) cout<<p->data<<" ";
    cout<<"\nIn nguoc: ";
    for(p=pTail;p!=NULL;p=p->prev) cout<<p->data<<" ";
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
void XoaConTro(DS &pHead,DS &pTail,DS p) {
    if(p==NULL||pHead==NULL) return;
    if(p==pHead) {XoaDau(pHead,pTail);return;}
    if(p==pTail) {XoaCuoi(pHead,pTail);return;}
    p->prev->next=p->next;
    p->next->prev=p->prev;
    delete p;
}
int Check_NT(int x){
	if(x<2) return 0;
	if(x==2||x==3) return 1;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
void XoaNT(DS &pHead,DS &pTail) {
    DS p=pHead;
    do{ 
        if(Check_NT(p->data)==1) {
            DS q=p;
            p=p->next;
            XoaConTro(pHead,pTail,q);
        }
		else p=p->next;
    }while(p!=NULL);
}
int main(){
    DS pHead=NULL,pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    cout<<"\nSau khi xoa:\n";
    XoaNT(pHead,pTail);
    InDS(pHead,pTail);
}
