#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef Node * Stack;
Node *TaoNode(int a){
    Node *p = new Node;
    p->data = a;
    p->next =NULL;
    return p;
}
void Init(Stack &pHead){
    pHead=NULL;
}
bool IsEmpty(Stack &pHead){
    return pHead==NULL;
}
void Push(Stack &pHead,int a){
    Stack p=TaoNode(a);
    p->next=pHead;
    pHead=p;
}
int Pop(Stack &pHead){
    int a=pHead->data;
    Stack p=pHead;
    pHead=pHead->next;
    delete p;
    return a;
}
void InPut(Stack &pHead,int S[],int n){
    for(int i=0;i<n;i++){
        while(S[i]!=0){
            Push(pHead,S[i]%2);
            S[i]=S[i]/2;
        }
        Push(pHead,-1);
    }
}
void OutPut(Stack &pHead){
    while(!IsEmpty(pHead)){
    int i=Pop(pHead);
    if(i==-1) cout<<"\n";
    else cout<<i;
    }
}
int main(){
    int A[]={2,3,4,5,6,7,8};
    Stack pHead;
    Init(pHead);
    InPut(pHead,A,7);
    OutPut(pHead);
}