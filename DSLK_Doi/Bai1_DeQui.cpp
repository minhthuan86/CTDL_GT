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
void TaoDSTuMang(DS &pHead,DS &pTail,int A[],int n,int i){
    if(i==n) return;
    else ChenDau(pHead,pTail,A[i]);
    TaoDSTuMang(pHead,pTail,A,n,i+1);
}
void InDS(DS pHead,DS pTail){
    cout<<"In thuan:";
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data<<" ";
    cout<<"\nIn nguoc: ";
    for(;pTail!=NULL;pTail=pTail->prev) cout<<pTail->data<<" ";
}
int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10};
    DS pTail,pHead;
    pHead=pTail=NULL;
    TaoDSTuMang(pHead,pTail,A,10,0);
    InDS(pHead,pTail);
}