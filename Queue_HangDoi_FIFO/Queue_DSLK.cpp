#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};
typedef Node *Queue;
Node *TaoNode(int  a){
    Node *p=new Node;
    p->data=a;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void Init(Queue &pHead, Queue &pTail){
    pHead= NULL;
    pTail= NULL;
}
bool IsEmpty(Queue &pHead, Queue &pTail){
    return pHead==NULL && pTail==NULL;
}
void Push(Queue &pHead,Queue &pTail, int a){
    Queue p=TaoNode(a);
    if(pHead==NULL){
        pHead=pTail=p;
    }
    else{
        p->next=pHead;
        pHead->prev=p;
        pHead=p;
    }
}
int Pop(Queue &pHead,Queue &pTail){
    int data;
    Queue p=pTail;
    if(pHead==pTail) {
        data=pHead->data;
        pHead=NULL;
        pTail=NULL;
        delete p;
        return data;
    }
    data=pTail->data;
    pTail=pTail->prev;
    pTail->next=NULL;
    delete p;
    return data;
}
void InPut(Queue &pHead,Queue &pTail){
    int a;
    do{
        cout<<"nhap a= ";cin>>a;
        if(a!=0) Push(pHead,pTail,a);
    }while(a!=0);
}
void OutPut(Queue &pHead,Queue &pTail){
    while(!IsEmpty(pHead,pTail)){
        cout<<Pop(pHead,pTail)<<"\t";
    }
}
int main(){
    Queue pHead,pTail;
    Init(pHead,pTail);
    InPut(pHead,pTail);
    OutPut(pHead,pTail);
}

