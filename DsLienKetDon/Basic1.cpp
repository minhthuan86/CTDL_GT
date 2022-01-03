#include<iostream>
using namespace std;
//khai bao cau truc cua mot nut
struct Node//nut;diem...
{
	int Data;//x,dulieu...
	Node * Next;//tiep; ketnoi;link;
};
//Dinh nghia kiem moi (DS) tu kieu Node
typedef Node * DS;
//Dinh nghia ham tao nut
Node *Tao_Nut(int data)
{
	//khai bao bien con tro p
	Node *p;
	//cap phat vung nho cho de luu tru du lieu
	p=new Node;
	//dua du lieu vao truong Data
	p->Data=data;
	//cho p->Next tro vao NULL
	p->Next=NULL;
	//tra ve bien con tro p
	return p;
}
//Ham chen phan tu moi vao dau danh sach theo co che chen dau
void Chen_Dau(DS &pHead,int x)
{
	//Khai bao bien con tro p
	Node *p;
	//Goi ham tao nut, gan p vao nut vua to
	p=Tao_Nut(x);
	//Noi p vao danh sach
	p->Next=pHead;
	//doi pHead ra vi tri p
	pHead=p;
}
//Ham tao danh sach pHead
void Tao_DS(DS &pHead)
{
	int a;
	//Dung vong lap de nhap cac gia tri
	do{
		cout<<"Nhap a =";cin>>a;
	  if(a!=0)Chen_Dau(pHead,a);
	}while(a!=0);
}
//Ham in danh dach
void In_DS(DS pHead)
{
	Node *p;
	//Dung vong lap de duyet qua cac nut cua ds
	for(p=pHead;p!=NULL;p=p->Next)
	 cout<<p->Data<<"\t"; //lay du lieu tai moi nut in ra man hinh
}
int main()
{
	DS pHead;
	//khoi tao danh sach rong
	pHead=NULL;
	//goi ham tao ds
	Tao_DS(pHead);
	//goi ham in ds
	In_DS(pHead);
}

