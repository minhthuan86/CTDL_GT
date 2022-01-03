#include<iostream>
using namespace std;
struct Node{
	int data;
	Node * Next;
};
typedef Node *DS;
Node *Tao_Node(int x){
	Node *p;
	p= new Node;
	p->data=x;
	p->Next=NULL;
	return p;
}
void ChenDau(DS &pHead,int x){
	Node *p;
	p=Tao_Node(x);
	p->Next=pHead;
	pHead=p;
}
void TaoDS(DS &pHead,int A[],int n){
	for(int i=0;i<n;i++) ChenDau(pHead,A[i]);//in nguoc danh sach
}
void InDS(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->Next){
		cout<<p->data<<"\t";
	}
    cout<<"\n";
}
void sapxep(DS pHead){
    for(DS p=pHead;p->Next!=NULL;p=p->Next)
        for(DS p2=p;p2!=NULL;p2=p2->Next)
        if(p2->data<p->data) swap(p2->data,p->data);
}
int main(){
	int A[]={1,4,2,3,5,6},n=6;
	DS pHead=NULL;
	TaoDS(pHead,A,6);
	InDS(pHead);
    sapxep(pHead);
    InDS(pHead);
}
