#include<iostream>
#include<cstdio>
#include<math.h>
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

void Tao_DS(DS &pHead,int A[],int n)
{
	for(int i=0;i<n;i++) Chen_Cuoi_Vong(pHead,A[i]);
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
int Check_NT(int x){
	if(x<2) return 0;
	if(x==2||x==3) return 1;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
void locdanhsach(DS pHead){
    const char *filePath = "D:/NguyenTo.txt";
	FILE *file;
	file=fopen(filePath,"w");
	if(!file) cout<<"ko the mo file";
	else cout<<"\nOK! Da tao File";
	DS p=pHead;
    do{
        if(Check_NT(p->Data)==1) {
            fprintf(file,"%d\n",p->Data);
        }
        p=p->Next;
    }while(p!=pHead);
    fclose(file);
}
int main(){
    int A[]={1,2,3,4,5,6,7,8};
    DS pHead;
	pHead=NULL;
	Tao_DS(pHead,A,8);
	In_DS(pHead);
    locdanhsach(pHead);
}