#include<iostream>
using namespace std;
  int B(int n){if(n>0){ cout<<n%10<<"\t";B(n/10); }} 
int main(){
	int A[]={1,2,3,4,5} ;
	cout<<B(102);
}
