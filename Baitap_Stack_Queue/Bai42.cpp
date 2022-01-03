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
void InPut(Stack &pHead){
    int a;
	do{
		cout<<"Nhap a = ";cin>>a;
	  if(a!=0) Push(pHead,a);
	}while(a!=0);
}
void OutPut(Stack &pHead){
    while(!IsEmpty(pHead)) cout<<Pop(pHead)<<"\t";
}
int main(){
    Stack pHead;
    Init(pHead);
    InPut(pHead);
    OutPut(pHead);
}