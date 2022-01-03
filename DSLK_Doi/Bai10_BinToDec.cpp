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
        if(a!=-1) ChenCuoi(pHead,pTail,a);
    }while(a!=-1);
}

void InDS(DS pHead,DS pTail){
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data<<" ";
}
int InBinToDec(DS pTail){
    DS p=pTail;
    if(pTail==NULL) return -1;
    int n=0,i=0;
    while(true){
        n=n+p->data*pow(2,i);
        if(p->prev==NULL) return n; 
        else {p=p->prev;i++;}
    }
}
int main(){
    DS pTail,pHead;
    pHead=pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    if (InBinToDec(pTail)==-1) cout<<"DS rong";
    else cout<<": "<<InBinToDec(pTail);
}
