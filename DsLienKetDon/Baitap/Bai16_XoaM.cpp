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
void xoaConTro(DS &pHead, Node *p){
    if(p == NULL) return;
    if(p == pHead)
        XoaDau(pHead);
    else{
        Node *q;
        for(q = pHead; q ->next != p; q = q->next);
        q->next = p->next;
        delete(p);
    }
}
bool DelX(DS &pHead,int x){
	DS q,p;
	int Found=0;
		q=pHead;
		while(q!=NULL && !Found)
			if(q->data!=x)
			{
				p=q;
				q=q->next;
			}
			else Found=1;
			if(Found)
			{
				if(q==pHead)
					pHead=q->next;
				else
					p->next=q->next;
				delete(q);
			}
}
int main(){
    int M;
    DS pHead=NULL;
    TaoDS(pHead);
    InDS(pHead);
    cout<<"\nNhap M = ";cin>>M;
	if(DelX(pHead,M)){
		cout<<"\nSau khi xoa x :\n";	
		InDS(pHead);
	}else{
		cout<<"\nkhong co "<<M<<" o trong danh sach !!!\n";
		InDS(pHead);
	}
}