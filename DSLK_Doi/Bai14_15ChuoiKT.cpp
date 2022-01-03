#include<iostream>
#include<string>
using namespace std;
struct Node{
    char data;
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
    string str;
    cout<<"Nhap chuoi: ";
    getline(cin,str);
    for(int i=0;i<str.length();i++) {
        ChenCuoi(pHead,pTail,str[i]);
    }
}
void XoaDau(DS &pHead,DS &pTail){
    DS p=pHead;
    if(pHead==NULL) return;
    if(pHead==pTail) {
        pHead=NULL;
        pTail=NULL;
        delete p;
        return;
    }
    pHead=pHead->next;
    pHead->prev=NULL;
    delete p;
}
void XoaCuoi(DS &pHead,DS &pTail){
    DS p=pTail;
    if(pHead==NULL) return;
    if(pHead==pTail) {
        pHead=NULL;
        pTail=NULL;
        delete p;
        return;
    }
    pTail=pTail->prev;
    pTail->next=NULL;
    delete p;
}
void XoaKhoangTrong(DS &pHead,DS &pTail){
    while(pHead->data==' ') XoaDau(pHead,pTail);
    while(pTail->data==' ') XoaCuoi(pHead,pTail);
    for(DS p=pHead; p!=NULL; p=p->next)
        if(p->data==' ') 
            while(p->next->data==' ') {
                DS q=p->next;
                q->prev->next=q->next;
                q->next->prev=q->prev;
                delete q;
            }
}
void InDS(DS pHead,DS pTail){
    for(;pHead!=NULL;pHead=pHead->next) cout<<pHead->data; 
}
int main(){
    DS pTail,pHead;
    pHead=pTail=NULL;
    TaoDS(pHead,pTail);
    InDS(pHead,pTail);
    cout<<"\nSau khi xoa khoan trong\n";
    XoaKhoangTrong(pHead,pTail);
    InDS(pHead,pTail);
   
}