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
int Check(DS pHead,int a){
    DS p=pHead;
	if(pHead==NULL) return 1;
	do{
		if(p->data==a) return 0;
		p=p->next;
	}while(p!=NULL);
    return 1;	
}
void TaoDSTuMang(DS &pHead,DS &pTail, int A[], int n){
	for(int i = 0; i < n; i++){
		if(Check(pHead,A[i])==1) {
            if(A[i]%2==0) ChenDau(pHead,pTail,A[i]);
            else ChenCuoi(pHead,pTail,A[i]);
		}
	}
}
void InDS(DS pHead,DS pTail){
    cout<<"In thuan:";
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data<<" ";
    cout<<"\nIn nguoc: ";
    for(;pTail!=NULL;pTail=pTail->prev) cout<<pTail->data<<" ";
}
int main(){
    int A[]={1,2,1,4,5,2,7,8,4,2};
    DS pTail,pHead;
    pHead=pTail=NULL;
    TaoDSTuMang(pHead,pTail,A,10);
    InDS(pHead,pTail);
}