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
void Chen_Dau(DS &pHead,int a)
{
	DS p=Tao_Nut(a);
	p->Next=pHead;
	pHead=p;
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
    FILE * fp = NULL;
    fp= fopen("D:/NguyenTo.txt", "r");
    int a;
    while (fscanf(fp,"%d",&a) != EOF)
    {
        Chen_Cuoi_Vong(pHead,a);
    }
    fclose(fp);
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
    DS pHead;
	pHead=NULL;
	Tao_DS(pHead);
	In_DS(pHead);
}
