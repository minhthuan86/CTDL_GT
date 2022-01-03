#include<iostream>
using namespace std;
int A(int n){if(n==0) return 0; return n*A(n-1);}
 
 
 int main(){
  int a, *p, *q; float *t; a=5; p=&a; p=q; t=p; printf("%d%f",a,t);
 }
