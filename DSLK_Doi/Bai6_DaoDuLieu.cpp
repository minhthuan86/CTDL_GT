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
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data<<" ";
}
void DaoDuLieu(DS pHead,DS pTail){
    if(pHead==NULL) return ;
    if(pHead==pTail) return ;
    do{
        swap(pHead->data,pTail->data);
        //cout<<pHead->data<<"<->"<<pTail->data<<endl;
        pTail=pTail->prev;
        pHead=pHead->next;
    }while(pHead!=pTail&&pHead->prev!=pTail);
}
int main(){
    DS pHead,pTail;
    pHead=pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    DaoDuLieu(pHead,pTail);
    InDS(pHead,pTail);
}