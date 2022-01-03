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
int KT_Lap(DS pHead,DS pTail,int x){
    for(;pHead!=pTail;pHead=pHead->next) 
        if(pHead->data==x) return 1;
    return 0;
}
void Dem(DS pHead,DS pTail){
    DS p=pHead;
    if(p==NULL) {
        cout<<"\nDS rong";
        return;
    }
    do{
        if(KT_Lap(pHead,p,p->data)==1) p=p->next;
        else{
            int t=0;
            DS q=p;
            for(;q!=NULL;q=q->next) if(q->data==p->data) t++;
            cout<<"\n"<<p->data<<" xuat hien: "<<t<<" lan";
            p=p->next;
        }
    }while(p!=NULL);
}
int main(){
    DS pHead,pTail;
    pHead=pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    Dem(pHead,pTail);
}