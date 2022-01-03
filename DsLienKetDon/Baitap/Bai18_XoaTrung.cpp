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
    return p;
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
void XoaTrung(DS &pHead){
	Node *p,*q,*trung;
	p = pHead;
	while (p->next!=NULL){
		q=p;
		while (q->next != NULL){
			if (p->data == q->next->data){
				trung = q->next;
				q->next = q->next->next;
				delete(trung);
			}else 
				q = q->next;
		}
		p = p->next;
	}
}
int main(){
    int M;
    DS pHead=NULL;
    TaoDS(pHead);
    InDS(pHead);
    cout<<"\nDS sau khi xoa phan tu trung : \n";
	XoaTrung(pHead);
    InDS(pHead);
	return 0;
}
