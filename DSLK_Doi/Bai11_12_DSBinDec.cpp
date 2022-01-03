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
        if(a!=0) ChenCuoi(pHead,pTail,a);
    }while(a!=0);
}
void InDS(DS pHead,DS pTail){
    for(;pHead!=NULL;pHead=pHead->next) 
        if(pHead->data==-1) cout<<"\n";
        else cout<<pHead->data<<" ";
}
void Binary(DS &pHead_NP,DS &pTail_NP,int n){
    if (n==0) {
        ChenCuoi(pHead_NP,pTail_NP,-1);
        return;
    };
    Binary(pHead_NP,pTail_NP,n/2);
    ChenCuoi(pHead_NP,pTail_NP,n%2);
}
void ChuyenNhiPhan(DS pHead,DS &pHead_NP,DS &pTail_NP){
    for (;pHead!=NULL;pHead=pHead->next){
        Binary(pHead_NP,pTail_NP,pHead->data);
    }       
}
void ChuyenThapPhan(DS pTail_NP){
    DS p=pTail_NP;
    if(pTail_NP==NULL) return ;
    int n=0,i=0;
    while(true){
        if(p->data==-1) {cout<<n<<"\t";n=0;i=0;}
        else {n=n+p->data*pow(2,i);i++;}
        p=p->prev;
        if(p==NULL) return ;
    }
}
int main(){
    DS pTail,pHead,pHead_NP,pTail_NP;
    pHead=pTail=pHead_NP=pTail_NP=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    ChuyenNhiPhan(pHead,pHead_NP,pTail_NP);
    cout<<"\nsau khi chuyen danh sach: \n";
    InDS(pHead_NP,pTail_NP);
    cout<<"\nsau khi chuyen danh sach: \n";
    ChuyenThapPhan(pTail_NP);
}