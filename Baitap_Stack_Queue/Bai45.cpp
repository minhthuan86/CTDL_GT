#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node *prev;
};
typedef Node *Stack;
Node *TaoNode(int  a){
    Node *p=new Node;
    p->data=a;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void Init(Stack &pHead, Stack &pTail){
    pHead= NULL;
    pTail= NULL;
}
bool IsEmpty(Stack &pHead, Stack &pTail){
    return pHead==NULL && pTail==NULL;
}
void Push(Stack &pHead,Stack &pTail, int a){
    Stack p=TaoNode(a);
    if(pHead==NULL){
        pHead=pTail=p;
    }
    else{
        p->next=pHead;
        pHead->prev=p;
        pHead=p;
    }
}
int Pop(Stack &pHead,Stack &pTail){
    int data;
    Stack p=pTail;
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
void InPut(Stack &pHead,Stack &pTail){
    int a;
    do{
        cout<<"nhap a= ";cin>>a;
        if(a!=0) Push(pHead,pTail,a);
    }while(a!=0);
}
void OutPut(Stack &pHead,Stack &pTail){
    while(!IsEmpty(pHead,pTail)){
        cout<<Pop(pHead,pTail)<<"\t";
    }
}
int main(){
    Stack pHead,pTail;
    Init(pHead,pTail);
    InPut(pHead,pTail);
    OutPut(pHead,pTail);
}

