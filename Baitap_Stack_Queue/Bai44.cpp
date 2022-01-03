#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
typedef Node *Queue;
Node *TaoNode(int  a){
    Node *p=new Node;
    p->data=a;
    p->next=NULL;
    return p;
}
void Init(Queue &pHead){
    pHead=NULL;
}
bool IsEmpty(Queue &pHead){
    return pHead==NULL;
}
void Push(Queue &pHead, int a){
    Queue p=TaoNode(a);
    if(pHead==NULL){
        pHead=p;
    }
    else{
	p->next=pHead;
	pHead=p;
    }
}
int Pop(Queue &pHead){
    int d;
	Node *p,*q;
	if(pHead->next==NULL){
     d=pHead->data;
	 pHead=NULL;
     return d;	
	}
	else{
	for(q=pHead;q->next!=NULL;q=q->next)
		p=q;
		p->next=NULL;
        d=q->data;
	 	delete(q);
        return d;
   }  
}
void InPut(Queue &pHead){
    int a;
    do{
        cout<<"nhap a= ";cin>>a;
        if(a!=0) Push(pHead,a);
    }while(a!=0);
}
void OutPut(Queue &pHead){
    while(!IsEmpty(pHead)){
        cout<<Pop(pHead)<<"\t";
    }
}
int main(){
    Queue pHead;
    Init(pHead);
    InPut(pHead);
    OutPut(pHead);
}

