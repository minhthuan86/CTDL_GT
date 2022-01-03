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
int CheckDS_DoiXung(DS pHead,DS pTail){
    if(pHead==NULL) return 0;
    if(pHead==pTail) return 1;
    do{
        if(pHead->data!=pTail->data) return 0;
        pTail=pTail->prev;
        pHead=pHead->next;
    }while(pHead!=pTail&&pHead->prev!=pTail);
    return 1;
}
int main(){
    DS pHead,pTail;
    pHead=pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    if(CheckDS_DoiXung(pHead,pTail)==1) cout<<"\nDS Doi Xung!"<<endl;
    else cout<<"\nDS Ko Doi Xung!"<<endl;
}