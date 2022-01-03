#include<iostream>
#include<math.h>
using namespace std;
struct Node{
	int data;
	Node * Next;
};
typedef Node *DS;
Node *TaoNode(int x){
	Node *p;
	p=new Node;
	p->data=x;
	p->Next=NULL;
	return p;
}
Node ChenDau(DS &pHead,int x){
	Node *p;
	p=TaoNode(x);
	p->Next=pHead;
	pHead=p;
}
void TaoDS(DS &pHead,int A[],int n){
	for(int i=0;i<n;i++) ChenDau(pHead,A[i]);//in nguoc danh sach
}
void InDS(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->Next)
		cout<<p->data<<"\t";
}
//Bai3
int Max(DS pHead){
	Node *p;
	int max=pHead->data;
	for(p=pHead;p!=NULL;p=p->Next) if(p->data>max) max=p->data;
	return max;
}
//Bai4
int nguyento(int x){
	if(x<2) return 0;
	if(x==2||x==3) return 1;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
void NT(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->Next) if(nguyento(p->data)) cout<<p->data<<"\t";
}
//Bai5
float TBC(DS pHead){
	Node *p;
	float a=0,t=0;
	for(p=pHead;p!=NULL;p=p->Next){
		a+=p->data;
		t++;
	}
	return a/t;
}
//Bai6
void TangDan(DS pHead){
	Node *p,*q;
	int t=1;
	for(p=pHead;p!=NULL;p=p->Next) {
	if(p->Next!=NULL) {q=p->Next;
//	cout<<p->data<<"  "<<q->data<<"---";
		if(p->data>=q->data) {
			t=0;
		}
	}
	}
	if(t==1) cout<<"ds tang dan";
	else cout<<"ds khong tang dan";
	//duyet nguoc
}
//Bai7
void TaoDS_KoTrung(DS &pHead,int A[],int n){
	for(int i=1;i<n;i++){
		ChenDau(pHead,A[0]);
		Node *p;
		for(p=pHead;p!=NULL;p=p->Next) {
			if(p->data==A[i]) break;
			ChenDau(p,A[i]);
		}
	}
}
//Bai8

int main(){
	int A[]={6,5,4,5,2,1};
	DS pHead=NULL;
	//TaoDS(pHead,A,6);
	//cout<<"Max= "<<Max(pHead);
	//NT(pHead);
	//cout<<"TBC= "<<TBC(pHead);
	//TangDan(pHead);
	TaoDS_KoTrung(pHead,A,6);
	InDS(pHead);
	return 0;
}
