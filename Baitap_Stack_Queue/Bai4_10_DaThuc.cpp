#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
struct SOHANG{
    float heso;
    int somu;
};
struct Node{
    SOHANG so;
    Node *next;
};
typedef Node *Queue;
Node *TaoNode(float a,int x){
    Node *p=new Node;
    p->so.heso=a;
    p->so.somu=x;
    p->next=NULL;
    return p;
}
void Init(Queue &pHead){
    pHead=NULL;
}
bool IsEmpty(Queue &pHead){
    return pHead==NULL;
}
void chendau(Queue &pHead, SOHANG X){
    Queue p=TaoNode(X.heso,X.somu);
    if(pHead==NULL){
        pHead=p;
    }
    else{
	p->next=pHead;
	pHead=p;
    }
}
Node *TK_MU(Queue pHead,int x){
        for(;pHead!=NULL;pHead=pHead->next){
            if(pHead->so.somu==x) return pHead;
    }
    return NULL;
}
void Push(Queue &pHead){
    Node *p,*q;
    SOHANG X;
    int i=1;
    char ch;
    do{
        cout<<"Nhap bieu thuc thu: "<<i;
        cout<<"\nNhap he so: ";cin>>X.heso;
        cout<<"Nhap so mu: ";cin>>X.somu;
        p=TK_MU(pHead,X.somu);
        if(p!=NULL) {
            p->so.heso=p->so.heso+X.heso;
        }
        else{
            chendau(pHead,X);
        }
        cout<<"Nhap ESC de thoat, phim bat ky de tiep tuc: \n";
        i++;
        ch=getch();
    }while(ch!=27);
}
Node *Pop(Queue &pHead){
    SOHANG d;
	Node *p,*q;
	if(pHead->next==NULL){
     p=pHead;
	 pHead=NULL;
     return p;	
	}
	else{
	for(q=pHead;q->next!=NULL;q=q->next)
		p=q;
		p->next=NULL;
	 	delete(q);
        return p;
   }  
}
void Sort(Queue pHead){
    Node *p,*q;
    for (p=pHead; p->next!=NULL; p=p->next)
        for (q=p->next; q!=NULL; q=q->next){
            if(q->so.somu<p->so.somu){
                swap(q->so,p->so);
            }
        }
}
void OutPut(Queue pHead){
    int a,x;
    Node* p;
    
    while(!IsEmpty(pHead)){   
        p=Pop(pHead);
        a=p->so.heso;
        x=p->so.somu;
        if(a==1){
        if(x==0) cout<<a;
        else if(x==1) cout<<"X";
        else cout<<"X^"<<x;
        }
        else{
        if(x==1) cout<<a<<"X";
        else if(x==0) cout<<a;
        else cout<<a<<"X^"<<x;
        }
        if(p->next!=NULL) cout<<" + ";
    }
}
void Tong(Queue &BTSum,Queue BT1,Queue BT2){
   // Sort(BT1);
   // Sort(BT2);
    while(!IsEmpty(BT1)&&!IsEmpty(BT2)){
        if(BT2!=NULL){
            while(BT1->so.somu>BT2->so.somu) {
                chendau(BTSum,BT1->so); 
                BT1=BT1->next;
            }
        }
        else {while(IsEmpty(BT1)){
                chendau(BTSum,BT1->so);
                BT1=BT1->next;
            }
        }
        if(BT1!=NULL){
            while(BT2->so.somu>BT1->so.somu) {
                chendau(BTSum,BT2->so); 
                BT2=BT2->next;
            }
        }
        else {while(IsEmpty(BT2)){
                chendau(BTSum,BT2->so);
                BT2=BT2->next;
            }
        }
        if(BT1->so.somu==BT2->so.somu){
            BT1->so.heso=BT1->so.heso+BT2->so.heso;
            chendau(BTSum,BT1->so);
            BT1=BT1->next;
            BT2=BT2->next;
        }
    }
}
int tinh(Queue pHead){
    cout<<"Nhap x=";
    
}
int main(){
    Queue BT1,BT2,BTSum;
    Init(BT1);
    Init(BT2);
    cout<<"Nhap BT1:\n";
    Push(BT1);
    cout<<"Nhap BT2:\n";
    Push(BT2);
    cout<<"BT 1:";
    OutPut(BT1);
    cout<<"\nBT 2:";
    OutPut(BT2);
    /*Init(BTSum);
    Tong(BTSum,BT1,BT2);
    cout<<"\nBT Tong:";
    OutPut(BTSum);*/
}

