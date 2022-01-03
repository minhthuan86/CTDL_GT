#include<iostream>
using namespace std;
struct Node
{
	int Data;
	Node *Next;
};
typedef Node * DS;
Node * Tao_Nut(int a)
{
	Node * p;
	p=new Node;
	p->Data=a;
	p->Next=p;
	return p;
}
void Chen_Cuoi_Vong(DS &pHead,int a)
{
	DS p=Tao_Nut(a),q;
	if(pHead==NULL) pHead=p;
	else
	{
		//tim phan tu cuoi ds lv vong;
		for(q=pHead;q->Next!=pHead;q=q->Next);
		//Noi nut moi vao ds
		q->Next=p;
		p->Next=pHead;
	}
}

void Tao_DS(DS &pHead)
{
	int a;
	do{
		cout<<"Nhap a=";cin>>a;
		if(a!=0)
		Chen_Cuoi_Vong(pHead,a);
	}while(a!=0);
}
int CheckTonTai(int A[],int n,int x){
   if(n==0) return 1;
    for(int i=0;i<n;i++){
        if(A[i]==x) return 0;
    }
    return 1;
}
void TaoMangKhongTrung(DS pHead,int A[],int &n){
    if(pHead==NULL) return;
    DS p=pHead;n++;
    do{
    if(CheckTonTai(A,n,p->Data)==1) {A[n]=p->Data;n++;}
    p=p->Next;
    }while(p!=pHead);
}
void xuatmang(int A[],int n){
    for(int i=0;i<n;i++) cout<<A[i]<<"\t";
}
void In_DS(DS pHead)
{
	DS p=pHead;
	if(pHead==NULL) return;
	do{
		cout<<p->Data<<"\t";
		p=p->Next;
	}while(p!=pHead);
	
}
int main(){
    int A[]={},n=-1;
    DS pHead;
	pHead=NULL;
	Tao_DS(pHead);
	In_DS(pHead);
    TaoMangKhongTrung(pHead,A,n);
    cout<<"\n"<<"mang duoc tao:"<<"\n"; 
    xuatmang(A,n);
    return 0;
}
