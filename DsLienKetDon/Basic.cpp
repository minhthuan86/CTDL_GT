#include<iostream>
using namespace std;
//khai bao cau truc nut
struct Node{
		int data;
		Node * Next;
};
//dinh nghia kieu moi tu kieu node	
typedef Node *DS;
//dinh nghia ham tao nut
Node *Tao_Node(int a){
	//khai bao con tro p
	Node *p;
	//cap phat vung nho de luu tru
	p=new Node;
	//dua du lieu vao truong data
	p->data=a;
	p->Next=NULL;
	//tra ve bien con tro p
	return p;
}
//chen phan tu moi vao dau danh sach
void Chen_Dau(DS &pHead,int x){
	//khai bao bien con tro p
	Node *p;
	//goi ham tao nut, gan p vao nut vua tao
	p=Tao_Node(x);
	//noi p vao danh sach
	p->Next=pHead;
	//doi pHead ra vi tri p
	pHead=p;
}
//viet ham tao danh sach
void Tao_DS(DS &pHead)
{
	int a;
	do{
	cout<<"Nhap a= ";cin>>a;
	if(a!=0) Chen_Dau(pHead,a);
  }while(a!=0);
}
void In_DS(DS pHead){
	Node *p;
	for(p=pHead;p!=NULL;p=p->Next)
		cout<<p->data<<"\t";
}
void Tong_Chan(DS pHead){
	int sum=0;
	Node *p;
	for(p=pHead;p!=NULL;p=p->Next)
		if(p->data%2==0) sum+=p->data;
	cout<<"\nTong chan: "<<sum;
}
int main(){
	DS pHead;
	pHead = NULL;
	Tao_DS(pHead);
	In_DS(pHead);
	Tong_Chan(pHead);
	return 0;
}
