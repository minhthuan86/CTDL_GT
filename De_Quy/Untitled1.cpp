#include<iostream>
using namespace std;
int Sum(int n)
{
		int s=0;
		for(int i=1;i<=n;i++)
		s+=i;
		return s;
}
int Sum1(int n)
{
		int s=0;
		for(int i=n;i>=1;i--)
		s+=i;
		return s;
}
int Sum_DQ(int n)
{
	if(n==1) return 1;
	return n+Sum_DQ(n-1);
}
int Sum_DQ_2TS(int n,int s=0)
{	
	if(n==0) return s;
	return Sum_DQ_2TS(n-1,s+n);
}
int Sum_DQ_3TS(int n,int s=0,int i=1)
{	
	if(i>n) return s;
	return Sum_DQ_3TS(n,s+i,i+1);
}
int main()
{
	int n=4;
	cout<<"Tong thuan: "<<Sum(n);
	cout<<"\nTong nguoc: "<<Sum1(n);
	cout<<"\nTong DQ: "<<Sum_DQ(n);
	cout<<"\nTong DQ 2 TA: "<<Sum_DQ_2TS(n);
	cout<<"\nTong DQ 3 TA: "<<Sum_DQ_3TS(n);
}

