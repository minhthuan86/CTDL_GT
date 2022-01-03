#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef Node * DS;
Node *TaoNode(int x){
    Node *p=new Node;
    p->data=x;
    p->next=NULL;
}
void ChenCuoi(DS &pHead, int x){
    DS p,q;
    p=TaoNode(x);
    if(pHead==NULL) pHead=p;
    else{
        for(q=pHead;q->next!=NULL;q=q->next);
        q->next=p;
    }
}
void TaoDS(DS &pHead){
    int a;
    do{
        cout<<"Nhap a: ";cin>>a;
        if(a!=0) ChenCuoi(pHead,a);
    }while(a!=0);
}
void InDS(DS pHead){
    DS p;
    for(p=pHead;p!=NULL;p=p->next) cout<<p->data<<"\t";
    cout<<"\n";
}
void XoaDau(DS &pHead){
    DS p;
	p=pHead;
	pHead=pHead->next;
	delete(p);
}
void XoaCuoi(DS &pHead){
    if(pHead==NULL) return;
    if(pHead->next==NULL) XoaDau(pHead);
    DS p,q;
    for(p=pHead;p->next!=NULL; p=p->next) q=p;
    q->next=NULL;
    delete p;
}
int main(){
    DS pHead=NULL;
    TaoDS(pHead);
    InDS(pHead);
    XoaCuoi(pHead);
    InDS(pHead);
}