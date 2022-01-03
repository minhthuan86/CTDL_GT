#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
struct Node{
	int data;
	Node *next;
};
typedef Node*DS;
Node *TaoNode(int x){
	Node *p;
	p=new Node;
	p->data=x;
	p->next=NULL;
	return p;
}
Node ChenDau(DS &pHead,int x){
	Node *p;
	p=TaoNode(x);
	p->next=pHead;
	pHead=p;
}
Node ChenCuoi(DS &pHead,int x){
	Node *p,*q;
	p=TaoNode(x);
	if(pHead==NULL) pHead=p;
	else{
		for(q=pHead;q->next!=NULL;q=q->next);
		q->next=p;
	}
}
int Check_NT(int x){
	if(x<2) return 0;
	if(x==2||x==3) return 1;
	for(int i=2;i<=sqrt(x);i++) if(x%i==0) return 0;
	return 1;
}
int Check_HH(int n){

    int flag = 0, total=0;   
    for (int i=1;i<n; i++){
         if (n % i == 0) total+=i;
    }
    if (total == n & n!=0) flag = 1;

    return flag;
}
void TaoDS(DS &pHead,int A[],int n){
	for(int i=0;i<n;i++) ChenCuoi(pHead,A[i]);
}
void InDS(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->next)
		cout<<p->data<<"\t";
	cout<<"\n";
}
void locdanhsach(DS pHead,DS &pHeadNT,DS &pHeadHH){
	for(Node *p=pHead;p!=NULL;p=p->next){
		if(Check_NT(p->data)) ChenDau(pHeadNT,p->data);
		else if (Check_HH(p->data)) ChenDau(pHeadHH,p->data);
	}
}
void ghivaofile(FILE *file,DS pHeadNT,DS pHeadHH){
	fputs("So Nguyen To: ",file);
	for(Node *p=pHeadNT;p!=NULL;p=p->next) fprintf(file,"%d\t",p->data);
	fputs("\n",file);
	fputs("So Hoan Hao: ",file);
	for(Node *p=pHeadHH;p!=NULL;p=p->next) fprintf(file,"%d\t",p->data);	
}
void TaoFile(DS pHeadNT,DS pHeadHH){
	const char *filePath = "D:/NT_HH.txt";
	FILE *file;
	file=fopen(filePath,"w");
	if(!file) cout<<"ko the mo file";
	else cout<<"OK!";
	ghivaofile(file, pHeadNT,pHeadHH);
	fclose(file);
}
int main(){
	int A[]={1,2,3,4,5,6,7,8,9};
	DS pHead,pHeadHH,pHeadNT;
	pHead=NULL;
	pHeadHH=NULL;
	pHeadNT=NULL;
	TaoDS(pHead,A,9);
	locdanhsach(pHead,pHeadNT,pHeadHH);
	InDS(pHead);
	cout<<"SO nguyen to: ";
	InDS(pHeadNT);
	cout<<"so hoan hao: ";
	InDS(pHeadHH);
	TaoFile(pHeadNT,pHeadHH);
	return 0;
}
