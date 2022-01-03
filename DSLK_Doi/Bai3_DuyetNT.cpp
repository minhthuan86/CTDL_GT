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
void TaoDSTuMang(DS &pHead,DS &pTail,int A[],int n,int i){
    if(i==n) return;
    else ChenCuoi(pHead,pTail,A[i]);
    TaoDSTuMang(pHead,pTail,A,n,i+1);
}
void InDS(DS pHead,DS pTail){
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data<<" ";
}
int Check_NT(int x){
	if(x<2) return 0;
	if(x==2||x==3) return 1;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
void TaoDSNT(DS pHead,DS &pHead_NT,DS &pTail_NT) {
    if(pHead==NULL) return;
    if(Check_NT(pHead->data)==1) ChenCuoi(pHead_NT,pTail_NT,pHead->data);
    TaoDSNT(pHead->next,pHead_NT,pTail_NT);
}
int main(){
    int A[]={1,2,3,4,5,6,7,8,9,10};
    DS pTail,pHead,pHead_NT,pTail_NT;
    pHead=pTail=pHead_NT=pTail_NT=NULL;
    TaoDSTuMang(pHead,pTail,A,10,0);
    InDS(pHead,pTail);
    TaoDSNT(pHead,pHead_NT,pTail_NT);
    cout<<"\nDS NT: ";
    InDS(pHead_NT,pTail_NT);  
}