#include<iostream>
#define max 5
using namespace std;
struct Queue
 {
 	int r;
 	int f;
 	int count;
 	int Node[max];
 };
 int n,x;
 //Ham khoi tao Queue
 void QueuetInit(Queue &s)
 {
 	s.r=-1;
 	s.f=0;
 	s.count=0;
 }
 //Hàm kiem tra DS rong
 int QueueEmpty(Queue Q)
 {
 	return (Q.count==0);
 }
 //Ham kiem tra danh Qach day
 int QueueFull(Queue Q)
 {
 	return (Q.count==max);
 }
 //Ham dua gia tri vao dQ
 void Push(Queue &Q, int x)
 {
 	if(QueueFull(Q))
 	{
 		cout<<"Ngan xep day!";
 	}
 	else
 	{
 		if(Q.r==max-1)
 		   Q.r=0;
 		else
 		 Q.r++;
 		Q.Node[Q.r]=x;
 		Q.count++;
 	}
 }
 //Ham lay gia tri ra khoi ds
 int Pop(Queue &Q)
 {
  if(QueueEmpty(Q))
 {
 	cout<<"Ngan xep rong";
 	return 0;
 }else
 { 
    int data=Q.Node[Q.f];
    Q.count--;
    if(Q.f==max-1)
    Q.f=0;
    else Q.f++;
 	return data;
 }
}
//Ham nhap danh sach
void InPut(Queue &Q)
{
     cout<<"Nhap so luong phan tu: ";
     cin>>n;
	 for(int i=1;i<=n;i++)
	 {
      if(QueueFull(Q))
      {
      cout<<"\nNgan xep day\n";
       break;
       }
	 	cout<<"Nhap x= ";
	 	cin>>x;
	 	Push(Q,x);
    }
}
//Ham in danh sach
void OutPut(Queue &Q)
{
    cout<<"\nNgan xep vua nhap la:\n"; 
   	while(!QueueEmpty(Q))
    {
	 cout<<Pop(Q)<<"\t";
    }
}
int main()
{
	int n;
	Queue Q;
	QueuetInit(Q);
	InPut(Q);
    OutPut(Q);
}
