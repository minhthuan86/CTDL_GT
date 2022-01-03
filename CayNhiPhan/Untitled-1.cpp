#include<iostream>
using namespace std;
//khao bao cau truc
struct Node
{
	int Data;
	Node * Left;
	Node * Right;
};
typedef Node *TREE;
//Ham tao tao nut
Node *Tao_Nut(int a)
{
	Node * p;
	p=new Node;
	p->Data=a;
	p->Left=NULL;
	p->Right=NULL;
	return p;
}
//Viet ham them nut vao cay bang vong lap
void ThemNode(TREE &T,int a)
{
	Node *f=Tao_Nut(a),*p,*q;
	//Kiem tra cay rong
	if(T==NULL) T=f;
	else{ //cay khac rong
		q=T;
		while(q!=NULL) // lap lai cho khi q=NULL
		{
			p=q; //cho p chay theo q;
			if(q->Data==a)return; //Neu da co a thi khong them vao
			if(q->Data>a) q=q->Left;//neu q->Data>a thi lech trai
			else q=q->Right; //nguoc lai thi lech phai
		}
		//kiem tra de noi p vao f
		if(p->Data>a) p->Left=f; 
		else p->Right=f;
	}
}
void Tao_Cay(TREE &T)
{
	int a;
	do{
		cout<<"Nhap a=";cin>>a;
		if(a!=0) ThemNode(T,a);
	}while(a!=0);
}
void NLR(TREE T)
{  if (T!= NULL)
  {    printf("%d ", T->Data);
    NLR(T->Left);
    NLR(T->Right);
 }
}
int main()
{
	TREE T=NULL;
	Tao_Cay(T);
	NLR(T);
}
